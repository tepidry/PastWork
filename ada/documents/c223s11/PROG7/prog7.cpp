//@author Ryan Draper(draper)
//@date January 25, 2011
//@file prog2.cpp
//@description: This Program will simulate a metal disc that can be read from or written to
//@         In this simulation we will use the class SSTF(shortest seek time first) which is 
//@         derived from class Que. 

#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "cheap.h"
#include "cmerge.h"

using namespace std;

//@Prints the display for the user to choose from
//@usage Options();
void Options();

//@returns the option from the user
//@post returns the integer choosen by user
//@usage TakeOptioin();
int TakeOption(int& option);

//@accomplishes the appropriate option picked by the user
//@pre option was choosen by the user
//@post the option choosen has be done 
//@param option
//@usage DoOptioin(option);
void DoOption(int option);

//@fills a the arrays with random integers between 0 and 99
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with random Citems
//@param merge
//@param heap
//@usage RandomMaker(merge, heap);
void RandomMaker(Cmerge& merge, Cheap& heap);

//@fills a the arrays with sorted integers 
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with ascending sorted Citems
//@param heap
//@param merge
//@usage SortedMaker(merge, heap);
void SortedMaker(Cmerge& merge, Cheap& heap);

//@fills a the arrays with reverse integers 
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with descending sorted Citems
//@param heap
//@param merge
//@usage ReverseMaker(merge, heap);
void ReverseMaker(Cmerge& merge, Cheap& heap);

//@fills a the arrays with nearly sorted integers 
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with nearly ascending sorted Citems
//@param heap
//@param merge
//@usage NearlySortedMaker(merge, heap);
void NearlySorted(Cmerge& merge, Cheap& heap);

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void PrintLines(int num);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok);

int main()
{ 
   srand(time(0));
   int option = 1;
   
   while (option != 5)
   {
      Options();
      TakeOption(option);
      PrintLines(3);
      DoOption(option);
   }
}

//@Prints the display for the user to choose from
//@usage Options();
void Options()
{
   PrintLines(3);
   cout << right << setw(20) << " " << "This is to contrast and help understand" << endl;
   cout << right << setw(20) << " " << "Merge and Heap Sort. Please Reference :" << endl;
   cout << right << setw(20) << " " << "Data Abstraction & Problem Solving." << endl;
   cout << right << setw(20) << " " << "Merge Sort <bigO of (n * log n)> " << endl;
   cout << right << setw(22) << " " << "Found on Pg. 466 - 472 " << endl;
   cout << right << setw(20) << " " << "Heap Sort <bigO of (n * log n)> " << endl;
   cout << right << setw(22) << " " << "Found on Pg. 466 - 472 " << endl;
   PrintLines(2);
   cout << right << setw(10) << " " << "+++++++++++ Choose which array to watch +++++++++++" << endl << endl;
   cout << right << setw(20) << " " << "1. Sorted Array" << endl;
   cout << right << setw(20) << " " << "2. Nearly Sorted Array" << endl;
   cout << right << setw(20) << " " << "3. Reverse Array" << endl;
   cout << right << setw(20) << " " << "4. Random Array" << endl;
   cout << right << setw(20) << " " << "5. Exit" << endl << endl;
   cout << right << setw(19) << " " << "+++++++++++++++++++++++++++++++" << endl;

   PrintLines(4);
   cout << right << setw(20) << " " << "Your Choice Here ---> " ;
}

//@returns the option from the user
//@post returns the integer choosen by user
//@usage TakeOptioin();
int TakeOption(int& option)
{
   cin >> option;
}

//@accomplishes the appropriate option picked by the user
//@pre option was choosen by the user
//@post the option choosen has be done 
//@param option
//@usage DoOptioin(option);
void DoOption(int option)
{
   Cheap heap;
   Cmerge merge;
   
   switch (option)
   {
      case 1:
         cin.get();
         SortedMaker(merge, heap);
         PrintMessage("A Sorted Array", "Heap");
         ToContinue();
         heap.HeapSortDisplay();
         PrintMessage("A Sorted Array", "Merge");
         ToContinue();
         merge.MergeDisplay();
         break;
      case 2:
         cin.get();
         NearlySorted(merge, heap);
         PrintMessage("A Nearly Sorted Array", "Heap");
         ToContinue();
         heap.HeapSortDisplay();
         PrintMessage("A Nearly Sorted Array", "Merge");
         ToContinue();
         merge.MergeDisplay();
         break;
      case 3:
         cin.get();
         ReverseMaker(merge, heap);
         PrintMessage("A Reverse Array", "Heap");
         ToContinue();
         heap.HeapSortDisplay();
         PrintMessage("A Reverse Array", "Merge");
         ToContinue();
         merge.MergeDisplay();
         break;
      case 4:
         cin.get();
         RandomMaker(merge, heap);
         PrintMessage("A Random Array", "Heap");
         ToContinue();
         heap.HeapSortDisplay();
         PrintMessage("A Random Array", "Merge");
         ToContinue();
         merge.MergeDisplay();
         break;
      case 5:
         cout << "Thank You!!" << endl << endl;
         break;
      default:
         cout << "Please select again:: Incorrect choose again. -> ";
    }
}

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok)
{
   cout << endl << "          Boolean value is ";
   if (ok)
      cout << "true";
   else
      cout << "false";
   cout << endl;
}  

//@fills a the arrays with random integers between 0 and 99
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with random Citems
//@param merge
//@param heap
//@usage RandomMaker(merge, heap);
void RandomMaker(Cmerge& merge, Cheap& heap)
{
   int num, i;
   Citem array[8];
   
   for (i = 0; i < 8; i++)
   {
      num = rand() % 100;
      array[i] = num;
      try
      {
         merge.MergeInsert(num);
      }
      catch (cexception ex)
      {
         cout << ex.what();
      }
   }
   try
   {
      heap.HeapInsert(array, 8);   
   }
   catch (cexception ex)
   {
      cout << ex.what();
   }

   
}
//@fills a the arrays with sorted integers 
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with ascending sorted Citems
//@param heap
//@param merge
//@usage SortedMaker(merge, heap);
void SortedMaker(Cmerge& merge, Cheap& heap)
{
   Citem array[8];
   int i;
   for (i = 0; i < 8; i++)
   {
      try
      {
         merge.MergeInsert(i + 1);
      }
      catch (cexception ex)
      {
         cout << ex.what();
      }
      array[i] = i + 1;
   }
   try
   {
      heap.HeapInsert(array, 8);
   }
   catch (cexception ex)
   {
      cout << ex.what();
   }
}
   
//@fills a the arrays with reverse integers 
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with descending sorted Citems
//@param heap
//@param merge
//@usage ReverseMaker(merge, heap);
void ReverseMaker(Cmerge& merge, Cheap& heap)
{
   Citem array[8];
   int i;
   int index = 25;
   
   for (i = 0; i < 8; i++)
   {
      try
      {
         merge.MergeInsert(index);
      }
      catch (cexception ex)
      {
         cout << ex.what();
      }
      array[i] = index;
      index--;
   }
   try
   {
      heap.HeapInsert(array, 8);
   }
   catch (cexception ex)
   {
      cout << ex.what();
   }

}

//@fills a the arrays with nearly sorted integers 
//@pre merge and heap are Cmerge and Cheap objects
//@post merge and heap are filled with nearly ascending sorted Citems
//@param heap
//@param merge
//@usage NearlySortedMaker(merge, heap);
void NearlySorted(Cmerge& merge, Cheap& heap)
{
   Citem array[8];
   int num;
   int i;
   for (int i = 0; i < 8; i++)
   {
      num = i;
      if (i % 3 == 0 || i % 6 == 0)
         num = rand() % 100;   
      try
      {
         merge.MergeInsert(num);
      }
      catch (cexception ex)
      {
         cout << ex.what();
      }

      array[i] = num;
   }
   try
   {
      heap.HeapInsert(array, 8);
   }
   catch (cexception ex)
   {
      cout << ex.what();
   }
}

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void PrintLines(int num)
{
   for (int k = 0; k < num; k++)
   {
      cout << endl;
   }
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   PrintLines(2);
   cout << "                      This program will scroll automatically!!" << endl;
   cout << "                              Enter To Continue ->" << endl;
   PrintLines(4);
   //cin.get(ch);
}

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase)
{
   PrintLines(7);
   cout << right << setw(25) << "Testing *** " << which << " *** in the " 
        << whatCase << " sort";
   PrintLines(2);
}
