//Ryan Draper (draper)
//cpsc224
//March 18th 2011
//MyExceptions.cs(Prob18)
using System;


namespace MyExceptions
{
    public class StackFullException: Exception
    {
        public StackFullException()
            : base("Illegal operation Stack Full")
        { }
        public StackFullException(string msg)
            : base(msg)
        { }
    }
    public class StackEmptyException : Exception
    {
        public StackEmptyException()
            : base("Illegal operation Stack Empty")
        { }
        public StackEmptyException(string msg)
            : base(msg)
        { }
    }
    public class QueFullException : Exception
    {
        public QueFullException()
            : base("Illegal operation Que Full")
        { }
        public QueFullException(string msg)
            : base(msg)
        { }
    }
    public class QueEmptyException : Exception
    {
        public QueEmptyException()
            : base("Illegal operation Que Empty")
        { }
        public QueEmptyException(string msg)
            : base(msg)
        { }
    }
    public class ContainerSizeException : Exception
    {
        public ContainerSizeException()
            : base("Illegal operation need non-negative number to create!")
        { }
        public ContainerSizeException(string msg)
            : base(msg)
        { }
    }
}

