//@Implementation for Cnode
//@   data object: representing a single branched level of a binary tree 
//@   data structure: an ItemType and two ints

//@   operations/methods: create, destroy, copy, GetLeft, GetRight, GetItem,
//@               operation=

//@author Ryan Draper(draper)
//@date Feb, 9 2010
//@file cnode.cpp

#include "cnode.h"
        

//@creates an empty node
//@post an empty node
//@usage Cnode ptr;
Cnode::Cnode()
{
   mleftChild = -1;
   mrightChild = -1;
   mitem = '!';      
}

//@copies an existing Cnode
//@pre rhsCnode exists
//@post Cnode object is a copy of rhsCnode
//@usage Cnode item(anotherCnode); or passing a Cnode object by value
Cnode::Cnode(const Cnode& rhsCnode)
{
   mleftChild = -1;
   mrightChild = -1;
   mitem = '!';
   operator=(rhsCnode);
}   
   
//@destroys a Cnode
//@pre Cnode object exists
//@post Cnode object does not exist
Cnode:: ~Cnode()
{
   mleftChild = -1;
   mrightChild = -1;   
   mitem = '!';
}
 
//@returns the int of the leftChild or index
//@pre Cnode exists
//@post returns mleftChild
//@usage left = item.GetLeft();    
int Cnode::GetLeft()
{
   return mleftChild;
} 
  
//@returns the int of the rightChild or index
//@pre Cnode exists
//@post returns mrightChild
//@usage right = item.GetRight(); 
int Cnode::GetRight()
{
   return mrightChild;
}

//@adds item into the Cnode
//@pre item is a ItemType
//@post mitem in Cnode contains an appropriate ItemType
//@param item
//@usage node.SetItem(item);
void Cnode::SetItem(ItemType item)
{
   mitem = item;
}
   
//@sets the index of the right Child of Cnode
//@pre right is a int to be placed in the existing Cnodes mrightChild
//@post mrightChild is set
//@param right
//@usage Cnode.SetRight(right);
void Cnode::SetRight(int right)
{
   mrightChild = right;  
}
   
//@sets the index of the left Child of Cnode
//@pre left is a int to be placed in the existing Cnodes mleftChild
//@post mleftChild is set
//@param left
//@usage Cnode.SetRight(left);
void Cnode::SetLeft(int left)
{
   mleftChild = left;
}  
   
//@returns an itemtype of a cnode
//@pre cnode exists
//@post returns itemType of mitem
//@usage item = index.GetItem();  
ItemType Cnode::GetItem()
{
   return mitem;
}  
 
//@copies the Cnode
//@pre rhsCnode exists. Cnode object exists with same amount of memory
//@post Cnode object is a copy of rhsCnode
//@param rhsCnode
//@usage cpyq.operator=(rhsCnode);
//@      or        cpyq = rhsCnode;
Cnode& Cnode::operator=(const Cnode& rhsCnode)
{
   if (this != &rhsCnode)
   {
      mleftChild = rhsCnode.mleftChild;
      mrightChild = rhsCnode.mrightChild;
	   mitem = rhsCnode.mitem; 
   }
   return *this;
}
