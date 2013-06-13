//@author Dr Y altered by Ryan Draper(draper)
//@date January 25, 2011
//@file sstftester.cpp
//@description: This program fully tests class child class SSTF of parent class Que.

#include <iostream>
#include <fstream>
#include "sstf.h"
using namespace std;

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@makes an itemType that corresponds to the first info fromt the arrivalFile
//@pre infile is the arrivalFile with arrival times and transaction times to be acted upon
//@post returns a ItemType that is in the arrivalFile
//@param infile
//@usage PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
ItemType GetItem(ifstream& infile);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@gets input from user for item
//@pre ItemType item is a data object
//@post item is filled with info from user
//@param item
//@usage GetItem(item);
void GetItem(ItemType& item);

//@Enqueue a specified num times from file to SSTF myq while it is not full otherwise ok is false
//@pre myq is a existing SSTF, num is an int to how many items will be read from a file
//@    file is to be read from and ok is true
//@post myq will have num items enqueued to it from file and ok will remain true while
//@     SSTF myq is not full
//@returns myq full of items from file
//@param myq
//@      num
//@      ok
//@      file
//@usage EnqueueItem(myq, 1, discFile, ok);
void EnqueueItem(SSTF& myq, int num, ifstream& file, bool& ok);

int main()
{
   SSTF myq;
   ItemType it, item;
   ifstream discFile;
   bool ok;

   OpenInputFile(discFile, ok);
   
   PrintLines(3);
   PrintMessage ("copy constructor", "empty");
   SSTF bq(myq);

   PrintMessage ("Find Next Track", "empty");
   cout << myq.FindNextTrack();

   ToContinue();  
   
   EnqueueItem(myq, 1, discFile, ok);
   PrintMessage("Enqueue", "size 1");
   cout << myq << endl;
   PrintMessage ("Find Next Track", "size 1");
   cout << myq.FindNextTrack();
   PrintBool (ok);

   ToContinue();
   
   
   EnqueueItem(myq, 1, discFile, ok);
   PrintMessage("Enqueue", "size 2");
   cout << myq << endl;
   PrintMessage ("Find Next Track", "size 2");
   cout << myq.FindNextTrack();
   PrintBool (ok);
 
   PrintMessage ("copy constructor", "size 2");
   SSTF otherq(myq);
   cout << otherq << endl;

   ToContinue();
     
   EnqueueItem(myq, 1, discFile, ok);
   PrintMessage("Enqueue", "size 3");
   cout << myq << endl;
   PrintMessage ("Find Next Track", "size 3");
   cout << myq.FindNextTrack();
   PrintBool (ok);
 
   ToContinue();
   
   EnqueueItem(myq, 1, discFile, ok);
   PrintMessage("Enqueue", "size 4");
   cout << myq << endl;
   PrintMessage ("Find Next Track", "size 4");
   cout << myq.FindNextTrack();
   PrintBool (ok);
   
   ToContinue();

   PrintMessage ("Find Next Track to Dequeue", "size 4");
   cout << myq.FindNextTrack();
   PrintMessage("Dequeue", "size 4");
   myq.Dequeue(ok);
   PrintBool(ok);
   cout << myq << endl;
   
   ToContinue();
   
   PrintMessage ("Find Next Track to Dequeue", "size 3");
   cout << myq.FindNextTrack();
   PrintMessage("Dequeue", "size 3");
   myq.Dequeue(ok);
   PrintBool(ok);
   cout << myq << endl;
   
   ToContinue();
   
   PrintMessage ("Find Next Track to Dequeue", "size 2");
   cout << myq.FindNextTrack();
   PrintMessage("Dequeue", "size 2");
   myq.Dequeue(ok);
   PrintBool(ok);
   cout << myq << endl;
   
   ToContinue();
   
   PrintMessage ("Find Next Track to Dequeue", "size 1");
   cout << myq.FindNextTrack();
   PrintMessage("Dequeue", "size 1");
   myq.Dequeue(ok);
   PrintBool(ok);
   cout << myq << endl;
   
   ToContinue();
   
   PrintMessage ("Find Next Track to Dequeue", "empty");
   cout << myq.FindNextTrack();
   PrintMessage("Dequeue", "empty");
   myq.Dequeue(ok);
   PrintBool(ok);
   cout << myq << endl;
   
   PrintLines(3);   
   return 0;   
}

//@Enqueue a specified num times from file to SSTF myq while it is not full otherwise ok is false
//@pre myq is a existing SSTF, num is an int to how many items will be read from a file
//@    file is to be read from and ok is true
//@post myq will have num items enqueued to it from file and ok will remain true while
//@     SSTF myq is not full
//@returns myq full of items from file
//@param myq
//@      num
//@      ok
//@      file
//@usage EnqueueItem(myq, 1, discFile, ok);
void EnqueueItem(SSTF& myq, int num, ifstream& file, bool& ok)
{
   ItemType item;
   
   for(int i = 0; i < num; i++)
   {
      item = GetItem(file);
      myq.Enqueue(item, ok);
   }
}
//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("in2.txt");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR: opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@makes an itemType that corresponds to the first info fromt the arrivalFile
//@pre infile is the arrivalFile with arrival times and transaction times to be acted upon
//@post returns a ItemType that is in the arrivalFile
//@param infile
//@usage PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
ItemType GetItem(ifstream& infile)
{
   ItemType event;
   bool ok;
   
   infile >> event;
   PrintMessage(" has an Item Type put in the Event List.", "here");

   return event;
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

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok)
{
   cout << endl << "          Boolean value is ";
   if (ok)
      cout << "true";
   else
      cout << "false";
   cout << endl;
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

