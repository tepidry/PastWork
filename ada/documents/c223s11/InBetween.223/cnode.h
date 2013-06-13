
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

typedef int Citem;

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
   Cnode (const Citem& leftItem, const Citem& rightItem,const Citem& centerItem,
          Cnode* left,  Cnode* midleft, Cnode* midright, Cnode* right):
          mleft (leftItem), mright (rightItem), mcenter (centerItem), mleftptr (left), 
          mrightptr (right), mleftmidptr (midleft), mrightmidptr (midright) {};

   // implementation of data object
   Citem mleft;
   Citem mright;
   Citem mcenter;
   
   Cnode* mleftptr;
   Cnode* mrightptr;
   Cnode* mrightmidptr;
   Cnode* mleftmidptr;
};

#endif
