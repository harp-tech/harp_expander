using System;
using System.ComponentModel;
using System.Linq;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [Description("Generates a Harp message to configure the expansion board connected to OutputExpander devices.")]
    public class ConfigureExpansion : Source<HarpMessage>
    {
        [Description("Specifies which board is currently connected in the expansion port.")]
        public ExpansionType ExpansionType { get; set; } = ExpansionType.Breakout;

        HarpMessage CreatePwmCommand()
        {
            return HarpCommand.WriteByte(OutputExpander.Registers.ExpansionOptions, (byte)ExpansionType);
        }

        public override IObservable<HarpMessage> Generate()
        {
            return Observable.Return(CreatePwmCommand());
        }

        public IObservable<HarpMessage> Generate<TSource>(IObservable<TSource> source)
        {
            return source.Select(input => CreatePwmCommand());
        }
    }

    [Flags]
    public enum ExpansionType : byte
    {
        Breakout,
        MagneticEncoder,
        ServoMotor1,
        ServoMotor2,
        ServoMotor3
    }
}
