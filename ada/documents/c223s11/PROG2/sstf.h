//@author Ryan Draper(draper)
//@date January 25, 2011
//@file sstf.h

//@Specification for ADT SSTF
//@   data object: a child class of que.h where Dequeue is modified using the data object of the 
//@                current track to operate on the shortest seek time to dequeue first.
//@   operations/methods: create, destroy, copy, the new sstf dequeue, find next R/W according to track,
//@                       get track
//@   friend: print as operator<<


#ifndef SSTF_H
#define SSTF_H

#include <iostream>
#include "que.h"

struct Node;

using namespace std;

class SSTF : public Que
{
   //@outputs to a file or the monitor the current track
   //@pre rhsst exists
   //@post contents of rhsitem have been output
   //@param output
   //@param rhsst
   //@usage cout << rhss << endl;   
   friend ostream& operator<< (ostream& output, const SSTF& rhsst);

public:

   //@creates an empty SSTF instance of default memory size
   //@post an empty current track
   //@usage SSTF shortest;
   SSTF();
   
   //@copies an existing SSTF
   //@pre rhsst exists
   //@post SSTF object is a copy of rhsst
   //@usage SSTF short(anothersstf); or passing a SSTF object by value
   SSTF(const SSTF& rhsst);
   
   //@destroys a SSTF
   //@pre SSTF object exists
   //@post SSTF object does not exist
   ~SSTF();
   
   //@returns the private data object mcurtrack 
   //@pre data object SSTF exists
   //@post returns the int that is the current Track
   //@returns an in mcurtrack
   //@usage sstf.GetCurrentTrack();
   int GetCurrentTrack();
   
   //@deletes item from the closest track to current position in the queue
   //@pre queue exists SSTF exists
   //@post if queue is nonempty, position of nearest track in queue has been removed
   //@         and ok is true else ok is false
   //@param ok
   //@usage shortest.Dequeue(iceCream);
   void Dequeue(bool& ok);
   
   //@Finds the next track to be dequeued that is closest to current track
   //@according to the helper function Search helper 
   //@post returns ItemType item as the next and closest track
   //@usage item = sstf.FindNextTrack();

   ItemType FindNextTrack();
   
private: 
int mcurtrack;
};
#endif
