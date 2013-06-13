//@file proglast.cpp
//@date: Dec 9, 2010
//@author Ryan Draper (draper)

//@description: This program tests the functions in clist.h and que.h to simulate a Bank Queue
//@             using a bent dynamic array as the Que and a linked list as the event list using the
//@             information from file inlast.txt

#include "clist.h"
#include "que.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

//@prints a number of newlines on the screen
//@pre num is nonnegative
//@post num newlines are output on the screen
//@param num
//@usage PrintNewLines(3);
void PrintNewLines(int num);

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@Waits for user to hit enter to move on
//@pre bankQueue is a Que and eventList is a List
//@post cout on screen a pause between events
//@param bankQueue
//@      eventList
//@usage GoToNextTest();
void Continue(Que bankQueue, List eventList);

//@Makes the list using the file in9.txt
//@pre a int of how many items to take from the file and the list where they are stored
//@post the list numlist has integers filled to the tot amount
//@param tot
//@      numlist
//@returns numlist with integers from the file
//@usage MakeList(9, list);
ItemType ArrivalFromEventFile(ifstream& infile);

//@increments the int current time to relate to the next event
//@pre currentTime contains an int and newEvent may or may not contain the next event from eventList
//@post currentTime is advanced to the next events arrival or departure time
//@param currentTime
//@      newEvent
//@returns the currentTime by reference
//@usage TimeMovesToNextEvent(currentTime, newEvent);
void TimeMovesToNextEvent(int& currentTime, ItemType newEvent);

//@retrieves the first event from eventList and places it in the newEvent
//@pre the first event is put into newEvent from eventList
//@post newEvent is Passed by reference with the ItemType from the first position in eventList
//@param eventList
//@      newEvent
//@      ok
//@usage GetNewEventFromEventList(eventList, newEvent, ok);
void GetNewEventFromEventList(List eventList, ItemType& newEvent, bool& ok);

//@returns true if the newEvent ItemType eventType holds the char 'A'
//@pre newEvent holds the current ItemType
//@post returns true if eventType holds and "A"
//@param neweEvent
//@usage NewEventIsArrival(newEvent);
bool NewEventIsArrival(ItemType newEvent);

//@returns true if the dummy amount is the next item in the input file
//@pre event is the next item read from the arrival File
//@post returns true unless the next amount is -1 which is located at the end of the arrival File
//@param event
//@usage EndOfInputFile(newEvent);
bool EndOfInputFile(ItemType event);

//@returns true if the bankQueue is not empty
//@pre bamkQueue is a Que
//@post returns true unless the bankQueue is empty
//@param bankQueue
//@usage BankLineIsNotEmpty(bankQueue
bool BankLineIsNotEmpty(Que bankQueue);

//@returns true if the bankQueue is empty
//@pre bankQueue is a Que
//@post returns true unless the Que is empty
//@param bankQueue
//@usage BankLineIsEmpty(bankQueue);
bool BankLineIsEmpty(Que bankQueue);

//@returns whether or not the evnetList is empty or not
//@pre the eventList is an active linked list
//@post returns true if the list is not empty
//@param eventList
//@usage EventListIsNotEmpty(eventList);
bool EventListIsNotEmpty(List eventList);

//@returns whether or not the evnetList is empty or not
//@pre the eventList is an active linked list
//@post returns true if the list is empty
//@param eventList
//@usage EventListIsNotEmpty(eventList);
bool EventListIsEmpty(List eventList);

//@bank line que is enqueued and the eventList is deleted the first postion
//@pre bankQueue is a Que and eventList list newEvent holds the next event and ok is true
//@post bankQueue contains new item in the Que
//@param bankQueue
//@      newEvent
//@      eventList
//@      ok
//@usage CustomerEntersBankLine(bankQueue, newEvent, eventList, ok);
void CustomerEntersBankLine(Que& bankQueue, ItemType newEvent, List& eventList, bool& ok);

//@both the bankQueue and eventList gets the first index itemType removed
//@pre bankQueue is a Que eventList is List and ok is true
//@post bankQueue gets dequeued one event and eventList gets the first index removed ok will remain true
//@param bankQueue
//@      eventList
//@      ok
//@usage CustomerExitsBankLine(bankQueue, eventList, ok);
void CustomerExitsBankLine(Que& bankQueue, List& eventList, bool& ok);

//@creates a new ItemType that is a departure for the first person in the bankQueue
//@pre currentTime is the time the person enters the bankQueue and the bankQueue is a Que
//@post returns a departure ItemType that corresponds to the first person in the bankQueue
//@param currentTime
//@      bankQueue
//@usage PutIntoEventList(DepartureEventForPersonInLine(currentTime, bankQueue), eventList, ok);
ItemType DepartureEventForPersonInLine(int currentTime, Que bankQueue);

//@organizes the Itemtype event according to the arrival time of the items in the list to the incoming event
//@pre event is a event and eventList is a list and ok is true
//@post inserts the event into the appropriate place in eventList according to the ItemType arrivalTime
//@param event
//@      eventList
//@      ok
//@usage PutIntoEventList(DepartureEventForPersonInLine(currentTime, bankQueue), eventList, ok);
void PutIntoEventList(ItemType event, List& eventList, bool& ok);

//@processes the arrival of a new event type into the event list and the bank queue
//@pre newEvent contains the current event from clist eventList, arrivalFile is where the eventList is 
//@    filled with customer info, arrival Times, and trasaction times from that are pending for the bank queue
//@    which may or may not be empty and current Time contains an int that relates to the arrival Time
//@post the bankqueue has a new Item Type filled with customer info, arrival Time, and transaction time
//@     if the banqueue was previously empty then there is a departure event created according to that 
//@     info if it is the end of the input file then a new arrival from the file is read into eventList
//@param newEvent
//@      arrivalFile
//@      eventList
//@      bankQueue
//@      currentTime
//@usage ProcessArrival(newEvent, arrivalFile, eventList, bankQueue, currentTime);
void ProcessArrival(ItemType newEvent, ifstream& arrivalFile, List& eventList, Que& bankQueue, int currentTime);

//@processes a departure from the event list and the bank queue
//@pre newEvent contains the current event from clist eventList, the bank queue is filled 
//@    with event(s) to be processed and currentTime has an int relating to the arrival Time
//@post bank queue gets dequeued one event and if there is still more events a departure
//@     is placed in the eventList that corresponds to the front of the line in the que
//@param newEvent
//@      eventList
//@      bankQueue
//@      currentTime
//@usage ProcessDeparture(newEvent, eventList, bankQueue, currentTime);
void ProcessDeparture(ItemType newEvent, List& eventList, Que& bankQueue, int currentTime);

//@Prints out a snap shot of the time, que, and the upcoming list
//@pre currentTime holds an int that is the time, bankqueue and eventList may or may not hold events
//@post output on the screen reads the current time, bank queue, and event List
//@param currentTime
//@      bankQueue
//@      eventList
//@usage PrintOutSnapShot(currentTime, bankQueue, eventList);
void PrintOutSnapShot(int currentTime, Que bankQueue, List eventList);

//@Prints the Time or the time of next event
//@pre message is a string ints hour and min are the hour and min of time
//@post the time is output on the screen with the message output before it
//@param message
//@      hour
//@      min
//@usage PrintCertainTime("TIME -> ", curHour, currentTime);
void PrintCertainTime(const char* message, int hour, int min);

//Prints a large money symbol and stick figures according to the size of the bankQueue
//@pre bankQueue is an active Que
//@post bankQueue is output on the screen as a bank line
//@param bankQueue
//@usage PrintBankQueue(bankQueue);
void PrintBankQueue(Que bankQueue);

//@prints a message on the screen
//@pre message is a string and event is an clist ItemType
//@post CustNum of event and the message are output on the screen
//@usage PrintMessage(" has an Arrival put in the Event List.", event);
void PrintMessage(const char* message, ItemType event);

//@Prints out a opening message
//@post outputs opening message
//@usage PrintOpenMessage();
void PrintOpenMessage();

int main()
{
   List eventList;
   Que bankQueue;
   ItemType newEvent;
   ifstream arrivalFile;
   int currentTime = 0;
   bool ok;
   
   OpenInputFile(arrivalFile, ok);
   
   PrintOpenMessage();
   PrintOutSnapShot(currentTime, bankQueue, eventList);
   PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
   PrintOutSnapShot(currentTime, bankQueue, eventList);
   
   while (EventListIsNotEmpty(eventList))
   {
      GetNewEventFromEventList(eventList, newEvent, ok);
      TimeMovesToNextEvent(currentTime, newEvent);
      if (NewEventIsArrival(newEvent)){
         ProcessArrival(newEvent, arrivalFile, eventList, bankQueue, currentTime);
      } else {
         ProcessDeparture(newEvent, eventList, bankQueue, currentTime);
      }
      
   }
}

//@Prints out a opening message
//@post outputs opening message
//@usage PrintOpenMessage();
void PrintOpenMessage()
{
   PrintNewLines(3);
   cout << "===================================================" << endl;
   cout << "     {THIS PROGRAM WILL ENACT A BANK QUE LINE}" <<  endl;
   cout << "===================================================" << endl;
}

//@processes the arrival of a new event type into the event list and the bank queue
//@pre newEvent contains the current event from clist eventList, arrivalFile is where the eventList is 
//@    filled with customer info, arrival Times, and trasaction times from that are pending for the bank queue
//@    which may or may not be empty and current Time contains an int that relates to the arrival Time
//@post the bankqueue has a new Item Type filled with customer info, arrival Time, and transaction time
//@     if the banqueue was previously empty then there is a departure event created according to that 
//@     info if it is the end of the input file then a new arrival from the file is read into eventList
//@param newEvent
//@      arrivalFile
//@      eventList
//@      bankQueue
//@      currentTime
//@returns pointer in eventList and bankQueue are passed 
//@usage ProcessArrival(newEvent, arrivalFile, eventList, bankQueue, currentTime);
void ProcessArrival(ItemType newEvent, ifstream& arrivalFile, List& eventList, Que& bankQueue, int currentTime)
{
   ItemType temp;
   bool ok, frontOfLine;
   
   frontOfLine = BankLineIsEmpty(bankQueue);
   CustomerEntersBankLine(bankQueue, newEvent, eventList, ok);
   if (frontOfLine) {
      PutIntoEventList(DepartureEventForPersonInLine(currentTime, bankQueue),eventList, ok);
      PrintOutSnapShot(currentTime, bankQueue, eventList);
   }
   if (not EndOfInputFile(newEvent)){
      PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
      PrintOutSnapShot(currentTime, bankQueue, eventList);
   }
}

//@processes a departure from the event list and the bank queue
//@pre newEvent contains the current event from clist eventList, the bank queue is filled 
//@    with event(s) to be processed and currentTime has an int relating to the arrival Time
//@post bank queue gets dequeued one event and if there is still more events a departure
//@     is placed in the eventList that corresponds to the front of the line in the que
//@param newEvent
//@      eventList
//@      bankQueue
//@      currentTime
//@returns eventList and bankQueue are passed by reference
//@usage ProcessDeparture(newEvent, eventList, bankQueue, currentTime);
void ProcessDeparture(ItemType newEvent, List& eventList, Que& bankQueue, int currentTime)
{
   bool ok;
   
   CustomerExitsBankLine(bankQueue, eventList, ok);
   if (BankLineIsNotEmpty(bankQueue))
      PutIntoEventList(DepartureEventForPersonInLine(currentTime, bankQueue), eventList, ok);
      PrintOutSnapShot(currentTime, bankQueue, eventList);
}

//@Prints out a snap shot of the time, que, and the upcoming list
//@pre currentTime holds an int that is the time, bankqueue and eventList may or may not hold events
//@post output on the screen reads the current time, bank queue, and event List
//@param currentTime
//@      bankQueue
//@      eventList
//@usage PrintOutSnapShot(currentTime, bankQueue, eventList);
void PrintOutSnapShot(int currentTime, Que bankQueue, List eventList)
{
   bool ok;
   int curHour = 0;
   int evenHour = 0;
   ItemType temp;

   if (EventListIsNotEmpty(eventList)) {
      eventList.RetrieveIth(0, temp, ok);
   } else {
      temp.arrivalTime = currentTime;
   }
   
   PrintNewLines(2);
   
   PrintCertainTime("TIME -> ", curHour, currentTime);
   PrintCertainTime("NEXT EVENT-> ", evenHour, temp.arrivalTime);
   
   PrintNewLines(2);
   
   PrintBankQueue(bankQueue);

   PrintNewLines(2);
   
   eventList.Print();
   
   PrintNewLines(3);
   
   Continue(bankQueue, eventList);
}

//@Prints the Time or the time of next event
//@pre message is a string ints hour and min are the hour and min of time
//@post the time is output on the screen with the message output before it
//@param message
//@      hour
//@      min
//@usage PrintCertainTime("TIME -> ", curHour, currentTime);
void PrintCertainTime(const char* message, int hour, int min)
{
   hour = min / 60;
   min = min % 60;
   if (min >= 10) {
      cout << message << hour << ":" << min << "     ";
   } else if (min < 10) {
      cout << message << hour << ":0" << min << "     ";
   }
}

//Prints a large money symbol and stick figures according to the size of the bankQueue
//@pre bankQueue is an active Que
//@post bankQueue is output on the screen as a bank line
//@param bankQueue
//@usage PrintBankQueue(bankQueue);
void PrintBankQueue(Que bankQueue)
{
   cout << bankQueue << endl;
   
   cout << setw(15) << left << " _$_";
   for (int i = 1; i <= bankQueue.GetSize(); i++)
   {
      cout << setw(12) << " ^";
   }
   cout << endl;
   cout << setw(15) << left << "( $ )";
   for (int i = 1; i <= bankQueue.GetSize(); i++)
   {
      cout << setw(12) << " 0";
   }
   cout << endl;
   cout << setw(15) << left << " \\$";
   for (int i = 1; i <= bankQueue.GetSize(); i++)
   {
      cout << setw(12) << "/|\\";
   }
   cout << endl;
   cout << setw(15) << left << "  $\\";
   for (int i = 1; i <= bankQueue.GetSize(); i++)
   {
      cout << setw(12) << "/ \\";
   }
   cout << endl;
   cout << setw(15) << left << "(_$_) {Front}" << endl;
   cout << setw(15) << left << "  $" << endl;
}

//@prints a message on the screen
//@pre message is a string and event is an clist ItemType
//@post CustNum of event and the message are output on the screen
//@usage PrintMessage(" has an Arrival put in the Event List.", event);
void PrintMessage (const char* message, ItemType event)
{
   if (event.custNum > 0) {
      cout << "Customer #" << event.custNum << message << endl;
   }
}

//@prints a number of newlines on the screen
//@pre num is nonnegative
//@post num newlines are output on the screen
//@param num
//@usage PrintNewLines(3);
void PrintNewLines(int num)
{
   for (int k = 0; k < num; k++)
   {
      cout << endl;
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
   infile.open("inlast.txt");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR: opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@Waits for user to hit enter to move on
//@pre bankQueue is a Que and eventList is a List
//@post cout on screen a pause between events
//@param bankQueue
//@      eventList
//@usage GoToNextTest();
void Continue(Que bankQueue, List eventList)
{
   cout << "===================================================" << endl;
   cout << "Press <enter> to continue ->";
   cin.get();
   cout << "===================================================" << endl;
   PrintNewLines(2);
   if (BankLineIsNotEmpty(bankQueue) or EventListIsNotEmpty(eventList)) 
      cout << "ACTION:-> " << endl;
}

//@makes an itemType that corresponds to the first info fromt the arrivalFile
//@pre infile is the arrivalFile with arrival times and transaction times to be acted upon
//@post returns a ItemType that is in the arrivalFile
//@param infile
//@usage PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
ItemType ArrivalFromEventFile(ifstream& infile)
{
   ItemType event;
   bool ok;
   
   infile >> event.custNum;
   event.eventType = 'A';
   infile >> event.arrivalTime;
   infile >> event.transactionTime;
   
   PrintMessage(" has an Arrival put in the Event List.", event);

   return event;
}

//@increments the int current time to relate to the next event
//@pre currentTime contains an int and newEvent may or may not contain the next event from eventList
//@post currentTime is advanced to the next events arrival or departure time
//@param currentTime
//@      newEvent
//@returns the currentTime by reference
//@usage TimeMovesToNextEvent(currentTime, newEvent);
void TimeMovesToNextEvent(int& currentTime, ItemType newEvent)
{
   currentTime = newEvent.arrivalTime;
}

//@retrieves the first event from eventList and places it in the newEvent
//@pre the first event is put into newEvent from eventList
//@post newEvent is Passed by reference with the ItemType from the first position in eventList
//@param eventList
//@      newEvent
//@      ok
//@usage GetNewEventFromEventList(eventList, newEvent, ok);
void GetNewEventFromEventList(List eventList, ItemType& newEvent, bool& ok)
{
   eventList.RetrieveIth(0, newEvent, ok);
}

//@returns true if the newEvent ItemType eventType holds the char 'A'
//@pre newEvent holds the current ItemType
//@post returns true if eventType holds and "A"
//@param neweEvent
//@usage NewEventIsArrival(newEvent);
bool NewEventIsArrival(ItemType newEvent)
{
   return newEvent.eventType == 'A';
}

//@returns true if the dummy amount is the next item in the input file
//@pre event is the next item read from the arrival File
//@post returns true unless the next amount is -1 which is located at the end of the arrival File
//@param event
//@usage EndOfInputFile(newEvent);
bool EndOfInputFile(ItemType event)
{  
   return event.custNum == -1;
}

//@returns true if the bankQueue is not empty
//@pre bamkQueue is a Que
//@post returns true unless the bankQueue is empty
//@param bankQueue
//@usage BankLineIsNotEmpty(bankQueue
bool BankLineIsNotEmpty(Que bankQueue)
{
   return (not bankQueue.IsEmpty());
}

//@returns true if the bankQueue is empty
//@pre bankQueue is a Que
//@post returns true unless the Que is empty
//@param bankQueue
//@usage BankLineIsEmpty(bankQueue);
bool BankLineIsEmpty(Que bankQueue)
{
   return bankQueue.IsEmpty();
}

//@returns whether or not the evnetList is empty or not
//@pre the eventList is an active linked list
//@post returns true if the list is not empty
//@param eventList
//@usage EventListIsNotEmpty(eventList);
bool EventListIsNotEmpty(List eventList)
{
   return (not eventList.IsEmpty());
}

//@returns whether or not the evnetList is empty or not
//@pre the eventList is an active linked list
//@post returns true if the list is empty
//@param eventList
//@usage EventListIsNotEmpty(eventList);
bool EventListIsEmpty(List eventList)
{
   return (not eventList.IsEmpty());
}

//@bank line que is enqueued and the eventList is deleted the first postion
//@pre bankQueue is a Que and eventList list newEvent holds the next event and ok is true
//@post bankQueue contains new item in the Que
//@param bankQueue
//@      newEvent
//@      eventList
//@      ok
//@usage CustomerEntersBankLine(bankQueue, newEvent, eventList, ok);
void CustomerEntersBankLine(Que& bankQueue, ItemType newEvent, List& eventList, bool& ok)
{
   QItemType newBankEvent;
   
   newBankEvent.custNum = newEvent.custNum;
   newBankEvent.arrivalTime = newEvent.arrivalTime;
   newBankEvent.transactionTime = newEvent.transactionTime;
   
   bankQueue.Enqueue(newBankEvent, ok);
   eventList.DeleteIth(0, ok);
   
   PrintMessage(" enters the Bank Line.", newEvent);
}

//@both the bankQueue and eventList gets the first index itemType removed
//@pre bankQueue is a Que eventList is List and ok is true
//@post bankQueue gets dequeued one event and eventList gets the first index removed ok will remain true
//@param bankQueue
//@      eventList
//@      ok
//@usage CustomerExitsBankLine(bankQueue, eventList, ok);
void CustomerExitsBankLine(Que& bankQueue, List& eventList, bool& ok)
{
   QItemType temp;
   ItemType event;
   
   bankQueue.GetFront(temp);
   event.custNum = temp.custNum;

   bankQueue.Dequeue(ok);
   eventList.DeleteIth(0, ok); 
   
   PrintMessage(" exits the Bank Line.", event);
}

//@creates a new ItemType that is a departure for the first person in the bankQueue
//@pre currentTime is the time the person enters the bankQueue and the bankQueue is a Que
//@post returns a departure ItemType that corresponds to the first person in the bankQueue
//@param currentTime
//@      bankQueue
//@usage PutIntoEventList(DepartureEventForPersonInLine(currentTime, bankQueue), eventList, ok);
ItemType DepartureEventForPersonInLine(int currentTime, Que bankQueue)
{
   ItemType depart;
   QItemType frontOfLine;
   
   bankQueue.GetFront(frontOfLine);
   
   depart.custNum = frontOfLine.custNum;
   depart.eventType = 'D';
   depart.arrivalTime = currentTime + frontOfLine.transactionTime;
   depart.transactionTime = 0;
   
   PrintMessage(" has a Departure put into the Event List.", depart);

   return depart;
}

//@organizes the Itemtype event according to the arrival time of the items in the list to the incoming event
//@pre event is a event and eventList is a list and ok is true
//@post inserts the event into the appropriate place in eventList according to the ItemType arrivalTime
//@param event
//@      eventList
//@      ok
//@usage PutIntoEventList(DepartureEventForPersonInLine(currentTime, bankQueue), eventList, ok);
void PutIntoEventList(ItemType event, List& eventList, bool& ok)
{
   ItemType compare;
   int count = 0;
   
   if (not EndOfInputFile(event)) {
      eventList.RetrieveIth(count, compare, ok);
      while (compare.arrivalTime <= event.arrivalTime and count != eventList.GetLength())
      {
         count++;
         eventList.RetrieveIth(count, compare, ok);
      }
      eventList.InsertIth(count, event, ok);
   }
}


