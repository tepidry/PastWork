//@file clist.cpp
//@ author  Ryan Draper (draper)
//@ date November 14, 2010

//@ Implementation of
//@ Abstract Data Type List
//@    Data Object: unsorted list (items in 1st 2nd 3rd order)
//@    data structures: (A linked list) Private variable NodeType list points to the 
//@                first NodeType containing a integer ItemType and a pointer
//@                that either contains NULL if it is the end of the list or 
//@                points to the next NodeType
//@    operations: constructor, destructor, copy constructor,
//@                DeleteIth, InsertIth
//@                GetLength, IsEmpty,
//@                RetrieveIth, Search,
//@                Print, ReversePrint

#include "clist.h"
#include <new>
#include <iostream>
using namespace std;
typedef int ItemType;


struct NodeType
{
   ItemType info; 
   NodeType* next;
};

//@returns in the paramether item what is in the location of i
//@pre rhs_list points to a list object, i has been assigned, ithItem exists
//@post ithItem gets passed by reference of item located in i
//@param i
//@      rhs_list
//@      ithItem
//@usage RetrieveIthHelper(i, list, ithItem);
void RetrieveIthHelper(int i, NodeType* rhs_list, ItemType& ithItem)
{
   if (i > 0) {
      RetrieveIthHelper(i - 1, rhs_list -> next, ithItem);
   } else {
      ithItem = rhs_list -> info;
   }   
}

//@deletes position i from the list object
//@pre i exists, rhs_list object exists
//@post item in position i in rhs_list has been deleted count has be incremented
//@param i
//@      rhs_list
//@usage DeleteIthHelper(i, list);
void DeleteIthHelper(int i, NodeType*& rhs_list)
{
   NodeType* del_list;
   
   if (i > 0) {
      DeleteIthHelper(i - 1, rhs_list -> next);
   } else {
      del_list = rhs_list;
      rhs_list = rhs_list -> next;
      delete del_list;
      del_list = NULL;
   }
}

//@inserts item into rhs_list in position i
//@pre count exists, i is assigned, rhs_list points to list object, item is assigned, ok is true
//@post rhs_list will hold the item in ith position ok will remaim true if there is memory 
//@     otherwise it will be returned as false
//@param count
//@      i
//@      rhs_list
//@      item
//@      ok
//@usage InsertAtIthHelper(i, list, item, ok);
void InsertAtIthHelper(int i, NodeType*& rhs_list, ItemType item, bool& ok)
{
   NodeType* insert_list;
   
   if (i > 0) {
      InsertAtIthHelper(i - 1, rhs_list -> next, item, ok);
   } else {
      insert_list = new (nothrow) NodeType;
      if (insert_list == NULL) {
         ok = false;
      } else {
         insert_list -> info = item;
         if (rhs_list == NULL) {
            insert_list -> next = NULL;
         } else {
            insert_list -> next = rhs_list;
         }
         rhs_list = insert_list;
         insert_list = NULL;
      }
   }
}

//@this copies the list object into a new list object
//@pre rhs_list exists copy_list points to a created list
//@post copy_list points to an identical list to rhs_list
//@param rhs_list
//@      copy_list
//@usage CopyHelper(rhs_list, copy_list -> next);
void CopyHelper(NodeType* rhs_list, NodeType*& copy_list)
{
   if(rhs_list == NULL) {
      copy_list = NULL;
   } else {
      copy_list = NULL;
      copy_list = new (nothrow) NodeType;
      copy_list -> info = rhs_list -> info;
      CopyHelper(rhs_list -> next, copy_list -> next);
   }
}

//@returns a number equivalent to the length of the linked list 
//@pre count exists, and list object exists
//@post count in incremented to the end of the list and is returned 
//@param count
//@      list
//@return count that is equal to the length of the linked list
//@usage GetLengthHelper(count, list);
int GetLengthHelper(int& count, NodeType* list)
{
   if (list == NULL) {
      return 0;
   } else {
      return 1 + GetLengthHelper(count, list -> next);
   }
}

//@searches through a linked list to for the location of item
//@pre count exists, rhs_list object exists, and item is assigned
//@post count is incremented to the location of item and returned
//@param count
//@      rhs_list
//@      item
//@return integer count as the location of item in linked list
//@usage SearchHelper(count, list, item);
int SearchHelper(NodeType* rhs_list, ItemType item)
{
   if (rhs_list != NULL) {
      if (item == rhs_list -> info) {
         return 0;
      } else {
         return 1 + SearchHelper(rhs_list -> next, item);
      }
   } else {
      return 0;
   }   
}

//@deconstructs the linked list that rhs_list is pointing to 
//@pre rhs_list is pointing to  a list object
//@post rhs_list is NULL
//@param rhs_list
//@returns rhs_list as NULL
//@usage DeconstructorHelper(list);
void DeconstructHelper(NodeType*& rhs_list)
{
   if (rhs_list != NULL) {
      DeconstructHelper(rhs_list -> next);
      delete rhs_list;
      rhs_list = NULL;
   }    
}

//@prints the linked list rhs_list points to backward
//@pre rhs_list points to a linked list
//@post prints the list backward
//@param rhs_list
//@usage ReversePrintHelper(list);
void ReversePrintHelper(NodeType* rhs_list)
{
   if (rhs_list != NULL) {
      ReversePrintHelper(rhs_list -> next);
      cout << rhs_list -> info << " ";
   } 
}

//@prints the linked list rhs_list points to 
//@pre rhs_list points to a linked list
//@post prints the list 
//@param rhs_list
//@usage PrintHelper(list);
void PrintHelper(NodeType* rhs_list) 
{
   if (rhs_list != NULL) {
      cout << rhs_list -> info << " ";
      PrintHelper(rhs_list -> next);
   } 
}

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
   DeconstructHelper(list);
}

//@Copies the list object to the class object
//@pre: list object exists
//@post: the class object has the same contents in same order as rhs_list
//@param rhs_list
//@usage: List alist(newlist);
List::List (const List& rhs_list)
{
   CopyHelper(rhs_list.list, list);
}

//@ deletes the ith item in the list
//@pre list object exists
//@post: if 0 <= i <length of list, ith item is deleted and ok is true
//@      else ok is false
//@param i
//@usage: alist.DeleteIth(2, ok); 
void List::DeleteIth(int i, bool& ok)
{  
   if (0 <= i and i < GetLength()) {
      DeleteIthHelper(i, list);
   } else { 
      ok = false;
   }
}

//@inserts a new item in the ith position
//@pre newitem is assigned, list object exists
//@post if 0<=i<=length of list and there is memory available,
//      newitem is placed at that position
//      and other items are appropriately moved and ok is true
//      else ok is false
//@param i
//@param newitem
//@usage alist.InsertIth(3, newitem, ok);
void List::InsertIth(int i, ItemType newitem, bool& ok)
{  
   if (0 <= i and i <= GetLength()) {
      InsertAtIthHelper(i, list, newitem, ok);
   } else {
      ok = false;
   }
}

//@ determines the number of items in a list
//@pre list object exists
//@ post the length is the number of elements in the list
//@ usage length = list.GetLength();
int List::GetLength() const
{
   int count = 0;
   
   return GetLengthHelper(count, list);
}

//@puts item in position i in the list in parameter item 
//@pre i assigned and item is waiting the item in position i
//@post the parameter item now carries the item that was located in position i in the list and ok is true
//@     if i is outside the list length, then ok returns false
//@return the ItemType gets passed through reference the item in position i
//@usage RetrieveIth (i, item, ok)
void List::RetrieveIth (int i, ItemType& item, bool& ok) const
{
   if (0 <= i and i < GetLength()) {
      RetrieveIthHelper(i, list, item);
   } else {
      ok = false;
   }
}

//@prints the list contained in the list object
//@pre list object exists
//@post prints correct list in correct order
//@return outputs the list in the correct order
//@usage alist.Print();
void List::Print() const
{
   PrintHelper(list);
}

//@Does a search through the object list for the ItemType
//@pre list object exists and user has specified what to search for in item
//@post returns the position of the item in the list
//@return the position of the item in the list unless not there than returns -1
//@usage alist.Search(item);
int List::Search(ItemType item) const
{
   if (SearchHelper(list,item) > GetLength() - 1) {
      return -1;
   } else {
      return 1 + SearchHelper(list, item);
   }
}

//@Prints the list in reverse order then the items are in the list
//@pre list object exists
//@post prints the list in reverse order
//@usage alist.ReversePrint();
void List::ReversePrint() const
{
   if (not IsEmpty()) {
      ReversePrintHelper(list);
   }
}

//@Determines whether or not a list is empty
//@pre: class object exists
//@post: returns true if class empty is empty; else returns false
//@return true or false
//@usage: alist.IsEmpty();
bool List::IsEmpty() const
{
   return (list == NULL);
}

