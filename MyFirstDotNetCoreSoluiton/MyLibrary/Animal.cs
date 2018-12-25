using System;

namespace MyLibrary
{
    public class Animal : Creature
    {
        public Animal(string name) : base(name) {}

        public void Roar()
        {
            Console.WriteLine("Animal {0}({1}) is roaring...", Name, Id);
        }
    }
}