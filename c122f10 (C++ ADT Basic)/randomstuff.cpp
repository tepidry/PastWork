//@author Dr Y
//@file randomstuff.cpp
//@date Sept 29, 2010
//@description This program fills a list with random numbers between 0 and 99 inclusive and
//             prints the list.


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 20;

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

int main()
{
   int list[MAXSIZE];
   int maximum;
   
   srand(time(0));
   PrintNewLines(3);
   MakeRandomList(list, MAXSIZE);
   PrintList(list, 0, MAXSIZE - 1);
   PrintNewLines(3);

   return 0;
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



