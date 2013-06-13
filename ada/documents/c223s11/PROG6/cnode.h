
// ADT Binary Tree Node:
// Spec and implementation file
//    data object: a node for a dynamic binary tree
//    operations: two constructors
// Friend classes: cbintree, cbstree, cavltree
// Contract: the items for the node are found in cKey which typedefed to handle Citem


#ifndef CNODE_H
#define CNODE_H


#include <cstddef>

using namespace std;

typedef Ckey Citem;

class Cnode
{
protected:

   // creates a node
   // post: the item of the node is empty, the kids are NULL and a mbalance is 0.
   // usage: newptr = new cnode();
   Cnode():mleftptr(NULL),mrightptr(NULL),mleftmidptr(NULL),mrightmidptr(NULL),mleft(0),mright(0),mcenter(0) {};

   // creates a node with a given item and kids
   // post: the item of the node is nodeItem, the kids are left and right, mbalance is balance
   // usage:aptr = new  cnode (thisone, NULL, NULL);
   // CAUTION: REQUIRES THAT COPY WORKS IN CITEM!!
   Cnode (const Citem& nodeItem, 
          Cnode* left, Cnode* right):
          mitem (nodeItem), mbalance(0), mleftptr (left), mrightptr (right) {};

   // implementation of data object
   Citem mitem;
   int mleft;
   int mright;
   int mcenter;
   
   Cnode* mleftptr;
   Cnode* mrightptr;
   Cnode* mrightmidptr;
   Cnode* mleftmidptr;

   friend class cbintree;
   friend class cbstree;
   friend class cavltree;
};

#endif
