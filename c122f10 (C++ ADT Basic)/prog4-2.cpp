//@author Ryan Draper(draper)
//@file prog4.cpp
//@date 10/01/10


#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 4;
 
//@fills a list with random integers between 0 and 99
//@pre size is assigned
//@post list[0..size-1] is assigned with random numbers
//@param list
//@param size
//@usage MakeRandomList(list, 10);
void MakeRandomList(int list[], int size);

//@fills a the parameter with random integer between 0 and 999
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomNum(num);
void MakeRandomBigNumber(int& num);

//@fills a the parameter with random integer between 0 and 10
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomNum(num);
void MakeRandomSmallNumber(int& num);

//@computes the sum of numbers in a list
//@pre list[start..end] is assigned
//@post returns the sum of the numbers in list[start..end]
//@param list
//@param start
//@param end
//@usage  sum = GetSum(list, 1, 4); 
int GetSum(int list[], int start, int end);

//@writes the digits of an integer in reverse order
//@pre num > 0 is assigned 
//@usage WriteDigits(num);
//@param num
void WriteDigits(int num);

//@outputs a series of the symbol "*" in a given set of columns
//@pre what must contain a single symbol "*" and numColumns must contain an integer
//@post outputs on screen the symbol the amout of times specified
//@usage WriteLine(what, numColumns);
void WriteLine(char what, int numColumns);

//@outputs in a set parameter for newColums and numRows the character '*'
//@pre what must contain a character and numComumns and numRows must contain an integer
//@post outputs a series of what character in numColumns by numRows
//@usage WriteBlock(what, numColumns, numRows);
void WriteBlock(char what, int numColumns, int numRows);

//@returns the product of a double x when it has been raised to the integer n
//@pre the parameter x is assigned a double and n an integer
//@post returns the x when it has been raised to n
//@param x
//@param n 
//@exponent = power(x, n)
int power(double x, int n); 

int main()
{
   int list[MAXSIZE];
   int sum;
   int smallNum;
   int bigNum;
   char what;
   int numColumns;
   int numRows;
   double x;
   int n;
   int exponent;
   
   x = 4;
   n = 4;
   what = '*';
   numColumns = 5;
   numRows = 7;
   
   srand(time(0));
   MakeRandomList(list, 3);
   MakeRandomBigNumber(bigNum);
   MakeRandomSmallNumber(smallNum);
   WriteLine(what, numColumns);
   cout << endl;
   WriteBlock(what, numColumns, numRows);
   cout << bigNum <<  endl;
   WriteDigits(bigNum);
   cout << endl;
   for (int k = 0; k <= 3; k++)
   {
	   cout << list[k] << " ";
   }
   cout << endl;
   sum = GetSum(list, 1, 4);
   cout << sum << endl;
   exponent = power(x, n);
   cout << exponent;
   
   return 0;
    
}

//@returns the product of a double x when it has been raised to the integer n
//@pre the parameter x is assigned a double and n an integer
//@post returns the x when it has been raised to n
//@param x
//@param n 
//@exponent = power(x, n)
int power(double x, int n)
{ 
   if (n > 0)
   {
      if (n % 2 == 0) 
      {
        return power(x * x, n / 2);
      } else {
         return x * power(x * x, n / 2);
      }
   } else if (n == 0) {
      return 1;
   }
   
}
         

//@computes the sum of numbers in a list
//@pre list[start..end] is assigned
//@post returns the sum of the numbers in list[start..end]
//@param list
//@param start
//@param end
//@usage  sum = GetSum(list, 1, 4); 
int GetSum(int list[], int start, int end)
{
   if (start == end)
   {
      return list[start - 1];
   } else {
      return list[start - 1] + GetSum(list, start + 1, end);
   }
}
   
//@writes the digits of an integer in reverse order
//@pre num > 0 is assigned 
//@usage WriteDigits(num)
//@param num
void WriteDigits(int num)
{
   if (num < 10)
   {
      cout << num;
   } else {
      cout << num % 10;
      WriteDigits(num / 10);
   }
}  

//@outputs a series of the symbol "*" in a given set of columns
//@pre what must contain a single symbol "*" and numColumns must contain a number of columns
//@post outputs on screen the symbol the amout of times specified
//@usage WriteLine(what, numColumns)
void WriteLine(char what, int numColumns)
{
   if (numColumns > 0)
   {
      cout << what << " ";
      WriteLine(what, numColumns - 1);
   } else {
      cout << endl;
   }
}

//@outputs in a set parameter for newColums and numRows the character '*'
//@pre what must contain a character and numComumns and numRows must contain an integer
//@post outputs a series of what character in numColumns by numRows
//@usage WriteBlock(what, numColumns, numRows);
void WriteBlock(char what, int numColumns, int numRows)
{
   if (numRows > 0)
   {
      WriteLine(what, numColumns);
      WriteBlock(what, numColumns, numRows - 1);
   }
}
      
//@fills a list with random integers between 0 and 99
//@pre size is assigned
//@post list[0..size-1] is assigned with random numbers
//@param list
//@param size
//@usage MakeRandomList(list, 10);
void MakeRandomList(int list[], int size)
{
   int number;
   for (int i = 0; i <= size; i++)
   {
      number = rand() % 100;
      list[i] = number;
   }
}

//@fills a the parameter with random integer between 0 and 999
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomNum(num);
void MakeRandomBigNumber(int& num)
{
      num = rand() % 1000;
}

//@fills a the parameter with random integer between 0 and 10
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomNum(num);
void MakeRandomSmallNumber(int& num)
{
   num = rand() % 11;
}

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@param num -- the number of desired newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}
