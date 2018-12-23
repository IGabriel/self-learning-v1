using System;
using System.Threading;

namespace MyLibrary
{
    public class Human
    {
        public static readonly string ToStringFormat = "Id: {0}, Name: {1}";
        private static int currentId = 0;

        public int Id { get; }
        public string Name { get; }

        public Human() => Id = GetNextId();

        public Human(string name) : this() => this.Name = name;

        private static int GetNextId() => Interlocked.Increment(ref currentId);

        public override string ToString() => string.Format(ToStringFormat, Id, Name);
    }
}
