//@file prog5.cpp
//@author Ryan Draper(draper)
//@date 10/12/2010

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
void SortColors(int lastBuck, Buckets buckets);

//@prints list of buckets
//@pre lastBuck must be initialized as the place of the last bucket
//@post outputs the color of the pebbles in order of the place pertaining
//@     to that bucket
//@param int lastBuck
//@usage PrintBuckets(lastBuck);
void PrintBuckets(int lastBuck, Buckets buckets);

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@usage PrintNewLines(3);
void PrintNewLines(int num);

//@allows user to enter if they would like to run the program again
//@post returns the char 'y' or 'n' into the variable continueBuckets
//@param continueBuckets;
//@usage GoAgain(contiueBuckets);
bool GoAgain();

//@Allows user to set up n number of buckets
//@pre userChoice must be an int
//@post userchoice must contain the number of buckets the user wishes
//@param userChoice
//@usage AmountBuckets(userChoice);
void AmountBuckets(int& userChoice);

//@prints out the color inside what looks like a bucket
//@pre pebble must contain the color of the pebble in a char
//@post prints out the color of pebbles inside buckets
//@param pebble
//@BucketWithPebble(pebble);
void BucketWithPebble(char pebble, int count, int lastBuck);

int main()
{
   Buckets buckets;
   Pebble peb;
   bool continueBuckets;
   int userChoice;
   
   continueBuckets = true;
   
   while (continueBuckets)
   {
      PrintNewLines(2);
	   AmountBuckets(userChoice);
	   
	   PrintNewLines(2);
      buckets.SetUpBuckets(userChoice);
      
      PrintNewLines(2);
      buckets.FillBuckets();
      
      PrintNewLines(2);
      PrintBuckets(userChoice, buckets);
      
      PrintNewLines(2);
      SortColors(userChoice, buckets);
      
      PrintBuckets(userChoice, buckets);
      
      buckets.TrashBuckets();
      
      PrintNewLines(2);
      continueBuckets = GoAgain();
   }
   
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
void SortColors(int lastBuck, Buckets buckets)
{
   int firstMix;
   int lastWhite;
   int lastRed;
   
   lastRed = -1;
   lastWhite = -1;
   firstMix = 0;
   
   for (int buckNum = 0; buckNum < lastBuck; buckNum++)
   {
      if (buckets.GetColor(buckNum) == RED)
      {
         lastWhite++;
         buckets.Swap(buckNum, lastWhite);
         lastRed++;
         buckets.Swap(lastWhite, lastRed);
      } else if (buckets.GetColor(buckNum) == WHITE) {
         lastWhite++;
         buckets.Swap(buckNum, lastWhite);
      } 
      firstMix++;
   }
}      

//@prints list of buckets
//@pre lastBuck must be initialized as the place of the last bucket
//@post outputs the color of the pebbles in order of the place pertaining
//@     to that bucket
//@param int lastBuck
//@usage buckets.PrintBuckets(lastBuck);
void PrintBuckets(int lastBuck, Buckets buckets)
{
   char color;
   
   for (int buckNum = 0; buckNum < lastBuck; buckNum++)
   {
      if (buckets.GetColor(buckNum) == BLUE)
      {
         color = 'B';
         BucketWithPebble(color, buckNum, lastBuck);
      } else if (buckets.GetColor(buckNum) == WHITE){
         color = 'W';
         BucketWithPebble(color, buckNum, lastBuck);
      } else { 
         color = 'R';
         BucketWithPebble(color, buckNum, lastBuck);
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
//@allows user to enter if they would like to run the program again
//@pre contiueBuckets must contain a character 'y' or 'n' in it
//@post returns the users choice, char 'y' or 'n' into the variable continueBuckets
//@param continueBuckets;
//@usage GoAgain();
bool GoAgain()
{
   char answer;
   
   cout << "Would you like to sort another set of buckets?" << endl;
   cout << "Enter 'y' for yes and 'n' for no---> ";
   cin >> answer;
   
   if (answer == 'y')
   {
      return true;
   } else {
      return false;
   }
}

//@Allows user to set up n number of buckets
//@pre userChoice must be an int
//@post userchoice must contain the number of buckets the user wishes
//@param userChoice
//@usage AmountBuckets(userChoice);
void AmountBuckets(int& userChoice)
{
   cout << "Enter the number of buckets you would like the robot to set up---> ";
   cin >> userChoice;
}

//@prints out the color inside what looks like a bucket
//@pre pebble must contain the color of the pebble in a char
//@post prints out the color of pebbles inside buckets
//@param pebble
//@BucketWithPebble(pebble);
void BucketWithPebble(char pebble, int count, int lastBuck)
{
   cout << " | " << pebble << " | ";
   if ((count + 1) == lastBuck)
   {
      cout << endl;
      for (int i = 1; i <= lastBuck % 4; i++)
      {
         cout << "  ===  ";
      }
   } else if ((count + 1) % 4 == 0) {
      cout << endl;
      cout << "  ===    ===    ===    ===" << endl << endl;
   }     
}
