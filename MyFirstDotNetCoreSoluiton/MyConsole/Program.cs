using System;
using MyLibrary;

namespace MyConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            Human h = new Human("James");
            h.Say("something useless!");

            Animal a = new Animal("Bobo");
            a.Roar();
        }
    }
}
