//@author Ryan Draper (draper)
//@date April 6, 2011
//@file cheap.h

//@Specification for ADT Cheap
//@   data object: a heap which is a complete binary tree that is either in the for empty or
//@                r   Where in r >= to the items in tL and tR and tL and tR are heaps
//@               / \
//@             tL   tR
//@   operations/methods: create, destroy, copy, operator=, insert, delete, isempty
//@            Heap sort, Tree Display, Array Display.

#ifndef CHEAP_H
#define CHEAP_H

#include <iostream>
#include <iomanip>
#include "cexception.h"

using namespace std;

typedef int Citem;
const int MAXHEAP = 20;

class Cheap 
{
   
public:

   //@creates an empty heap of default memory size
   //@post msize is 0 and heap is created;
   //@usage Cheap heap;
   Cheap();
   
   //@copies an existing heap
   //@pre rhsheap exists
   //@post heap object is a copy of rhsheap
   //@usage Cheap heap(anotherheap); or passing a heap object by value
   Cheap(const Cheap& rhsheap);
   
   //@destroys a Cheap
   //@pre heap object exists
   //@post Cheap object does not exist
   ~Cheap();
   
   //@copies the heap
   //@pre rhsheap exists. The heap object exists with same amount of memory
   //@post Heap object is a copy of rhsheap
   //@param rhsheap
   //@usage cpyheap.operator=(rhsheap);
   //@      or        cpyheap = rhsheap;
   Cheap& operator=(const Cheap& rhsheap);
   
   //@copies an array of Citems
   //@pre rhsitems exists. The heap object exists with same amount of memory
   //@post Heap object is a copy of rhsitems
   //@param rhsitems
   //@usage cpyheap.operator=(rhsitems);
   //@      or        cpyheap = rhsitems;
   void HeapInsert(const Citem itemArray[], const int size)
      throw (cexception);
   
   //@checks to see if the heap object is empty
   //@pre heap exists
   //@post if heap is empty returns true else returns false
   //@usage if (heap.IsEmpty())
   bool IsEmpty() const;
	
   //@Inserts a new citem into the Heap
   //@pre a Heap of Citems exists
   //@post a new citem is entered into the heap else an exception 
   //@     is thrown when the heap is full
   //@param newItem
   //@usage heap.Insert(item);
   void HeapInsert(const Citem& newItem)
		throw (cexception);
		
   //@deletes the root or first item in the heap and trickles down to adjust the heap
   //@pre the heap exists and is not empty otherwise throws an exception
   //@post the heap has the root removed and adjusted to be an appropriate ehap
   //@param maxItem
   //@usage heap.Delete(max);
   void HeapDelete(Citem& maxItem)
      throw (cexception);
		
   //@Sorts the array of citems
   //@pre heap object exists
   //@post heap is sorted into ascending
   //@usage heap.HeapSort();
   void HeapSort();
   
   //@outputs the steps to HeapSort
   //@pre Cheap objects exist
   //@post outputs the steps to Heap Sort
   //@usage heap.HeapSortDisplay();
   void HeapSortDisplay();
   
   //@Displays the heap as a tree
   //@pre heap object exists
   //@post heap is output looking like a tree
   //@usage heap.TreeDisplay();
   void TreeDisplay()const;
   
   //@Displays the heap as an array
   //@pre heap object exists
   //@post heap is output looking like a array
   //@usage heap.ArrayDisplay();
   void ArrayDisplay()const;
   
protected: 
   //@rebuilds the heap after the root has been deleted
   //@pre index is the location of the furrent place in the tree as it trickles down
   //@post the root is found and all the items in rT and lT have been adjusted appropriately
   //@param index
   //@usage RebuildHeaep(0);
   void RebuildHeap(int root);
   
   //@Displays an array
   //@pre array object exists
   //@post array is output looking like a array
   //@usage ArrayDisplay(array);
   void arrayDisplay(Citem array[], int last)const;

   //@Displays the placement of mitems
   //@pre first and last is the part of the array to number
   //@post the numbers are put under the location needed
   //@param first
   //@param last
   //@usage placeDisplay(first, last);
   void placeDisplay(int first, int last)const;
	
   //@Prints a heap array on its side with the first position to the far left
   //@pre an int for current level 
   //@post recursively the heap is printed to the screen
   //@param level
   //@param height
   //@param last
   //@usage treeHelper(level);
   void treeHelper(int level, int height, int last)const;

   //@swaps the Citems in these two locations with one another
   //@pre Citem first and second are citems.
   //@post Citem fist contains what Citem second did and second contains what first did;
   //@param first
   //@      second
   //@usage Swap(mitem[root], mitem[rightChild])
   void Swap(Citem& first, Citem& second);
	
   int msize, mlast;
   Citem mitems[MAXHEAP];
   bool msorting;
   bool msorted;
};
#endif
