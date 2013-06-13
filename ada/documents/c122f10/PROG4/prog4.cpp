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
//@usage MakeRandomBigNum(num);
void MakeRandomBigNumber(int& num);

//@fills a the parameter with random integer between 0 and 10
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomSmallNum(num);
void MakeRandomSmallNumber(int& num);

//@fills a the parameter with random double between 0 and 10
//@pre num is assigned
//@post num is assigned with a random double
//@param num
//@usage MakeRandomSmallNum(x);
void MakeRandomDouble(double& num);

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

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@param num -- the number of desired newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num);

//@returns the product of a double x when it has been raised to the random 
//@        integer n        
//@pre the parameter x is assigned a double and n an integer
//@post returns the x when it has been raised to n
//@param x
//@param n 
//@exponent = power(x, n)
int power(double x, int n); 

//@pre numColumns and numRows must have a random integers already assigned
//@post out put telling of the number pertaining to the column and row
//@param numColumns
//@param numRows
//@usage ShowNumLines(numColumns);
void ShowNumLines(int numColumns, int numRows);

//@pre bigNum must be assigned a int betwee 0 and 999
//@post displays bigNum
//@usage ShowBigNum(bigNum);
void ShowBigNum(int bigNum);

//@pre list must be filled with random integers
//@post displays prompt list
//@param list[]
//@usage ShowList(list);
void ShowList(int list[], int sum);

//@pre x and n must be assined integers
//@post output the product of the power function
//@param x
//@param n
//@usage ShowPower(x, n) 
void ShowPower(double x, int n, int product);

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
   int product;
   
   what = '*';
   
   MakeRandomDouble(x);
   srand(time(0));
   MakeRandomList(list, 3);
   MakeRandomBigNumber(bigNum);
   MakeRandomSmallNumber(n);
   MakeRandomSmallNumber(numColumns);
   MakeRandomSmallNumber(numRows);
   
   PrintNewLines(2);
   ShowNumLines(numColumns, 1);
   WriteLine(what, numColumns);
   PrintNewLines(1);
   ShowNumLines(numColumns, numRows);
   WriteBlock(what, numColumns, numRows);
   PrintNewLines(2);
   ShowBigNum(bigNum);
   WriteDigits(bigNum);
   PrintNewLines(3);
   sum = GetSum(list, 1, 4);
   ShowList(list, sum);
   PrintNewLines(3);
   product = power(x, n);
   ShowPower(x, n, product);
   PrintNewLines(3);
   
   return 0;
    
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
//@usage MakeRandomBigNum(num);
void MakeRandomBigNumber(int& num)
{
   num = rand() % 1000;
}

//@fills a the parameter with random integer between 0 and 10
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomSmallNum(num);
void MakeRandomSmallNumber(int& num)
{
   num = rand() % 11;
   if (num == 0)
   {
      MakeRandomSmallNumber(num);
   }
}

//@fills a the parameter with random double between 0 and 10
//@pre num is assigned
//@post num is assigned with a random double
//@param num
//@usage MakeRandomSmallNum(x);
void MakeRandomDouble(double& num)
{
   num = rand() % 11;
   if (num == 0)
   {
      MakeRandomDouble(num);
   }
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

//@returns the product of a double x when it has been raised to the integer n
//@pre the parameter x is assigned a double and n an integer
//@post returns the x when it has been raised to n
//@param x
//@param n 
//@exponent = power(x, n)
int power(double x, int n)
{ 
   int ans;
   if (n > 0)
   {
      if (n % 2 == 0) 
      {
         ans = n / 2;
         return x * power(x * 1.0, ans);
      } else {
         ans = (n -1) / 2;
         return (x * x) * power(x, ans);
      }
   } else if (n == 0) {
      return 1;
   }
   
}

//@pre numColumns and numRows must have a random integers already assigned
//@post out put telling of the number pertaining to the column and row
//@param numColumns
//@param numRows
//@usage ShowNumLines(numColumns);
void ShowNumLines(int numColumns, int numRows)
{
   cout << "This is a brick of " << numColumns << " columns ";
   cout << "by " << numRows;
   PrintNewLines(2);
   cout << "1 2 3 4 5 6 7 8 9 10" << endl;
}

//@pre bigNum must be assigned a int betwee 0 and 999
//@post displays bigNum
//@usage ShowBigNum(bigNum);
void ShowBigNum(int bigNum)
{
   cout << "This is an integer forward ----> " << bigNum << endl << endl;
   cout << "This is the same one backward -> ";
}

//@pre list must be filled with random integers between [0...99]
//@post displays prompt list
//@param list[]
//@usage ShowList(list);
void ShowList(int list[], int sum)
{
   cout << "-Here is a list of four integers-" << endl << endl;
   for (int i = 0; i < 4; i++)
   {
      cout << fixed << right;
      cout << setw(15) << list[i] << endl;
     
   }
   PrintNewLines(1);
   cout << "-------Here is there sum--------";
   PrintNewLines(2);
   cout << setw(15) << sum;
   
}
    
//@pre x and n must be assined integers
//@post output the product of the power function
//@param x
//@param n
//@usage ShowPower(x, n) 
void ShowPower(double x, int n, int product)
{
   cout << setprecision(0);
   cout << "This is the product of " << x;
   cout << " to the power of " << n << "--> ";
   cout << product;
}

