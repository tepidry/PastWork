using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MyExceptions;

namespace Utilities
{
    public class UtilitiesClass
    {
        
        static public bool IsPrime(int num1)
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

        static public int FindGCD(int num1, int num2)
        {
            for (int i = num1; i <= num1; i--)
            {
                if (num2 % i == 0)
                    return i;
            }
            return 1;

        }

        static public int ConvertToDecimal(string current)
        {
            return (Convert.ToInt32(current, 2));
        }

        static public string ConvertToBinary(int baseTen)
        {
			int binarytemp;
			char[] binaryArray;
			string binary = "";

            if (baseTen <= 0)
                return "0";

			while (baseTen > 0)
			{
                binarytemp = baseTen % 2;
                binary += binarytemp;
				baseTen = baseTen / 2;
			}
            

            binaryArray = binary.ToCharArray();
            Array.Reverse(binaryArray);
            binary = new string(binaryArray);
            return binary;
        }

        static public int FindInverse(int mult)
        {
            int[] key = { 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25 };
            int[] inverse = { 1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25 };

            for (int i = 0; i < 12; i++)
            {
                if (key[i] == mult)
                {
                    return inverse[i];
                }
            }
            throw new Exception("No Multiplicative Inverse");
        }
    }
}
