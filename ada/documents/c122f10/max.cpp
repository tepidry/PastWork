//@author Dr Y
//@date Sept 28, 2010
//@file max.cpp

//@description This program presents two recursive designs for a function that
//@            finds the maximum number in a list. It also demonstrates how
//@            to fill a list randomly.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXSIZE = 20;

//@pre list[0..size - 1] is assigned
//@post returns the largest number in list[0..size - 1]
//@param list
//@param size
//@return the largest number in the list
//@usage maxNum = FindMaxLinear(list, 6);
//@finds the maximum number in a list
int FindMaxLinear(int list[], int size);

//@finds the maximum number in a list
//@pre list[first..last] is assigned
//@post returns the largest number in list[first..last]
//@param list
//@param first
//@param last
//@return the largest number in the list
//@usage maxNum = FindMaxBinary(list, 0, 10);
int FindMaxBinary(int list[], int first, int last);

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@param num -- the number of desired newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num);

//@prints out contents of a list
//@pre list[first..last] is assigned
//@post values in list[first..last] are output 40 to a line
//@param list
//@param first
//@param last
//@usage PrintList(list, 0, 6);
void PrintList(int list[], int first, int last);

//@fills a list with random integers between 0 and 99
//@pre size is assigned
//@post list[0..size-1] is assigned with random numbers
//@param list
//@param size
//@usage MakeRandomList(list, 10);
void MakeRandomList(int list[], int size);

//@prints the maximum value in a list
//@pre maximum is assigned
//@post prints the maximum with a label
//@param maximum
//@usage PrintMax(max)
void PrintMax(int maximum);

int main()
{
   int list[MAXSIZE];
   int maximum;
   
   srand(time(0));
   PrintNewLines(3);
   MakeRandomList(list, MAXSIZE);
   PrintList(list, 0, MAXSIZE - 1);
   
   PrintNewLines(3);
   PrintList(list, 0, 4);
   maximum = FindMaxLinear(list, 5);
   PrintNewLines(2);
   PrintMax(maximum);
   PrintNewLines(3);
   
   maximum = FindMaxBinary(list, 2, 8);
   PrintList(list, 2, 8);
   PrintNewLines(2);
   PrintMax(maximum);
   PrintNewLines(3);

   return 0;
}

//@pre list[0..size - 1] is assigned
//@post returns the largest number in list[0..size - 1]
//@param list
//@param size
//@return the largest number in the list
//@usage maxNum = FindMaxLinear(list, 6);
int FindMaxLinear(int list[], int size)
{
    int lastNum, restMax;
    if (size == 1)
       return list[0];
    else
    {
       lastNum = list[size - 1];
       restMax = FindMaxLinear(list, size - 1);
       if (restMax > lastNum)
          return restMax;
       else
          return lastNum;
    }
}

//@finds the maximum number in a list
//@pre list[first..last] is assigned
//@post returns the largest number in list[first..last]
//@param list
//@param first
//@param last
//@return the largest number in the list
//@usage maxNum = FindMaxBinary(list, 0, 10);
int FindMaxBinary(int list[], int first, int last)
{
   int mid, firstHalfMax, lastHalfMax;
   if (first < last)
   {
      mid = (first + last) / 2;
      firstHalfMax = FindMaxBinary(list, first, mid);
      lastHalfMax = FindMaxBinary(list, mid + 1, last);
      if (firstHalfMax > lastHalfMax)
      {
         return firstHalfMax;
      } else {
         return lastHalfMax;
      }
   } else {
      return list[first];
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

//@prints out contents of a list
//@pre list[first..last] is assigned
//@post values in list[first..last] are output 40 to a line
//@param list
//@param first
//@param last
//@usage PrintList(list, 0, 6);
void PrintList(int list[], int first, int last)
{
   if (first <= last)
   {
      cout << list[first] << "  ";
      PrintList(list, first + 1, last);
   } else {
      cout << "<-- the list" << endl;
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
   for (int k = 0; k < size; k++)
   {
      number = rand() % 100;
      list[k] = number;
   }
}

//@prints the maximum value in a list
//@pre maximum is assigned
//@post prints the maximum with a label
//@param maximum
//@usage PrintMax(max)
void PrintMax(int maximum)
{
   cout << "The maximum value is " << maximum << endl;
}



