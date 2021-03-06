﻿using Bonsai.Expressions;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Linq.Expressions;
using System.Reactive.Linq;

namespace Bonsai.Harp.Expander
{
    [WorkflowElementCategory(ElementCategory.Condition)]
    [Description("Returns the sequence of PWM rise events generated by OutputExpander devices.")]
    public class PwmRise : SingleArgumentExpressionBuilder
    {
        [Description("Specifies whether to include the Harp timestamp in the result.")]
        public bool IncludeTimestamp { get; set; }

        public override Expression Build(IEnumerable<Expression> arguments)
        {
            var expression = arguments.First();
            var methodName = IncludeTimestamp ? nameof(GetTimestampedPwmRiseEvent) : nameof(GetPwmRiseEvent);
            return Expression.Call(typeof(PwmRise), methodName, null, expression);
        }

        static IObservable<PwmFlags> GetPwmRiseEvent(IObservable<HarpMessage> source)
        {
            return source.Where(OutputExpander.Registers.PwmRiseEvent, MessageType.Event)
                         .Select(message => (PwmFlags)message.GetPayloadByte());
        }

        static IObservable<Timestamped<PwmFlags>> GetTimestampedPwmRiseEvent(IObservable<HarpMessage> source)
        {
            return source.Where(OutputExpander.Registers.PwmRiseEvent, MessageType.Event).Select(message =>
            {
                var payload = message.GetTimestampedPayloadByte();
                return Timestamped.Create((PwmFlags)payload.Value, payload.Seconds);
            });
        }
    }
}
