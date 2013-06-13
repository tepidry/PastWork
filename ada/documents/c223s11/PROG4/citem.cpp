//@Implementation for ADT Citem
//@   data object: a item that holds the meaning of the key
//@   data structure: a string 
//@   operations/methods: create, destroy, copy, operator=
//@   friend: print as operator<< and input as operator>>

//@author Ryan Draper (draper)
//@date Feb 17, 2011
//@file citem.cpp

#include "citem.h"
#include "ckey.h"


//@creates an empty string
//@post an empty string
//@usage Citem item;  
Citem::Citem() : Ckey()
{
   mmeaning.clear();
}
   
//@copies an existing Citem
//@pre rhscitem exists
//@post Citem object is a copy of rhscitem
//@usage Citem item(anothercitem); or passing a Citem object by value
Citem::Citem(const Citem& rhscitem) : Ckey(rhscitem)
{
   mmeaning.clear();
   operator= (rhscitem);
}
//@destroys a Citem
//@pre Citem object exists
//@post Citem object does not exist
Citem:: ~Citem()
{
   mmeaning.clear();
}
   
//@copies the Citem
//@pre rhscitem exists. Citem object exists with same amount of memory
//@post Citem object is a copy of rhscitem
//@param rhscitem
//@usage cpycitem.operator=(rhscitem);
//@      or        cpyq = rhscitem;   
Citem& Citem::operator=(const Citem& rhscitem)
{
   if (this != &rhscitem)
   {
      mmeaning = rhscitem.mmeaning;
      macronym = rhscitem.macronym;
   }
   return *this;
}
   
//@outputs to a file or the monitor a Citem object
//@pre rhscitem exists. output is open.
//@post contents of rhscitem have been output
//@param output
//@param rhscitem
//@usage cout << rhscitem << endl;   
ostream& operator<< (ostream& output, const Citem& rhscitem)
{
   if (!rhscitem.mmeaning.empty())
   { 
      output << rhscitem.macronym << " : ";
	   output << rhscitem.mmeaning;
   } else {
      output << "Empty" << endl;
   }
   return output;
}
   
//@inputs a Citem from a file or cin
//@pre rhscitem exists. input is open.
//@post contents of rhscitem have been input either by file or user
//@param input
//@param rhscitem
//@usage cout << rhscitem << endl;   
istream& operator>> (istream& input, Citem& rhscitem)
{
   if(&input == &cin)
   {
      cout << "Please Enter the abbreviation :-> ";
   }
   getline(input, rhscitem.macronym);
   if(&input == &cin)
   {
      cout << "Please Enter the meaning for that abbreviation :-> ";
   }
   getline(input, rhscitem.mmeaning);
   
   return input;
}
