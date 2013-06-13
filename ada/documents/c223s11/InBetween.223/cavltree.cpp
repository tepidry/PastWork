WTFWTFDr Y's comment: where is size initialized to 0?
                why didn't you use the cnode constructor that allows inputs of newItem and NULL children?

//@Alex Harris, Marshall Hurson, Ryan Dewey
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
void cavltree::BSTreeInsertNMakeSearchPath(const Citem& newitem, Cnode*& treeptr,
          SearchPath& search) throw (cexception)
{
   if (treeptr == NULL) {
      treeptr = new (nothrow) Cnode;
      if (treeptr == NULL)
         throw ("Cavltree::BSTreeInsertNMakeSearchPath - Not Enough Memory to Make Node");
      search.path[size] = treeptr;
      search.size++;
      treeptr -> mitem = newItem;
      
      mcount++;
   } else if (newItem < treeptr -> mitem) {
      search.path[size] = treeptr;
      search.size++;
      BSTreeInsertNMakeSearchPath(newItem, treeptr -> mleftptr, search);
   } else {
      search.path[size] = treeptr;
      search.size++;
      BSTreeInsertNMakeSearchPath(newItem, treeptr -> mrightptr, search);
   }
}

//@author Ethan Fleming, Paul Jewell, Spencer Larsen
//@date 19 march, 2011
//@description: determines whether or not there is a pivot in the search path    
//              and if there is, sets the pivot index in search
//@pre search.path has been assigned, search.size is assigned the size of
//     the search path, search.pivot is initialized to -1
//@post assigns a value to search.pivot if there is a pivot
//@     and returns false else returns true
//@param search
//@usage if(AVLtree.HasNoPivot(search))
bool cavltree::HasNoPivot(SearchPath& search) const
{
	bool noPivot = true;
	int index = search.size - 1;
	do {
		if (search.path[index] -> mbalance != 0)
		{
			search.pivot = index;
			noPivot = false;
		}
		index--;
	} while (index >= 0 && noPivot);
	
	return noPivot;
}

//@ This function made possible by David #1, David #2, and Kevin
//@ Adjusts the balances of the nodes in a portion of the search path on an AVL tree after an insert
//@ pre: start and search are assigned
//@ post: AVL tree Nodes are changed appropriately on the search path from index start down to parent of new new node
//@ param: search, the Search Path of the AVL tree
//@ param: start, the starting point in the path where mbalance needs to be adjusted
//@ usage: ChangesBalances(mysearch, 0);
void cavltree::ChangesBalances(const SearchPath& search, int start);
{
   for(int k = start; k < search.size - 1; k++)
   {
      if(search.path[k] -> mrightptr == search.path[k+1])
         search.path[k] -> mbalance = search.path[k] -> mbalance + 1;
      else
         search.path[k] -> mbalance = search.path[k] -> mbalance - 1;
   }
}

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
bool cavltree::IsAddedToShortSide(const SearchPath& search) const
{
   Cnode* pivotptr, nextpathptr;
   
   pivotptr = search.path[search.pivot];
   nextpathptr = search.path[search.pivot + 1];
   
   if(pivotptr -> mbalance == -1 && pivotptr -> mrightptr == nextpathptr)
      return true;  // tall left and added right
   else if(pivotptr -> mbalance  == 1 && pivotptr -> mleftptr == nextpathptr)
      return true;  // tall right and added left
   else
      return false;
}  

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
bool cavltree::IsSingleRotateLeft(const SearchPath& search) const
{
   if(search.path[search.pivot] -> mrightptr == search.path[search.pivot + 1])
      return (search.path[search.pivot + 1] -> mrightptr == search.path[search.pivot + 2]);
   else
      return false;
}

//@Checks whether or not the AVL tree needs a Right Rotate
//@pre:   the pivot exists, the search path exists and contains the path
//        taken by the insert function
//@post:  Returns true if the search path goes left twice,
//        otherwise returns false.
//@usage: if(IsSingleRotateRight)
//           (do something);
//@param search
bool cavltree::IsSingleRotateRight(const SearchPath& search) const
{
   if(search.path[search.pivot] -> mleftptr == search.path[search.pivot + 1])
      return (search.path[search.pivot + 1] -> mleftptr == search.path[search.pivot + 2]);
   else
      return false;
}

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
bool cavltree::IsDoubleRotateLeftRight (const SearchPath& search) const
{
   return ((search.path [search.pivot] -> mleftptr == search.path [search.pivot + 1]) &&
       (search.path [search.pivot + 1] -> mrightptr == search.path [search.pivot + 2]))
}  

// Team Teh League of Really Awesom3 People who Write Code
// Collin Deel, Dan Rahm, Marvin Rumbaua, Josh MacMillan
// Inserts a new item into the AVL Tree
// pre: AVL Tree object exists
//      newItem has been assigned
// post: newItem has been added to AVL Tree
//       If AVL Tree has become unbalanced, it has been subsequently rebalanced
// param newItem
// usage: ourawesometree.Insert (awesomenewitem)
void cavltree::Insert (const Citem& newItem) throw (cexception)
{
   SearchPath search;
   
   BSTreeInsertNMakeSearchPath(newitem, mroot, search);   

   if (HasNoPivot (search))
      ChangesBalances (search, 0);
   else if (IsAddedToShortSide (search))
      ChangesBalances (search, search.pivot);
   else if (IsSingleRotateLeft (search))
      DoSingleRotateLeft ();
   else if (IsSingleRotateRight (search))
      DoSingleRotateRight ();
   else if (IsDoubleRotateLeftRight (search))
      DoDoubleRotateLeftRight ();
   else
      DoDoubleRotateRightLeft ();
}  
