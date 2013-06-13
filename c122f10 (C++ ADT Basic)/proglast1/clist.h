//@ Specification of
//@ Abstract Data Type List
//@ADT List
//@    Data Object: unsorted list (items in 1st 2nd 3rd order)
//@    operations: constructor, destructor, copy constructor,
//@                DeleteIth, InsertIth
//@                GetLength, IsEmpty,
//@                RetrieveIth, Search,
//@                Print, ReversePrint
//@file clistkey.h
//@author Dr Y
//@date November 19, 2010

#ifndef CLIST_H
#define CLIST_H

#include <new>
#include <iostream>
using namespace std;

const int MAXSIZE = 20;

struct ItemType
{
   int custNum;
   char eventType;
   int arrivalTime;
   int transactionTime;
};

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

//@copies a list
//@pre rhslist exists
//@post list object is a copy of rhslist
//@usage List copy(other);
List (const List& rhslist);

//@pre for all member functions below: list object exists **********

//@ deletes the ith item in the list
//@pre i is assigned
//@post: if 0 <= i <length of list, ith item is deleted and ok is true
//@      else ok is false
//@param i
//@usage: alist.DeleteIth(2, ok); 
void DeleteIth(int i, bool& ok);

//@inserts a new item in the ith position
//@pre newitem is assigned
//@post if 0<=i<=length of list, newitem is placed at that position
//      and other items are appropriately moved and ok is true
//      else ok is false
//@param i
//@param newitem
//@usage alist.InsertIth(3, newitem, ok);
void InsertIth(int i, const ItemType& newitem, bool& ok);

//@ determines the number of items in a list
//@ post the length is the number of elements in the list
//@ usage length = list.GetLength();
int GetLength() const;

//@retrieves the ith item from a list
//@pre i is assigned
//@post if 0 <= i < length of list, item is the ith item in the list
//@        and ok is true else ok is false
//@param i  the position
//@param item  the sought-for list item
//@param ok  whether or not the retrieve is successful
//@usage list.RetrieveIth(2, item, ok);
void RetrieveIth (int i, ItemType& item, bool& ok) const;

//@prints a list
//@post items of list are printed on one line, if possible, separated by a space
//@usage list.Print();
void Print() const;

//@prints a list in reverse
//@post items of list are printed in reverse order on one line, separated by a space
//@usage list.ReversePrint();
void ReversePrint() const;

//@determines if a list is empty
//@post if list is empty returns true else returns false
//@usage if (list.IsEmpty())
bool IsEmpty() const;

//@searches a list for an item
//@pre target is assigned
//@post if target is in list, returns the position 0, 1, ... else returns -1
//@param target   the desired item in the list
//@usage where = list.Search(target);
int Search(int target) const;

private:
   NodeType* list;
};
#endif
