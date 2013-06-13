//@Implementation for ADT Queue
//@   data object: a queue which is a First In First Out List
//@   data structure: a static array for the items
//@                   an int for the index of front item,
//@                   an int for the index of rear item
//@                   an int for the count
//@   operations/methods: create, destroy, make empty, check if empty,
//@               insert at the rear (Enqueue), delete from the front (Dequeue)
//@               copy the front (GetFront), get the size (GetSize)
//@   friend: print as operator<<

//@author Dr Y
//@date November, 2010
//@file que.cpp

#include "que.h"

//@creates an empty queue
//@post an empty queue
//@usage Que q;
Que::Que()
{
   mfront = 0;
   mrear = MAXQUE - 1;
   mcount = 0;
}

//@copies an existing queue
//@pre rhsq exists
//@post queue object is a copy of rhsq
//@usage Que q(anotherq); or passing a Que object by value
Que::Que(const Que& rhsq)
{
   //make empty first




   //now use copy


}   
   
//@destroys a queue
//@pre queue object exists
//@post queue object does not exist
Que:: ~Que()
{
   //no memory to free but if we had obeyed data hiding, client does not know
   mfront = 0;
   mrear = MAXQUE - 1;
   mcount = 0;
}
     
//@finds the size of a queue object
//@pre queue object exists
//@post returns the size of the queue object
//@usage cout << q.GetSize();
int Que::GetSize() const
{

}
   
//@checks to see if a queue object is empty
//@pre queue object exists
//@post if queue is empty returns true else returns false
//@usage if (q.IsEmpty())
bool Que::IsEmpty() const
{

}
   
//@inserts a new item at the rear of the queue
//@pre newItem has an assigned value; queue exists
//@post if queue object is not full, newItem is added
//@      at the rear of the queue and ok is true else ok is false
//@param newItem
//@param ok
//@usage q.Enqueue(newguy, ok);
void Que::Enqueue(const ItemType& newItem, bool& ok)
{
   ok = (mcount < MAXQUE);
   if (ok)
   {
      mrear = (mrear + 1) % MAXQUE;
      mitems[mrear] = newItem;
   }
   mcount++;
}
   
//@deletes item from the front of the queue
//@pre queue exists
//@post if queue is nonempty, front of the queue has been deleted
//@         and ok is true else ok is false
//@param frontItem
//@param ok
//@usage q.Dequeue(iceCream);
void Que::Dequeue(bool& ok)
{



}
   
//@copies the front item
//@pre queue exists and is not empty
//@post the front item in the queue is copied into frontItem
//@param frontItem
//@usage q.GetFront(frontItem);
void Que::GetFront(ItemType& frontItem) const
{

}

//@copies the queue
//@pre rhsq exists. queue object exists with same amount of memory
//@post queue object is a copy of rhsq
//@param rhsq
//@usage cpyq.operator=(rhsq);
//@      or        cpyq = rhsq;
Que& Que::operator=(const Que& rhsq)
{
   if (this != &rhsq)
   {
      //copy each of the ints from queue object rhsq to calling object
      mcount = rhsq.mcount;


      //copy just the items that represent the actual queue NOT the entire array
      for (int i = 0; i < mcount; i++)
      {


      }
   }
   return *this;
}

//@outputs to a file or the monitor a queue object
//@pre rhsq exists. output is open.
//@post contents of rhsq have been output
//@param output
//@param rhsq
//@usage cout << rhsq << endl;   
ostream& operator<< (ostream& output, const Que& rhsq)
{
   output << "The Queue: ";
   if (rhsq.mcount > 0)
   {
      int i;
      int front = rhsq.mfront;
      output << "front -> ";
      for (i = 0; i < rhsq.mcount - 1; i++)
      {
         output << rhsq.mitems[(front + i) % MAXQUE] << " , ";
      }
      output << rhsq.mitems[(front + i) % MAXQUE] << " <- rear " << endl;
   } else {
      output << "Empty" << endl;
   }
   return output;
}    
