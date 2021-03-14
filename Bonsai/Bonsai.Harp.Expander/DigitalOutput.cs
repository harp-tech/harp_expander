using Bonsai.Expressions;
using System;
using System.ComponentModel;
using System.Linq.Expressions;

namespace Bonsai.Harp.Expander
{
    [Description("Controls the digital outputs of OutputExpander devices.")]
    [TypeDescriptionProvider(typeof(DeviceTypeDescriptionProvider<DigitalOutput>))]
    public class DigitalOutput : SelectBuilder, INamedElement
    {
        [RefreshProperties(RefreshProperties.All)]
        [Description("Specifies the command used to control the digital outputs.")]
        public DigitalOutputCommand Command { get; set; } = DigitalOutputCommand.Set;

        [Description("Specifies which digital outputs to control.")]
        public DigitalOutputFlags Mask { get; set; } = DigitalOutputFlags.Output0;

        string INamedElement.Name => $"{nameof(DigitalOutput)}.{Command}";

        string Description
        {
            get
            {
                switch (Command)
                {
                    case DigitalOutputCommand.Set: return "Sets the specified digital outputs to HIGH.";
                    case DigitalOutputCommand.Clear: return "Sets the specified digital outputs to LOW";
                    case DigitalOutputCommand.Toggle: return "Toggles the specified digital outputs.";
                    case DigitalOutputCommand.Write: return "Sets the specified digital outputs to the specified state.";
                    default: return null;
                }
            }
        }

        protected override Expression BuildSelector(Expression expression)
        {
            var instance = Expression.Constant(this);
            return Expression.Call(instance, nameof(CreateCommand), null);
        }

        HarpMessage CreateCommand()
        {
            return HarpCommand.WriteUInt16(OutputExpander.Registers.OutputSet + (byte)Command, (ushort)Mask);
        }
    }

    public enum DigitalOutputCommand
    {
        Set,
        Clear,
        Toggle,
        Write
    }

    [Flags]
    public enum DigitalOutputFlags : ushort
    {
        None = 0 << 0,
        Output0 = 1 << 0,
        Output1 = 1 << 1,
        Output2 = 1 << 2,
        Output3 = 1 << 3,
        Output4 = 1 << 4,
        Output5 = 1 << 5,
        Output6 = 1 << 6,
        Output7 = 1 << 7,
        Output8 = 1 << 8,
        Output9 = 1 << 9,
    }
}
