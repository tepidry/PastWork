//@ cbintree.cpp   Implementation for ADT Binary Tree
//@    data object is a binary tree.
//@        A binary tree is a tree which is either
//@        (1) empty or
//@        (2) in the form     r
//@                          /   \
//@                         TL    TR
//@            where r is called the root and left and right subtrees
//@            TL and TR are binary trees
//@ operations: create, destroy, add a node, 
//@             prints (preorder, inorder, postorder)
//@
//@ Contract: based on cnode that is based on citem

//@author Ryan Draper(draper)
//@date Feb 9, 2011
//@file cbintree.cpp


#include "cbintree.h"


//@ creates a binary tree
//@ post: binary tree object exists
//@ usage: Cbintree b;
Cbintree::Cbintree()
{
   mroot = -1;
   mfree = 0;
}

//@ destroys a binary tree
//@ pre: binary tree object exists
//@ post: binary tree object does not exist
//@ usage: automatically called at the end of scope
Cbintree::~Cbintree()
{
   mroot = -1;
   mfree = 0;
}

//@ makes a new binary tree as a copy
//@ pre: rhstree exists
//@ post: binary tree object is a copy of rhstree
//@ uses: operator=
//@ usage: Cbintree lhstree(rhstree);
Cbintree::Cbintree(const Cbintree& rhstree)
{
   mroot = -1;
   mfree = 0;
   operator= (rhstree);
}  

//@ member functions pre: binary tree object exists

//@ assigns one binary tree to another one
//@ pre: rhstree exists
//@ post: calling object is a copy of rhstree
//@ usage: atree = btree;
Cbintree& Cbintree::operator= (const Cbintree& rhstree)
{
   if (this != &rhstree)
   {
      mroot = rhstree.mroot;
      mfree = rhstree.mfree;
      for (int i = 0; i < mfree; i++)
      {
         mTree[i] = rhstree.mTree[i];
      }
   }
   return *this
}

//@ adds a node to a binary tree
//@ pre: newNode exists
//@ post: newNode has been added to the tree
//@ usage: b.addNode (thisNode);
void Cbintree::addNode (const Cnode& newNode)
{
   mTree[mfree] = newNode;
   mfree++;  
}

//@ pre: all prints assume the standard output's pointer is
//@       at the beginning of a new line.

//@ prints the nodes in a tree in pre-order
//@ post: if tree object is not empty, displays the node items
//@    in preorder on standard output else does nothing
//@ usage: b.preOrderPrint();
void Cbintree::preOrderPrint ()
{
   cout << "Pre-Order: -> ";
   preorderHelper(mroot);;
}

//@ prints the nodes in a tree in in-order
//@ post: if tree object is not empty, displays the node items
//@    in in-order on standard output else does nothing
//@ usage: b.inOrderPrint();
void Cbintree::inOrderPrint ()
{
   cout << "In-Order:  -> ";
   inorderHelper(mroot);
}

//@ prints the nodes in a tree in post-order
//@ post: if tree object is not empty, displays the node items
//@   in post-order
//@ usage: b.postOrderPrint();
void Cbintree::postOrderPrint()
{
   cout << "Pre-Order: -> ";
   postorderHelper(mroot);
}

//@recursively couts the binary tree in preorder fashion
//@pre subroot is the root of the bin tree to be cout
//@post Cbintree has bee output to the screen in preorder
//@param subroot
//@usage preorderHelper(mroot);
void Cbintree::preorderHelper(int subroot)
{
   if (subroot != -1)
   {
      cout << mTree[subroot].GetItem() << " ";
      preorderHelper(mTree[subroot].GetLeft());
      preorderHelper(mTree[subroot].GetRight());
   }
}
   
//@recursively couts the binary tree in inorder fashion
//@pre subroot is the root of the bin tree to be cout
//@post Cbintree has bee output to the screen in inorder
//@param subroot
//@usage inorderHelper(mroot);
void Cbintree::inorderHelper(int subroot)
{
   if (subroot != -1)
   {
      inorderHelper(mTree[subroot].GetLeft());
      cout << mTree[subroot].GetItem() << " ";
      inorderHelper(mTree[subroot].GetRight());
   }
}
   
//@recursively couts the binary tree in postorder fashion
//@pre subroot is the root of the bin tree to be cout
//@post Cbintree has bee output to the screen in postorder
//@param subroot
//@usage postorderHelper(mroot);
void Cbintree::postorderHelper(int subroot)
{
   if (subroot != -1)
   {
      postorderHelper(mTree[subroot].GetLeft());
      postorderHelper(mTree[subroot].GetRight());
      cout << mTree[subroot].GetItem() << " ";
   }
}
