//@ Implementation of
//@ Abstract Data Type BucketsNPebbles
//@    data object: buckets filled with colored pebbles
//@    operations: SetUpBuckets, FillBuckets, GetColor, Swap, TrashBuckets
//@    data structures: private variable buckets points to a record 
//@                     containing the number of buckets and a pointer to 
//@                     a dynamic array of size equal to the number of buckets.
//@ file buckets.cpp
//@ author  Ryan Draper (draper)
//@ date October 19, 2010

#include "buckets.h"
#include <iostream>
using namespace std;

struct BuckStuff
{
   int num;
   Pebble* list;
};

   //@gets a number of buckets for the robot
   //@pre number is assigned the desired number of buckets
   //@post number buckets are placed in front of the robot
   //@param number is the number of buckets desired
   //@usage  b.SetUpBuckets(userchoice);
   void Buckets::SetUpBuckets(int number)
   {
      buckets = new BuckStuff;
      buckets -> num = number;
      buckets -> list = new Pebble[number];
   }

   //@fills all of the buckets with pebbles
   //@pre buckets are placed in front of the robot
   //@post one colored pebble is placed in each bucket
   //@     according to the user's input
   //@usage   b.FillBuckets();
   void Buckets::FillBuckets()
   {
      char color;
      
      cout << "Enter R for Red, W for White, B for Blue" << endl;
      for (int count = 0; count < buckets -> num; count++)
      {
         cout << "Enter color for bucket " << count + 1 << " ->";
         cin >> color;
         
         if (color == 'R' || color == 'r')
         {
            buckets -> list[count] = RED;
         } else if (color == 'W' || color == 'w') {
            buckets -> list[count] = WHITE;
         } else {
            buckets -> list[count] = BLUE;
         }
      }
         
      
   }
   
   //@robot uses its eye to view the color of the pebble
   //@pre i is the position of the bucket
   //@    positions of the buckets are labeled 0, 1, 2, ....
   //@post the color of the pebble is returned
   //@param i
   //@return the color of the pebble
   //@usage  pebble = b.GetColor(2);
   Pebble Buckets::GetColor(int i)
   {
      return buckets -> list[i];
   }
   
   //@robot swaps the pebbles in two buckets with its arms
   //@pre  i and j are the positions of the two buckets
   //@     buckets are given positions 0, 1, 2, 3,...
   //@post the pebbles in buckets i and j are swapped
   //@param i
   //@param j
   //@usage    b.Swap(i,j);
   void Buckets::Swap (int i, int j)
   {
      Pebble temp;
      
      temp = buckets -> list[i];
      buckets -> list[i] = buckets -> list[j];
      buckets -> list[j] = temp;
   }
  
   //@all of the buckets are thrown in the trash
   //@pre  there are buckets placed before the robot
   //@post there are no buckets placed before the robot
   //@usage   b.TrashBuckets();
   void Buckets::TrashBuckets()
   {
      delete [] buckets -> list;
      buckets -> list = NULL;
      delete buckets;
      buckets = NULL;
   }
   
   //@counts the number of buckets placed before the robot
   //@pre   there are buckets
   //@post  returns the number of buckets
   //@usage   num = b.GetNum();
   int Buckets::GetNumber()
   {
      int numBuck;
      
      numBuck = buckets -> num;
      
      return numBuck;
   }
