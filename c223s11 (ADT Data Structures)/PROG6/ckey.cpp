//@Implementation for CKey
//@   data object: A key that takes in an int
//@   data structure: a int
//@   operations/methods: create, destroy, copy, operator=, operator<, operator==, 
//@                friend: operator<<, operator>>

//@author Ryan Draper(draper)
//@date March 26, 2010
//@file ckey.cpp

#include "ckey.h"

//@creates an empty mitem
//@post an empty mitem
//@usage Ckey key;    
Ckey::Ckey()
{
   mitem = -1;
}
   
//@copies an existing Ckey
//@pre rhskey exists
//@post Ckey object is a copy of rhskey
//@usage Ckey item(anotherCkey); or passing a Ckey object by value           
Ckey::Ckey(const Ckey& rhskey)
{
   mitem = rhskey.mitem;
}
   
//@destroys a Ckey
//@pre Ckey object exists
//@post Ckey object does not exist
Ckey:: ~Ckey()
{
   mitem = -1;
}
 
//@rhskey exsts and returns true if it is equal to the data object
//@pre rhskey exists Ckey object exists 
//@post returns true is rhskey is the same as data object false otherwise
//@param rhskey
//@usage if (key == rhskey)
bool Ckey::operator==(const Ckey& rhskey) const
{
   return mitem == rhskey.mitem;
}
 
//@rhskey exsts and returns true if it is equal to the data object
//@pre rhskey exists Ckey object exists 
//@post returns true is rhskey is the same as data object false otherwise
//@param rhskey
//@usage if (key < rhskey) 
bool Ckey::operator<(const Ckey& rhskey) const
{
   return (mitem < rhskey.mitem);
}
   
//@copies the Ckey
//@pre rhskey exists. Ckey object exists with same amount of memory
//@post Ckey object is a copy of rhskey
//@param rhskey
//@usage cpykey.operator=(rhskey);
//@      or        cpyq = rhskey;   
Ckey& Ckey::operator=(const Ckey& rhskey)
{
   if (this != &rhskey)
   {
      mitem = rhskey.mitem;
   }
   return *this;
}
   
//@outputs to a file or the monitor a Ckey object
//@pre rhskey exists. output is open.
//@post contents of rhskey have been output
//@param output
//@param rhskey
//@usage cout << rhskey << endl;   
ostream& operator<< (ostream& output, const Ckey& rhskey)
{
   if (rhskey.mitem != -1)
   { 
	  output << rhskey.mitem;             
   } else {
      output << "Empty";
   }
   return output;
}
   
//@inputs a item from a file or cin
//@pre rhskey exists. input is open.
//@post contents of rhskey have been input either by file or user
//@     if the sector < 0 or > 200 -1 is assigned 
//@     if the track < 0 or > 100 -1 is assigned
//@param output
//@param rhskey
//@usage cout << rhskey << endl;   
istream& operator>> (istream& input, Ckey& rhskey)
{  
   input >> rhskey.mitem;
   
   return input;
}
