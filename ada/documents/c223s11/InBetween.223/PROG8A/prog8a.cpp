//@author Ryan Draper(draper)
//@date April 18, 2011
//@file prog8.cpp
//@description: This program will test the first 2 cases in a c234tree


#include "c234tree.h"

using namespace std;

int main()
{
	int index;
   C234node node;
   C234tree big;
   
   Citem item, data;
   cin >> index;
   for (int i = 0; i < index; i++)
   {
      cin >> item;
      big.Insert(item);
      big.DisplayTree();
   }
   
}
