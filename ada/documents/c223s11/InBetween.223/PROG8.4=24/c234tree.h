//@author Ryan Draper (draper)
//@date April 14, 2011
//@file c234tree.h

//@ADT 2-3-4 Tree:
//@Specification of a 2-3-4 Tree
//@   data object: T is a 2-3-4 tree of height h if 
//@                1. T is empty (a 2-3-4 tree of height 0), or
//@					 2. T is in the form:   
//@                   r     where r is a node that contains one data item, and TL and TR are both
//@                 /   \    2-3-4 trees, each of height h-1. And TL < r < TR.
//@                TL    TR   
//@                3. T is in the form:
//@                   r     where r contains 2 ascending data items, and; TL, TR, and TM are 2-3-4 trees
//@               /   |   \     each of height h-1. where TL < smaller r < TM < bigger r < TR
//@              TL  TM   TR
//@                4. T is in the form:
//@                _ _r_ _  where r contains 3 ascending data items, and; TL, TML, TMR, and TR are all 2-3-4 trees of
//@              /  |   |  \    h-1. where TL < smaller r < TML < middle r < TMR < biggest r < TR.
//@           TL, TML, TMR, TR   
//@                And, the keys or items obey properties that is a generalization of a binary search tree.
//@
//@   operations: four constructors, copy, deconstructor, operator=, recyclenode,
//@               isempty, isfull


#ifndef C234TREE_H
#define C234TREE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "c234node.h"

using namespace std;


class C234tree
{
public:

   //@creates an empty 234 tree
   //@post: object is an empty 234 tree
   //@usage: C234tree awesomeDataStructure;
   C234tree();

   //@creates a new 234 tree that is a copy of an existing 234 tree
   //@post: object is a copy of rhs234tree
   //@param rhs234tree
   //@usage: C234tree awesomeDataStructure (sweet);
   C234tree(const C234tree& rhs234tree);

   //@releases the memory of a 234 tree
   //@pre: object exists
   //@post: memory for the object has been released. object has been deleted
   ~C234tree();

   // ******************** member functions ********************************************
   //@pre: 234 tree object exists
   // **********************************************************************************

   //@Inserts into the tree a new item
   //@pre newItem is a Citem
   //@post a 234 tree object 
   //@param newItem
   //@usage tree.Insert(newItem);
   void Insert(const Citem& newItem) 
   	throw (cexception);
   
   //@delets a item from the tree
   //@post a 234 tree object
   //@param treeItem
   //@usage tree.Delete(treeItem);	
   void DeleteItem(const Citem& treeItem)
   	throw (cexception);
   	
   //@searches for a item in the 234 tree object and
   //@   returns a bool if in tree
   //@pre: item has been assigned.
   //@post: if item is in tree return true, else false
   //@param: item
   // usage: if(tree.InTree(item);
	bool InTree (const Citem item) const;

   //@checks for an empty tree
   //@post: returns true if the object is empty; else returns false
   //@return: true if object is empty; false if object is not
   //@usage: if (tree.isEmpty())
   bool IsEmpty() const;

   //@copies one tree to another
   //@pre: rhstree is an assigned tree.
   //@post: object is a copy of rhstree
   //@param rhstree
   //@usage: atree = btree = ctree;
   C234tree& operator=(const C234tree& rhstree);

   //@writes the tree to look like a computer science tree into a file
   //@post: outputs the tree as in the example below
   //
   //                        bar
   //                  foo
   //                        geeU
   //  root ->  queue
   //                        stack
   //                  list
   //                        array
   //@nodes at the same level are indented the same.
   //@Viewer must rotate head 90 degrees in order to look like a cs tree
   //@param outfile
   //@usage: tree.WriteTree(outfile);
   void WriteTree(ofstream& outfile);

   //@prints the tree to look like a computer science tree
   //@post: outputs the tree as in the example below
   //
   //                        bar
   //                  foo
   //                        geeU
   //  root ->  queue
   //                        stack
   //                  list
   //                        array
   //@nodes at the same level are indented the same.
   //@Viewer must rotate head 90 degrees in order to look like a cs tree
   //@usage: tree.DisplayTree();
   void DisplayTree();

   
protected:
   
   //@writes a tree to a file
   //@pre treeptr points to a 234 tree and outfile is open and ready to be written to
   //@post treeptr has been read into outfile
   //@param treeptr
   //       outfile
   //@usage writeTree(mroot, outfile);
   void writeTree(const C234node* treeptr, ofstream& outfile);
   
   //@Prints a 234 tree on its side with the root to the far left
   //@pre a pointer to the root of the tree and a int is passed
   //@post recursively the tree is printed to the screen
   //@param treep
   //@param level
   //@usage writePretty(mroot, level);
   void writePretty (C234node* treep, int level);
   
   // helper functions for coding member functions
   // Copies one 234 tree to another
   // pre: oldtreep points to the root of a 234 tree
   // post: newtreep points to the root of a 234 tree
   //  that has copies of the nodes of oldtreep's tree
   // param: newtreeep
   //        oldtreep
   // usage: copyTree (newptr, oldptr);
   void copyTree (C234node*& newtreep, C234node* oldtreep);
   
   //@Releases memory for a binary tree
   //@pre: treep points to the root of a 234 tree
   //@post: releases all of the nodes in the tree pointed to by treep
   //    and leaves treep empty.
   //@param treep
   //@usage: destroyTree (mroot);
   void destroyTree (C234node*& treep);

   //@splits the node into three where the middle item and the left and right items are now 
   //@the analogous children of it
   //@pre node is full and must be split
   //@post the single node has been split into 3 nodes each with a single item from the original
   //@     where the middle item is the parent of the other two.
   //@param
   //@usage branchIndex.Split();
   void split(C234node*& currentPtr, const Citem& newItem)
      throw (cexception);
   
   //@Inserts into the tree a new item
   //@pre newItem is a Citem
   //@post a 234 tree object 
   //@param newItem
   //@usage insertHelper(mroot, newItem);
   void insertHelper (C234node*& treeptr, const Citem& newItem)
      throw (cexception);
      
   // recursively searches (modeling on binary search) for a item in the 234 tree
   // pre: treeptr is assigned. newItem is assigned.
   // post: searches for the key in the tree with treeptr's root.
   //    If the item is found return true else false,
   // param: treeptr
   //        item
   // usage: retrieveHelper (mroot, newItem);
   bool retrieveHelper (C234node* treeptr, const Citem item) const;

	C234node* mparent;
   C234node* mroot;

};
#endif
