//@Implementation for ADT Citem
//@   data object: Citem that holds an item
//@   data structure: a int 
//@   operations/methods: create, destroy, copy,
//@               operator=, operator<, operator==
//@   friend: print as operator<< and input as operator>>

//@author Ryan Draper (draper)
//@date April 14, 2011
//@file citem.cpp

#include "citem.h"


//@creates an empty citem
//@post an empty citem
//@usage Citem item;  
Citem::Citem()
{
   mitem = -1;
}
   
//@copies an existing Citem
//@pre rhscitem exists
//@post Citem object is a copy of rhscitem
//@usage Citem item(anothercitem); or passing a Citem object by value
Citem::Citem(const Citem& rhscitem) 
{
   mitem = -1;
   operator= (rhscitem);
}
//@destroys a Citem
//@pre Citem object exists
//@post Citem object does not exist
Citem:: ~Citem()
{
   mitem = -1;
}
   
//@copies the Citem
//@pre rhscitem exists. Citem object exists with same amount of memory
//@post Citem object is a copy of rhscitem
//@param rhscitem
//@usage cpycitem.operator=(rhscitem);
//@      or        cpycitem = rhscitem;   
Citem& Citem::operator=(const Citem& rhscitem)
{
   if (this != &rhscitem)
   {
	   mitem = rhscitem.mitem;
   }
   return *this;
}
   
//@deletes a Citem
//@pre a Citem exists
//@post content of Citem is deleted
//@usage item.EmptyOut()
void Citem::EmptyOut()
{
	mitem = -1;
}

//@returns true if the mitem is empty
//@pre Citem exists
//@post returns true if mitem is empty else false
//@usage rhsitem.IsEmpty();
bool Citem::IsEmpty()const
{
	return (mitem == -1);
}

//@Citem exsts and returns true if it is equal to the rhs Citem object
//@pre rhsitem exists Citem object exists 
//@post returns true is rhsitem is the same as data object false otherwise
//@param rhsitem
//@usage if (item == rhsitem)
bool Citem::operator==(const Citem& rhsitem) const
{
   return (mitem == rhsitem.mitem);
}
 
//@rhsitem exsts and returns true if it is equal to the data object
//@pre rhsitem exists Citem object exists 
//@post returns true is rhsitem is the same as data object false otherwise
//@param rhsitem
//@usage if (item < rhsitem) 
bool Citem::operator<(const Citem& rhsitem) const
{
   return (mitem < rhsitem.mitem);
}

//@outputs to a file or the monitor a Citem object
//@pre rhscitem exists. output is open.
//@post contents of rhscitem have been output
//@param output
//@param rhscitem
//@usage cout << rhscitem << endl;   
ostream& operator<< (ostream& output, const Citem& rhscitem)
{
   if (rhscitem.IsEmpty())
   { 
      output << "---" ;
   } else {
      output << right << setw(3) << rhscitem.mitem;
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
      cout << "Please Enter the item :-> ";
   }
   input >> rhscitem.mitem;
   
   return input;
}
