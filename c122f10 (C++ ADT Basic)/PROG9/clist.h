//@file clist.h
//@ author  Ryan Draper (draper)
//@ date Novemver 14, 2010

//@ Specification of
//@ Abstract Data Type List
//@    Data Object: unsorted list (items in 1st 2nd 3rd order)
//@    operations: constructor, destructor, copy constructor,
//@                DeleteIth, InsertIth
//@                GetLength, IsEmpty,
//@                RetrieveIth, Search,
//@                Print, ReversePrint

#ifndef LIST_H
#define LIST_H
#include <new>
#include <iostream>
using namespace std;
typedef int ItemType;


struct NodeType;

class List
{
public:

//@makes an empty list
//@post an empty list object exists
//@usage List mylist;
List();

//@destroys a list 
//@pre list object exists
//@post list object no longer exists
~List();

//@Copies the list object to the class object
//@pre: rhs_list exists
//@post: the class object has the same contents in same order as rhs_list
//@param rhs_list
//@usage: List alist(newlist);
List(const List& rhs_list);

//@ deletes the ith item in the list
//@pre list object exists
//@post: if 0 <= i <length of list, ith item is deleted and ok is true
//@      else ok is false
//@param i
//@usage: alist.DeleteIth(2, ok); 
void DeleteIth(int i, bool& ok);

//@inserts a new item in the ith position
//@pre newitem is assigned, list object exists
//@post if 0<=i<=length of list and there is memory available,
//      newitem is placed at that position
//      and other items are appropriately moved and ok is true
//      else ok is false
//@param i
//@param newitem
//@usage alist.InsertIth(3, newitem, ok);
void InsertIth(int i, ItemType newitem, bool& ok);

//@ determines the number of items in a list
//@pre list object exists
//@ post the length is the number of elements in the list
//@ usage length = list.GetLength();
int GetLength() const;

//@pre retrieves the item located i numbers from the beginning of the linked list
//@post the item now carries the item that was located in int i in the list
//@return the ItemType gets passed through reference the item in position i
//@usage alist.RetrieveIth(3, 99, ok);
void RetrieveIth (int i, ItemType& item, bool& ok) const;

//@prints the list contained in the list object
//@pre list object exists
//@post prints correct list in correct order
//@return outputs the list in the correct order
//@usage alist.Print();
void Print() const;

//@Does a search through the object list for the ItemType
//@pre list object exists and user has specified what to search for in it
//@post returns the position of the item in the list
//@return the position of the item in the list
//@usage =================================================
int Search(ItemType item) const;

//@Prints the list in reverse order then the items are in the list
//@pre list object exists
//@post prints the list in reverse order
//@usage alist.ReversePrint();
void ReversePrint() const;

//@Determines whether or not a list is empty
//@pre: class object exists
//@post: returns true if class empty is empty; else returns false
//@return true or false
//@usage: alist.IsEmpty();
bool IsEmpty() const;

private:
   NodeType* list;
};

#endif
