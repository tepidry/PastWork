//@Ryan Draper (draper)
//@Kelsey Takahashi(ktakahashi)
//@Nate Wendt(nwendt) 

//@
//@pre
//@post
//@return
//@param search
//@usage
bool IsAddedToShortSide(const SearchPath& search) const
{
   //@int balance; 
   Cnode* pivotptr, nextpathptr;
   pivotptr = search.path[search.pivot];
   nextpathptr = search.path[search.pivot + 1];
   
   //@if(search.balance == 1 && pivotptr -> mrightptr == nextpathptr)
   if(pivotptr -> mbalance == -1 && pivotptr -> mrightptr == nextpathptr)
      return true;  // tall left and added right
      
   //@else if(search.balance == 0 && pivotptr -> mleftptr == nextpathptr)
   else if(pivotptr -> mbalance  == 1 && pivotptr -> mleftptr == nextpathptr)
      return true;  // tall right and added left
   else
      return false;
}  