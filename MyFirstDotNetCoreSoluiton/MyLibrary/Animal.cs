using System;

namespace MyLibrary
{
    public class Animal : Creature
    {
        public static readonly string AnimalToStringFormat = "Animal object: {0}.";
        public Animal(string name) : base(name) {}

        public void Roar()
        {
            Console.WriteLine("Animal {0}({1}) is roaring...", Name, Id);
        }

        public override string ToString()
        {
            return string.Format(AnimalToStringFormat, base.ToString());
        }
    }
}