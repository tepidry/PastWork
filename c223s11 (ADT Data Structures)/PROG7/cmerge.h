//@author Ryan Draper(draper)
//@date April 9, 2011
//@file cmerge.h

//@Specification for ADT Cmerge
//@   data object: a max merge
//@   operations/methods: create, copy, destroy, IsMerged, MergeInserts, MergeDelete,
//@                  operator=, MergeSort, MergeDisplay, ArrayDisplay
 

#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <iomanip>
#include "cexception.h"

using namespace std;

typedef int Citem;
const int MAXMERGE = 25;

class Cmerge
{
public:

   //@creates an empty Cmerge of default memory size
   //@post an empty Cmerge object
   //@usage Cmerge merge;
   Cmerge();
   
   //@copies an existing merge object
   //@pre rhsmerge exists
   //@post merge object is a copy of rhsmerge
   //@param rhsmerge
   //@usage Cmerge merge(anothermerge); or passing a Cmerge object by value
   Cmerge(const Cmerge& rhsmerge);
   
   //@destroys a merge
   //@pre merge object exists
   //@post merge object does not exist
   ~Cmerge();
   
   //@checks to see if a merge object is empty
   //@pre merge object exists
   //@post if merge is empty returns true else returns false
   //@usage if (m.IsEmpty())
   bool IsEmpty() const;
   
   //@tells whether the array has had merged sort ran on it or not
   //@pre merge object exists
   //@post returns true if merged is true else false
   //@usage if(IsMerged())s
   bool IsMerged() const;
   
   //@inserts a new item at the rear of the merge
   //@pre newItem has an assigned value; merge exists
   //@post if merge object is not full, newItem is added to the end of the array
   //@param newItem
   //@usage m.MergeInsert(newguy);
   void MergeInsert(const Citem& newItem)
      throw (cexception);
   
   //@inserts a new array into the merge
   //@pre newArray has an assigned value; merge exists size indexes the newArray
   //@post if merge object exists and size is not larger than MAXMERGE, newArray is added
   //@param newItem
   //@usage m.MergeInsert(newguy);
   void MergeInsert(const Citem newArray[], int size)
      throw (cexception);
      
   //@deletes a item from the merge after copying it to item
   //@pre merge exists and item is Citem
   //@post if mergev is nonempty, front of merge has been removed
   //@         and ok is true else ok is false
   //@param frontItem
   //@param item
   //@usage q.Dequeue(iceCream);
   void MergeDelete(Citem& item)
      throw (cexception);
   
   //@copies the queue
   //@pre rhsq exists. queue object exists with same amount of memory
   //@post queue object is a copy of rhsq
   //@param rhsq
   //@usage cpyq.operator=(rhsq);
   //@      or        cpyq = rhsq;
   Cmerge& operator=(const Cmerge& rhsmerge);
   
   //@sorts an array into ascending order
   //@pre an Citem array
   //@post a sorted array
   //@usage merge.MergeSort();
   void MergeSort();
   
   //@displays all that merge sort does
   //@pre object exists and is output
   //@post object is diplayed as it works
   //@usage merge.MergeDisplay();
   void MergeDisplay();

   //@Displays the merge as an array
   //@pre merge object exists
   //@post merge is output looking like a array
   //@usage merge.ArrayDisplay();
   void ArrayDisplay()const;
   
protected: 

   //@displays the call tree for the user to see  
   //@pre merge object exists 
   //@post MS and Merge calls are displayed
   //@usage mergeTree();
   void mergeTree()const;
   
   //@displays the calls for merge sort
   //@pre first mid and last all index parts of the array Cmerge exists
   //@post the call for merge sort is displayed as MS(first, last)
   //@usage mergeSortDisplay(first,mid,last);
   void mergeSortDisplay(int first, int mid, int last);
   
   //@displays calls to merge
   //@pre first, mid and last all index parts of the array and cmerge exists
   //@post output the call for merge displayed as Merge(first, mid, last)
   //@usage mergeDisplay(first,mid,last);
   void mergeDisplay(int first, int mid, int last);
   
   //@Displays the merge as an array from first to last
   //@pre merge object exists int first is the beginning of the array and last is the end
   //@post merge is output looking like a array
   //@usage merge.ArrayDisplay();
   void arrayDisplay(Citem array[], int first, int mid, int last)const;
   
   //@Displays an array
   //@pre array object exists
   //@post array is output looking like a array
   //@usage ArrayDisplay(array);
   void arrayDisplay(Citem array[])const;
   
   //@Displays the placement of mitems
   //@pre first and last is the part of the array to number
   //@post the numbers are put under the location needed
   //@param first
   //@param last
   //@usage placeDisplay(first, last);
   void placeDisplay(int first, int last)const;

   //@Merges two sorted array sefments into one sorted array.
   //@pre first <= mid <= last. The subarrays [first...mid] and [mid + 1...last]
   //@post there is one assorted array
   //@param first
   //@param mid
   //@param last
   //@usage Merge(0, mid, msize);
   void merge(int first, int mid, int last);
   
   //@Helps sort an array into ascending order
   //@pre a Citem array
   //@post a sorted array
   //@param first
   //@param last
   //@usage merge.MergeSort();
   void mergeSortHelper(int first, int last);
   
   int mlast;
   Citem mitems[MAXMERGE];
   bool mmerged;
   bool mmerging;
};
#endif
