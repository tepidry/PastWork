//@author Ryan Draper (draper)
//@date Jan 17 2011
//@file citem.h

//@Specification for ADT citem
//@   data object: a ItemType which is three ints and a bool
//@   operations/methods: create, destroy, copy
//@               get track, get sector, get ID, get Read or Write
//@   friend: print as operator<< and input as operator>>

#ifndef CITEM_H
#define CITEM_H

#include <iostream>
#include "ckey.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;



class Citem : public Ckey
{
   //@outputs to a file or the monitor a Citem object
   //@pre rhscitem exists. output is open.
   //@post contents of rhscitem have been output
   //@param output
   //@param rhscitem
   //@usage cout << rhscitem << endl;   
   friend ostream& operator<< (ostream& output, const Citem& rhscitem);
   
   //@inputs a Citem from a file or cin
   //@pre rhscitem exists. input is open.
   //@post contents of rhscitem have been input either by file or user
   //@param input
   //@param rhscitem
   //@usage cout << rhscitem << endl;   
   friend istream& operator>> (istream& input, Citem& rhscitem);
   
public:

   //@creates an empty string
   //@post an empty string
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
   //@      or        cpyq = rhscitem;   
   Citem& operator=(const Citem& rhscitem);
   
   
protected: 
   string mmeaning;

};
#endif
