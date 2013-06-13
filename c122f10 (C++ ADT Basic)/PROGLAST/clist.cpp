//@ Implementation of
//@ Abstract Data Type List
//@ADT List
//@    data object: unsorted list (items in 1st 2nd 3rd order)
//@                 with each item in the index containing an int for the customer number, 
//@                 a char for the event type an int for the arrival Time, and an int for 
//@                 the transaction time.
//@    data structure: a linked list
//@    operations: constructor, destructor, copy constructor,
//@                DeleteIth, InsertIth
//@                GetLength, IsEmpty,
//@                RetrieveIth, Search,
//@                Print, ReversePrint

//@file clist.cpp
//@ author  Ryan Draper (draper) and Dr Y
//@ date December 8, 2010

#include "clist.h"

struct NodeType
{
   ItemType info;
   NodeType* next;
};

//********************************** Helper functions **************************
//@inserts a new item in the ith position
//@pre newitem, i, are firstptr are assigned
//@post if 0<=i<=length of list pointed to by firstptr, 
//@        newitem is placed at that position
//      and other items are appropriately moved and ok is true
//      else ok is false
//@param i
//@param newitem
//@param firstptr
//@usage InsertIthHelper(list, i, newitem, ok);
void InsertIthHelper(NodeType*& firstptr, int i, ItemType newitem, bool& ok)
{
   if (i < 0 )
   {
      ok = false;
   } else if ((firstptr == NULL) && (i != 0)) {
      ok = false;
   } else {
      if (i == 0)
      {
         NodeType* newptr = new (nothrow) NodeType;
         ok = (newptr != NULL);
         if (ok)
         {
            (newptr -> info).custNum = newitem.custNum;
            (newptr -> info).eventType = newitem.eventType;
            (newptr -> info).arrivalTime = newitem.arrivalTime;
            (newptr -> info).transactionTime = newitem.transactionTime;
            newptr -> next = firstptr;
            firstptr = newptr;
         }
      } else {
         InsertIthHelper(firstptr -> next, i - 1, newitem, ok);
      }
   }
}

//@frees the memory in a list
//@pre firstptr is assigned
//@post all of the nodes in the linked list pointed to by firstptr
//@        are released back to the heap and firstptr is NULL
//@param firstptr
//@usage DestroyHelper(list);
void DestroyHelper(NodeType*& firstptr)
{
   if (firstptr != NULL)
   {
      DestroyHelper(firstptr -> next);
      delete firstptr;
      firstptr = NULL;
   }
}

//@prints the items in a list
//@pre firstptr is assigned
//@post the items in list pointed to by firstptr are output with spaces between
//@param firstptr
//@usage PrintHelper(list);      
void PrintHelper(NodeType* firstptr)
{
   if (firstptr != NULL)
   {
      cout << "|" << (firstptr -> info).custNum << "|:|";
      cout << (firstptr -> info).eventType << "|:|";
      cout << (firstptr -> info).arrivalTime << "|:|";
      cout << (firstptr -> info).transactionTime << "| ";
      PrintHelper(firstptr -> next);
   } 
}

//@copies a linked list
//@pre rhsptr is assigned and points to a linked list
//@post firstptr points to a linked list containing the same data as rhsptr's
//@param firstptr
//@param rhsptr
//@usage CopyHelper(list, rhslist.list);
void CopyHelper(NodeType*& firstptr, NodeType* rhsptr)
{
   if (rhsptr == NULL)
   {
      firstptr = NULL;
   } else {
      firstptr = new (nothrow) NodeType;
      (firstptr -> info).custNum = (rhsptr -> info).custNum;
      (firstptr -> info).eventType = (rhsptr -> info).eventType;
      (firstptr -> info).arrivalTime = (rhsptr -> info).arrivalTime;
      (firstptr -> info).transactionTime = (rhsptr -> info).transactionTime;
      CopyHelper(firstptr -> next, rhsptr -> next);
   }
}
 
//@counts the number of nodes in a linked list
//@pre firstptr points to the linked list
//@post returns the length of the list
//@param firstptr
//@usage return GetLengthHelper(list);    
int GetLengthHelper(NodeType* firstptr)
{
   if (firstptr == NULL)
   {
      return 0;
   } else {
      return 1 + GetLengthHelper(firstptr -> next);
   }
}

//@prints the items in a linked list in reverse order
//@pre firstptr points to the list
//@post items in firstptr are output in reverse order with spaces between
//@param firstptr
//@usage ReversePrintHelper(list);
void ReversePrintHelper(NodeType* firstptr)
{
   if (firstptr != NULL)
   {
      ReversePrintHelper(firstptr -> next);
      cout << (firstptr -> info).custNum << ", ";
      cout << (firstptr -> info).eventType << ", ";
      cout << (firstptr -> info).arrivalTime << ", ";
      cout << (firstptr -> info).transactionTime << ", ";
   }
}

//@retrieves a particular item from a list
//@pre i and firstptr are assigned
//@post if 0 <= i < length of list, item is the ith item in the list
//@        and ok is true else ok is false
//@param i  the position
//@param item
//@param ok
//@param firstptr
//@usage RetrieveIthHelper(list, i, item, ok);
void RetrieveIthHelper (NodeType* firstptr, int i, ItemType& item, bool& ok)
{
   if (i < 0 || firstptr == NULL)
   {
      ok = false;
   } else if (i == 0) {
      item.custNum = (firstptr -> info).custNum;
      item.eventType = (firstptr -> info).eventType;
      item.arrivalTime = (firstptr -> info).arrivalTime;
      item.transactionTime = (firstptr -> info).transactionTime;
      ok = true;
   } else {
      RetrieveIthHelper(firstptr -> next, i - 1, item, ok);
   }
}

//@deletes an item from a list
//@pre firstptr and i are assigned
//@post if 0 <= i < length of list, item is the ith item in the list
//@        and ok is true else ok is false
//@param i  the position
//@param item
//@param ok
//@param firstptr
//@usage DeleteIthHelper(list, i, ok);
void DeleteIthHelper(NodeType*& firstptr, int i, bool& ok)
{
   if (i < 0 || firstptr == NULL)
   {
      ok = false;
   } else if (i == 0) {
      NodeType* delptr = firstptr;
      firstptr = firstptr -> next;
      delptr -> next = NULL;
      delete delptr;
      ok = true;
   } else {
       DeleteIthHelper(firstptr -> next, i - 1, ok);
   }
}
 
//@searches a list for an item
//@pre target and firstptr are assigned
//@post if target is in list, returns the position 0, 1, ... else returns -1
//@param target  the desired item in the list
//@param firstptr
//@usage SearchHelper(list, target);    
int SearchHelper(NodeType* firstptr, int target)
{
   int where;

   if (firstptr == NULL)
   {
      return -1;
   } else if (target == (firstptr -> info).arrivalTime) {
      return 0;
   } else {
      where = SearchHelper(firstptr -> next, target);
      if (where == -1)
      {
         return -1;
      } else {
         return 1 + where;
      }
   }
}

// ***************************** end of helper functions **************************
// ********************************************************************************
// ***************************beginning of member functions ***********************

//@makes an empty list
//@post an empty list object exists
//@usage List mylist;
List::List()
{
   list = NULL;
}

//@destroys a list 
//@pre list object exists
//@post list object no longer exists
List::~List()
{
   DestroyHelper(list);
}

//@copies a list
//@pre rhslist exists
//@post list object is a copy of rhslist
//@usage List copy(other);
List::List (const List& rhslist)
{
   CopyHelper(list, rhslist.list);
}

//@pre for all member functions below: list object exists **********

//@deletes an item from a list
//@pre i is assigned
//@post if 0 <= i < length of list, item is the ith item in the list
//@        and ok is true else ok is false
//@param i  the position
//@param item
//@param ok
//@usage: alist.DeleteIth(2, ok); 
void List::DeleteIth(int i, bool& ok)
{
   DeleteIthHelper(list, i, ok);
}

//@inserts a new item in the ith position
//@pre newitem and i are assigned
//@post if 0<=i<=length of list, newitem is placed at that position
//      and other items are appropriately moved and ok is true
//      else ok is false
//@param i
//@param newitem
//@usage alist.InsertIth(3, newitem, ok);
void List::InsertIth(int i, const ItemType& newitem, bool& ok)
{
   InsertIthHelper(list, i, newitem, ok);
}

//@ determines the number of items in a list
//@ post the length is the number of elements in the list
//@ usage length = list.GetLength();
int List::GetLength() const
{
   return GetLengthHelper(list);
}

//@retrieves the ith item from a list
//@pre i is assigned
//@post if 0 <= i < length of list, item is the ith item in the list
//@        and ok is true else ok is false
//@param i  the position
//@param item
//@param ok
//@usage list.RetrieveIth(2, item, ok);
void List::RetrieveIth (int i, ItemType& item, bool& ok) const
{
   RetrieveIthHelper(list, i, item, ok);
}

//@prints a list
//@post items of list are printed on one line, if possible, separated by a space
//@usage list.Print();
void List::Print() const
{
   cout << "EVENT LIST-> : ";
   if (IsEmpty())
      cout << "Is Empty";
   PrintHelper(list);
}

//@prints a list in reverse
//@post items of list are printed in reverse order on one line, separated by a space
//@usage list.ReversePrint();
void List::ReversePrint() const
{
   ReversePrintHelper(list);
}

//@determines if a list is empty
//@post if list is empty returns true else returns false
//@usage if (list.IsEmpty())
bool List::IsEmpty() const
{
   return (list == NULL);
}

//@searches a list for an item
//@pre target is assigned
//@post if target is in list, returns the position 0, 1, ... else returns -1
//@param target  the desired item in the list
//@usage where = list.Search(target);
int List::Search(int target) const
{
   return SearchHelper(list, target);
}
