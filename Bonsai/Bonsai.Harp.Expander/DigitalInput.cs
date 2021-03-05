using Bonsai.Expressions;
using Bonsai.Harp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Linq.Expressions;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [TypeDescriptionProvider(typeof(DeviceTypeDescriptionProvider<DigitalInput>))]
    [Description("Returns the sequence of state transitions for the digital inputs of InputExpander devices.")]
    public class DigitalInput : SingleArgumentExpressionBuilder, INamedElement
    {
        [RefreshProperties(RefreshProperties.All)]
        [Description("Specifies which digital input state to read.")]
        public DigitalInputEvent Type { get; set; } = DigitalInputEvent.Input0;

        [Description("Specifies whether to include the Harp timestamp in the result.")]
        public bool IncludeTimestamp { get; set; }

        string INamedElement.Name => $"{nameof(DigitalInput)}.{Type}";

        string Description
        {
            get
            {
                switch (Type)
                {
                    case DigitalInputEvent.State: return "Reads the compound state of all digital inputs, as a bitmask.";
                    default: return "Reads the state of the specified digital input."; ;
                }
            }
        }

        public override Expression Build(IEnumerable<Expression> arguments)
        {
            string methodName;
            var expression = arguments.First();
            switch (Type)
            {
                case DigitalInputEvent.State:
                    methodName = IncludeTimestamp ? nameof(GetTimestampedState) : nameof(GetState);
                    return Expression.Call(typeof(DigitalInput), methodName, null, expression);
                default:
                    var bitmask = Expression.Constant((byte)Type);
                    var eventMask = Expression.Constant((byte)((byte)Type << 8));
                    methodName = IncludeTimestamp ? nameof(GetTimestampedDigitalInput) : nameof(GetDigitalInput);
                    return Expression.Call(typeof(DigitalInput), methodName, null, expression, eventMask, bitmask);
            }
        }

        static IObservable<ushort> GetState(IObservable<HarpMessage> source)
        {
            return source.Event(InputExpander.Registers.Inputs).Select(input => input.GetPayloadUInt16());
        }

        static IObservable<bool> GetDigitalInput(IObservable<HarpMessage> source, byte eventMask, byte bitmask)
        {
            return GetState(source).Where(state => (state & eventMask) == eventMask).Select(value => (value & bitmask) == bitmask);
        }

        static IObservable<Timestamped<ushort>> GetTimestampedState(IObservable<HarpMessage> source)
        {
            return source.Event(InputExpander.Registers.Inputs).Select(input => input.GetTimestampedPayloadUInt16());
        }

        static IObservable<Timestamped<bool>> GetTimestampedDigitalInput(IObservable<HarpMessage> source, byte eventMask, byte bitmask)
        {
            return GetTimestampedState(source).Where(state => (state.Value & eventMask) == eventMask).Select(state =>
            {
                return Timestamped.Create((state.Value & bitmask) == bitmask, state.Seconds);
            });
        }
    }

    public enum DigitalInputEvent
    {
        State,
        Input0 = 1 << 0,
        Input1 = 1 << 1,
        Input2 = 1 << 2,
        Input3 = 1 << 3,
        Input4 = 1 << 4,
        Input5 = 1 << 5,
        Input6 = 1 << 6,
        Input7 = 1 << 7,
        Input8 = 1 << 8,
        Input9 = 1 << 9,
    }
}
