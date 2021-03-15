using System;
using System.ComponentModel;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [Combinator(MethodName = nameof(Generate))]
    [WorkflowElementCategory(ElementCategory.Source)]
    [Description("Generates events and processes commands for the OutputExpander device.")]
    public class OutputExpander
    {
        readonly Device board = new Device();

        [Description("The name of the serial port used to communicate with the OutputExpander device.")]
        [TypeConverter(typeof(PortNameConverter))]
        public string PortName
        {
            get { return board.PortName; }
            set { board.PortName = value; }
        }

        public IObservable<HarpMessage> Generate()
        {
            return Generate(Observable.Empty<HarpMessage>());
        }

        public IObservable<HarpMessage> Generate(IObservable<HarpMessage> source)
        {
            return board.Generate(source);
        }

        internal static class Registers
        {
            public const byte AuxInputs = 32; // U8     State of the auxiliar inputs
            public const byte OutputSet = 35; // U16    Set the outputs
            public const byte OutputClear = 36; // U16    Clear the outputs
            public const byte OutputToggle = 37; // U16    Toggle the outputs
            public const byte OutputWrite = 38; // U16    Write to all outputs at once
            public const byte Reserved0 = 39; // U8
            public const byte Reserved1 = 40; // U8
            public const byte PwmEnable = 41; // U16     Selects the current expansion board available in the EXPANSION port
            public const byte Pwm0Frequency = 42; // FLOAT
            public const byte Pwm0DutyCycle = 43; // FLOAT
            public const byte Pwm0Count = 44; // U16
            public const byte Pwm0ActualFrequency = 45; // FLOAT
            public const byte Pwm0ActualDutyCycle = 46; // FLOAT
            public const byte Pwm0Mode = 47; // U8
            public const byte Pwm0Trigger = 48; // U8
            public const byte Pwm0ConfigureEvent = 49; // U8
            public const byte PwmStart = 66; // U8
            public const byte PwmStop = 67; // U8
            public const byte PwmRiseEvent = 68; // U8
            public const byte MagEncoderMode = 91; // U8
            public const byte Reserved4 = 92; // U8
            public const byte Reserved5 = 93; // U8
            public const byte ServoPeriodUs = 94; // U16
            public const byte Servo0PulseUs = 95; // U16
            public const byte Servo1PulseUs = 96; // U16
            public const byte Servo2PulseUs = 97; // U16
        }
    }
}
