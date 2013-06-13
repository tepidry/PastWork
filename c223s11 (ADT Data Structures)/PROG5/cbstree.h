//@author Ryan Draper (draper)
//@date Feb 27 2011
//@file cbstree.h

//@Specification for ADT cbstree
//@   data object: a derived class of cbintree that is a binary tree that is either empty or in the form: 
//                          mroot       where TreeLeft and TreeRight are binary trees
//                        /       \
//                  TreeLeft     TreeRight
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
   //@param: tkey
   //        rest
   //@usage: bst.retrieve (key, rest);
   void retrieve (const Ckey& tkey, Citem& rest) const
      throw (cexception);

   // inserts a new item into the binary search tree
   // pre: newItem has been assigned
   // post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree and 
   //         mnumItems is incremented by one
   //       else an exception is thrown
   // param: newItem
   // usage: tree.insert(item);   
   void insert (const Citem& newItem) throw (cexception);
   
   //calls recursive helper for cbintree and outputs data member mnumitems
   //pre cbstree exists
   //post outputs to scree inorder list of citems and mnumIitems
   //usage tree.inorderTraverse();
   void inorderTraverse();
   
   //outputs the cbintree and mnumitems to a file
   //pre outfile is a open file 
   //post outfile has been written too.
   //param outfile
   //usage tree.outputTree(outfile);
   void outputTree(ofstream& outfile);
   
   //takes infrom a file a binary tree starting with the mnumItems
   //pre infile is open and cbstree exists
   //post cbstree has bee read from the file and so has mnumItems  so that 
   //     a complete binary tree of minimum height has been created
   //param infile
   //usage tree.rebalance(infile);
   void rebalance(ifstream& infile);

protected:  // recursive helper functions

   //@writes a tree to a file
   //@pre treeptr points to a binary tree and outfile is open and ready to be written to
   //@post treeptr has been read into outfile
   //@param treeptr
   //       outfile
   //@usage writeTree(mroot, outfile);
   void writeTree(const Cnode* treeptr, ofstream& outfile);
   
   //@reads from a file to make a tree
   //@pre treeptr points to a binary tree infile is a open file ready to be read from to
   //     index references the count of items in the tree
   //@post tree has been read from file and balanced to a tree of minimum height.
   //@usage readTree(mroot, infile, mnumcount);
   void readTree(Cnode*& treeptr, ifstream& infile, int index);
   
   //@recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for the key in the tree with treeptr's root.
   //    If the key is found, rest is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@param: treeptr
   //        tkey
   //        rest
   //@usage: retrieveItem (mroot, key, rest);
   void retrieveHelper (Cnode* treeptr, const Ckey& tkey,
                      Citem& rest) const throw (cexception);

   // inserts a new item into the binary search tree
   // pre: treepptr is pointing to a part of a existing tree, newItem has been assigned
   // post: if the newItem's key is not already in the tree then the newItem is added 
   //           to the tree and countItem in incremented by one 
   //       else an exception is thrown
   // param: treeptr
   //        newItem
   //        countItem
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
