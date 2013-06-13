//@author Dr Y 
//@date 1/20/99  last modified 2/21/10
//@file cstack.h

//@Specification for Abstract Data Type Stack:
//    data object: a stack of items (Last-In-First-Out list of items)
//                 where the top denotes the most-recently-added item
//    operations: create, copy, destroy (constructors and destructor)
//                Push and Pop  (insert and delete at 'the top')
//                GetTop (retrieve 'the top'), IsEmpty

#ifndef STACK_H
#define STACK_H

typedef int ItemType;
struct NodeType;

class Stack
{
public:

   //@Initializes an empty stack
   //@post: the class object is empty
   //@usage: Stack stk;
   Stack();

   //@Copies the stack object s to the class object
   //@pre: rhs_stk exists
   //@post: the class object has the same contents in same order as rhs_stk
   //@param rhs_stk
   //@sage: Stack stk2 (stk1);
   Stack (const Stack& rhs_stk);

   //@Destroys the class object
   //@pre: class object exists
   //@post: class object no longer exists
   //@usage: automatically done at exit of the module in which declared
   ~Stack();

   //@Determines whether or not a stack is empty
   //@pre: class object exists
   //@post: returns true if class empty is empty; else returns false
   //@return true or false
   //@usage: if (stk.IsEmpty()) 
   bool IsEmpty() const;

   //@Adds a new item to the top of a stack
   //@pre: class object exists
   //@post: If class object is not full, then
   //          adds newItem at the top of the class object and 
   //          ok is true else ok is false
   //@param newItem
   //@param ok
   //@usage: stk.Push (4, ok);
   void Push (ItemType newItem, bool& ok);

   //@Deletes the top item from a stack
   //@pre: class object exists
   //@post: If class object was not empty, ok is true and the post-
   //     object is without top item of the pre-object; 
   //     else ok is false
   //@param ok
   //@usage: stk.Pop(ok); 
   void Pop (bool& ok);

   //@Copies the top item of a stack
   //@pre: class object exists
   //@post: If object is not empty, theTop contains the top item of
   //    object and ok is true; else ok is false
   //@param theTop
   //@param ok
   //@usage stk.GetTop(top,ok);
   void GetTop (ItemType& theTop, bool& ok);

private:
   NodeType* topptr;
};   

#endif

