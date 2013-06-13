//@author Ryan Draper(draper)
//@file prog3.cpp
//@date 10/06/2010

//@description:  This program print the a list of buckets with a colored
//@              pebble wither white or blue in it. It will then sort the 
//@              colors in the bucketsand reprint the containing buckets 
//@              and their color.

#include "buckets.h"
#include <iostream>
using namespace std;

//@sorts the pebbles in the buckets puting the blue in the first buckets and white
//@in the last buckets
//@pre lastBuck must contain the number of buckets. last Blue and firstMixt must
//@    be initialized at -1 and 0 perspectively
//@post the buckets will be sorted
//@param lastBuck 
//@      lastBlue
//@      firstMix
//@usage SortColors(lastBuck, -1, 0)
void SortColors(int lastBuck, Pebble peb, Buckets buckets);

//@prints list of buckets
//@pre lastBuck must be initialized as the place of the last bucket
//@post outputs the color of the pebbles in order of the place pertaining
//@     to that bucket
//@param int lastBuck
//@usage PrintBuckets(lastBuck);
void PrintBuckets(int lastBuck, Pebble peb, Buckets buckets);

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num);

int main()
{
   Buckets buckets;
   Pebble peb;
   
   PrintNewLines(2);
   buckets.SetUpBuckets(10);
   buckets.FillBuckets();
   PrintNewLines(2);
   PrintBuckets(10, peb, buckets);
   PrintNewLines(2);
   SortColors(10, peb, buckets);
   PrintBuckets(10, peb, buckets);
   buckets.TrashBuckets();
   PrintNewLines(2);
   
   return 0;
}

//@sorts the pebbles in the buckets puting the blue in the first buckets and white
//@in the last buckets
//@pre lastBuck must contain the number of buckets. last Blue and firstMixt must
//@    be initialized at -1 and 0 perspectively
//@post the buckets will be sorted
//@param lastBuck 
//@      lastBlue
//@      firstMix
//@usage SortColors(lastBuck, peb, buckets)
void SortColors(int lastBuck, Pebble peb, Buckets buckets)
{
   int firstMix;
   int lastBlue;
   int lastRed;
   
   lastBlue = -1;
   lastRed = -1;
   firstMix = 0;
   
   for (int i = 0; i < lastBuck; i++)
   {
      peb = buckets.GetColor(i);
      if (peb == BLUE)
      {
         buckets.Swap(i, lastBlue + 1);
         buckets.Swap(i, lastRed +1);
         lastBlue++;
         lastRed++;
         firstMix++;
      } else if (peb == RED) {
         buckets.Swap(i, lastRed + 1);
         lastRed++;
         firstMix++;
      } else {
         buckets.Swap(i, firstMix);
         firstMix++;
      }
   }
}      

//@prints list of buckets
//@pre lastBuck must be initialized as the place of the last bucket
//@post outputs the color of the pebbles in order of the place pertaining
//@     to that bucket
//@param int lastBuck
//@usage buckets.PrintBuckets(lastBuck);
void PrintBuckets(int lastBuck, Pebble peb, Buckets buckets)
{
   
   for (int j = 0; j < lastBuck; j++)
   {
      peb = buckets.GetColor(j);
      
      if (peb == BLUE)
      {
         cout << "Blue" << endl;
      } else if (peb == WHITE){
         cout << "White" << endl;
      } else { 
         cout << "Red" << endl;
      }
   }
}
//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}
