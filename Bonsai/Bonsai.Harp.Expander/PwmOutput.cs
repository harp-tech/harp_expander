using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [Description("Controls the PWM outputs of OutputExpander devices.")]
    [TypeDescriptionProvider(typeof(DeviceTypeDescriptionProvider<PwmOutput>))]
    public class PwmOutput : Combinator<HarpMessage>, INamedElement
    {
        [RefreshProperties(RefreshProperties.All)]
        [Description("Specifies the command used to control the PWM outputs.")]
        public PwmCommand Command { get; set; } = PwmCommand.Start;

        [Description("Specifies which PWM outputs to control.")]
        public PwmFlags Mask { get; set; } = PwmFlags.Pwm0;

        string INamedElement.Name => $"{nameof(PwmOutput)}.{Command}";

        public override IObservable<HarpMessage> Process<TSource>(IObservable<TSource> source)
        {
            return source.Select(input => HarpCommand.WriteByte(OutputExpander.Registers.PwmStart + (byte)Command, (byte)Mask));
        }
    }

    public enum PwmCommand : byte
    {
        Start,
        Stop
    }

    [Flags]
    public enum PwmFlags : byte
    {
        Pwm0 = 1 << 0,
        Pwm1 = 1 << 1,
        Pwm2 = 1 << 2
    }
}
