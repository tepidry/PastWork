//@author Ryan Draper(draper)
//@date January 25, 2011
//@file prog2.cpp
//@description: This Program will simulate a metal disc that can be read from or written to
//@         In this simulation we will use the class SSTF(shortest seek time first) which is 
//@         derived from class Que. 

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
   
//@returns true if the dummy amount is the next item in the input file
//@pre event is the next item read from the disc File
//@post returns true unless the next amount is -1 which is located at the end of the disc File
//@param tempItem
//@usage while(NotEndOfInputFile(item));
bool NotEndOfInputFile(ItemType tempItem);

//@Takes in all data on the disc file into the disc que 
//@pre discFile is where we fill the SSTF discQue from and ok is true
//@post inserts the events into the disc Que in a unorganized order from the file ok is true as long as the 
//@     que is not full
//@param discFile
//@      discQue
//@      ok
//@usage FillDiscQue(infile, discQue, ok);
void FillDiscQue(ifstream& discFile, SSTF& discQue, bool& ok);          
 
//@makes an itemType that corresponds to the first info fromt the discFile
//@pre infile is the discFile with que items that are put into a ItemType
//@post returns a ItemType that is in the discFile
//@param infile
//@usage item = GetFromDiscFile(discFile);
ItemType GetFromDiscFile(ifstream& infile);            
     
//@this will output what this program does as it acts upon the que
//@post outputs words
//@usage Start();
void Start();  

//@Prints the Que and prompts to show what track the head reader writer is moving to next
//@pre discQue is a existing SSTF
//@post outputs que and next SST track first
//@param discQue
//@usage SnapShot(discQue);
void SnapShot(SSTF discQue); 

//@Prints the Item in the que that is the shortest time from current track and dequeue's it
//@pre discQue is a existing que and ok is true while discque is not empty
//@post discQue is dequeued the closest track
//@param discQue
//@      ok
//@usage DequeueSSTFTrack(discQue, ok);  
void DequeueSSTFTrack(SSTF& discQue, bool& ok);

int main()
{
   SSTF discQue;
   ifstream discFile;
   ItemType item;
   bool ok;
    
   Start();
   OpenInputFile(discFile, ok);   
   FillDiscQue(discFile, discQue, ok);
   
   while (not discQue.IsEmpty()) {
      SnapShot(discQue);
      DequeueSSTFTrack(discQue, ok);
   }
     
   SnapShot(discQue);

   return 0;   
}
 
//@this will output what this program does as it acts upon the que
//@post outputs words
//@usage Start();
void Start()
{    
	PrintLines(2);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "This program will simulate a que reading from and" << endl; 
	cout << "  to a metal disc using a shortest seek time to " << endl;
	cout << "  determinethe next track that it will act upon." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	ToContinue();
}
 
//@Prints the Item in the que that is the shortest time from current track and dequeue's it
//@pre discQue is a existing que and ok is true while discque is not empty
//@post discQue is dequeued the closest track
//@param discQue
//@      ok
//@usage DequeueSSTFTrack(discQue, ok); 
void DequeueSSTFTrack(SSTF& discQue, bool& ok)
{
   PrintLines(2); 
   cout << "< Item " << discQue.FindNextTrack() << " is DeQueued/Processed >" << endl;
   discQue.Dequeue(ok);
   
   ToContinue(); 
}   

//@Prints the Que and prompts to show what track the head reader writer is moving to next
//@pre discQue is a existing SSTF
//@post outputs que and next SST track first
//@param discQue
//@usage SnapShot(discQue);
void SnapShot(SSTF discQue)
{                 
   ItemType track;
        
   
   track = discQue.FindNextTrack(); 
   PrintLines(2);
   cout << discQue;
   PrintLines(2);
   if (discQue.IsEmpty()) 
      cout << "< Que is empty head doesn't move >" << endl;
   else                        
      cout << "< Head Moves To Track " << track.GetTrack() <<" >" << endl;
   
   ToContinue();
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

//@returns true if the dummy amount is the next item in the input file
//@pre event is the next item read from the disc File
//@post returns true unless the next amount is -1 which is located at the end of the disc File
//@param tempItem
//@usage while(NotEndOfInputFile(item));
bool NotEndOfInputFile(ItemType tempItem) 
{          
   return (tempItem.GetId() != -1);
}
       
//@Takes in all data on the disc file into the disc que 
//@pre discFile is where we fill the SSTF discQue from and ok is true
//@post inserts the events into the disc Que in a unorganized order from the file ok is true as long as the 
//@     que is not full
//@param discFile
//@      discQue
//@      ok
//@usage FillDiscQue(infile, discQue, ok);
void FillDiscQue(ifstream& discFile, SSTF& discQue, bool& ok)
{        
   ItemType item;
 
   item = GetFromDiscFile(discFile); 
   while (NotEndOfInputFile(item)) {
      discQue.Enqueue(item, ok);
	  item = GetFromDiscFile(discFile);
   }

}
    
//@makes an itemType that corresponds to the first info fromt the discFile
//@pre infile is the discFile with que items that are put into a ItemType
//@post returns a ItemType that is in the discFile
//@param infile
//@usage item = GetFromDiscFile(discFile);
ItemType GetFromDiscFile(ifstream& infile) 
{    
   ItemType event;
   
   infile >> event;

   return event;   
}



