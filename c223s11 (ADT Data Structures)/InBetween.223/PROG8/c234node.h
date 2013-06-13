//@author Ryan Draper (draper)
//@date April 14, 2011
//@file c234node.h

//@ADT 2-3-4 Tree Node:
//@Specification of a 2-3-4 Tree Node
//@   data object: a node for a dynamic 2-3-4 tree
//@   operations: four constructors, copy, deconstructor, operator=, recyclenode,
//@               isempty, isfull, is leaf, connets to parent, connect pointer, disconnect pointer
//@               display node, insert, delete node. 
//@   friend: operator<<


#ifndef C234NODE_H
#define C234NODE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "citem.h"
#include "cexception.h"

using namespace std;

const int MAXITEMS = 4;

class C234node
{
   //@outputs to a file or the monitor a Citem object
   //@pre rhscitem exists. output is open.
   //@post contents of rhscitem have been output
   //@param output
   //@param rhscitem
   //@usage outfile << rhscitem << endl;   
   friend ostream& operator<< (ostream& output, const C234node& rhs234node);
   
public:

//@creates a node
//@post: the item of the node is empty, the kids are NULL.
//2usage: newptr = new cnode();
C234node();

//@creates a 2 234node with a given item and kids
//@post: the item of the node is leftItem, the kids are left and midleft
//@usage:anode = new  C234node (thisone, NULL, NULL);
C234node (const Citem& leftItem, C234node* left, C234node* midleft);
          
//@creates a 3 234node with a given items and kids
//@post: the first item of the node is leftItem the 2nd item of the node is centerItem,
//@       the kids are left, mid right and midleft
//@usage:anode = new  C234node (leftone, midone, NULL, NULL, NULL);
C234node (const Citem& leftItem, const Citem& centerItem, C234node* left,  C234node* midleft, C234node* midright);

//@creates a 4 234node with a given items and kids
//@post: the first item of the node is leftItem the 2nd item of the node is centerItem, 3rd item is rightItem,
//@       the kids are left, mid right, right and midleft
//@usage:anode = new  C234node (leftone, midone, rightone, NULL, NULL, NULL, NULL);
C234node (const Citem& leftItem, const Citem& centerItem, const Citem& rightItem,
          C234node* left,  C234node* midleft, C234node* midright, C234node* right);
	
//@copies an existing C234node
//@pre rhsc234node exists
//@post C234node object is a copy of rhsc234node
//@usage C234node item(anotherc234node); or passing a C234node object by value
C234node(const C234node& rhsc234node);
   
//@destroys a C234node
//@pre C234node object exists
//@post C234node object does not exist
~C234node();
   
//@copies the C234node
//@pre rhsc234node exists. C234node object exists with same amount of memory
//@post C234node object is a copy of rhsc234node
//@param rhsc234node
//@usage cpyc234node.operator=(rhsc234node);
//@      or        cpynode = rhsc234node;   
C234node& operator=(const C234node& rhsc234node);

// ******************** member functions ********************************************
//@pre: 234 node object exists
// **********************************************************************************

//@connects to parent node
//@pre parent node exists
//@post parent now points to this c234node
//@param parent
//@usage node.ConnectsToParent(mparent.mptrs[1])
void ConnectsToParent(C234node*& parent);

//@connects child to mptr[childPtr]
//@pre child is a node childPtr refence the pointer 
//@post childPtr of mptrs now points to child
//@param childPtr
//@param child
//@usage node.ConnectPtr(2, mchild);
void ConnectPtr(int childPtr, C234node*& child);

//@disconnects child from mptrs[]
//@pre is an int that references the ptr to be disconnected
//@post ptr[childPtr] has been disconnected
//@param childPtr
//@usage node.DisconnecPtr(2);
C234node* ReturnPtr(int childPtr);

//@copies the last two items in a node
//@pre second and third are Citems
//@post second and third are copies of the 2nd and 3rd positions in mdata[]
//@param second
//@param third
//@usage CopyRightItems(secondItem, thirdItem);
void CopyRightItems(Citem& second, Citem& third);

//@recycles a node to be used as the left child of its current locatioin
//@pre c234node is full  
//@post Empties out all children except the first positions '0' and clears
//@     all pointers except two left most '0' and '1'
//@usage node.RecycleNode();
void RecycleNode();

//@prints out node data items
//@pre node has atleast one item in it
//@post out put is all the data items else dashes
//@usage node.DisplayItems();
void DisplayItems() const;


//@inserts new item into a existing node finding it location among the data aleady in the data using swap
//@pre c234 Node is not full and is a leaf 
//@post new item is in it's sorted location in the node
//@returns the position the item was entered into the mdata array
//@param item
//@usage node.Insert(item);
int Insert(const Citem& item); 

//@returns bool depending on if the C234node is empty
//@post returns true if the node is empty else false
//@usage if(node.IsEmpty())
bool IsEmpty() const;

//@returns bool value whether or not the C234node is full
//@post returns true if the node is full else false
//@usage if (node.IsFull())
bool IsFull() const;   

//@retruns true if the node is a leaf, meaning it has no children
//@post true if the node is a leaf else false
//@ usage if(IsLeaf())
bool IsNotLeaf() const;

//@bool value for if item is in node
//@post true if value is in node else false
//@param newItem
//@usage 
bool IsInNode(const Citem& item) const;

//@retruns a pointer to the next child along the path of the insert for the newItem
//@pre newItem is a citem to insert and currentPtr is the current location along the path
//@post returns a pointer to the next node along the insert path
//@param currentPtr
//@param newItem
//@usage currentPtr = getNextChild(currentPtr, newItem);
C234node* GetNextChild(const Citem& newItem)
   throw(cexception);

//@AdjustsParents pointers post insert of the split item in it's child.
//@pre child has bee spit and has recieve a new Citem into mdata[] and adjusting prior pointers
//@post prior pointers have been adjusted and are ready for new pointers to be connected.
//@param indexPlacement
//@usage mparent.AdjustParentsPtrs(indexPlacement);
void AdjustParentsPtrs(const int indexPlacement);

int msize;
Citem mdata[MAXITEMS - 1];
C234node* mptrs[MAXITEMS];

protected:
//@destroys node
//@post releases all data in a node
//@usage destoyNode();
void destoyNode();

//@swaps two items inside a 234node
//@post the two items have been swapped
//@param first
//@param second
//@usage node.swap(node, first, second);
void swap(Citem& first, Citem& second);

};

#endif


