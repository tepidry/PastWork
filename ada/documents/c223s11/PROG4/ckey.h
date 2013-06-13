//@author Ryan Draper(draper)
//@date Feb 17, 2011
//@file ckey.h

//@Specification for Ckey
//@   data object: A key that takes in the acronym or appreviation
//@   operations/methods: create, destroy, copy, operator=, operator<, operator==, 
//@                friend: operator<<, operator>>

#ifndef CKEY_H
#define CKEY_H

#include <iostream>
#include <string>

using namespace std;

class Ckey
{ 
   //@outputs to a file or the monitor a Ckey object
   //@pre rhskey exists. output is open.
   //@post contents of rhskey have been output
   //@param output
   //@param rhskey
   //@usage cout << rhskey << endl;   
   friend ostream& operator<< (ostream& output, const Ckey& rhskey);
   
   //@inputs a item from a file or cin
   //@pre rhskey exists. input is open.
   //@post contents of rhskey have been input either by file or user
   //@     if the sector < 0 or > 200 -1 is assigned 
   //@     if the track < 0 or > 100 -1 is assigned
   //@param output
   //@param rhskey
   //@usage cout << rhskey << endl;   
   friend istream& operator>> (istream& input, Ckey& rhskey);
   
public:

   //@creates an empty string
   //@post an empty string
   //@usage Ckey key;    
   Ckey();
   
   //@copies an existing Ckey
   //@pre rhskey exists
   //@post Ckey object is a copy of rhskey
   //@usage Ckey item(anotherCkey); or passing a Ckey object by value        
   Ckey(const Ckey& rhskey);
   
   //@destroys a Ckey
   //@pre Ckey object exists
   //@post Ckey object does not exist
   ~Ckey();
   
   //@rhskey exsts and returns true if it is equal to the data object
   //@pre rhskey exists Ckey object exists 
   //@post returns true is rhskey is the same as data object false otherwise
   //@param rhskey
   //@usage if (key == rhskey)
   bool operator==(const Ckey& rhskey) const;
   
   //@rhskey exsts and returns true if it is equal to the data object
   //@pre rhskey exists Ckey object exists 
   //@post returns true is rhskey is the same as data object false otherwise
   //@param rhskey
   //@usage if (key < rhskey)
   bool operator<(const Ckey& rhskey) const;
   
   //@copies the Ckey
   //@pre rhskey exists. Ckey object exists with same amount of memory
   //@post Ckey object is a copy of rhsCnode
   //@param rhskey
   //@usage cpykey.operator=(rhskey);
   //@      or        cpyq = rhskey;   
   Ckey& operator=(const Ckey& rhskey);
   
protected: 
   string macronym;

};
#endif
