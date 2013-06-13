using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MyExceptions;

namespace ArrayLib
{
    public class MyArray
    {

        public int Size { get; set; }
        private Object[] data;

        //default constructor
        public MyArray(int sizeIn)
        {
            if (sizeIn > 0)
            {
                Size = sizeIn;
            }
            else
            {
                Size = 0;
                throw new ContainerSizeException();
            }
            data = new Object[Size];
        }

        //copy constructor
        public MyArray(MyArray copy)
        {
            this.Size = copy.Size;
            this.data = new Object[copy.Size];
            for (int i = 0; i < this.Size; i++)
            {
                this.data[i] = copy.data[i];
            }
        }


        public void Insert(Object item, int position)
        {
            data[position] = item;
        }

        public Object Retrieve(int position)
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

