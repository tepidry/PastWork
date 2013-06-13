//@Implementation for ADT cbintree
//@   data object: Data object: A binary tree that is either empty or in the form: 
//                          mroot       where TreeLeft and TreeRight are binary trees
//                        /       \
//                  TreeLeft     TreeRight
//@   data structure: a linked binary tree
//    Operations: (a scaled-down version)
//       create, destroy, copy, is empty, operator=, pretty display, Make a tree(testing only)
//       traversals (preorder, inorder, postorder)

//@author Ryan Draper (draper)
//@date Feb. 27, 2011
//@file cbintree.cpp

#include "cbintree.h"

// creates an empty binary tree
// post: object is an empty binary tree
// usage: Cbintree zags;
cbintree::cbintree(): mroot(NULL)
{
}

// creates a new binary tree that is a copy of an existing tree
// post: object is a copy of rhstree
// usage: Cbintree zags (bulldog);
cbintree::cbintree(const cbintree& rhstree): mroot(NULL)
{
   copyTree (mroot, rhstree.mroot);
}

// releases the memory of a binary tree
// pre: object exists
// post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
cbintree:: ~cbintree()
{
   destroyTree (mroot);
}

// ******************** member functions ********************************************
// pre: binary tree object exists
// **********************************************************************************
// post: returns true if the object is empty; else returns false
// usage: if (tree.isEmpty())
bool cbintree::isEmpty() const
{
   return (mroot == NULL);
}

// pre: rhstree is an assigned tree.
// post: object is a copy of rhstree
// usage: atree = btree = ctree;
cbintree& cbintree::operator=(const cbintree& rhstree)
{
   if (this != &rhstree)
   {
      destroyTree (mroot);
      copyTree (mroot, rhstree.mroot);
   }
   return *this;
}  

//@prints the tree to look like a computer science tree
//@post: outputs the tree as in the example below
//
//                        bar
//                      /
//                  foo
//                 /    \   
//  root ->  queue       geeU
//                 \       stack
//                  list
//                        array
//@nodes at the same level are indented the same.
//@Viewer must rotate head 90 degrees in order to look like a cs tree
//@usage: tree.prettyDisplay();
void cbintree::prettyDisplay(ofstream& outfile)
{
   int level = 1;
   
   if (mroot != NULL) {
      writePretty (mroot, outfile, level);
   } else {
      outfile << "root -> Empty!" << endl;
   }
}

// *************** on the following traversals
// uses: operator<< from citem
// post: prints the objects in the tree in order specified
// usage: tree.preorderTraverse();  
// similarly for the other traversals
// *****************************************************
void cbintree::preorderTraverse ()
{
   cout << "Pre-Order:" << endl;
   preorder (mroot);
}

void cbintree::inorderTraverse ()
{
   cout << "In-Order:" << endl;
   inorder (mroot);
}
   
void cbintree::postorderTraverse()
{
   cout << "Post-Order" << endl;
   postorder (mroot);
}

// makes a tree for testing purposes. You may add a file parameter
// post: the tree is a full tree of height 3 with minimum of five in sorted order.
// param: infile
// usage: mytree.makeTree();
void cbintree:: makeTreeOne(ifstream& infile)
{
   Citem item;
   infile >> item;
   mroot = new (nothrow) Cnode(item, NULL, NULL);
   infile >> item;
   mroot -> mrightptr = new (nothrow) Cnode(item, NULL, NULL);
   infile >> item;
   mroot -> mleftptr = new (nothrow) Cnode(item, NULL, NULL);
   infile >> item;
   mroot -> mleftptr -> mrightptr = new (nothrow) Cnode(item, NULL, NULL);
   infile >> item;
   mroot -> mleftptr -> mleftptr = new (nothrow) Cnode(item, NULL, NULL);
}

// helper functions for coding member functions
// Copies one binary tree to another
// pre: oldtreep points to the root of a binary tree
// post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
// param: newtreeep
//        oldtreep
// usage: copyTree (newptr, oldptr);
void cbintree::copyTree (Cnode*& newtreep, Cnode* oldtreep) 
{
   if (oldtreep == NULL)
   {
      newtreep = NULL;
   }
   else
   {
      // preorder traversal
      newtreep = new Cnode(oldtreep -> mitem, NULL, NULL);
      newtreep -> mbalance = oldtreep -> mbalance;
      copyTree (newtreep -> mleftptr, oldtreep -> mleftptr);
      copyTree (newtreep -> mrightptr, oldtreep -> mrightptr);
   }
}

// Releases memory for a binary tree
// pre: treep points to the root of a binary tree
// post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
// param: treep
// usage: destroyTree (mroot);
void cbintree::destroyTree (Cnode*& treep)
{
   // do a postorder traversal
   if (treep != NULL)
   {
      destroyTree (treep -> mleftptr);
      destroyTree (treep -> mrightptr);
      delete treep;
      treep = NULL;
   }
}

//@Prints a binary tree on its side with the root to the far left
//@pre a pointer to the root of the tree and a int is passed
//@post recursively the tree is printed to the screen
//@param treep
//@param level
//@usage writePretty(mroot, level);
void cbintree::writePretty (const Cnode* treep, ofstream& outfile, int level)
{
   if (treep != NULL)
   {
      //backward inorder
      writePretty(treep -> mrightptr, outfile, level +1);
      if (treep -> mrightptr != NULL)
         outfile << right << setw(6 * level + 2) << "/" << endl;
      if (level == 1){
         outfile << "root-> " << treep -> mitem << endl;
         outfile << right << setw(8) << treep -> mbalance << endl;
      }else{ 
         outfile << right << setw(6 * level) << treep -> mitem << endl;
         outfile << right << setw(6 * level) << treep -> mbalance << endl;
      }
      if (treep -> mleftptr != NULL)
         outfile << right << setw(6 * level + 2) << "\\" << endl;
      writePretty(treep-> mleftptr, outfile, level + 1);
   }
}
    
// ********** recursive helpers for the traversals ****************
// pre: treep points to the root of a binary tree to be traversed
// post: prints the objects of the nodes on the screen in the
// specified order
// param: tree
// usage: preorder (mroot);   
//    similarly for the others
void cbintree::preorder (Cnode* treep)
{
   if (treep != NULL)
   {
      cout <<  treep -> mitem << endl;
      preorder (treep -> mleftptr);
      preorder (treep -> mrightptr);
   }
}

void cbintree::inorder (Cnode* treep)
{
   if (treep != NULL)
   {
      inorder (treep -> mleftptr);
      cout <<  treep -> mitem << endl; 
      inorder (treep -> mrightptr);
   }
}

void cbintree::postorder (Cnode* treep)
{
   if (treep != NULL)
   {
      postorder (treep -> mleftptr);
      postorder (treep -> mrightptr);
      cout <<  treep -> mitem << endl;
   }
}

