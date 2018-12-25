using System;

namespace MyLibrary
{
    public class Human : Creature
    {
        public Human(string name) : base(name) {}

        public void Say(string message)
        {
            Console.WriteLine("Human {0}({1}) is say: {2}", Name, Id, message);
        }
    }
}