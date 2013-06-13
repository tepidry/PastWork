using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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
            if (num1 % num2 == 0)
                return num2;
            else
                return FindGCD(num2, (num1 % num2));
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
    }
}
