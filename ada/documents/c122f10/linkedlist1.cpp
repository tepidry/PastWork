//@file linkedlist1.cpp
//@date: Oct 10, 2005    modified: Feb 16, 2010
//@author Dr Y
//@YOU DO

#include <cstdlib>     // for the use of new and delete
#include <iostream>
using namespace std;

typedef int ItemType;
struct NodeType
{
   ItemType info;
   NodeType* next;
};

//@makes an empty list
//@post firstptr represents an empty list
//@param firstptr
//@usage MakeEmpty(firstptr);
void MakeEmpty(NodeType*& firstptr);

//@makes a list of size even numbers starting at 2
//@pre: size is a non-negative value
//@post: firstptr points to a list of size successive even numbers
//@param firstptr
//@param size
//@usage: MakeList (first, 3);
void MakeList (NodeType*& firstptr, int size);

//@prints a list of numbers
//@pre: firstptr points to a possibly empty list
//@post: prints the data in list if nonempty else prints a message
//@param firstptr
//@usage: PrintList(firstptr);
void PrintList (NodeType* firstptr);

//@prints a number of new lines
//@pre: num >= 1
//@post: outputs num newline characters
//@param num
//@usage: PrintNewLines(3);
void PrintNewLines (int num);

//@frees the memory in the heap used by the list
//@pre firstptr points to a list but may be empty
//@post the memory for the nodes is returned to the heap
//@     and firstptr is NULL
//@param firstptr
//@usage  DeleteAll(firstptr);
void DeleteAll(NodeType*& firstptr);

int main()
{
   NodeType* firstptr;
   
   PrintNewLines(3);
   MakeEmpty(firstptr);
   MakeList(firstptr, 3);
   
   PrintList(firstptr);
   
   DeleteAll(firstptr);
   PrintNewLines(3);
   
   return 0;
}
   
//@makes an empty list
//@post firstptr represents an empty list
//@param firstptr
//@usage MakeEmpty(firstptr);
void MakeEmpty(NodeType*& firstptr)
{
   firstptr = NULL;
}

//@makes a list of size even numbers starting at 2
//@pre: size is a non-negative value. firstptr is an empty list.
//@post: firstptr points to a list of size successive even numbers
//@param firstptr
//@param size
//@usage: MakeList (first, 3);
void MakeList (NodeType*& firstptr, int size)
{ 
   if (size > 0)
   { 
      NodeType *curptr;
      int k, myit;
      firstptr = new NodeType;
      curptr = firstptr;
      myit = 2;
      curptr -> info = myit;
      curptr -> next = NULL;
      for (k = 1; k < size; k++)
      {
         curptr -> next = new NodeType;
         curptr = curptr -> next;
         myit = 2 * k + 2;
         curptr -> info = myit;
         curptr -> next = NULL;
      }
   }
}

//@prints a list of numbers
//@pre: firstptr points to a list which may be empty
//@post: prints the data in list if nonempty else prints a message
//@param firstptr
//@usage: PrintList(firstptr);
void PrintList (NodeType* firstptr)
{
   NodeType* curptr = firstptr; 
   if (firstptr == NULL)
   {
      cout << "Empty List";
   }
   while (curptr != NULL)
   {
      cout << curptr -> info << " , ";
      curptr = curptr -> next;
   }
   cout << endl;
}

//@prints a number of new lines
//@pre: num >= 1
//@post: outputs num newline characters
//@param num
//@usage: PrintNewLines(3);
void PrintNewLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

//@frees the memory in the heap used by the list
//@pre firstptr points to a list but may be empty
//@post the memory for the nodes is returned to the heap
//@     and firstptr is NULL
//@param firstptr
//@usage  deleteAll(firstptr);
void DeleteAll(NodeType*& firstptr)
{
   NodeType* delptr;
   
   while (firstptr != NULL)
   {
      delptr = firstptr;
      firstptr = firstptr -> next;
      delptr -> next = NULL;  // a good practice
      delete delptr;
   }
}
