//@author Ryan Draper (draper)
//@file asgn2.cs
//@date Jan 28, 2010

using System;

namespace asgn2
{
    public class asgn2
    {
        static void Main(string[] args)
        {
            int num1, num2;

            Console.WriteLine("Please Enter Beginning Of Range ->");
            num1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Please Enter End Of Range ->");
            num2 = Convert.ToInt32(Console.ReadLine());

            for (int i = num1; i <= num2; i++)
                if (IsPrime(i))
                    Console.WriteLine(i);
        }

        public static bool IsPrime(int num1)
        {
            if (num1 < 3 || (num1 % 2 == 0))
            {
                if (num1 == 2)
                    return true;
                else
                    return false;
            }
   
            else
            {
                for (int i = 2; i < num1; i++)
                {
                    if (num1 % i == 0)
                        return false;                    
                } 
                return true;
            }
        }
    }

}
