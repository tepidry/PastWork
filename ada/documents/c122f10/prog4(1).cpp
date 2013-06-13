//@author Ryan Draper(draper)
//@file prog4.cpp
//@date 10/01/10


#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 10;
 
//@fills a list with random integers between 0 and 99
//@pre size is assigned
//@post list[0..size-1] is assigned with random numbers
//@param list
//@param size
//@usage MakeRandomList(list, 10);
void MakeRandomList(int list[], int size);

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
//@usage WriteDigits(num)
void WriteDigits(int num);

//@
void WriteLine(char what, int numColumns);
void WriteBlock(char what, int numColumns, int numRows);
int power(double x, int n); 

int main()
{
 ////////////////////
   int sum;
   
   MakeRandomList(list, 10)
   for(int i = 0; i < 10; i++)
   {
	   cout << list[i];
   }
   ///sum = GetSum(list, 1, 4);
   ///cout << sum;
    
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
   for (int k = 0; k < size; k++)
   {
      number = rand() % 100;
      list[k] = number;
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
