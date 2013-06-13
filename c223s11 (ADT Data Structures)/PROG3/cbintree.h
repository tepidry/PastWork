//@author Ryan Draper(draper)
//@date Feb 9, 2011
//@file cbintree.h

//@ cbintree.h   Specification for ADT Binary Tree
//@     data object is a binary tree.
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

#ifndef CBINTREE_H
#define CBINTREE_H
  
#include <new>
#include <iostream>   
#include "cnode.h"  

using namespace std;
const int MAXNODES = 15;

class Cbintree
{
   
public:
   //@ creates a binary tree
   //@ post: binary tree object exists
   //@ usage: Cbintree b;
   Cbintree();

   //@ destroys a binary tree
   //@ pre: binary tree object exists
   //@ post: binary tree object does not exist
   //@ usage: automatically called at the end of scope
   ~Cbintree();

   //@ makes a new binary tree as a copy
   //@ pre: rhstree exists
   //@ post: binary tree object is a copy of rhstree
   //@ uses: operator=
   //@ usage: Cbintree lhstree(rhstree);
   Cbintree(const Cbintree& rhstree);  

   //@ member functions pre: binary tree object exists

   //@ assigns one binary tree to another one
   //@ pre: rhstree exists
   //@ post: calling object is a copy of rhstree
   //@ usage: atree = btree;
   Cbintree& operator= (const Cbintree& rhstree);

   //@ adds a node to a binary tree
   //@ pre: newNode exists
   //@ post: newNode has been added to the tree
   //@ usage: b.addNode (thisNode);
   void addNode (const Cnode& newNode);

   //@ pre: all prints assume the standard output's pointer is
   //@       at the beginning of a new line.

   //@ prints the nodes in a tree in pre-order
   //@ post: if tree object is not empty, displays the node items
   //@    in preorder on standard output else does nothing
   //@ usage: b.preOrderPrint();
   void preOrderPrint ();

   //@ prints the nodes in a tree in in-order
   //@ post: if tree object is not empty, displays the node items
   //@    in in-order on standard output else does nothing
   //@ usage: b.inOrderPrint();
   void inOrderPrint ();

   //@ prints the nodes in a tree in post-order
   //@ post: if tree object is not empty, displays the node items
   //@   in post-order
   //@ usage: b.postOrderPrint();
   void postOrderPrint ();

private:
   //@recursively couts the binary tree in preorder fashion
   //@pre subroot is the root of the bin tree to be cout
   //@post Cbintree has bee output to the screen in preorder
   //@param subroot
   //@usage preorderHelper(mroot);
   void preorderHelper(int subroot);
   
   //@recursively couts the binary tree in inorder fashion
   //@pre subroot is the root of the bin tree to be cout
   //@post Cbintree has bee output to the screen in inorder
   //@param subroot
   //@usage inorderHelper(mroot);
   void inorderHelper(int subroot);
   
   //@recursively couts the binary tree in postorder fashion
   //@pre subroot is the root of the bin tree to be cout
   //@post Cbintree has bee output to the screen in postorder
   //@param subroot
   //@usage postorderHelper(mroot);
   void postorderHelper(int subroot);

   Cnode mTree [MAXNODES];
   int mroot;
   int mfree;
};
#endif
