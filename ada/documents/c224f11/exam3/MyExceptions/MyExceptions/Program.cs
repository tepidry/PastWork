using System;


namespace MyExceptions
{
    public class InvalidShiftAmount: Exception
    {
        public InvalidShiftAmount()
            : base("Illegal operation Invalid Shift Amount")
        { }
        public InvalidShiftAmount(string msg)
            : base(msg)
        { }
    }
    public class InvalidMultiplier : Exception
    {
        public InvalidMultiplier()
            : base("Illegal operation Invalid Multiplier")
        { }
        public InvalidMultiplier(string msg)
            : base(msg)
        { }
    }
    public class InvalidKey : Exception
    {
        public InvalidKey()
            : base("Illegal operation Invalid Key (Must be alphabetic)")
        { }
        public InvalidKey(string msg)
            : base(msg)
        { }
    }
    public class FildNotFound: Exception
    {
        public FildNotFound()
            : base("File Was Not found.")
        { }
        public FildNotFound(string msg)
            : base(msg)
        { }
    }
}
