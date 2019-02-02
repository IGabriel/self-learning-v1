using System;
using Xunit;
using MyLibrary;

namespace MyLibrary.Test
{
    public class CreatureTest
    {
        [Fact]
        public void ToString_ShouldShowHumanString_WhenIsCreatedByHuman()
        {
            Creature c = new Human("Human");

            string baseToString = string.Format(Creature.ToStringFormat, c.Id, c.Name);
            string expected = string.Format(string.Format(Human.HumanToStringFormat, baseToString));

            Assert.Equal(expected, c.ToString());
        }
    }
}
