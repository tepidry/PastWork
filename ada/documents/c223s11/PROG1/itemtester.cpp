//@author Ryan Draper (draper)
//@date Jan 17, 2011
//@file itemtester.cpp
//@description: This program fully tests class itemtype.

#include <iostream>
#include "itemtype.h"
using namespace std;

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@prints ItemType data
//@pre ItemType is a data object
//@post ItemType is printed on the screen
//@param item
//@usage PrintItem(item);
void PrintItem (ItemType item);

//@post outputs what program is doing
//@usage BegingTest();
void BeginTest();

//@gets input from user for item
//@pre ItemType item is a data object
//@post item is filled with info from user
//@param item
//@usage GetItem(item);
void GetItem(ItemType& item);

//@prints the whether ItemType is empty
//@pre item is a data object
//@post outputs true if ItemType is empty false otherwise
//@usage PrintBool(q.IsEmpty());
void PrintEmpty (ItemType item);

//@copies a existing ItemType to another ItemType and uses the constant char to output what case is being used
//@pre copy item and item are existing data objects and whatCase is a string
//@post copyItem contains what item contains in it and it is printed on the screen
//@return copyItem is returned by reference
//@param copyItem
//@param item
//@param whatCase
//@usage TestCopyItem(copyItem, item, whatCase);
void TestCopyItem(ItemType& copyItem, ItemType item, const char* whatCase);

//@retrieves just the sector form ItemType item
//@pre item is a existing data object
//@post returns the int in the sector of item
//@param item
//@usage TestGetSector(item);
void TestGetSector(ItemType item);

//@retrieves just the Track from ItemType item
//@pre item is a existing data object
//@post returns the int in the track of item
//@param item
//@usage TestGetTrack(item);
void TestGetTrack(ItemType item);

//@retrieves just the ID# from ItemType item
//@pre item is a existing data object
//@post returns the int in the ID# of item
//@param item
//@usage TestGetId(item);
void TestGetId(ItemType item);

//@retrieves just the Read or Write from ItemType item
//@pre item is a existing data object
//@post returns the int in the ID# of item
//@param item
//@usage TestGetReadWrite(item);
void TestGetReadWrite(ItemType item);

int main()
{
   ItemType item, copyItem;

   PrintLines(3);
   BeginTest();
   ToContinue();
   
   PrintLines(3);
   PrintMessage ("new item", "empty");
   PrintEmpty (item);
   PrintItem(item);
   ToContinue();
   
   PrintLines(3);
   TestCopyItem(copyItem, item, "empty");
   ToContinue();
   
   PrintLines(3); 
   GetItem(item);
   ToContinue();
   
   PrintLines(3);
   PrintMessage("new item", "non-empty");
   PrintEmpty (item);
   PrintItem(item);
   ToContinue();
   
   PrintLines(3);
   TestCopyItem(copyItem, item, "non-empty");
   ToContinue();
   
   PrintLines(3);
   TestGetSector(item);
   ToContinue();
   
   PrintLines(3);
   TestGetTrack(item);
   ToContinue();
   
   PrintLines(3);
   TestGetId(item);
   ToContinue();
   
   PrintLines(3);
   TestGetReadWrite(item);
   ToContinue();
   
   PrintLines(3);   
   return 0;   
}

//@prints the whether ItemType is empty
//@pre item is a data object
//@post outputs true if ItemType is empty false otherwise
//@usage PrintBool(q.IsEmpty());
void PrintEmpty (ItemType item)
{
   cout << "   Testing IsEmpty:" << endl; 
   cout << "   ItemType is ";
   if (item.IsEmpty())
      cout << "Empty";
   else
      cout << "Not-Empty";
   PrintLines(2);
}  

//@post outputs what program is doing
//@usage BegingTest();
void BeginTest()
{
   cout << "This will test the class ItemType member functions:" << endl;
   cout << "create, copy, destroy, operator=," << endl; 
   cout << "Is Empty, get Track, get Sector," << endl; 
   cout << "get ID, and get Read or Write." << endl << endl; 
   cout << "And it's friend functions:" << endl;
   cout << "operator<<, and operator>>" << endl;
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   PrintLines(2);
   cout << "                           Hit <Enter> to continue -> ";
   cin.get(ch);
}

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase)
{
   PrintLines(2);
   cout << "Testing *** " << which << " *** in the " 
        << whatCase << " case";
   PrintLines(2);
}  

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

//@prints ItemType data
//@pre ItemType is a data object
//@post ItemType is printed on the screen
//@param item
//@usage PrintItem(item);
void PrintItem (ItemType item)
{
   cout << ":Output an item using the friend << operator:" << endl;
   cout << item;
}

//@gets input from user for item
//@pre ItemType item is a data object
//@post item is filled with info from user
//@param item
//@usage GetItem(item);
void GetItem(ItemType& item)
{
   cout << ":Make an Item using the friend >> operator:" << endl;
   cin >> item;
}

//@copies a existing ItemType to another ItemType and uses the constant char to output what case is being used
//@pre copy item and item are existing data objects and whatCase is a string
//@post copyItem contains what item contains in it and it is printed on the screen
//@return copyItem is returned by reference
//@param copyItem
//@param item
//@param whatCase
//@usage TestCopyItem(copyItem, item, whatCase);
void TestCopyItem(ItemType& copyItem, ItemType item, const char* whatCase)
{
   copyItem = item;
   PrintMessage ("copy item", whatCase);
   PrintEmpty (item);
   PrintItem(item);
}

//@retrieves just the sector from ItemType item
//@pre item is a existing data object
//@post returns the int in the sector of item
//@param item
//@usage TestGetSector(item);
void TestGetSector(ItemType item)
{
   cout << "From the ItemType: " << endl;
   cout << item;
   PrintLines(2);
   cout << "We can just get the Sector -> " << item.GetSector() << endl;
}

//@retrieves just the Track from ItemType item
//@pre item is a existing data object
//@post returns the int in the track of item
//@param item
//@usage TestGetTrack(item);
void TestGetTrack(ItemType item)
{
   cout << "From the ItemType: " << endl;
   cout << item;
   PrintLines(2);
   cout << "We can just get the Track -> " << item.GetTrack() << endl;
}

//@retrieves just the ID# from ItemType item
//@pre item is a existing data object
//@post returns the int in the ID# of item
//@param item
//@usage TestGetId(item);
void TestGetId(ItemType item)
{
   cout << "From the ItemType: " << endl;
   cout << item;
   PrintLines(2);
   cout << "We can just get the ID# -> " << item.GetId() << endl;
}

//@retrieves just the Read or Write from ItemType item
//@pre item is a existing data object
//@post returns the int in the ID# of item
//@param item
//@usage TestGetReadWrite(item);
void TestGetReadWrite(ItemType item)
{
   cout << "From the ItemType: " << endl;
   cout << item;
   PrintLines(2);
   cout << "We can just get if it's reading or writing -> ";
    if(item.GetReadWrite() == true)
       cout << "Read" << endl;
    else
       cout << "Write" << endl;
}
