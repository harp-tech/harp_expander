using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [Description("Generates a sequence of Harp messages to configure the PWM feature of OutputExpander devices.")]
    public class ConfigurePwm : Source<HarpMessage>
    {
        [Description("Specifies which PWM digital outputs to enable.")]
        public PwmEnableFlags Mask { get; set; } = PwmEnableFlags.PwmOutput1;

        [Description("The frequency of the PWM. The maximum frequency is 1000Hz.")]
        public float Frequency { get; set; }

        [Description("The duty cycle of the PWM. The maximum value is 100%.")]
        public float DutyCycle { get; set; }

        [Description("The number of pulses to trigger on the specified PWM. If the default value of zero is specified, the PWM will be infinite.")]
        public int Count { get; set; }

        IEnumerable<HarpMessage> CreatePwmCommand()
        {
            var pwmOffset = Mask >= PwmEnableFlags.PwmOutput6 ? OutputExpander.Registers.Pwm1 : OutputExpander.Registers.Pwm0;
            yield return HarpCommand.WriteUInt16(OutputExpander.Registers.PwmEnable, (ushort)Mask);
            yield return HarpCommand.WriteSingle(pwmOffset + OutputExpander.Registers.PwmFrequency, Frequency);
            yield return HarpCommand.WriteSingle(pwmOffset + OutputExpander.Registers.PwmDutyCycle, DutyCycle);
            if (Count > 0)
            {
                yield return HarpCommand.WriteUInt16(pwmOffset + OutputExpander.Registers.PwmCount, (ushort)Count);
                yield return HarpCommand.WriteByte(pwmOffset + OutputExpander.Registers.PwmMode, 1);
            }
            else yield return HarpCommand.WriteByte(pwmOffset + OutputExpander.Registers.PwmMode, 0);
            yield return HarpCommand.WriteByte(pwmOffset + OutputExpander.Registers.PwmTrigger, 0);
            yield return HarpCommand.WriteByte(pwmOffset + OutputExpander.Registers.PwmConfigureEvent, 1);
        }

        public override IObservable<HarpMessage> Generate()
        {
            return CreatePwmCommand().ToObservable();
        }

        public IObservable<HarpMessage> Generate<TSource>(IObservable<TSource> source)
        {
            return source.SelectMany(input => CreatePwmCommand());
        }
    }

    [Flags]
    public enum PwmEnableFlags : ushort
    {
        None = 0 << 0,
        PwmOutput1 = 1 << 0,
        PwmOutput2 = 1 << 1,
        PwmOutput3 = 1 << 2,
        PwmOutput6 = 1 << 3,
        PwmOutput7 = 1 << 4,
        PwmOutput8 = 1 << 5,
        PwmOutput9 = 1 << 6
    }
}
