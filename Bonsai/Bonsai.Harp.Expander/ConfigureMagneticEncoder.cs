using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [Description("Generates a sequence of Harp messages to configure the magnetic encoder in OutputExpander devices.")]
    public class ConfigureMagneticEncoder : Source<HarpMessage>
    {
        [Description("Specifies the sampling rate of the magnetic encoder.")]
        public MagneticEncoderSampleRate SampleRate { get; set; } = MagneticEncoderSampleRate.SampleRate1000Hz;

        IEnumerable<HarpMessage> CreatePwmCommand()
        {
            yield return HarpCommand.WriteByte(OutputExpander.Registers.ExpansionOptions, (byte)ExpansionType.MagneticEncoder);
            yield return HarpCommand.WriteByte(OutputExpander.Registers.MagEncoderMode, (byte)SampleRate);
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

    public enum MagneticEncoderSampleRate : byte
    {
        SampleRate50Hz,
        SampleRate100Hz,
        SampleRate200Hz,
        SampleRate250Hz,
        SampleRate500Hz,
        SampleRate1000Hz
    }
}
