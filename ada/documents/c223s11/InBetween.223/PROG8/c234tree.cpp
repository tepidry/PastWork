//@ADT 2-3-4 Tree:
//@Implementation of a 2-3-4 Tree
//@   data structure: a linked 234 tree where the items obey properties that is a generalization of a binary search tree.
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
//@   operations: constructor, copy, deconstructor, operator=,
//@               isempty, isfull

//@author Ryan Draper (draper)
//@date April 14, 2011
//@file c234tree.cpp


#include "c234tree.h"

using namespace std;

//@creates an empty 234 tree
//@post: object is an empty 234 tree
//@usage: C234tree awesomeDataStructure;
C234tree::C234tree()
{
   mroot = NULL;
   mparent = NULL;
}

//@creates a new 234 tree that is a copy of an existing 234 tree
//@post: object is a copy of rhs234tree
//@param rhs234tree
//@usage: C234tree awesomeDataStructure (sweet);
C234tree::C234tree(const C234tree& rhs234tree)
{
   destroyTree(mroot);
   operator=(rhs234tree);
   mparent = mroot;
}

//@releases the memory of a 234 tree
//@pre: object exists
//@post: memory for the object has been released. object has been deleted
C234tree::~C234tree()
{
   destroyTree(mroot);
   mparent = mroot;
}

// ******************** member functions ********************************************
//@pre: 234 tree object exists
// **********************************************************************************
   

//@Inserts into the tree a new item
//@pre newItem is a Citem
//@post a 234 tree object 
//@param newItem
//@usage tree.Insert(newItem);
void C234tree::Insert(const Citem& newItem) 
   throw (cexception)
{
   insertHelper(mroot, newItem);
   mparent = mroot;
}
      
//@delets a item from the tree
//@post a 234 tree object
//@param treeItem
//@usage tree.Delete(treeItem);	
void C234tree::DeleteItem(const Citem& treeItem)
   throw (cexception)
{
   
}
   	
//@searches for a item in the 234 tree object and
//@   returns a bool if in tree
//@pre: item has been assigned.
//@post: if item is in tree return true, else false
//@param: item
// usage: if(tree.InTree(item);
bool C234tree::InTree (const Citem item) const
{
   return (retrieveHelper(mroot, item));
}

//@checks for an empty tree
//@post: returns true if the object is empty; else returns false
//@return: true if object is empty; false if object is not
//@usage: if (tree.isEmpty())
bool C234tree::IsEmpty() const
{
   return (mroot == NULL);
}

//@copies one tree to another
//@pre: rhstree is an assigned tree.
//@post: object is a copy of rhstree
//@param rhstree
//@usage: atree = btree = ctree;
C234tree& C234tree::operator=(const C234tree& rhstree)
{
   if (this != &rhstree)
   {
      destroyTree(mroot);
	   copyTree (mroot, rhstree.mroot);
   }
   return *this;
   
}

//@
void C234tree::WriteTree(ofstream& outfile)
{

}

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
//@usage: tree.prettyDisplay();
void C234tree::DisplayTree()
{
   writePretty(mroot, 1);
}

//@writes a tree to a file
//@pre treeptr points to a binary tree and outfile is open and ready to be written to
//@post treeptr has been read into outfile
//@param treeptr
//       outfile
//@usage writeTree(mroot, outfile);
void C234tree::writeTree(const C234node* treeptr, ofstream& outfile)
{

}

//@Prints a binary tree on its side with the root to the far left
//@pre a pointer to the root of the tree and a int is passed
//@post recursively the tree is printed to the screen
//@param treep
//@param level
//@usage writePretty(mroot, level);
void C234tree::writePretty (C234node* treep, int level)
{
   if (treep != NULL)
   {
      //backward inorder
      writePretty(treep -> mptrs[0], level +1);
      writePretty(treep -> mptrs[1], level + 1);
      /*if (treep -> mrightptr != NULL)
         cout << right << setw(10 * level + 5) << "/" << endl;/**/
      if (level == 1){
         cout << left << setw(7 * level) << "root->" << (*treep) << endl;
      }else{ 
         cout << right << setw(10 * level) << (*treep) << endl;
      }
      /*if (treep -> mleftptr != NULL)
         cout << right << setw(10 * level + 5) << "\\" << endl;/**/
      writePretty(treep -> mptrs[2], level +1);
      writePretty(treep -> mptrs[3], level + 1);
   }
}


// helper functions for coding member functions
// Copies one 234 tree to another
// pre: oldtreep points to the root of a 234 tree
// post: newtreep points to the root of a 234 tree
//  that has copies of the nodes of oldtreep's tree
// param: newtreeep
//        oldtreep
// usage: copyTree (newptr, oldptr);
void C234tree::copyTree (C234node*& newtreep, C234node* oldtreep) 
{
   if (oldtreep == NULL)
      newtreep = NULL;
   else
   {
      // preorder traversal
      newtreep = new  C234node (oldtreep -> mdata[0], oldtreep -> mdata[1], oldtreep -> mdata[2], NULL, NULL, NULL, NULL);
      copyTree (newtreep -> mptrs[0], oldtreep -> mptrs[0]);
      copyTree (newtreep -> mptrs[1], oldtreep -> mptrs[1]);
      copyTree (newtreep -> mptrs[2], oldtreep -> mptrs[2]);
      copyTree (newtreep -> mptrs[3], oldtreep -> mptrs[3]);
   }
}

//@Releases memory for a binary tree
//@pre: treep points to the root of a binary tree
//@post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//@param treep
//@usage: destroyTree (mroot);
void C234tree::destroyTree (C234node*& treep)
{
   // do a postorder traversal
   if (treep != NULL)
   {
      destroyTree (treep -> mptrs[0]);
      destroyTree (treep -> mptrs[1]);
      destroyTree (treep -> mptrs[2]);
      destroyTree (treep -> mptrs[3]);
      //delete [] treep -> mptrs;
      for (int i = 0; i < MAXITEMS; i++)
         treep -> mptrs[i] = NULL;
      
   }

}

//@splits the node into three where the middle item and the left and right items are now 
//@the analogous children of it
//@pre node is full and must be split mparent points to either itself if its the root or to 
//@    the node above this one mchild points to currentpointer.
//@post the single node has been split into 3 nodes each with a single item from the original
//@     where the middle item is the parent of the other two.
//@param
//@usage branchIndex.Split();
void C234tree::split(C234node*& currentPtr, const Citem& newItem)
   throw (cexception)
{
   C234node* leftChild; 
   C234node* rightChild;
   C234node* newRight;
   
   int indexPlacement;
   Citem parentItem, rightItem; 
   cout << "here"; 
   (*currentPtr).CopyRightItems(parentItem, rightItem);
   cout << parentItem << " " << rightItem;
   
   leftChild = (*currentPtr).ReturnPtr(2);
   rightChild = (*currentPtr).ReturnPtr(3);
   
   cout << "2";
   (*currentPtr).RecycleNode();
   cout << "3";
   newRight = new (nothrow) C234node(rightItem, leftChild, rightChild);
   if(newRight == NULL)
      throw cexception("C234tree Split, Insert:: No more memory to split items or create more nodes tree.");
      
   if(currentPtr == mroot)                
   {
      mroot = new (nothrow) C234node(parentItem, currentPtr, newRight); 
      if(mroot == NULL)
         throw cexception("C234tree Split, Insert:: No more memory to split items or create more nodes tree.");              
      mroot = mparent;                    
   } else {                             
      indexPlacement = (*mparent).Insert(parentItem);
      (*mparent).AdjustParentsPtrs(indexPlacement);
      (*mparent).ConnectPtr(indexPlacement, currentPtr);
      (*mparent).ConnectPtr(indexPlacement + 1, newRight);
   }    
/**/
}

//@Inserts into the tree a new item
//@pre newItem is a Citem
//@post a 234 tree object 
//@param newItem
//@usage insertHelper(mroot, newItem);
void C234tree::insertHelper (C234node*& treeptr, const Citem& newItem)
   throw (cexception)
{
   cout << "insert";
   if (treeptr == NULL) {
      treeptr = new (nothrow) C234node(newItem, NULL, NULL);
      if(treeptr == NULL)
         throw cexception("C234tree Insert:: No more memory in to insert item into this tree.");
   } else {
      C234node* indexBranch = treeptr;
      C234node* child = treeptr;
      
      while ((*indexBranch).IsNotLeaf())  
      {
         cout << "while";
         if ((*indexBranch).IsFull())
         {
            cout << "while full";
            //split(indexBranch, newItem);
            mparent = indexBranch;
            child = (*mparent).GetNextChild(newItem);
            indexBranch = child;
            
         } else {
            mparent = indexBranch;
            child = (*mparent).GetNextChild(newItem);
            indexBranch = child;
               
         }
      }
      if ((*indexBranch).IsFull())
      {
         cout << "here";
         //split(indexBranch, newItem);
         child = (*mparent).GetNextChild(newItem);
         indexBranch = child;
      }
      if ((*indexBranch).IsInNode(newItem))
      {
         throw cexception ("C234tree Insert:: This item is already in the tree insert is not possible.");
      } else {
         (*indexBranch).Insert(newItem);
      }
   }

}

// recursively searches (modeling on binary search) for a item
// pre: treeptr is assigned. newItem is assigned.
// post: searches for the key in the tree with treeptr's root.
//    If the item is found return true else false,
// param: treeptr
//        item
// usage: retrieveHelper (mroot, newItem);
bool C234tree::retrieveHelper (C234node* treeptr, const Citem item) const 
{
   while ((*treeptr).IsNotLeaf())
   {
      if ((*treeptr).IsInNode(item))
         return true;
      else 
         treeptr = (*treeptr).GetNextChild(item);
   }
   return ((*treeptr).IsInNode(item));
}



