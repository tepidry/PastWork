
//@This program demonstrates crudely the use of dynamic memory for
//@the construction of a data structure called a linked list.
//@We will find better ways to do this.
//@Output: contents of the list
//@file playnode.cpp
//@date Feb 17, 2010
//@author Dr Y

#include <cstdlib>
#include <iostream>
using namespace std;

typedef int ItemType;

struct NodeType
{
   ItemType info;
   NodeType* next;
};

int main()
{
   ItemType myit;

   myit = 8;
   NodeType* firstptr;
   firstptr = new NodeType;
   firstptr -> info = myit;
   firstptr -> next = NULL;
   cout << "first node's item: " << firstptr -> info << endl;

   myit = 'B';
   firstptr -> next = new NodeType;
   firstptr -> next -> info = myit;
   firstptr -> next -> next = NULL;
   cout << "2nd node's item: " << firstptr -> next -> info << endl;

   myit = '(';
   firstptr -> next -> next = new NodeType;
   firstptr -> next -> next -> info = myit;
   firstptr -> next -> next -> next = NULL;   
   cout << "3rd node's item: " << firstptr -> next -> next -> info << endl;

   return 0;
}
