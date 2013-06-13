// Keys to the function code from prog4

//@computes the sum of numbers in a list
//@pre list[start..end] is assigned
//@post returns the sum of the numbers in list[start..end]
//@param list
//@param atart
//@param end
//@usage  sum = GetSum(list, 1, 4); 
int GetSum(int list[], int start, int end)
{
   if (start <= end)
   {
      return list[start] + GetSum(list, start + 1, end);
   } else {
   	return 0;
	}
}

//@writes the digits of an integer in reverse order
//@pre num > 0 is assigned 
//@post writes the digits of num in reverse order
//@param num
//@usage WriteDigits(1234);
void WriteDigits(int num)
{
   if (num != 0)
   {
      int digit = num % 10;
      cout << digit;
      WriteDigits(num / 10);
   }
}

//@writes a line of characters on the screen
//@pre what and numColumns are assigned
//@post the character in what is printed numColumns times on one line
//@     curson is left at the beginning of the next line
//@param what -- the desired character to be printed
//@param numColumns -- the number of times (columns) to print what
//@usage WriteLine('*', 10);
void WriteLine(char what, int numColumns)
{
   if (numColumns > 0)
   {
      cout << what;
      WriteLine(what, numColumns - 1);
   } else {
      cout << endl;
   }
}

//@writes a two-dimenisonal block of characters on the screen
//@pre what, numColumns, numRows are assigned with numColumns, numRows nonnegative
//@post numRows lines of numColumns of what are output
//@param what
//@param numColumns
//@param numRows
//@usage WriteBlock ('*', 5, 10);
void WriteBlock(char what, int numColumns, int numRows)
{
   if (numRows > 0)
   {
      WriteLine(what, numColumns);
      WriteBlock(what, numColumns, numRows - 1);
   }
}

//@finds the power of a number
//@pre x and n are assigned with n >= 0
//@post returns x raised to the nth power
//@param x -- the base
//@param n -- the exponent
//@usage  value = power(2.3, 10);
double power(double x, int n)
{
   double result;
   if (n == 0)
   {
      return 1;
   } else if (n % 2 == 0) {
      result = power(x, n / 2);
      return result * result;
   } else {
      result = power(x, n / 2);
      return x * result * result;
   }
}