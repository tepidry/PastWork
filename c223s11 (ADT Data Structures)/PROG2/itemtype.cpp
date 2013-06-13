//@Implementation for ADT ItemType
//@   data object: a ItemType which is a group of ints for track, sector and id and a bool for read or write
//@   data structure: an int for the track number,
//@                   an int for the sector number,
//@                   an int for the id number,
//@                   and a bool to signify read or write
//@   operations/methods: create, destroy, make empty, 
//@                       get track, get sector, get ID, get read or write
//@   friend: print as operator<< input as operator>>

//@author Ryan Draper (draper)
//@date December 17, 2011
//@file itemtype.cpp

#include "itemtype.h"

//@creates an empty ItemType of default memory size
//@post all integers are 0 and mreadwrite is at true or read;
//@usage ItemType item;
ItemType::ItemType()
{
   msector = 0; 
   mtrack = 0; 
   mident = -1;
   mreadwrite = true;
}

//@destroys a itemtype
//@pre itemtype object exists
//@post ItemType object does not exist
ItemType:: ~ItemType()
{
   msector = 0; 
   mtrack = 0; 
   mident = -1;
   mreadwrite = true;
}
 
//@copies an existing ItemType
//@pre rhsitem exists
//@post itemtype object is a copy of rhsitem
//@usage ItemType item(anotheritem); or passing a ItemType object by value
ItemType::ItemType(const ItemType& rhsitem)
{
   msector = 0; 
   mtrack = 0; 
   mident = -1;
   mreadwrite = true;
   operator=(rhsitem);
}   

//@checks to see if a ItemType object is empty
//@pre ItemType object exists
//@post if ItemType is empty returns true else returns false
//@usage if (item.IsEmpty())
bool ItemType::IsEmpty() const
{
   return mident == -1;
}

//@returns the bool mreadwrite private member
//@pre ItemType object exists
//@post returned bool value representing true for read and false for write
//@usuage bool read = item.GetReadWrite();
bool ItemType::GetReadWrite() const
{
   return mreadwrite;
}
  
//@returns the int msector private member
//@pre ItemType object exists
//@post returned int value representing sector number between 0 to 200
//@usuage sect = item.GetSector();
int ItemType::GetSector() const
{
   return msector;
}
   
//@returns the int mtrack private member
//@pre ItemType object exists
//@post returned int value representing track number between 0 to 100
//@usuage track = item.GetTrack();
int ItemType::GetTrack() const
{
   return mtrack;
}
   
//@returns the int mident private member
//@pre ItemType object exists
//@post returned int value representing unique ID number
//@usuage ID = item.GetId();
int ItemType::GetId() const
{
   return mident;
}

//@copies the itemtype
//@pre rhsitem exists. itemtype object exists with same amount of memory
//@post itemtype object is a copy of rhsitem
//@param rhsitem
//@usage cpyitem.operator=(rhsitem);
//@      or        cpyitem = rhsitem;
ItemType& ItemType::operator=(const ItemType& rhsitem)
{
   if (this != &rhsitem)
   {
      msector = rhsitem.msector; 
      mtrack = rhsitem.mtrack; 
      mident = rhsitem.mident;
      mreadwrite = rhsitem.mreadwrite;
   }
   return *this;
}

//@outputs to a file or the monitor a ItemType object
//@pre rhsitem exists. output is open.
//@post contents of rhsitem have been output
//@param output
//@param rhsitem
//@usage cout << rhsitem << endl;   
ostream& operator<< (ostream& output, const ItemType& rhsitem)
{
   if (rhsitem.mident >= 0)
   { 
	  output << "~{ ";
      if (rhsitem.mreadwrite == true)
	     output << "R ";
      else                                          
         output << "W "; 
      output << "| ID: " << rhsitem.mident; 
      output << "| S: " << rhsitem.msector;
      output << "| T: " << rhsitem.mtrack << " }~";               
   } else {
      output << "Empty";
   }
   return output;
}    

//@inputs a item from a file or cin
//@pre rhsitem exists. input is open.
//@post contents of rhsitem have been input either by file or user
//@     if the sector < 0 or > 200 -1 is assigned 
//@     if the track < 0 or > 100 -1 is assigned
//@param output
//@param rhsitem
//@usage cout << rhsitem << endl;   
istream& operator>> (istream& input, ItemType& rhsitem)
{
   char RorW;

   if (&input == &cin)
      cout << "Enter r/w for Read or Write -> ";
   input >> RorW;
   if (RorW == 'R' || RorW == 'r')
      rhsitem.mreadwrite = true;  
   else
      rhsitem.mreadwrite = false;

   if (&input == &cin)
      cout << "Enter Sector # between 0 and 200 ->  ";
   input >> rhsitem.msector;
   if (rhsitem.msector < 0 || rhsitem.msector > 200)
      rhsitem.msector = -1;
      
   if (&input == &cin)
      cout << "Enter Track # between 0 and 100 ->  ";
   input >> rhsitem.mtrack;
   if (rhsitem.mtrack < 0 || rhsitem.mtrack > 100)
      rhsitem.mtrack = -1;
      
   if (&input == &cin)
      cout << "Enter a non negative ID number -> ";
   input >> rhsitem.mident;
   
   return input;
}    
