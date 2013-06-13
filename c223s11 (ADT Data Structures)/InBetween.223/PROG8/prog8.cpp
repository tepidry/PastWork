//@author Ryan Draper(draper)
//@date April 14, 2011
//@file prog8.cpp
//@description: This program will test many cases and subcases that occure with a 2-3-4 tree


#include "c234tree.h"

using namespace std;

int main()
{
	int index;
   C234node node;
   C234tree big;
   
   Citem item, data;
   
   cin >> item;
   big.Insert(item);
   big.DisplayTree();
   
   cin >> item;
   big.Insert(item);
   big.DisplayTree();
   
   cin >> item;
   big.Insert(item);
   big.DisplayTree();
   
   cin >> data;
   big.Insert(data);
   big.DisplayTree();
   
   
   
   /*index = node.Insert(item);
   cout << node << " 0 -> " << index << endl;
   
   
   cin >> item;
   index = node.Insert(item);
   cout << node << index << endl;
   
   
   cin >> item;
   index = node.Insert(item);
   cout << node << index << endl;
   node.RecycleNode();
   cout << node << index << endl;/**/
}
