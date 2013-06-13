//@Implementation for ADT Cmerge
//@   data object: a max merge array 
//@   data structure: a static array for the items
//@                   an int for the index of rear item
//@                   an bool for when the array has been merged
//@                   a bool for while it is merging
//@   operations/methods: create, copy, destroy, IsMerged, MergeInserts, MergeDelete,
//@                  operator=, MergeSort, MergeDisplay, ArrayDisplay

//@author Ryan Draper (draper) 
//@date April 9, 2011
//@file cmerge.cpp

#include "cmerge.h"

//@creates an empty Cmerge of default memory size
   //@post an empty Cmerge object
   //@usage Cmerge merge;
   Cmerge::Cmerge()
   {
      mlast = 0;
      mmerged = false;
      mmerging = false;
   }
   
   //@copies an existing merge object
   //@pre rhsmerge exists
   //@post merge object is a copy of rhsmerge
   //@param rhsmerge
   //@usage Cmerge merge(anothermerge); or passing a Cmerge object by value
   Cmerge::Cmerge(const Cmerge& rhsmerge)
   {
      mlast = 0;
      mmerged = false;
      mmerging = false;
      operator=(rhsmerge);
      
   }
   
   //@destroys a merge
   //@pre merge object exists
   //@post merge object does not exist
   Cmerge::~Cmerge()
   {
      mlast = 0;  
      mmerged = false; 
      mmerging = false;
   }
   
   //@checks to see if a merge object is empty
   //@pre merge object exists
   //@post if merge is empty returns true else returns false
   //@usage if (m.IsEmpty())
   bool Cmerge::IsEmpty() const
   {
      return mlast == 0;
   }
   
   //@tells whether the array has had merged sort ran on it or not
   //@pre merge object exists
   //@post returns true if merged is true else false
   //@usage if(IsMerged())s
   bool Cmerge::IsMerged() const
   {
      return mmerged == true;
   }
   
   //@inserts a new item at the rear of the merge
   //@pre newItem has an assigned value; merge exists
   //@post if merge object is not full, newItem is added to the end of the array
   //@param newItem
   //@usage m.MergeInsert(newguy);
   void Cmerge::MergeInsert(const Citem& newItem)
      throw (cexception)
   {
      if (mlast == MAXMERGE) {
         throw cexception("Cmerge::Insert, Sorry there is not enough memory in the array for your item.");
      } else {
         mitems[mlast] = newItem;
         mlast++;
         mmerged = false;
      }
   }
   
   //@inserts a new array into the merge
   //@pre newArray has an assigned value; merge exists size indexes the newArray
   //@post if merge object exists and size is not larger than MAXMERGE, newArray is added
   //@param newItem
   //@usage m.MergeInsert(newguy);
   void Cmerge::MergeInsert(const Citem newArray[], int size)
      throw (cexception)
   {
      if (size > MAXMERGE) {
         throw cexception("Cmerge::Insert, Sorry there is not enough memory to put your array into a Cmerge. Shorten your array and try again");
      } else {
         for (int i = 0; i < size; i++)
         {
            mitems[i] = newArray[i];
         }
         mlast = size;
         mmerged = false;
      }
   }   
   
   //@deletes a item from the merge after copying it to item
   //@pre merge exists and item is Citem
   //@post if mergev is nonempty, front of merge has been removed
   //@         and ok is true else ok is false
   //@param frontItem
   //@param item
   //@usage q.Dequeue(iceCream);
   void Cmerge::MergeDelete(Citem& item)
      throw (cexception)
   {
      if (mlast < 1) {
         throw cexception("Cmerge::Delete, Sorry your Cmerge array is empty, there is nothing to delete.");
      } else {
         mitems[mlast - 1] = -1;
         mlast--;
      }
      
   }   
   
   //@copies the queue
   //@pre rhsq exists. queue object exists with same amount of memory
   //@post queue object is a copy of rhsq
   //@param rhsq
   //@usage cpyq.operator=(rhsq);
   //@      or        cpyq = rhsq;
   Cmerge& Cmerge::operator=(const Cmerge& rhsmerge)
   {
      if (this != &rhsmerge)
      {
         mlast = rhsmerge.mlast; 
         mmerged = rhsmerge.mmerged;
         mmerging = rhsmerge.mmerging;
         for (int i = 0; i < mlast; i++)
         {
            mitems[i] = rhsmerge.mitems[i];
         }
      }
      return *this;
   }
   
   //@sorts an array into ascending order
   //@pre an Citem array
   //@post a sorted array
   //@usage merge.MergeSort();
   void Cmerge::MergeSort()
   {
      mergeSortHelper(0, mlast - 1);
   }
   
   //@Displays the merge as an array
   //@pre merge object exists
   //@post merge is output looking like a array
   //@usage merge.ArrayDisplay();
   void Cmerge::ArrayDisplay()const
   {
      if (IsMerged())
         cout << "Merge Sorted Array of length " << mlast << " using MergeSort." << endl;
      else
         cout << "A Un-Merge Sorted Array of length " << mlast << " gets split in half." << endl;
      if (not IsEmpty()) {
         for (int i = 0; i < mlast; i++)
         {
            cout << "|" << right << setw(2) << mitems[i] << "| ";
         }
         cout << endl;
         for (int i = 0; i < mlast; i++)
         {
            cout << right << setw(3) << i << "  ";
         }
         cout << endl << endl;
      } else {
         cout << "Empty!" << endl;
      }
   }
   
   //@Displays an array
   //@pre array object exists
   //@post array is output looking like a array
   //@usage ArrayDisplay(array);
   void Cmerge::arrayDisplay(Citem array[])const
   {
      for (int i = 0; i < mlast; i++)
      {
         cout << "|" << right << setw(2) << array[i] << "| ";
      }
      cout << endl;
      for (int i = 0; i < mlast; i++)
      {
         cout << right << setw(3) << i << "  ";
      }
      cout << endl << endl;
   }
   
   //@displays all that merge sort does
   //@pre object exists and is output
   //@post object is diplayed as it works
   //@usage merge.MergeDisplay();
   void Cmerge::MergeDisplay()
   {
      mmerging = true;
      cout << ":    +++++++ Recursive Merge Sort +++++++       :" << endl;
      cout << ": Calls to Merge Sort shown as, MS(first, last) :" << endl;
      cout << ":   Calls to Merge as Merge(first, mid, last)   :" << endl << endl;
      ArrayDisplay();
      cin.get();
      MergeSort();
      cout << "Giving you a, ";
      ArrayDisplay();
      cout << "press Enter to Continue. " << endl;
      cin.get();
      mmerging = false;
   }
   
   //@displays the calls for merge sort
   //@pre first mid and last all index parts of the array Cmerge exists
   //@post the call for merge sort is displayed as MS(first, last)
   //@usage mergeSortDisplay(first,mid,last);
   void Cmerge::mergeSortDisplay(int first, int mid, int last)
   {
      if (first == mid && mid + 1 == last)
         cout << "Two base cases:" << endl;
      else if (first == mid || mid + 1 == last)
         cout << "One base cases:" << endl;
      
      cout << "MS(" << right << setw(2) << first << ", " << right << setw(2) << mid << ")";
      
      for (int i = first + 2; i <= mid + 1; i++)
         cout << "     ";
      cout << "MS(" << right << setw(2) << mid + 1 << ", " << right << setw(2) << last << ")" << endl;
   }
   
   //@displays calls to merge
   //@pre first, mid and last all index parts of the array and cmerge exists
   //@post output the call for merge displayed as Merge(first, mid, last)
   //@usage mergeDisplay(first,mid,last);
   void Cmerge::mergeDisplay(int first, int mid, int last)
   {
      if (first == mid)
         cout << "A base case Merge Call:" << endl;
      cout << "Merge(" << right << setw(2) << first << ", " << right << setw(2) << mid << ", " << right << setw(2) << last << ")" << endl;

   }
   
   //@Displays the merge as an array from first to last
   //@pre merge object exists int first is the beginning of the array and last is the end
   //@post merge is output looking like a array
   //@usage merge.ArrayDisplay();
   void Cmerge::arrayDisplay(Citem array[], int first, int mid, int last)const
   {
      for (int i = first; i <= mid; i++)
      {
         cout << "|" << right << setw(2) << array[i] << "| ";
      }
      cout << "     ";
      for (int j = (mid + 1); j <= last; j++)
      {
         cout << "|" << right << setw(2) << array[j] << "| ";
      }
      cout << endl;
      placeDisplay(first, last);
   }
   
   //@Displays the placement of mitems
   //@pre first and last is the part of the array to number
   //@post the numbers are put under the location needed
   //@param first
   //@param last
   //@usage placeDisplay(first, last);
   void Cmerge::placeDisplay(int first, int last)const
   {
      int mid = (first + last) / 2;
      for (int i = first; i <= last; i++)
      {
         cout << right << setw(3) << i << "  ";
         if (i == mid ) {
            cout << "     ";
         }
      }
      cout << endl << "_______________________________________________________________________________" ;
      cout << endl << endl; 
   }
   
   //@Merges two sorted array sefments into one sorted array.
   //@pre first <= mid <= last. The subarrays [first...mid] and [mid + 1...last]
   //@post there is one assorted array
   //@param first
   //@param mid
   //@param last
   //@usage Merge(0, mid, msize);
   void Cmerge::merge(int first, int mid, int last)
   {
      
      Citem tempArray[MAXMERGE];
      
      int first1 = first;
      int last1 = mid;
      int first2 = mid + 1;
      int last2 = last;
      int index = first1;
      
      if (mmerging) {
         cout << "Then is sorted in a temp array from " << first << " to " << mid << " and " << mid + 1 << " to " << last << endl;
         mergeDisplay(first, mid, last);
         arrayDisplay(mitems, first, mid, last);
         sleep(6);
      }
      
      for(;(first1 <= last1) && (first2 <= last2); ++index)
      {
         if (mitems[first1] < mitems[first2]) {
            tempArray[index] = mitems[first1];
            ++first1;
         } else {
            tempArray[index] = mitems[first2];
            ++first2;
         }
      }
      
      for (;first1 <= last1; ++first1, ++index)
      {
         tempArray[index] = mitems[first1];
      }
      
      for (;first2 <= last2; ++first2, ++index)
      {
         tempArray[index] = mitems[first2];
      }
      
      for (index = first; index <= last; ++index)
      {
         mitems[index] = tempArray[index];
      }
      mmerged = true;
      if (first == 0 && last == mlast - 1) {
         cout << "The Sorted Temporary Array then gets put back into the original merge array ~~>" << endl;
         arrayDisplay(tempArray);
         sleep(6);
      }
   }
   
   //@Helps sort an array into ascending order
   //@pre a Citem array
   //@post a sorted array
   //@param first
   //@param last
   //@usage merge.MergeSort();
   void Cmerge::mergeSortHelper(int first, int last)
   {
      if (first < last)
      {
         int mid = (first + last) / 2;
         
         if (mmerging) {
            cout << "The unsorted array is split from " << first << " to " << mid << " and " << mid + 1 << " to " << last << endl;
            mergeSortDisplay(first, mid, last); 
            arrayDisplay(mitems, first, mid, last);
            sleep(6);
         }
         
         mergeSortHelper(first, mid);
         mergeSortHelper(mid + 1, last);
         merge(first, mid, last);
      }
   }
