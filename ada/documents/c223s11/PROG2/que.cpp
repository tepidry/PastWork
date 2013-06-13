//@Implementation for ADT Queue
//@   data object: a queue which is a First In First Out List
//@   data structure: circular linked list

//@   operations/methods: create, destroy, check if empty, copy
//@               insert at end (enqueue), delete at front (dequeue)
//@               copy the front, get the size
//@   friend: print as operator<<

//@author Dr Y altered by Ryan Draper(draper
//@date January 25, 2010
//@file que.cpp

#include "que.h"
#include <new>

struct Node
{
   ItemType item;
   Node* next;
};

//@creates an empty queue
//@post an empty queue
//@usage Que q;
Que::Que()
{
   mbackptr = NULL;
}

//@copies an existing queue
//@pre rhsq exists
//@post queue object is a copy of rhsq
//@usage Que q(anotherq); or passing a Que object by value
Que::Que(const Que& rhsq)
{
   mbackptr = NULL;
   operator=(rhsq);
}   
   
//@destroys a queue
//@pre queue object exists
//@post queue object does not exist
Que:: ~Que()
{
   bool ok =(!IsEmpty());
   
   while(ok)
   {
      Dequeue(ok);
   }	   
}
     
//@finds the size of a queue object
//@pre queue object exists
//@post returns the size of the queue object
//@usage cout << q.GetSize();
int Que::GetSize() const
{
   int size = 0;
 
   if (!IsEmpty()) {
      Node* frontPtr = mbackptr -> next;  
      size++;
      while (frontPtr != mbackptr)
      {
         size++;
         frontPtr = frontPtr -> next;
      }
   }
   return size;
}
   
//@checks to see if a queue object is empty
//@pre queue object exists
//@post if queue is empty returns true else returns false
//@usage if (q.IsEmpty())
bool Que::IsEmpty() const
{
   return mbackptr == NULL;
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
   Node* newptr = new (nothrow) Node;
   ok = (newptr != NULL);
   if (ok)
   {
      newptr->item = newItem;
      if (IsEmpty())
      {
         newptr->next = newptr;    // makes it circular
      } else {
         newptr->next = mbackptr->next; // connects new node to front
         mbackptr->next = newptr;       // connects old back to new node
      }
      mbackptr = newptr;
   }
}
   
//@deletes item from the front of the queue
//@pre queue exists
//@post if queue is nonempty, front of the queue has been deleted from queue
//@         and ok is true else ok is false
//@param ok
//@usage q.Dequeue(iceCream);
void Que::Dequeue(bool& ok)
{
   ok = (!IsEmpty());
   if (ok)
   {
      Node* tempPtr = mbackptr -> next;
      if (tempPtr == mbackptr) {
         mbackptr = NULL;
      } else {
         mbackptr -> next = tempPtr -> next;
      }
      tempPtr -> next = NULL;
      delete tempPtr;

   }

}
 
//@copies the back item
//@pre queue exists and is not empty
//@post the back item in the queue is copied into backItem
//@param backItem
//@usage q.GetBack(backItem);
void Que::GetBack(ItemType& backItem) const
{
	backItem = mbackptr -> item;
}  
  
//@copies the front item
//@pre queue exists and is not empty
//@post the front item in the queue is copied into frontItem
//@param frontItem
//@usage q.GetFront(frontItem);
void Que::GetFront(ItemType& frontItem) const
{
   frontItem = mbackptr -> next -> item;
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
       bool ok;
       while(!IsEmpty())
          Dequeue(ok);
       if (rhsq.IsEmpty())
       {
          mbackptr = NULL;
       } else {
          Node* rhsqfront = rhsq.mbackptr->next;
          //Node* rhsqback = rhsq.mbackptr;
          while (rhsqfront != rhsq.mbackptr)
          {
             Enqueue (rhsqfront -> item, ok);
             rhsqfront = rhsqfront -> next;
          }
          Enqueue (rhsqfront -> item, ok);
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
   if (rhsq.IsEmpty())
   {
      output << "Empty" << endl;
   } else {
      Node* frontptr = rhsq.mbackptr->next;
      output << "+++ FRONT -> " << endl;
      for (int i = 1; i < rhsq.GetSize(); i++)
      {
         output << frontptr -> item << endl;
         frontptr = frontptr -> next; 
         if (i % 3 == 0)
			cout << endl;
      }
      output << frontptr -> item << endl; 
      output << "<- REAR +++" << endl;
   }
   return output;
}    
