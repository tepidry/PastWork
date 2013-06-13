//@author Ryan Draper(draper)
//@date Feb 9, 2011
//@file cnode.h

//@Specification for Cnode
//@   data object: representing a single branched level of a binary tree containg a char
//@                and two ints to represent indexing of its children
//@   operations/methods: create, destroy, copy, GetLeft, GetRight, GetItem,
//@               operator=

#ifndef CNODE_H
#define CNODE_H

#include <iostream>
typedef char ItemType;

using namespace std;

class Cnode
{  
public:

   //@creates an empty node
   //@post an empty node
   //@usage Cnode ptr;    
   Cnode();
   
   //@copies an existing Cnode
   //@pre rhsCnode exists
   //@post Cnode object is a copy of rhsCnode
   //@usage Cnode item(anotherCnode); or passing a Cnode object by value        
   Cnode(const Cnode& rhsq);
   
   //@destroys a Cnode
   //@pre Cnode object exists
   //@post Cnode object does not exist
   ~Cnode();
    
   //@returns the int of the leftChild or index
   //@pre Cnode exists
   //@post returns mleftChild
   //@usage left = item.GetLeft();
   int GetLeft(); 
     
   //@returns the int of the rightChild or index
   //@pre Cnode exists
   //@post returns mrightChild
   //@usage right = item.GetRight();
   int GetRight(); 
    
   //@returns an itemtype of a cnode
   //@pre cnode exists
   //@post returns itemType of mitem
   //@usage item = index.GetItem();
   ItemType GetItem();
   
   //@adds item into the Cnode
   //@pre item is a ItemType
   //@post mitem in Cnode contains an appropriate ItemType
   //@param item
   //@usage node.SetItem(item);
   void SetItem(ItemType item);
   
   //@sets the index of the right Child of Cnode
   //@pre right is a int to be placed in the existing Cnodes mrightChild
   //@post mrightChild is set
   //@param right
   //@usage Cnode.SetRight(right);
   void SetRight(int right);
   
   //@sets the index of the left Child of Cnode
   //@pre left is a int to be placed in the existing Cnodes mleftChild
   //@post mleftChild is set
   //@param left
   //@usage Cnode.SetRight(left);
   void SetLeft(int left);  
   
   //@copies the Cnode
   //@pre rhsCnode exists. Cnode object exists with same amount of memory
   //@post Cnode object is a copy of rhsCnode
   //@param rhsCnode
   //@usage cpyq.operator=(rhsCnode);
   //@      or        cpyq = rhsCnode;   
   Cnode& operator=(const Cnode& rhsCnode);
   
private: 
int mleftChild, mrightChild;
ItemType mitem;

};
#endif
