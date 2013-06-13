//@Implementation for ADT cbstree
//@   data object: a inherited binary tree that holds items and keys of a dictionary
//@   data structure: a number that keeps count of items in the inherited tree
//@   operations/methods: create, destroy, retrieve, insert, remove(not done)

//@author Ryan Draper (draper)
//@date Feb 23, 2011
//@file cbstree.cpp

#include "cbstree.h"

   // creates a new binary search tree
   // post: an empty binary search tree object exists
   // usage: cbinsrchtree bst;
cbstree:: cbstree(): cbintree()
{}

   // releases memory for a binary search tree
   // pre: binary search tree object exists
   // post: binary search tree object does not exist
   // usage: automatically done at end of score
cbstree:: ~cbstree()
{}

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   // searches for a key in a binary search tree object and
   //    retrieves the corresponding node item
   // pre: key has been assigned.
   // post: rest contains the key with rest of the item if
   //    the key is found in the binary search tree object
   //    else an exception is thrown
   // usage: bst.retrieve (key, rest);
void cbstree::retrieve (const Ckey& tkey, Citem& rest) const
      throw (cexception)
{
   retrieveHelper (mroot, tkey, rest);
}

   // inserts a new item into the binary search tree
   // pre: newItem has been assigned
   // post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   // usage: tree.insert(item);
void cbstree::insert (const Citem& newItem) throw (cexception)
{
   insertHelper (mroot, newItem, mnumItems);
}

   // removes an item from a binary search tree
   // pre: tkey has been assigned
   // post: if tkey is found in the tree, its corresponding item
   //       is removed otherwise an exception is thrown
   // usage: tree.remove(key);
//void cbstree::remove (const Ckey& tkey) throw (cexception)
//{
   //removeHelper (mroot, tkey);
//}

   // recursive helper functions
 
   // recursively searches (modeling on binary search) for a key
   // pre: treeptr is assigned. newItem is assigned.
   // post: searches for the key in the tree with treeptr's root.
   //    If the key is found, rest is the key together with the other
   //    parts of the item. Else an exception is thrown.
   // usage: retrieveHelper (mroot, key, rest);
void cbstree::retrieveHelper (Cnode* treeptr, const Ckey& tkey,
                      Citem& rest) const throw (cexception)
{
   if (treeptr == NULL)
      throw cexception ("in retrieve: key has not been found! " );
   else if (tkey == treeptr -> mitem)
      rest = treeptr -> mitem;
   else if (tkey < treeptr -> mitem)
      retrieveHelper (treeptr -> mleftptr, tkey, rest);
   else
      retrieveHelper (treeptr -> mrightptr, tkey, rest);
}
   

   // inserts a new item into the binary search tree
   // pre: treepptr is pointing to a part of a existing tree, newItem has been assigned
   // post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   // usage: insertHelper (mroot, newItem);
void cbstree::insertHelper (Cnode*& treeptr, const Citem& newItem, int& countItem)
      throw (cexception)
{
   if (treeptr == NULL) {
      treeptr = new (nothrow) Cnode(newItem, NULL, NULL);
      if(treeptr == NULL)
         throw cexception("New Item: no memory to assign item");
      countItem++;
   } else if (newItem == treeptr-> mitem) {
      throw cexception ("Item in tree: key has not been found! " );
   } else if (newItem < treeptr -> mitem) {
      insertHelper (treeptr -> mleftptr, newItem, countItem);
   } else {
      insertHelper (treeptr -> mrightptr, newItem, countItem);
   }
}

   // removes the assigned key from the tree if found
   // pre: treepptr is pointing to a part of a existing tree, tkey is the item to be removed
   // post: if the tkey is in the tree the it is removed
   //       else an exception is thrown
   // usage: removeHelper (mroot, key); 
//void cbstree::removeHelper (cnode*& treeptr, const Ckey& tkey)
      //throw (cexception)
//{
   //if (treeptr == NULL) {
     // throw cexception ("Item not in tree: key cannot be removed! " );
   //}else if (tkey == treeptr-> mitem) {
      //work on here
   //} else if (newItem < treeptr -> mitem) {
      //removeHelper (treeptr -> mleftptr, newItem);
   //}else
      //removeHelper (treeptr -> mrightptr, newItem);
   //}
//}
