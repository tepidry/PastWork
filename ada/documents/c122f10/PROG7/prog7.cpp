//@file prog7.cpp
//@date: Oct 25, 2010
//@author Ryan Draper (draper)

//@description: This program will use a linked list from the struct NodeType and create using the variables
//@             item type info as a set of integers and the node next.  Using the linked list functions 
//@             will be used to find the sum of the list, add another item in 
//@             the front of the list, and return the last integer from the linked list.

#include <ctime>
#include <cstdlib>     
#include <iostream>
using namespace std;

typedef int ItemType;
struct NodeType
{
   ItemType info;
   NodeType* next;
};

//@makes a list of size even numbers starting at 2
//@pre: size is a non-negative value
//@post: firstptr points to a list of size successive even numbers
//@param firstptr
//@param size
//@usage: MakeList (first, 3);
void MakeList (NodeType*& firstptr, int size);

//@prints a list of numbers
//@pre: firstptr points to a possibly empty list
//@post: prints the data in list if nonempty else prints a message
//@param firstptr
//@usage: PrintList(firstptr);
void PrintList (NodeType* firstptr);

//@prints a number of new lines
//@pre: num >= 1
//@post: outputs num newline characters
//@param num
//@usage: PrintNewLines(3);
void PrintNewLines (int num);

//@frees the memory in the heap used by the list
//@pre firstptr points to a list but may be empty
//@post the memory for the nodes is returned to the heap
//@     and firstptr is NULL
//@param firstptr
//@usage  DeleteAll(firstptr);
void DeleteAll(NodeType*& firstptr);

//@sums up the numbers in a list
//@pre  firstptr points to a list that may be empty
//@post if the list is empty the sum is 0 otherwise the sum is
//      the total of the numbers in the list
//@return sum
//@param firstptr
//@usage  YOU DO
int FindSum(NodeType* firstptr);

//@determines if a list is empty
//@pre firstptr is a list which may be empty
//@post if firstptr is an empty list then returns true else returns false
//@param firstptr
//@returns true or false depending on empty or not
//@usage if (IsEmpty(firstptr))
bool IsEmpty(NodeType* firstptr);

//@gets the last number in a list of nonnegative numb
//@pre firstptr is a nonempty list
//@post finds the last item in the list
//@param firstptr points to the beginning of the list
//@return the last number in the list
//@usage YOU DO
ItemType GetLast(NodeType* firstptr);

//@adds a new item to the beginning of the list
//@pre firstptr may be empty
//@post new item is added at the beginning of the list
//@param newItem
//@param firstptr
//@usage YOU DO
void AddAtFront(NodeType*& firstptr, int newItem);

//@This allows the screen to stop and wait for the user 
//@to hit enter before continuing.
//@post will continue with the program once enter has be hit by the user.
//@usage PressEnter();
void PressEnter();

//@This function print Next Case on the screen when it is appropriate to the condition
//@pre listSize has to refrence the size of a list being printed out
//@post cout's Next Case  
//@param listSize
//@usage NextCase(listSize);
void NextCase(int listSize);

//@This will increment the size of the list
//@pre listSize in an int
//@post will past list Size either incremented by one or multiplied by three.
//@param listSize
//@usage IncrementListSize(listSize);
void IncrementListSize(int& listSize);

//@This will test the function IsEmpty which returns a bool statement
//@depending whether the firstptr is a list or not.
//@pre firstptr will have either NULL or a list assigned
//@post will return a bool statement true if first pointer is a list.
//@     false if it contains NULL.
//@param firstptr
//@usage TestIsEmpty(firstptr);
void TestIsEmpty(NodeType* firstptr);

//@This will test the function GetLast(firstptr)
//@post after a list had been created and the function GetLast
//@     has been tested the list will be deleted
//@param firstptr
//@usage TestGetLast(firstptr);
void TestGetLast(NodeType* firstptr);

//@This will test the function FindSum()
//@post will output Find Sum with sum of the list in firstptr
//@param firstptr
//@usage TestFindSum(firstptr);
void TestFindSum(NodeType* firstptr);

//@This will test the function AddAtFront();
//@post will output tests that add a item to the begging of firstptr
//@param firstptr
//@usage TestAddAtFront(firstptr);
void TestAddAtFront(NodeType* firstptr);

//@fills a the parameter with random integer between 0 and 99
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomBigNum(num);
void MakeRandomBigNumber(int& num);

int main()
{
   NodeType* firstptr;
   
   PrintNewLines(3);
   TestIsEmpty(firstptr);
   
   PrintNewLines(3);
   TestGetLast(firstptr);
   
   PrintNewLines(3);
   TestFindSum(firstptr);
   
   PrintNewLines(3);
   TestAddAtFront(firstptr);
   
   return 0;
}

//@makes a list of size even numbers starting at 2
//@pre: size is a non-negative value
//@post: firstptr points to a list of size successive even numbers
//@param firstptr
//@param size
//@usage: MakeList (first, 3);
void MakeList (NodeType*& firstptr, int size)
{  
   if (size > 0)
   { 
      NodeType *curptr;
      int k, myit;
      firstptr = new NodeType;
      curptr = firstptr;
      myit = 2;
      curptr -> info = myit;
      curptr -> next = NULL;
      for (k = 1; k < size; k++)
      {
         curptr -> next = new NodeType;
         curptr = curptr -> next;
         myit = 2 * k + 2;
         curptr -> info = myit;
         curptr -> next = NULL;
      }
   } else {
      firstptr = NULL;
   }
}

//@prints a list of numbers
//@pre: firstptr points to a NONEMPTY list
//@post: prints the data in list
//@param firstptr
//@usage: PrintList(firstptr);
void PrintList (NodeType* firstptr)
{
   NodeType* curptr = firstptr; 
   while (curptr != NULL)
   {
      cout << curptr -> info;
      curptr = curptr -> next;
      if (curptr != NULL) {
         cout  << " , ";
      }
   }
   cout << endl;
}


//@prints a number of new lines
//@pre: num >= 1
//@post: outputs num newline characters
//@param num
//@usage: PrintNewLines(3);
void PrintNewLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

//@frees the memory in the heap used by the list
//@pre: firstptr points to a list but may be empty
//@post: the memory for the nodes is returned to the heap
//@     and firstptr is NULL
//@param firstptr
//@usage:  DeleteAll(firstptr);
void DeleteAll(NodeType*& firstptr)
{
   NodeType* delptr;
   
   while (firstptr != NULL)
   {
      delptr = firstptr;
      firstptr = firstptr -> next;
      delptr -> next = NULL;  
      delete delptr;
   }
}

//@sums up the numbers in a list
//@pre: firstptr points to a list that may be empty
//@post: if the list is empty the sum is 0 otherwise the sum is
//      the total of the numbers in the list
//@return: sum
//@param firstptr
//@usage:  cout << "The FindSum function returns the sum of the list = " << FindSum(firstptr) << endl;
int FindSum(NodeType* firstptr)
{
   int sum = 0;
   
   if (!IsEmpty(firstptr)) {
      while (firstptr != NULL)
      {
         sum = firstptr -> info + sum;
         firstptr = firstptr -> next;
      }
   }
   return sum;
    
   
}

//@determines if a list is empty
//@pre firstptr is a list which may be empty
//@post if firstptr is an empty list then returns true else returns false
//@param firstptr
//@returns true or false depending on empty or not
//@usage if (IsEmpty(firstptr))
bool IsEmpty(NodeType* firstptr)
{
   if (firstptr == NULL) {
      return true;
   } else {
      return false;
   }
}

//@gets the last number in a list of nonnegative numb
//@pre firstptr is a nonempty list
//@post finds the last item in the list
//@param firstptr points to the beginning of the list
//@return the last number in the list
//@usage cout << "The GetLast function returns the last digit --> " << GetLast(firstptr) << endl;
ItemType GetLast(NodeType* firstptr)
{
   while (firstptr -> next != NULL)
   {
      firstptr = firstptr -> next;
   }
   return firstptr -> info;     
}

//@adds a new item to the beginning of the list
//@pre firstptr may be empty
//@post new item is added at the beginning of the list
//@param newItem
//@param firstptr
//@usage AddAtFront(firstptr, item);
void AddAtFront(NodeType*& firstptr, int newItem)
{
   NodeType *frontptr;
   frontptr = new NodeType;
   frontptr -> info = newItem;
   frontptr -> next = NULL;
   if (firstptr != NULL) {
      frontptr -> next = firstptr;
   }
   firstptr = frontptr;
}

//@This allows the screen to stop and wait for the user 
//@to hit enter before continuing.
//@post will continue with the program once enter has be hit by the user.
//@usage PressEnter();
void PressEnter()
{
	cout << "Press <Enter> to continue!";
   cin.get();
   PrintNewLines(3);
}

//@This function print Next Case on the screen when it is appropriate to the condition
//@pre listSize has to refrence the size of a list being printed out
//@post cout's Next Case  
//@param listSize
//@usage NextCase(listSize);
void NextCase(int listSize)
{
   if (listSize < 10) {
      cout << "Next Case:" << endl;
   }
}

//@This will increment the size of the list
//@pre listSize in an int
//@post will past list Size either incremented by one or multiplied by three.
//@param listSize
//@usage IncrementListSize(listSize);
void IncrementListSize(int& listSize)
{
   if (listSize >= 3) {
      listSize = listSize * 3;
   } else {
      listSize++;
   }
}

//@This will test the function GetLast(firstptr) 
//@post after a list had been created and the function GetLast
//@     has been tested the list will be deleted
//@param firstptr
//@usage TestGetLast(firstptr);
void TestGetLast(NodeType* firstptr)
{
   int listSize = 1;
   
	cout << "FUNCTION: GetLast ->";
	PrintNewLines(2);
	cout << "First Case:" << endl;
	
	while (listSize < 30)
	{
		MakeList (firstptr, listSize);
		cout << "For a non-empty list with " << listSize << " integer(s) that looks like :" << endl;
		PrintList(firstptr);
		cout << "The GetLast function returns the last digit --> " << GetLast(firstptr) << endl;
		PrintNewLines(1);
		DeleteAll(firstptr);
		
		PressEnter();
		NextCase(listSize);
		IncrementListSize(listSize);
	}
}

//@This will test the function FindSum()
//@post will output Find Sum with sum of the list in firstptr
//@param firstptr
//@usage TestFindSum(firstptr);
void TestFindSum(NodeType* firstptr)
{
   int listSize = 0;
   
	cout << "FUNCTION: FindSum ->";
	PrintNewLines(2);
	cout << "First Case:" << endl;
	
	while (listSize < 30)
	{
		MakeList (firstptr, listSize);
		cout << "For a list with " << listSize << " integer(s) that looks like :" << endl;
		PrintList(firstptr);
		cout << "The FindSum function returns the sum of the list = " << FindSum(firstptr) << endl;
		PrintNewLines(1);
		DeleteAll(firstptr);
		
		PressEnter();
		NextCase(listSize);
      IncrementListSize(listSize);
	}
}

//@This will test the function AddAtFront();
//@post will output tests that add a item to the begging of firstptr
//@param firstptr
//@usage TestAddAtFront(firstptr);
void TestAddAtFront(NodeType* firstptr)
{
   int item;
   int listSize = 0;
   
   cout << "FUNCTION: AddAtFront ->";
   PrintNewLines(2);
	cout << "First Case:" << endl;
	
   while (listSize < 30)
   {
      MakeRandomBigNumber(item);
      MakeList (firstptr, listSize);
      cout << "For a list with " << listSize << " integer(s) that looks like :" << endl;
      PrintList(firstptr);
      cout << "The AddAtFront function returns the list with " << endl;
      cout << "the random number " << item << " in the front of it :" << endl;
      AddAtFront(firstptr, item);
      PrintList(firstptr);
      PrintNewLines(1);
      DeleteAll(firstptr);
      
      PressEnter();
		NextCase(listSize);
      IncrementListSize(listSize);
	}
}

//@This will test the function IsEmpty which returns a bool statement
//@depending whether the firstptr is a list or not.
//@pre firstptr will have either NULL or a list assigned
//@post will return a bool statement true if first pointer is a list.
//@     false if it contains NULL.
//@param firstptr
//@usage TestIsEmpty(firstptr);
void TestIsEmpty(NodeType* firstptr)
{
   int listSize = 0;
   
   cout << "FUNCTION: IsEmpty ->";
   PrintNewLines(2);
   cout << "First Case:" << endl;
	
   while (listSize < 10)
   {
      MakeList (firstptr, listSize);
      cout << "For a list with " << listSize << " integer(s)" << endl; 
      cout << "IsEmpty() will return -> " << IsEmpty(firstptr) << endl;
      cout << "Returning 1 for true list is empty, or 0 for false list isn't empty.";
      PrintNewLines(2);
      
      PressEnter();
      NextCase(listSize + 1);
      IncrementListSize(listSize);
   }
}

//@fills a the parameter with random integer between 0 and 99
//@pre num is assigned
//@post num is assigned with a random number
//@param num
//@usage MakeRandomBigNum(num);
void MakeRandomBigNumber(int& num)
{
   num = rand() % 1000;
}
