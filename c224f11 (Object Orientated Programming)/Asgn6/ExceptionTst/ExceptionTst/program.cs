using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ArrayLib;
using ListLib;
using MyContainersExc;
using MyExceptions;


namespace ExceptionTst
{
    class Program
    {
        static void Main(string[] args)
        {
            bool ok = true;
            int index;
            Console.WriteLine("This is the exception in the Array constructor.");
            do
            {
                try
                {
                    Console.WriteLine("Please Enter Size of Stack 0 or less to recieve an exception.");
                    index = Convert.ToInt32(Console.ReadLine());
                    MyStack stk = new MyStack(index);
                    ok = false;
                }
                catch (ContainerSizeException neg)
                {
                    Console.WriteLine(neg.Message);
                }
                
            } while (ok);

            ok = true;
            int push;
            Console.WriteLine("This is the exception in Stack's Push method.");
            do
            {
                try
                {
                    MyStack stk = new MyStack(1);
                    stk.Push(2);
                    Console.WriteLine("Please Enter 1 to push something onto a full stack, otherwise enter 2.");
                    push = Convert.ToInt32(Console.ReadLine());
                    if (push == 1)
                       stk.Push(push);
                    ok = false;
                }
                catch (StackFullException empty)
                {
                    Console.WriteLine(empty.Message);
                }

            } while (ok);

            ok = true;
            int DeQ;
            Console.WriteLine("This is the exception in Que's dequeue.");
            do
            {
                try
                {
                    MyQue que = new MyQue(1);
                    Console.WriteLine("Please Enter 1 to Dequeue from a empty que, otherwise enter 2.");
                    DeQ = Convert.ToInt32(Console.ReadLine());
                    if (DeQ == 1)
                       que.Dequeue();
                    ok = false;
                }
                catch (QueEmptyException empty)
                {
                    Console.WriteLine(empty.Message);
                }
            } while (ok);
            
            

        }
    }
}
