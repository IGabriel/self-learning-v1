using System.Threading;

namespace MyLibrary
{
    public abstract class Creature
    {
        public static readonly string ToStringFormat = "Id: {0}, Name: {1},";
        private static int currentId = 0;

        public int Id { get; }
        public string Name { get; }

        public Creature() => Id = GetNextId();

        public Creature(string name) : this() => Name = name;

        protected static int GetNextId() => Interlocked.Increment(ref currentId);

        public override string ToString() => string.Format(ToStringFormat, Id, Name);
    }
}