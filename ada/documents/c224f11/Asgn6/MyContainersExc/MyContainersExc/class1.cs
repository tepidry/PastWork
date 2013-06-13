///Ryan Draper (draper)
///March 18th 2011
///MyContainersExc.cs (Prob 18)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ListLib;
using ArrayLib;
using MyExceptions;

namespace MyContainersExc
{

    public class MyStack : MyList
    {
        ///<summary>MyStack is a data structure with a LIFO protocol.</summary>
        ///<param>insize is the insize of the stack </param>
        ///<usage>MyStack stk = new MyStack(5)</usage> 
        public MyStack(int insize) : base(insize) { }

        ///<pre>MyStack exists</pre> 
        ///<post>item is on top of the stack </post> 
        ///<usage>stk.Push(item), where stk is an instance of MyStack and item is of type Object void Push(Object item)</usage>   
        ///<exception>StackFullException()</exception>
        public void Push(Object item)
        {
            if (IsFull())
                throw new StackFullException();
            else
                InsertAtFront(item);
        }

        ///<pre>MyStack exists</pre>
        ///<post>top item of the stack is removed and returned</post> 
        ///<usage>Object item = stk.Pop(), where stk is an instance of MyStack Object Pop()</usage>
        ///<exception>StackEmptyException()</exception>
        public Object Pop()
        {
            if (IsEmpty())
                throw new StackEmptyException();
            else
                return RemoveFromFront();
        }

        ///<pre>MyStack exists</pre> 
        ///<post>top item of stack returned, stack is unchanged </post>
        ///<usage> Object item = stk.peek(), where stk is an instance of MyStack</usage>
        ///<exception>StackEmptyException()</exception>"
        public Object Peek()
        {
            if (IsEmpty())
            {
                throw new StackEmptyException();
            }
            else
            {
                Object temp = RemoveFromFront();
                InsertAtFront(temp);
                return temp;
            }
        }
    }

    public class MyQue : MyList
    {
        ///<summary>MyQue is a data structure with a FIFO protocol.</summary>
        ///<param>insize is the insize of the Que </param>
        ///<usage>MyQue que = new MyQue(5)</usage> 
        public MyQue(int insize) : base(insize) { }

        ///<pre>MyQue exists</pre> 
        ///<post>item is in the first open spot of the Que </post> 
        ///<usage>que.Enqueue(item), where que is an instance of MyQue and item is of type Object void Enqueue(Object item)</usage>   
        ///<exception>QueFullException()</exception>
        public void Enqueue(Object item)
        {
            if (IsFull())
                throw new QueFullException();
            else
                InsertAtBack(item);
        }

        ///<pre>MyQue exists</pre>
        ///<post>first item of the que is removed and returned</post> 
        ///<usage>Object item = que.Dequeue(), where que is an instance of MyQue Object Dequeue()</usage>
        ///<exception>QueEmptyException()</exception>
        public Object Dequeue()
        {
            if (IsEmpty())
                throw new QueEmptyException();
            else
                return RemoveFromFront();
        }

        ///<pre>MyQue exists</pre> 
        ///<post>front item of que returned, que is unchanged </post>
        ///<usage> Object item = que.AtFront(), where que is an instance of MyQue</usage>
        ///<exception>QueEmptyException()</exception>"
        public Object AtFront()
        {
            if (IsEmpty())
            {
                throw new QueEmptyException();
            }
            else
            {
                Object temp = RemoveFromFront();
                InsertAtFront(temp);
                return temp;
            }
        }
    }
}
