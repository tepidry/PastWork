//Ryan Draper
//cpsc 224
//Prob 18 / MyArray

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ArrayLib
{
    public class MyArray<R>
    {

        public int Size { get; set; }
        private R[] data;

        //default constructor
        public MyArray(int sizeIn)
        {
            Size = sizeIn;
            data = new R[Size];
        }

        //copy constructor
        public MyArray(MyArray<R> copy)
        {
            this.Size = copy.Size;
            this.data = new R[copy.Size];
            for (int i = 0; i < this.Size; i++)
            {
                this.data[i] = copy.data[i];
            }
        }


        public void Insert(R item, int position)
        {
            data[position] = item;
        }

        public R Retrieve(int position)
        {
            return (data[position]);
        }

        public void Display()
        {
            for (int i = 0; i < Size; i++)
                Console.WriteLine(data[i]);
            Console.WriteLine();
        }
    }

}

