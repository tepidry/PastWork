////@author Dr Y
//@date Sept 28, 2010
//@file searching.cpp

//@description This program presents two recursive designs for a function that
//@            searches through a list for a target item. One of these designs
//@            is called "linear search" and the other is called "binary search."
//@            Notice the difference in pre-conditions.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAXSIZE = 20;

//@searches through a list for a target item
//@pre list[0..size - 1] is assigned. target is assigned.
//@post if target is found in list[0..size-1] then
//@        returns the location in the list
//@     otherwise returns -1
//@param list
//@param target
//@param size
//@usage where = DoLinearSearch(list, target, 10);
int DoLinearSearch(int list[], int target, int size);

//@searches through a list for a target item
//@pre list[first..last] is assigned in sorted order. 
//@    target is assigned.
//@post if target is found in list[first..last] then
//@        returns the location in the list
//@     otherwise returns -1
//@param list
//@param target
//@param size
//@usage where = DoBinarySearch(list, target, 10);
int DoBinarySearch(int list[], int target, int first, int last);

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@param num -- the number of desired newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num);

//@prints a range of integers
//@pre first and last are assigned
//@post numbers between first and last inclusive are printed
//@param first
//@param last
//@usage PrintNumbers(3, 7);
void PrintNumbers(int first, int last);

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

//@gets an item from the user
//@post returns the item
//@usage  num = GetItem();
int GetItem();

//@prints the result of a search
//@pre where and list[0..size-1] is assigned
//@post outputs the location and contents from a search
//@param list
//@param where
//@param size
//@usage PrintSearch(list, where, size);
void PrintsSearch(int list[], int where, int size);

//@sorts a list
//@pre list[0..size - 1] is assigned
//@post list[0..size - 1] is sorted into ascending order
//@param list
//@param size
//@usage SortBySelection(list, size);
void SortBySelection(int list[], int size);

//@locates the largest item in a list
//@pre list[0..size - 1] is assigned
//@post returns the largest item in list[0..size-1]
//@param list
//@param size
//@usage location = FindIndexOfLargest(list, size);
int FindIndexOfLargest(const int list[], int size);

//@swaps two items
//@pre item1, item2 are assigned
//@post contents of item1 and item2 are interchanged
//@param item1
//@param item2
//@usage Swap(list[1], list[3]);
void Swap (int& item1, int& item2);

int main()
{
   int list[MAXSIZE];
   int item, where;
   int size = MAXSIZE;
   
   srand(time(0));
   PrintNewLines(3);
   MakeRandomList(list, size);
   PrintNumbers(0, size - 1);
   PrintNewLines(2);
   PrintList(list, 0, size - 1);
   PrintNewLines(2);
   
   item = GetItem();
   PrintNewLines(3);
   where = DoLinearSearch(list, item, size);
   PrintsSearch(list, where, size);   
   
   PrintNewLines(3);
   SortBySelection(list, size);
   PrintNumbers(0, size - 1);
   PrintNewLines(2);
   PrintList(list, 0, size - 1);
   PrintNewLines(3);
   
   where = DoBinarySearch(list, item, 0, size - 1);
   PrintsSearch(list, where, size);
   
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

//@prints a range of integers
//@pre first and last are assigned
//@post numbers between first and last inclusive are printed
//@param first
//@param last
//@usage PrintNumbers(3, 7);
void PrintNumbers(int first, int last)
{
	if (first <= last)
	{
		cout << setw(4) << first;
		PrintNumbers(first + 1, last);
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
      cout << setw(4) << list[first];
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

//@gets an item from the user
//@post returns the item
//@usage  num = GetItem();
int GetItem()
{
	int item;
	cout << "Enter item -> ";
	cin >> item;
	return item;
}

//@searches through a list for a target item
//@pre list[0..size - 1] is assigned. target is assigned.
//@post if target is found in list[0..size-1] then
//@        returns the location in the list
//@     otherwise returns -1
//@param list
//@param target
//@param size
//@usage where = DoLinearSearch(list, target, 10);
int DoLinearSearch(int list[], int target, int size)
{
	if (size >= 1)
	{
		if (target == list[size - 1])
		{
			return size - 1;
		} else {

			return DoLinearSearch(list, target, size - 1);
		}
	} else {
		return -1;
	}
}

//@searches through a list for a target item
//@pre list[first..last] is assigned in sorted order. 
//@    target is assigned.
//@post if target is found in list[first..last] then
//@        returns the location in the list
//@     otherwise returns -1
//@param list
//@param target
//@param size
//@usage where = DoBinarySearch(list, target, 10);
int DoBinarySearch(int list[], int target, int first, int last)
{
	return 0;
}

//@prints the result of a search
//@pre where and list[0..size-1] is assigned
//@post outputs the location and contents from a search
//@param list
//@param where
//@param size
//@usage PrintSearch(list, where, size);
void PrintsSearch(int list[], int where, int size)
{
	if (where >= 0)
	{
		cout << list[where] << " is located at index " << where << endl;
	} else {
		cout << "Your item was not found in the list" << endl;
	}
}

//@sorts a list
//@pre list[0..size - 1] is assigned
//@post list[0..size - 1] is sorted into ascending order
//@param list
//@param size
//@usage SelectionSort(list, size);
void SortBySelection(int list[], int size)
{
	for (int last = size - 1; last >= 1; last--)
	{
		int largest = FindIndexOfLargest(list, last + 1);
		Swap(list[largest], list[last]);
	}
}

//@locates the largest item in a list
//@pre list[0..size - 1] is assigned
//@post returns the largest item in list[0..size-1]
//@param list
//@param size
//@usage location = FindIndexOfLargest(list, size);
int FindIndexOfLargest(const int list[], int size)
{
	int indexSoFar = 0;
	for (int currIndex = 1; currIndex < size; currIndex++)
	{
		if (list[currIndex] > list[indexSoFar])
		{
			indexSoFar = currIndex;
		}
	}
	return indexSoFar;
}

//@swaps two items
//@pre item1, item2 are assigned
//@post contents of item1 and item2 are interchanged
//@param item1
//@param item2
//@usage Swap(list[1], list[3]);
void Swap (int& item1, int& item2)
{
	int temp;
	
	temp = item1;
	item1 = item2;
	item2 = temp;
}




