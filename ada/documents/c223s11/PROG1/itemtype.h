//@author Ryan Draper (draper)
//@date December 17 2011
//@file ItemType.h

//@Specification for ADT ItemType
//@   data object: a ItemType which is three ints and a bool
//@   operations/methods: create, destroy, copy
//@               get track, get sector, get ID, get Read or Write
//@   friend: print as operator<< and input as operator>>

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

class ItemType
{
   //@outputs to a file or the monitor a ItemType object
   //@pre rhsitem exists. output is open.
   //@post contents of rhsitem have been output
   //@param output
   //@param rhsitem
   //@usage cout << rhsitem << endl;   
   friend ostream& operator<< (ostream& output, const ItemType& rhsitem);
   
   //@inputs a item from a file or cin
   //@pre rhsitem exists. input is open.
   //@post contents of rhsitem have been input either by file or user
   //@     if the sector < 0 or > 200 -1 is assigned 
   //@     if the track < 0 or > 100 -1 is assigned
   //@param output
   //@param rhsitem
   //@usage cout << rhsitem << endl;   
   friend istream& operator>> (istream& input, ItemType& rhsitem);
   
public:

   //@creates an empty ItemType of default memory size
   //@post all integers are 0 and mreadwrite is at true or read;
   //@usage ItemType item;
   ItemType();
   
   //@copies an existing ItemType
   //@pre rhsitem exists
   //@post itemtype object is a copy of rhsitem
   //@usage ItemType item(anotheritem); or passing a ItemType object by value
   ItemType(const ItemType& rhsitem);
   
   //@destroys a itemtype
   //@pre itemtype object exists
   //@post ItemType object does not exist
   ~ItemType();
   
   //@copies the itemtype
   //@pre rhsitem exists. itemtype object exists with same amount of memory
   //@post itemtype object is a copy of rhsitem
   //@param rhsitem
   //@usage cpyitem.operator=(rhsitem);
   //@      or        cpyitem = rhsitem;
   ItemType& operator=(const ItemType& rhsitem);
   
   //@checks to see if a ItemType object is empty
   //@pre ItemType object exists
   //@post if ItemType is empty returns true else returns false
   //@usage if (item.IsEmpty())
   bool IsEmpty() const;

   //@returns the bool mreadwrite private member
   //@pre ItemType object exists
   //@post returned bool value representing true for read and false for write
   //@usuage item.GetReadWrite();
   bool GetReadWrite() const;
   
   //@returns the int msector private member
   //@pre ItemType object exists
   //@post returned int value representing sector number between 0 to 200
   //@usuage item.GetSector();
   int GetSector() const;
   
   //@returns the int mtrack private member
   //@pre ItemType object exists
   //@post returned int value representing track number between 0 to 100
   //@usuage item.GetTrack();
   int GetTrack() const;
   
   //@returns the int mident private member
   //@pre ItemType object exists
   //@post returned int value representing unique ID number
   //@usuage item.GetId();
   int GetId() const;
   
private: //for simplicity, we are disobeying the concept of data hiding
   int msector, mtrack, mident;
   bool mreadwrite;

};
#endif
