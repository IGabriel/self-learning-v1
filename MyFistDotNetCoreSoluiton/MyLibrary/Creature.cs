using System;
using System.Threading;

namespace MyLibrary
{
    public abstract class Creature
    {
        private static long currentId = 0;

        public long Id { get; }
        public string Name { get; }

        public Creature() => Id = GetNextId();

        public Creature(string name) : this() => Name = name;

        private static long GetNextId() => Interlocked.Increment(ref currentId);
    }
}
