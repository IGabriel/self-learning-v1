using System;
using MyLibrary;

namespace MyConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            Human h1 = new Human("Abc");
            Human h2 = new Human("bcd");

            Console.WriteLine("H1: {0}; H2： {1}", h1, h2);
        }
    }
}
