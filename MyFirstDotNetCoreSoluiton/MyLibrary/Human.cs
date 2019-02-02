using System;

namespace MyLibrary
{
    public class Human : Creature
    {
        public static readonly string HumanToStringFormat = "Human object: {0}.";

        public Human(string name) : base(name) {}

        public void Say(string message)
        {
            Console.WriteLine("Human {0}({1}) is saying: {2}", Name, Id, message);
        }

        public override string ToString()
        {
            return string.Format(HumanToStringFormat, base.ToString());
        }
    }
}