//Ryan Draper
//cpsc 224
//Prob 18 / ListLib

using System;
using ArrayLib;

namespace ListLib
{
    public class MyList<R>
    {
        public int HowMany { get; set; }
        protected MyArray<R> holder;
        private int front;
        private int back;
        public MyList(int sizeIn)
        {
            holder = new MyArray<R>(sizeIn);
            back = 0;
            front = 0;
            HowMany = 0;
        }

        public bool IsEmpty()
        {
            if (HowMany == 0)
                return true;
            return false;
        }

        public bool IsFull()
        {
            if (HowMany == holder.Size)
                return true;
            return false;
        }

        public void InsertAtBack(R item)
        {
            holder.Insert(item, back);
            back++;
            HowMany++;
        }

        public void InsertAtFront(R item)
        {
            //The base class increments HowMany only when the cell to be inserted into is empty. 
            //This one is not, so HowMany has to be incremented here.
            MoveBack();
            holder.Insert(item, front);
            back++;
            HowMany++;
        }

        public R RemoveFromBack()
        {
            int lastItem = back - 1;
            R item = holder.Retrieve(lastItem);
            back--;
            HowMany--;
            return item;
        }

        public R RemoveFromFront()
        {
            R item = holder.Retrieve(front);
            MoveForward();
            back--;
            HowMany--;
            return item;
        }

        public R SeeFront()
        {
            return holder.Retrieve(front);
        }

        public void Display()
        {
            for (int i = 0; i < HowMany; i++)
                Console.WriteLine(holder.Retrieve(i));
        }

        private void MoveBack()
        {
            int lastItem = back - 1;
            for (int i = lastItem; i >= 0; i--)
            {
                R item = holder.Retrieve(i);
                holder.Insert(item, i + 1);
            }
        }

        private void MoveForward()
        {
            int firstItem = front + 1;
            for (int i = firstItem; i < HowMany; i++)
            {
                R item = holder.Retrieve(i);
                holder.Insert(item, i - 1);
            }
        }
    }
}

