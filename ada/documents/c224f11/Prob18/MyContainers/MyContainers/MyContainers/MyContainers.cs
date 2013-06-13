///Ryan Draper (draper)
///March 18th 2011
///MyContainers.cs (Prob 18)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ListLib;
using ArrayLib;

namespace MyContainers 
{
    
    public class MyStack<R> : MyList<R>
    {
        public MyStack(int insize) : base(insize) {}

        public void Push(R item)
        {
            InsertAtFront(item);
        }

        public R Pop()
        {
            return RemoveFromFront();
        }

        public R Peek()
        {
            R temp = RemoveFromFront();
            InsertAtFront(temp);
            return temp;
        }
    }
    public class MyQue<R> : MyList<R>
    {
        MyQue(int insize) : base(insize) {}

        public void Enqueue(R item)
        {
            InsertAtBack(item);
        }

        public R Dequeue()
        {
            return RemoveFromFront();
        }

        public R AtFront()
        {
            R temp = RemoveFromFront();
            InsertAtFront(temp);
            return temp;
        }
    }
}
