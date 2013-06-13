//@Implementation for ADT cbstree
//@   data object: a derived class of cbintree that is a binary search tree that is either empty or in the form: 
//          mroot             where TreeLeft and TreeRight are binary search trees and TL is less than
//        /       \           the keys in mroot and those are less then the keys in TR. 
//  TreeLeft     TreeRight
//@   data structure: a linked binary tree with an int for number of items
//@   operations/methods: create, destroy, retrieve, insert, remove(not done)

//@author Ryan Draper (draper)
//@date Feb 23, 2011
//@file cbstree.cpp

#include "cbstree.h"

   // creates a new binary search tree
   // post: an empty binary search tree object exists
   // usage: cbinsrchtree bst;
cbstree:: cbstree(): cbintree()
{
   mnumItems = 0;
}

   // releases memory for a binary search tree
   // pre: binary search tree object exists
   // post: binary search tree object does not exist
   // usage: automatically done at end of score
cbstree:: ~cbstree()
{
   mnumItems = 0;
}

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   // searches for a key in a binary search tree object and
   //    retrieves the corresponding node item
   // pre: key has been assigned.
   // post: rest contains the key with rest of the item if
   //    the key is found in the binary search tree object
   //    else an exception is thrown
   //@param: tkey
   //        rest
   // usage: bst.retrieve (key, rest);
void cbstree::retrieve (const Ckey tkey, Citem& rest) const
      throw (cexception)
{
   retrieveHelper (mroot, tkey, rest);
}


   // inserts a new item into the binary search tree
   // pre: newItem has been assigned
   // post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree and 
   //         mnumItems is incremented by one
   //       else an exception is thrown
   // param: newItem
   // usage: tree.insert(item);
void cbstree::Insert (const Citem& newItem) throw (cexception)
{
   insertHelper (mroot, newItem, mnumItems);
}

   //outputs the cbintree and mnumitems to a file
   //pre outfile is a open file 
   //post outfile has been written too.
   //param outfile
   //usage tree.outputTree(outfile);
void cbstree::outputTree(ofstream& outfile)
{
	writeTree(mroot, outfile);
}

   //calls recursive helper for cbintree and outputs data member mnumitems
   //pre cbstree exists
   //post outputs to scree inorder list of citems and mnumIitems
   //usage tree.inorderTraverse();
void cbstree::inorderTraverse ()
{
   inorder (mroot);
   cout << endl << "There are " << mnumItems << " definitions in the list." << endl;
}

   //takes infrom a file a binary tree starting with the mnumItems
   //pre infile is open and cbstree exists
   //post cbstree has bee read from the file and so has mnumItems  so that 
   //     a complete binary tree of minimum height has been created
   //param infile
   //usage tree.rebalance(infile);
void cbstree::rebalance (ifstream& infile)
{
   destroyTree(mroot);
   infile >> mnumItems;
   infile.ignore(100, '\n');
   readTree(mroot, infile, mnumItems);
}

   // recursive helper functions
 
   //@writes a tree to a file
   //@pre treeptr points to a binary tree and outfile is open and ready to be written to
   //@post treeptr has been read into outfile
   //@param treeptr
   //       outfile
   //@usage writeTree(mroot, outfile);
void cbstree::writeTree(const Cnode* treeptr, ofstream& outfile)
{
   if (treeptr != NULL)
   {
      writeTree (treeptr -> mleftptr, outfile);
      outfile <<  treeptr -> mitem; 
      writeTree (treeptr -> mrightptr, outfile);
   }
}

   //@reads from a file to make a tree
   //@pre treeptr points to a binary tree infile is a open file ready to be read from to
   //     index references the count of items in the tree
   //@post tree has been read from file and balanced to a tree of minimum height.
   //@usage readTree(mroot, infile, mnumcount);
void cbstree::readTree(Cnode*& treeptr, ifstream& infile, int index)
{
	Citem item;
   if (index > 0)
   {
      treeptr = new (nothrow) Cnode();
      if (treeptr == NULL)
         throw cexception ("No Memory to make tree");
      readTree(treeptr -> mleftptr, infile, index / 2);
      infile >> treeptr -> mitem;
      readTree(treeptr -> mrightptr, infile, (index - 1) / 2);
   }
}


   // recursively searches (modeling on binary search) for a key
   // pre: treeptr is assigned. newItem is assigned.
   // post: searches for the key in the tree with treeptr's root.
   //    If the key is found, rest is the key together with the other
   //    parts of the item. Else an exception is thrown.
   // param: treeptr
   //        tkey
   //        rest
   // usage: retrieveHelper (mroot, key, rest);
void cbstree::retrieveHelper (Cnode* treeptr, const Ckey& tkey,
                      Citem& rest) const throw (cexception)
{
   if (treeptr == NULL)
      throw cexception ("Cannot retrieve item, it is not in the Dictionary!");
   else if (tkey == treeptr -> mitem)
      rest = treeptr -> mitem;
   else if (tkey < treeptr -> mitem)
      retrieveHelper (treeptr -> mleftptr, tkey, rest);
   else
      retrieveHelper (treeptr -> mrightptr, tkey, rest);
}
   

   // inserts a new item into the binary search tree
   // pre: treepptr is pointing to a part of a existing tree, newItem has been assigned
   // post: if the newItem's key is not already in the tree then the newItem is added 
   //           to the tree and countItem in incremented by one 
   //       else an exception is thrown
   // param: treeptr
   //        newItem
   //        countItem
   // usage: insertHelper (mroot, newItem);
void cbstree::insertHelper (Cnode*& treeptr, const Citem& newItem, int& countItem)
      throw (cexception)
{
   if (treeptr == NULL) {
      treeptr = new (nothrow) Cnode(newItem, NULL, NULL);
      if(treeptr == NULL)
         throw cexception("No more memory in this dictionary to insert item.");
      countItem++;
   } else if (newItem == treeptr-> mitem) {
      throw cexception ("This item is already in the tree insert aborted.");
   } else if (newItem < treeptr -> mitem) {
      insertHelper (treeptr -> mleftptr, newItem, countItem);
   } else {
      insertHelper (treeptr -> mrightptr, newItem, countItem);
   }
}

