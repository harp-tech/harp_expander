using Bonsai.Expressions;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Linq.Expressions;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [TypeDescriptionProvider(typeof(DeviceTypeDescriptionProvider<AuxInputs>))]
    [Description("Returns the sequence of state transitions for the auxiliary inputs of Expander devices.")]
    public class AuxInputs : SingleArgumentExpressionBuilder, INamedElement
    {
        [RefreshProperties(RefreshProperties.All)]
        [Description("Specifies which auxiliary input state to read.")]
        public AuxInputEvent Type { get; set; } = AuxInputEvent.Input0;

        [Description("Specifies whether to include the Harp timestamp in the result.")]
        public bool IncludeTimestamp { get; set; }

        string INamedElement.Name => $"{nameof(AuxInputs)}.{Type}";

        string Description
        {
            get
            {
                switch (Type)
                {
                    case AuxInputEvent.State: return "Reads the compound state of all auxiliary inputs, as a bitmask.";
                    case AuxInputEvent.Input0: return "Reads the state of auxiliary input 0.";
                    case AuxInputEvent.Input1: return "Reads the state of auxiliary input 1.";
                    default: return null;
                }
            }
        }

        public override Expression Build(IEnumerable<Expression> arguments)
        {
            string methodName;
            var expression = arguments.First();
            switch (Type)
            {
                case AuxInputEvent.State:
                    methodName = IncludeTimestamp ? nameof(GetTimestampedState) : nameof(GetState);
                    return Expression.Call(typeof(AuxInputs), methodName, null, expression);
                case AuxInputEvent.Input0:
                case AuxInputEvent.Input1:
                    var bitmask = Expression.Constant((byte)Type);
                    methodName = IncludeTimestamp ? nameof(GetTimestampedAuxInput) : nameof(GetAuxInput);
                    return Expression.Call(typeof(AuxInputs), methodName, null, expression, bitmask);
                default:
                    throw new InvalidOperationException("Invalid or unsupported event type.");
            }
        }

        static IObservable<byte> GetState(IObservable<HarpMessage> source)
        {
            return source.Event(InputExpander.Registers.AuxInputs).Select(input => input.GetPayloadByte());
        }

        static IObservable<bool> GetAuxInput(IObservable<HarpMessage> source, byte bitmask)
        {
            return GetState(source).Select(value => (value & bitmask) == bitmask);
        }

        static IObservable<Timestamped<byte>> GetTimestampedState(IObservable<HarpMessage> source)
        {
            return source.Event(InputExpander.Registers.AuxInputs).Select(input => input.GetTimestampedPayloadByte());
        }

        static IObservable<Timestamped<bool>> GetTimestampedAuxInput(IObservable<HarpMessage> source, byte bitmask)
        {
            return GetTimestampedState(source).Select(state =>
            {
                return Timestamped.Create((state.Value & bitmask) == bitmask, state.Seconds);
            });
        }
    }

    public enum AuxInputEvent
    {
        State,
        Input0,
        Input1
    }
}
