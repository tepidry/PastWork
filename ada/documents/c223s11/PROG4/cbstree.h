//@author Ryan Draper (draper)
//@date Feb 27 2011
//@file cbstree.h

//@Specification for ADT cbstree
//@   data object: a inherited binary tree that holds items and keys of a dictionary
//@   operations/methods: create, destroy, retrieve, insert, remove(not done)


#include "cbintree.h"
#include "cnode.h"
#include "citem.h"
#include "ckey.h"
#include "cexception.h"

class cbstree: public cbintree
{
public:
   //@creates a new binary search tree
   //@post: an empty binary search tree object exists
   //@usage: cbstree bst;
   cbstree();

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of score
   ~cbstree();

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@searches for a key in a binary search tree object and
   //    retrieves the corresponding node item
   //@pre: key has been assigned.
   //@post: rest contains the key with rest of the item if
   //    the key is found in the binary search tree object
   //    else an exception is thrown
   //@usage: bst.retrieve (key, rest);
   void retrieve (const Ckey& tkey, Citem& rest) const
      throw (cexception);

   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: you do
   void insert (const Citem& newItem) throw (cexception);

protected:  // recursive helper functions
   //@recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for the key in the tree with treeptr's root.
   //    If the key is found, rest is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: retrieveItem (mroot, key, rest);
   void retrieveHelper (Cnode* treeptr, const Ckey& tkey,
                      Citem& rest) const throw (cexception);

   // inserts a new item into the binary search tree
   // pre: treepptr is pointing to a part of a existing tree, newItem has been assigned
   // post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   // usage: insertHelper (mroot, newItem);
   void insertHelper (Cnode*& treeptr, const Citem& newItem, int& countItem)
      throw (cexception);
      
   // removes the assigned key from the tree if found
   // pre: treepptr is pointing to a part of a existing tree, tkey is the item to be removed
   // post: if the tkey is in the tree the it is removed
   //       else an exception is thrown
   // usage: removeHelper (mroot, key);   
   //void removeHelper (Cnode*& treeptr, const Ckey& tkey)
      //throw (cexception);
      
   //data member
   int mnumItems;
   

};
