//@Implementation for ADT SSTF
//@   data object: a queue which is a First In First Out List
//@   data structure: circular linked list

//@   data object: a child class of que.h where Dequeue is modified using the data object of the 
//@                current track to operate on the shortest seek time to dequeue first.
//@   operations/methods: create, destroy, copy, the new sstf dequeue, find next R/W according to track
//@                       get track
//@   friend: print as operator<<


//@author Ryan Draper
//@date January 25, 2011
//@file sstf.cpp

#include "sstf.h"
#include <new>
#include <stdio.h>
#include <stdlib.h>


struct Node
{
   ItemType item;
   Node* next;
};


//@searches through a linked list to for the location of closest track to curtrack 
//@pre rhs_que points to a exiting Node with atleast one node
//@post returns the node directly before the node that contains the closest track to curtrack
//@param rhs_back
//@      curtrack
//@return pointer of the node before the node containing the correct item
//@usage item = SearchHelper(mbackptr, mcurtrack) -> next -> item;
Node* SearchHelper(Node* rhs_back, int curtrack)
{
   int dist;
   Node* frontPtr = rhs_back -> next;
   Node* returnPtr = rhs_back;
   
   if (frontPtr != rhs_back)
   {
      dist = abs(( frontPtr -> item).GetTrack() - curtrack);
      for (int i = 0; frontPtr != rhs_back; i++)
      {
         if (abs((frontPtr -> next -> item).GetTrack() - curtrack) < dist)
         {
            dist = abs((frontPtr -> next -> item).GetTrack() - curtrack);
            returnPtr = frontPtr;
         }
         frontPtr = frontPtr -> next;
      }
   }
   return returnPtr;
}

//++++++++ End Of Helper Functions +++++++++++++++++++++++++++++++++++

//@creates an empty SSTF instance of default memory size
//@post an empty current track
//@usage SSTF shortest;
SSTF::SSTF() : Que()
{
   mcurtrack = 0;
}
   
//@copies an existing SSTF
//@pre rhsst exists
//@post SSTF object is a copy of rhsst
//@usage SSTF newsstf(oldsstf); or passing a SSTF object by value
SSTF::SSTF(const SSTF& rhs_stuff) : Que(rhs_stuff)
{
   mcurtrack = rhs_stuff.mcurtrack;
}
   
//@destroys a SSTF
//@pre SSTF object exists
//@post SSTF object does not exist
SSTF::~SSTF()
{
   mcurtrack = 0;   
}
   
//@returns the private data object mcurtrack 
//@pre data object SSTF exists
//@post returns the int that is the current Track
//@returns an in mcurtrack
//@usage sstf.GetCurrentTrack();
int SSTF::GetCurrentTrack()
{
   return mcurtrack;
}
   
//@deletes item from the closest track to current position in the queue
//@pre queue exists SSTF exists
//@post if queue is nonempty, position of nearest track in queue has been removed
//@         and ok is true else ok is false
//@param ok
//@usage shortest.Dequeue(iceCream);
void SSTF::Dequeue(bool& ok)
{
   ok = (!IsEmpty());
   if (ok)
   {
      Node* prePtr = SearchHelper(mbackptr, mcurtrack);
      Node* delPtr = SearchHelper(mbackptr, mcurtrack) -> next;
      if (GetSize() == 1) {
         mbackptr = NULL;
      } else if (mbackptr == delPtr) { 
		 mbackptr = prePtr;
         prePtr -> next = delPtr -> next;
      } else {
	     prePtr -> next = delPtr -> next;
      }
      mcurtrack = (delPtr -> item).GetTrack();
      delPtr -> next = NULL;
      delete delPtr;
   } 
}
   
//@Finds the next track to be dequeued that is closest to current track
//@according to the helper function Search helper 
//@post returns ItemType item as the next and closest track
//@usage item = sstf.FindNextTrack();
ItemType SSTF::FindNextTrack()
{
   ItemType item;
   
   if (!IsEmpty())
   {
      item = SearchHelper(mbackptr, mcurtrack) -> next -> item;
   }
   return item;
}   

//@outputs to a file or the monitor the current track
//@pre rhsst exists
//@post contents of rhsitem have been output
//@param output
//@param rhsst
//@usage cout << rhss << endl;   
ostream& operator<< (ostream& output, const SSTF& rhsst)
{
   output << "The Queue: ";
   if (rhsst.IsEmpty())
   {
      output << "Empty" << endl;
   } else {
      Node* frontptr = rhsst.mbackptr->next;
      output << "+++ FRONT -> " << endl;
      output << "+++++++++++++++++++++++++++" << endl;
      for (int i = 1; i < rhsst.GetSize(); i++)
      {
         output << frontptr -> item;
         frontptr = frontptr -> next;
         if (i % 3 == 0)
			cout << endl; 
      }
      output << frontptr -> item << endl; 
      output << "+++++++++++++++++++++++++++" << endl;
      output << "<- REAR +++" << endl; 
   }

   output << "current track : " << rhsst.mcurtrack;
   
   return output;
}
