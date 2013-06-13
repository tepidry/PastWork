//@Implementation for ADT Cheap
//@   data object: a max heap array
//@   data object: a heap which is a complete binary tree that is either in the for empty or
//@                r   Where in r >= to the items in tL and tR and tL and tR are heaps
//@               / \
//@             tL   tR
//@   operations/methods: create, destroy, copy, operator=, insert, delete, isempty
//@            Heap sort, Tree Display, Array Display.

//@author Ryan Draper (draper)
//@date April 6, 2010
//@file cheap.cpp

#include "cheap.h"


//@creates an empty heap of default memory size
//@post msize is 0 and heap is created;
//@usage Cheap heap;
Cheap::Cheap()
{
   msize = 0;
   mlast = 0;
   msorting = false;
   msorted = false;
}
   
//@copies an existing heap
//@pre rhsheap exists
//@post heap object is a copy of rhsheap
//@usage Cheap heap(anotherheap); or passing a heap object by value
Cheap::Cheap(const Cheap& rhsheap)\
{
   msize = 0;
   mlast = 0;
   msorting = false;
   msorted = false;
   operator=(rhsheap);	
}
   
//@destroys a Cheap
//@pre heap object exists
//@post Cheap object does not exist
Cheap::~Cheap()
{
   msize = 0;
   mlast = 0;
   msorting = false;
   msorted = false;
}
   
//@copies the heap
//@pre rhsheap exists. The heap object exists with same amount of memory
//@post Heap object is a copy of rhsheap
//@param rhsheap
//@usage cpyheap.operator=(rhsheap);
//@      or        cpyheap = rhsheap;
Cheap& Cheap::operator=(const Cheap& rhsheap)
{
   if (this != &rhsheap)
   {
      msize = rhsheap.msize; 
      mlast = rhsheap.mlast;
      msorting = rhsheap.msorting;
      msorted = rhsheap.msorted;
      for (int i = 0; i < msize; i++)
      {
         mitems[i] = rhsheap.mitems[i];
      }

   }
   return *this;
}

//@copies an array of Citems into the heap
//@pre itemArray exists. The heap object exists with same amount of memory
//@post Heap object is a copy of rhsitems
//@param rhsitems
//@usage cpyheap.operator=(rhsitems);
//@      or        cpyheap = rhsitems;
 void Cheap::HeapInsert(const Citem itemArray[], const int size)
    throw (cexception)
{
   if (size > MAXHEAP) {
      throw cexception("Cheap::ArrayInsert, Sorry there is not enough memory for your Array to become a Heap.");
   } else {
      for (int i = 0; i < size; i++)
      {
         mitems[i] = itemArray[i];
      }
      msize = size;
      mlast = size;
   }
}
	
//@checks to see if the heap object is empty
//@pre heap exists
//@post if heap is empty returns true else returns false
//@usage if (heap.IsEmpty())
bool Cheap::IsEmpty() const
{
   return (msize == 0);
}
	
//@Inserts a new citem into the Heap
//@pre a Heap of Citems exists
//@post a new citem is entered into the heap else an exception 
//@     is thrown when the heap is full
//@param newItem
//@usage heap.Insert(item);
void Cheap::HeapInsert(const Citem& newItem)
	throw (cexception)
{
   if (msize == MAXHEAP) {
      throw cexception("Cheap::Insert, Sorry there is not enough memory for your item.");
   } else {
      mitems[msize] = newItem;
	   int place = msize;
      int parent = (place - 1) / 2;
      while((parent >= 0) && (mitems[parent] < mitems[place]))
      {
         Swap(mitems[parent], mitems[place]);
         place = parent;
         parent = (place - 1) / 2;
      }
      msize++;
      mlast++;
   }
}
		
//@deletes the root or first item in the heap and trickles down to adjust the heap
//@pre the heap exists and is not empty otherwise throws an exception
//@post the heap has the root removed and adjusted to be an appropriate ehap
//@param maxItem
//@usage heap.Delete(max);
void Cheap::HeapDelete(Citem& maxItem)
   throw (cexception)
{
   if(IsEmpty()) {
      throw cexception("Heap::Delete, The heap is empty nothing to be deleted.");
   } else {
      maxItem = mitems[0];
      mitems[0] = mitems[msize - 1];
      RebuildHeap(0);
      msize--;
   }
}

//@outputs the steps to HeapSort
//@pre Cheap objects exist
//@post outputs the steps to Heap Sort
//@usage heap.HeapSortDisplay();
void Cheap::HeapSortDisplay()
{
   msorting = true;
   ArrayDisplay();
   cin.get();
   HeapSort();
   ArrayDisplay();
   msorting = false;
}

//@Displays the heap as a tree
//@pre heap object exists
//@post heap is output looking like a tree
//@usage heap.TreeDisplay();
void Cheap::TreeDisplay()const
{ 
   cout << endl << endl;
   if (msize != 0) {
      treeHelper(0, 1, msize);
   } else {
      cout << "root -> Empty!" << endl;
   }
   cout << endl << endl;
}

//@Displays the heap as an array
//@pre heap object exists
//@post heap is output looking like a array
//@usage heap.ArrayDisplay();
void Cheap::ArrayDisplay()const
{
   cout << endl << endl;
   if (not msorted)
      cout << "An Array to be Sorted by the Heap!" << endl;
   else 
      cout << "A Heap Sorted Array!" << endl;
   if (msize != 0) {
      for (int i = 0; i < msize; i++)
      {
         cout << "|" << right << setw(2) << mitems[i] << "| ";
      }
      cout << endl;
      placeDisplay(0, msize - 1);
   } else {
      cout << "Empty!" << endl;
   }
   cout << endl << endl;
}

//@rebuilds the heap after the root has been deleted
//@pre index is the location of the furrent place in the tree as it trickles down
//@post the root is found and all the items in rT and lT have been adjusted appropriately
//@param index
//@usage RebuildHeaep(0);
void Cheap::RebuildHeap(int root)
{
   int rightChild, maxChild;
   int leftChild = 2 * root + 1;
	
   
   if(leftChild < msize)
   {
      maxChild = leftChild;
      rightChild = leftChild + 1;
      if (rightChild < msize)
		{
		   if (mitems[leftChild] < mitems[rightChild]) {
		      maxChild = rightChild;
         }
	   }
	   if (mitems[root] < mitems[maxChild])
	   {
	      Swap(mitems[root], mitems[maxChild]);
	      RebuildHeap(maxChild);
         
      }
   }
}
	
//@Sorts the array of citems
//@pre heap object exists
//@post heap is sorted into ascending
//@usage heap.HeapSort();
void Cheap::HeapSort()
{
   bool temp = msorting;
   int mlast = msize;
   
   msorting = false;
   for (int j = msize - 1; j >= 0; j--)
   {
      RebuildHeap(j);
   }
   
   msorting = temp;
   for (int i = 0; i < mlast; i++)
   {
      if (msorting) {/*
         cout << endl << endl;
         cout << "Here we will swap " << mitems[0] << " in position " << 0;
         cout << " with " << mitems[msize - 1] << " in position " << msize - 1 << endl;
         cout << endl;/**/
         msorted = true;
         
      }
      Swap(mitems[0], mitems[msize - 1]);
      msize--;
      if (msorting) {
         cout << "Position " << msize << " item " << mitems[msize] << " gets re-moved from the heap and is sorted." << endl;
      }
      
      RebuildHeap(0);
       
      if (msorting) {
         cout << "_______________________________________________________________________________" << endl << endl; 
         treeHelper(0, 1, msize);
         cout << endl;
         cout << "Heap unsorted from " << 0 << " to " << (mlast - (mlast - msize)) - 1 << "." << endl << endl;
         if ((mlast - (mlast - msize)) - 1 == 0) {
            cout << "All of the Heap is Sorted!" << endl;
            msorting = false;
         }
         sleep(6);
         cout << "Complete Array sorted from " << (mlast - (mlast - msize)) << " to " << mlast - 1 << "." << endl ;
         cout << "_______________________________________________________________________________" << endl << endl; 
         treeHelper(0, 1, mlast); 
         cout << endl;
         sleep(6);
      }
   } 
   msize = mlast;
   msorted = true;
}

//@Displays an array
//@pre array object exists
//@post array is output looking like a array
//@usage ArrayDisplay(array);
void Cheap::arrayDisplay(Citem array[], int last)const
{
   for (int i = 0; i < last; i++)
   {
      cout << "|" << right << setw(2) << array[i] << "| ";
   }
   cout << endl;
   for (int i = 0; i < last; i++)
   {
      cout << right << setw(3) << i << "  ";
   }
   cout << endl ;
}
   
//@Displays the placement of mitems
//@pre first and last is the part of the array to number
//@post the numbers are put under the location needed
//@param first
//@param last
//@usage placeDisplay(first, last);
void Cheap::placeDisplay(int first, int last)const
{
   
   for (int i = first; i <= last; i++)
   {
      cout << left << setw(5) << i ;
   }
   cout << endl << endl;
}

//@Prints a heap array on its side with the first position to the far left
//@pre a int for the size and an int for current level 
//@post recursively the heap is printed to the screen
//@param last
//@param level
//@param height
//@usage treeHelper(0,1,mlast);
void Cheap::treeHelper(int level, int height, int last)const
{
   if (level < last)
   {
      treeHelper(level * 2 + 2, height + 1, last);
      
      if (level * 2 + 2 < last)
         cout << right << setw(6 * height + 2) << "/" << endl;
         
      if (level == 0) {
         cout << "root-> " << right << setw(2) << mitems[level] << right << setw(15);
         for (int i = 0; i < last; i++)
         {
            cout << "|" << right << setw(2) << mitems[i] << "| ";
         } 
         cout << endl;
      } else { 
         cout << right << setw(height * 6) << mitems[level] << endl;
      }
      
      if (level * 2 + 1 < last)
         cout << right << setw(6 * height + 2) << "\\";
         if (height == 1) 
         {
            cout << "            "; 
            for (int j = 0; j < last; j++)
            {
               cout << right << setw(5) << j ;
            }
         } 
         cout << endl;
      treeHelper(level * 2 + 1, height + 1, last);
   }
}

//@swaps the Citems in these two locations with one another
//@pre Citem first and second are citems.
//@post fist contains what second did and second contains what first did;
//@param first
//@      second
//@usage Swap(mitem[root], mitem[rightChild])
void Cheap::Swap(Citem& first, Citem& second)
{
   if (msorted) {
      cout << "In Heap swapping " << first << " with " << second << "." << endl;
      cout << "_______________________________________________________________________________" << endl << endl; 
      treeHelper(0,1,msize);
      cout << endl ;
      sleep(6);
      msorted = false;
   }
   Citem temp;
   temp = first;
   first = second;
   second = temp;
}
