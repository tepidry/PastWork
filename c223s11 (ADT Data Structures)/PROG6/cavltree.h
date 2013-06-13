//@author Ryan Draper (draper)
//@date March 22 2011
//@file cavltree.h

//@Specification for ADT cavltree (Adelson, Velski, & Landis)
//@   data object: a derived class of cbintree and cbstree that is a binary tree that 
//@                is either empty or in the form: 
//                          mroot       such that {|hR- hL| <= 1, hR is the height of TR
//                        /       \                               hL is the height of TL
//                       TL       TR   where TL and TR are binary trees
//
//@   operations/methods: create, destroy, insert

#ifndef CAVLTREE_H
#define CAVLTREE_H

#include "cbstree.h"
#include "cnode.h"
#include "ckey.h"
#include "cexception.h"

using namespace std;

typedef Ckey Citem;

struct SearchPath;

class cavltree: public cbstree
{
public:
   
   cavltree();
   
	~cavltree();
	
   // Inserts a new item into the AVL Tree
   // pre: AVL Tree object exists
   //      newItem has been assigned
   // post: newItem has been added to AVL Tree
   //       If AVL Tree has become unbalanced, it has been subsequently rebalanced
   // param newItem
   // usage: ourawesometree.Insert (awesomenewitem)
   void Insert (const Citem& newItem) throw (cexception);

   
protected:

	//@Does a single rotation of a AVL tree to the left where after the rotated the pivot would be on the left 
	//@of it's child node the parent of the pivot is now the parent of it's child
	//@pre cavl tree exists and insertion point is grandchild right of pivot
	//@post pivot and new item are now childeren of pivot's child pivot's balance is set to 0
	//@return cavl tree has been balanced using a single rotation to the left
	//@param search
	//@usage DoSingleRotateLeft (search);
   void DoSingleRotateLeft (const SearchPath& search);

	//@Does a single rotation of a AVL tree to the right where after the rotated the pivot would be on the right 
	//@of it's child node the parent of the pivot is now the parent of it's child
	//@pre cavl tree exists and insertion point is grandchild left of pivot
	//@post pivot and new item are now childeren of pivot's child, pivot's balance is set to 0
	//@return cavl tree has been balanced using a single rotation to the right
	//@param search
	//@usage DoSingleRotateRight (search);
   void DoSingleRotateRight (const SearchPath& search);

	//@Does a double rotation of a AVL tree when the new node is left then right from the pivot down the tree.
	//@pre a avl tree who has height minimum of 3 and new item is left then right down the tree
	//@post the grandchild of the pivot is now in the pivot's position where the pivot is on it's right and the 
	//@     pivot's child is on it's left. any children of the grandchild have been reallocated as necessary 
	//@return a proper avl tree after a double left right rotation
	//@param search
	//@usage DoDoubleRotateLeftRight(search);	
   void DoDoubleRotateLeftRight (const SearchPath& search);

	//@Does a double rotation of a AVL tree when the new node is right then left from the pivot down the tree.
	//@pre a avl tree who has height minimum of 3 and new item is right then left down the tree
	//@post the grandchild of the pivot is now in the pivot's position where the pivot is on it's left and the 
	//@     pivot's child is on it's right. any children of the grandchild have been reallocated as necessary 
	//@return a proper avl tree after a double right left rotation
	//@param search
	//@usage DoDoubleRotateRightLeft(search);
   void DoDoubleRotateRightLeft (const SearchPath& search);

   //@runs binary tree insert then builds the search array path and assigns
   //@   size
   //@pre AVL newitem, treeptr, and search are all assigned
   //@post newitem is added to the tree, treeptr is updated, and search has been created
   //@   and filled out
   //@param newitem
   //@param treeptr
   //@param search
   //@throw cexception
   //@usage try {BStreeInsertNMakeSearchPath(newitem, mroot, search); }
   //@      throw (cexception except) {cout << except.what(); }
   void BSTreeInsertNMakeSearchPath(const Citem& newitem, Cnode*& treeptr,
          SearchPath& search) throw (cexception);

   //@date 19 march, 2011
   //@description: determines whether or not there is a pivot in the search path    
   //              and if there is, sets the pivot index in search
   //@pre search.path has been assigned, search.size is assigned the size of
   //     the search path, search.pivot is initialized to -1
   //@post assigns a value to search.pivot if there is a pivot
   //@     and returns false else returns true
   //@param search
   //@usage if(AVLtree.HasNoPivot(search))
   bool HasNoPivot(SearchPath& search) const;

   //@ Adjusts the balances of the nodes in a portion of the search path on an AVL tree after an insert
   //@ pre: start and search are assigned
   //@ post: AVL tree Nodes are changed appropriately on the search path from index start down to parent of new new node
   //@ param: search, the Search Path of the AVL tree
   //@ param: start, the starting point in the path where mbalance needs to be adjusted
   //@ usage: ChangesBalances(mysearch, 0);
   void ChangesBalances(const SearchPath& search, int start);

   //@Team_3
   //@Ryan Draper (draper)
   //@Kelsey Takahashi(ktakahashi)
   //@Nate Wendt(nwendt) 
   //@-IsAddedToShortSide
   //@checks to see if the added node is attached to the shorter
   // side from the pivot. 
   //@pre: search has been assigned and has a pivot. 
   //@post: returns true if added node is attached to shorter side of tree
   //       else returns false
   //@param search
   //@usage if(IsAddedToShortSide(search));
   bool IsAddedToShortSide(const SearchPath& search) const;

   //@Zachary Costello, Jamie Haddock, Zhia Chong
   //@Group Name: My God That Was Fast!
   //@Checks whether or not the AVL tree needs a Left Rotate
   //@pre:   the pivot exists, the search path exists and contains the path
   //        taken by the insert function 
   //@post:  Returns true if the search path goes right twice from the pivot,
   //        otherwise returns false.
   //@usage: if(IsSingleRotateLeft)
   //           (do something);
   //@param search
   bool IsSingleRotateLeft(const SearchPath& search) const;


   //@Checks whether or not the AVL tree needs a Right Rotate
   //@pre:   the pivot exists, the search path exists and contains the path
   //        taken by the insert function
   //@post:  Returns true if the search path goes left twice,
   //        otherwise returns false.
   //@usage: if(IsSingleRotateRight)
   //           (do something);
   //@param search
   bool IsSingleRotateRight(const SearchPath& search) const;

   // Team Teh League of Really Awesom3 People who Write Code
   // Collin Deel, Dan Rahm, Marvin Rumbaua, Josh MacMillan
   // Checks if the tree needs to be rotated left then right
   // pre: Calling AVL Tree object exists
   //      search has been assigned and has a pivot
   //      A new item has been added to the long side of the tree
   // post: If search path goes left then right from pivot, then returns true
   //       else returns false
   // param search
   // usage: if (ourawesometree.IsDoubleRotateLeftRight (search)) {DoDoubleRotateLeftRight ()};
   bool IsDoubleRotateLeftRight (const SearchPath& search) const;


};

#endif
