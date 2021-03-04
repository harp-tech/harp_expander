using System;
using System.ComponentModel;

namespace Bonsai.Harp.Expander
{
    [Combinator(MethodName = nameof(Generate))]
    [WorkflowElementCategory(ElementCategory.Source)]
    [Description("Generates events and processes commands for the InputExpander device.")]
    public class InputExpander
    {
        readonly Device board = new Device();

        [Description("The name of the serial port used to communicate with the InputExpander device.")]
        [TypeConverter(typeof(PortNameConverter))]
        public string PortName
        {
            get { return board.PortName; }
            set { board.PortName = value; }
        }

        public IObservable<HarpMessage> Generate()
        {
            return board.Generate();
        }

        public IObservable<HarpMessage> Generate(IObservable<HarpMessage> source)
        {
            return board.Generate(source);
        }

        internal static class Registers
        {
            public const byte AuxInputs = 32; // U8     State of the auxiliary inputs
            public const byte Inputs = 33; // U16    State of the inputs [0] , change masks [1]
            public const byte RisingEdgeEnable = 34; // U16    Enables the rising edge detection of the correspondent input (bitmask)
            public const byte FallingEdgeEnable = 35; // U16    Enables the falling edge detection of the correspondent input (bitmask)
            public const byte InputMode = 36; // U8     Configures the input mode
            public const byte Reserved0 = 37; // U8     
            public const byte Reserved1 = 38; // U8     
            public const byte ExpansionOptions = 39; // U8     Selects the current expansion board available in the EXPANSION port
        }
    }
}
