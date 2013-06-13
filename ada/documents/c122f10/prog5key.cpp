//@author: anon and Dr Y
//@date: 10/7/10
//@file: prog5.cpp
//@description: This program uses the Buckets class to set buckets in front of
//@             a robot, put a red, white or blue pebble into each bucket, and
//@             sort the pebbles by color into a red section, white section and
//@             blue section, then print proof and images of the sorted buckets.

#include "buckets.h"
#include <iostream>
#include <iomanip>
using namespace std; 

//@gets the number of buckets from the user
//@post: num is assigned a positive number of buckets by user
//@param: num is the number of buckets
//@usage: GetNumBuckets(num);
void GetNumBuckets(int& num);

//@sorts the pebbles in buckets until they are divided into colors
//@pre buckets have been placed in front of the robot and each
//@     bucket has a colored pebble inside
//@post the pebbles will be divided by color; red, white, blue
//@param num is the number of buckets
//@param buckets are the buckets set up and filled with pebbles
//@usage RobotSort(num, buckets);
void RobotSort(int num, Buckets& buckets);

//@prints a number of new lines
//@pre num >= 0 is assigned
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintNewLines(2);
void PrintNewLines(int num);

//@prints the pebble colors within each bucket
//@pre the buckets are set out and have pebbles within them
//@post outputs the colors of the pebbles
//@param num is the number of buckets
//@param buckets are the buckets set out and filled
//@usage PrintBuckets(num, buckets);
void PrintBuckets(int num, Buckets buckets);

//@prints images of the buckets with colored pebbles inside
//@pre the buckets are set out and filled
//@post outputs images of buckets with colors inside
//@param num is the number of buckets
//@param buckets are the buckets set out and filled
//@usage PrintBucketsImage(num, buckets);
void PrintBucketsImage(int num, Buckets buckets);

//@asks the user if they would like to go again
//@post returns true or false depending on whether the user wants to go again
//@usage: goAgain = AskGoAgain();
bool AskGoAgain();

//@tests if the user is ready to move on in the output from main
//@usage: MoveOn();
void MoveOn();

int main()
{
   Buckets buckets;
   Pebble pebble;
   int num;
   bool goAgain = true;
   
   while(goAgain)
   {
      PrintNewLines(2);
      GetNumBuckets(num);
      
      buckets.SetUpBuckets(num);
      PrintNewLines(2);
      
      buckets.FillBuckets();
      PrintNewLines(2);
      
      PrintBucketsImage(num, buckets);
      PrintNewLines(2);
      RobotSort(num, buckets);
      PrintNewLines(2);
      PrintBucketsImage(num, buckets);
      
      PrintNewLines(2);
      goAgain = AskGoAgain();
   }
}

//@gets the number of buckets from the user
//@post num is assigned a positive number of buckets by user
//@param num is number of buckets
//@usage GetNumBuckets(num);
void GetNumBuckets(int& num)
{
   cout << "How many buckets do you want set in front of the robot? ";
   cin >> num;
   if (num < 1)
   {
      cout << "You need at least one bucket!" << endl;
      GetNumBuckets(num);
   }
}

//@sorts the pebbles in buckets until they are divided into colors
//@pre buckets have been placed in front of the robot and each
//@     bucket has a colored pebble inside
//@post the pebbles will be divided by color; red, white, blue
//@param num is the number of buckets
//@param buckets are the buckets set up and filled with pebbles
//@usage RobotSort(num, buckets);
void RobotSort(int num, Buckets& buckets)
{
    int lastRed, lastWhite, firstMixed;
    Pebble colorPebble;
    lastRed = -1; lastWhite = -1;
    for (firstMixed = 0; firstMixed < num; firstMixed++)
    {
       colorPebble = buckets.GetColor(firstMixed);
       if (colorPebble == WHITE)
       {
          lastWhite++;
          buckets.Swap(lastWhite, firstMixed);
       } else if (colorPebble == RED)
       {
          lastWhite++;
          buckets.Swap(lastWhite, firstMixed);
          lastRed++;
          buckets.Swap(lastWhite, lastRed);
       }
    }
} 

//@prints a number of new lines
//@pre: num is assigned
//@post: outputs num new lines
//@param: num is the number of new lines to output
//@usage: PrintNewLines(2);
void PrintNewLines(int num)
{
   if (num > 0)
   {
      cout << endl;
      PrintNewLines(num - 1);
   }
}
  
//@prints the pebble colors within each bucket
//@pre the buckets are set out and have pebbles within them
//@post outputs the colors of the pebbles
//@param num is the number of buckets
//@param buckets are the buckets set out and filled
//@usage PrintBuckets(num, buckets);
void PrintBuckets(int num, Buckets buckets)
{
   for (int i = 0; i < num; i++)
   {
      if (buckets.GetColor(i) == RED)
         cout << "The pebble in bucket " << i << " is --> Red" << endl;
      else if (buckets.GetColor(i) == WHITE)
         cout << "The pebble in bucket " << i << " is --> White" << endl;
      else
         cout << "The pebble in bucket " << i << " is --> Blue" << endl;
   }
}  

//@prints images of the buckets with colored pebbles inside
//@pre the buckets are set out and filled
//@post outputs images of buckets with colors inside
//@param num is the number of buckets
//@param buckets are the buckets set out and filled
//@usage  PrintBucketsImage(num, buckets);
void PrintBucketsImage(int num, Buckets buckets)
{
   for (int i = 0; i < num; i++)
   {
      cout << "|   | ";
   }
   PrintNewLines(1);
  
   for (int j = 0; j < num; j++)
   {
      if (buckets.GetColor(j) == RED)
         cout << "| R | ";
      else if (buckets.GetColor(j) == WHITE)
         cout << "| W | ";
      else
         cout << "| B | ";
   }
   PrintNewLines(1);
   
   for (int k = 0; k < num; k++)
      cout << "|___| ";
   PrintNewLines(1);
}

//@asks the user if they would like to go again
//@post returns true or false depending on whether the user wants to go again
//@usage: goAgain = AskGoAgain();
bool AskGoAgain()
{
   char yesOrNo;
   
   cout << "Would like to go again? <y or n> -> ";
   cin >> yesOrNo;
   
   if (yesOrNo == 'y')
      return true;
   else
      return false;
}

//@tests if the user is ready to move on in the output from main
//@usage: MoveOn();
void MoveOn()
{
   char moveOn;
   
   PrintNewLines(1);
   cout << "If you are ready to see more, enter 'y' -> " ;
   cin >> moveOn;
   if (moveOn != 'y')
      MoveOn();
}
