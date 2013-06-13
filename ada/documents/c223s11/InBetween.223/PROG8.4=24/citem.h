
//@author Ryan Draper (draper)
//@date April 14, 2011
//@file citem.h

//@Specification for ADT Citem
//@   data object: Citem that holds an item 
//@   operations/methods: create, destroy, copy,
//@               operator=, operator<, operator==
//@   friend: print as operator<< and input as operator>>

#ifndef CITEM_H
#define CITEM_H

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;



class Citem
{
   //@outputs to a file or the monitor a Citem object
   //@pre rhscitem exists. output is open.
   //@post contents of rhscitem have been output
   //@param output
   //@param rhscitem
   //@usage outfile << rhscitem << endl;   
   friend ostream& operator<< (ostream& output, const Citem& rhscitem);
   
   //@inputs a Citem from a file or cin
   //@pre rhscitem exists. input is open.
   //@post contents of rhscitem have been input either by file or user
   //@param input
   //@param rhscitem
   //@usage infile << rhscitem << endl;   
   friend istream& operator>> (istream& input, Citem& rhscitem);
   
public:

   //@creates an empty citem
   //@post an empty citem
   //@usage Citem item;  
   Citem();
   
   //@copies an existing Citem
   //@pre rhscitem exists
   //@post Citem object is a copy of rhscitem
   //@usage Citem item(anothercitem); or passing a Citem object by value
   Citem(const Citem& rhscitem);
   
   //@destroys a Citem
   //@pre Citem object exists
   //@post Citem object does not exist
   ~Citem();
   
   //@copies the Citem
   //@pre rhscitem exists. Citem object exists with same amount of memory
   //@post Citem object is a copy of rhscitem
   //@param rhscitem
   //@usage cpycitem.operator=(rhscitem);
   //@      or        cpycitem = rhscitem;   
   Citem& operator=(const Citem& rhscitem);
   
   //@deletes a Citem
   //@pre a Citem exists
   //@post content of Citem is deleted
   //@usage item.EmptyOut()
   void EmptyOut();
   
   //@returns true if the mitem is empty
	//@pre Citem exists
	//@post returns true if mitem is empty else false
	//@usage rhsitem.IsEmpty();
	bool IsEmpty()const;

   
   //@Citem exsts and returns true if it is equal to the rhs Citem object
	//@pre rhsitem exists Citem object exists 
	//@post returns true is rhsitem is the same as data object false otherwise
	//@param rhsitem
	//@usage if (item == rhsitem)
	bool operator==(const Citem& rhsitem) const;
 
	//@rhsitem exsts and returns true if it is equal to the data object
	//@pre rhsitem exists Citem object exists 
	//@post returns true is rhsitem is the same as data object false otherwise
	//@param rhsitem
	//@usage if (item < rhsitem) 
	bool operator<(const Citem& rhsitem) const;


protected: 
   int mitem;

};
#endif
