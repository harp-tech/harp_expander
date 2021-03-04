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
            public const byte OutputSet = 33; // U16    Set the outputs
            public const byte OutputClear = 34; // U16    Clear the outputs
            public const byte OutputToggle = 35; // U16    Toggle the outputs
            public const byte OutputWrite = 36; // U16    Write to all outputs at once
            public const byte Reserved0 = 37; // U8     
            public const byte Reserved1 = 38; // U8     
            public const byte ExpansionOptions = 39; // U8     Selects the current expansion board available in the EXPANSION port
            public const byte Reserved2 = 40; // U8     
            public const byte Reserved3 = 41; // U8     
            public const byte MagEncoderRead = 42; // U16    
            public const byte MagEncoderMode = 43; // U8     
            public const byte Reserved4 = 44; // U8     
            public const byte Reserved5 = 45; // U8     
            public const byte ServoPeriodUs = 46; // U16    
            public const byte Servo0PulseUs = 47; // U16    
            public const byte Servo1PulseUs = 48; // U16    
            public const byte Servo2PulseUs = 49; // U16    
        }
    }
}
