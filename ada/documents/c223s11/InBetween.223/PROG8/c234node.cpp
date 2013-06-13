//@ADT 2-3-4 Tree Node:
//@Implementation of a 2-3-4 Tree Node
//@   data object: a node for a dynamic 2-3-4 tree
//@   data structure: int for size in mdata
//@                   an array of 3 Citems
//@                   and an array of 4 pointers
//@   operations: four constructors, copy, deconstructor, operator=, recyclenode,
//@               isempty, isfull, is leaf, connets to parent, connect pointer, disconnect pointer
//@               display node, insert, delete node. 
//@   friend: operator<<

//@author Ryan Draper (draper)
//@date April 14, 2011
//@file c234node.cpp

#include "c234node.h"

using namespace std;

//@creates a node
//@post: the item of the node is empty, the kids are NULL.
//2usage: newptr = new cnode();
C234node::C234node()
{
   msize = 0;
   for(int i = 0; i < MAXITEMS; i++)
      mptrs[i] = NULL;
}

//@creates a 2 234node with a given item and kids
//@post: the item of the node is leftItem, the kids are left and midleft
//@usage:anode = new  C234node (thisone, NULL, NULL);
C234node::C234node (const Citem& leftItem, C234node* left, C234node* midleft)
{
   msize = 1;
   mdata[0] = leftItem;
   mptrs[0] = left;
   mptrs[1] = midleft;
   for(int i = 2; i < MAXITEMS; i++)
      mptrs[i] = NULL;
}
          
//@creates a 3 234node with a given items and kids
//@post: the first item of the node is leftItem the 2nd item of the node is centerItem,
//@       the kids are left, mid right and midleft
//@usage:anode = new  C234node (leftone, midone, NULL, NULL, NULL);
C234node::C234node (const Citem& leftItem, const Citem& centerItem, C234node* left, C234node* midleft, C234node* midright)
{
   msize = 2;
   mdata[0] = leftItem;
   mdata[1] = centerItem;
   mptrs[0] = left;
   mptrs[1] = midleft;
   mptrs[2] = midright;
   mptrs[3] = NULL;
}

//@creates a 4 234node with a given items and kids
//@post: the first item of the node is leftItem the 2nd item of the node is centerItem, 3rd item is rightItem,
//@       the kids are left, mid right, right and midleft
//@usage:anode = new  C234node (leftone, midone, rightone, NULL, NULL, NULL, NULL);
C234node::C234node (const Citem& leftItem, const Citem& centerItem, const Citem& rightItem,
          C234node* left,  C234node* midleft, C234node* midright, C234node* right)
{
   msize = 3;
   mdata[0] = leftItem;
   mdata[1] = centerItem;
   mdata[2] = rightItem;
   mptrs[0] = left;
   mptrs[1] = midleft;
   mptrs[2] = midright;
   mptrs[3] = right;
}
	
//@copies an existing C234node
//@pre rhsc234node exists
//@post C234node object is a copy of rhsc234node
//@usage C234node item(anotherc234node); or passing a C234node object by value
C234node::C234node(const C234node& rhsc234node)
{
   msize = 0;
   for(int i = 0; i < MAXITEMS; i++)
      mptrs[i] = NULL;
   operator=(rhsc234node);   
}
   
//@destroys a C234node
//@pre C234node object exists
//@post C234node object does not exist
C234node::~C234node()
{
   destoyNode();   
}
   
//@copies the C234node
//@pre rhsc234node exists. C234node object exists with same amount of memory
//@post C234node object is a copy of rhsc234node
//@param rhsc234node
//@usage cpyc234node.operator=(rhsc234node);
//@      or        cpynode = rhsc234node;   
C234node& C234node::operator=(const C234node& rhsc234node)
{
   if (this != &rhsc234node)
   {
      msize = rhsc234node.msize;
      for(int i = 0; i < MAXITEMS - 1; i++)
         mdata[i] = rhsc234node.mdata[i];
      for(int i = 0; i < MAXITEMS; i++)
         mptrs[i] = rhsc234node.mptrs[i];
   }
}

// ******************** member functions ********************************************
//@pre: 234 node object exists
// **********************************************************************************


//@connects child to mptr[childPtr]
//@pre child is a node childPtr refence the pointer 
//@post childPtr of mptrs now points to child
//@param childPtr
//@param child
//@usage node.ConnectPtr(2, mchild);
void C234node::ConnectPtr(int childPtr, C234node*& child)
{
   mptrs[childPtr] = child;
}

//@disconnects child from mptrs[]
//@pre is an int that references the ptr to be disconnected
//@post ptr[childPtr] has been disconnected
//@param childPtr
//@usage node.DisconnecPtr(2);
C234node* C234node::ReturnPtr(int childPtr)
{
   C234node* temp = mptrs[childPtr];
   mptrs[childPtr] = NULL;
   return temp;
}

//@copies the last two items in a node
//@pre second and third are Citems in full c234node
//@post second and third are copies of the 2nd and 3rd positions in mdata[]
//@param second
//@param third
//@usage CopyRightItems(secondItem, thirdItem);
void C234node::CopyRightItems(Citem& second, Citem& third)
{
   second = mdata[1];
   third = mdata[2];
}

//@recycles a node to be used as the left child of its current locatioin
//@pre c234node is full  
//@post Empties out all children except the first positions '0' and clears
//@     all pointers except two left most '0' and '1'
//@usage node.RecycleNode();
void C234node::RecycleNode()
{
   msize = msize -2;
   
   for(int i = 1; i < MAXITEMS - 1; i++)
      mdata[i].EmptyOut();
      
   for(int i = 2; i < MAXITEMS; i++)
      mptrs[i] = NULL;
}

//@prints out node data items
//@pre node has atleast one item in it
//@post out put is all the data items else dashes
//@usage node.DisplayItems();
void C234node::DisplayItems() const
{
   int i;
   
   cout << "NODE of size " <<  msize << "-> :{";
   for (i = 0; i < MAXITEMS - 2; i++)
   {
      cout << mdata[i] << "|";
   }
      
   cout << mdata[i] << "}:";
}

//@inserts new item into a existing node finding it location among the data aleady in the data using swap
//@pre c234 Node is not full and is a leaf
//@post new item is in it's sorted location in the node
//@param item
//@usage node.Insert(item);
int C234node::Insert(const Citem& item)
{
   int indexPlace;
   if(msize < 3)
   {
      mdata[msize] = item;
      indexPlace = msize;
      for (int i = msize; i > 0; i--)
      {
         if (mdata[i] < mdata[i - 1]) 
         {
            indexPlace = i - 1;
            swap(mdata[i], mdata[i-1]);
         }
      }
      msize++;
   }
   return indexPlace;
}

//@returns bool depending on if the C234node is empty
//@post returns true if the node is empty else false
//@usage if(node.IsEmpty())
bool C234node::IsEmpty()const
{
   return (msize == 0);
}

//@returns bool value whether or not the C234node is full
//@post returns true if the node is full else false
//@usage if (node.IsFull())
bool C234node::IsFull() const
{
   return (msize == 3);
}

//@retruns true if the node is a leaf, meaning it has no children
//@post true if the node is a leaf else false
//@ usage if(IsLeaf())
bool C234node::IsNotLeaf() const
{
   return (mptrs[0] != NULL && mptrs [1] != NULL);
}

//@bool value for if item is in node
//@post true if value is in node else false
//@param newItem
//@usage 
bool C234node::IsInNode(const Citem& item) const
{
   bool IsInNode = false;
   for (int i = 0; i < MAXITEMS - 1; i++)
   {
      if (mdata[i] == item)
         IsInNode = true;
   }
   return IsInNode;
}

//@retruns a pointer to the next child along the path of the insert for the newItem
//@pre newItem is a citem to insert and currentPtr is the current location along the path
//@post returns a pointer to the next node along the insert path
//@param currentPtr
//@param newItem
//@usage currentPtr = getNextChild(currentPtr, newItem);
C234node* C234node::GetNextChild(const Citem& newItem)
   throw(cexception)
{
   int nextPtr;
   for (int i = 0; i < msize; i++)
   {
      if (newItem < mdata[i])
         nextPtr = i;
      else
         nextPtr = i + 1;
   }
   return (mptrs[nextPtr]);
         
}

//@AdjustsParents pointers post insert of the split item in it's child.
//@pre child has bee spit and has recieve a new Citem into mdata[] and adjusting prior pointers
//@post prior pointers have been adjusted and are ready for new pointers to be connected.
//@param indexPlacement
//@usage mparent.AdjustParentsPtrs(indexPlacement);
void C234node::AdjustParentsPtrs(const int indexPlacement)
{
   if (indexPlacement == 0)
   {
      ConnectPtr(indexPlacement + 3, mptrs[indexPlacement + 2]);
   } 
   if (indexPlacement <= 1) 
   {
      ConnectPtr(indexPlacement + 2, mptrs[indexPlacement + 1]);
   }
}

//@destroys node
//@post releases all data in a node
//@usage destoyNode();
void C234node::destoyNode()
{
   msize = 0;
   for(int i = 0; i < MAXITEMS - 1; i++)
      mdata[i].EmptyOut();
   for(int i = 0; i < MAXITEMS; i++)
      mptrs[i] = NULL;
}

//@swaps two items inside a 234node
//@post the two items have been swapped
//@param first
//@param second
//@usage node.swap(node, first, second);
void C234node::swap(Citem& first, Citem& second)
{
   Citem temp = first;
   first = second;
   second = temp;
}

//@outputs to a file or the monitor a Citem object
//@pre rhscitem exists. output is open.
//@post contents of rhscitem have been output
//@param output
//@param rhscitem
//@usage cout << rhscitem << endl;   
ostream& operator<< (ostream& output, const C234node& rhs234node)
{
   int i;
   
   output << ":{";
   for (i = 0; i < 2; i++)
   {
      output << rhs234node.mdata[i] << "|";
   }
   output << rhs234node.mdata[i] << "}:";
   return output;
}
