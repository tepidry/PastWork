//@file prog9.cpp
//@date: Nov 18, 2010
//@author Ryan Draper (draper)
//@description: this program tests the functions in clist.h constructor, destructor, copy constructor,
//@             DeleteIth, InsertIth, GetLength, IsEmpty, RetrieveIth, Search, Print, ReversePrint
//@              while allowing the user to

#include "clist.h"
#include "que.h"
#include <fstream>
#include <iostream>
using namespace std;


//@test the IsEmpty member function of clist.h
//@post a list has been created and incremented 0 to 2 to show how it handles different lists
//@     while still giving the proper outcome of empty or not.
//@return couts appropriate tests for IsEmpty();
//@usage TestIsEmpty(); 
void TestIsEmpty();

//@tests the print function 
//@pre list exists
//@post couts the list or the word nothing if empty
//@usage TestPrint(list);
void TestPrint(List printList);

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void PrintNewLines(int num);

//@Opens the input file in9.txt in this case so that it may be read by the program
//@pre infile and a bool variable must be made
//@post infile is open to be read else ok is returned false if there is an error
//@param infile
//@      ok
//@returns an open file in9.txt
//@usage OpenInputFile(infile, ok);
void OpenInputFile(ifstream& infile, bool& ok);

//@Makes the list using the file in9.txt
//@pre a int of how many items to take from the file and the list where they are stored
//@post the list numlist has integers filled to the tot amount
//@param tot
//@      numlist
//@returns numlist with integers from the file
//@usage MakeList(9, list);
void MakeList(int k, List& numlist);

//@Waits for user to hit enter to move on
//@usage GoToNextTest();
void GoToNextTest();

//@tests the copy constructor of clist.h
//@post the List list has be passed by value to another function making a copy that will be outputed
//@usage TestCopy();
void TestCopy();

//@This will make a few scenarios in a list that the clist.h will then print in reverse order
//@post the lists are outputted backward
//@usage TestReversePrint();
void TestReversePrint();

//@This will test DeleteIth from clist.h by creating 3 list and having it delete from it
//@in different ways
//@post List del_list has been sent to DeleteTests to be deleted.
//@uage TestDeleteIth();
void TestDeleteIth();

//@This responds the the certain list that delete ith is acting upon it 1, 2, or 3
//@pre dellist holds integers and test is assigned whish test the function will preform ok is true
//@post del_list has been altered by the DeleteIth and if where you try to delete is outside the 
//@     list then ok is returned as false
//@param del_list
//@      test
//@      ok
//@return del_list has been deleted from
void DeleteTests(List del_list, int test, bool& ok);

//@This makes a copy to have deleteith act upon it so that we can see that it has no effect
//@on the copy constructors original
//@pre del_list is an exiting list, num is the position to delete and ok is true
//@post del_list has been deleted and altered and ok is returned false if num is outside the length of list
//@param del_list
//@      num
//@      ok
//@return ok is false if num is outside the length of del_list
//@usage DelPrint(Del_list, num, ok);
void DelPrint(List del_list, int num, bool& ok);

//@returns the value associated with the list that is created in the program
//@post a list has been created and the get length function returns a value
//@returns a list and its length 
//@usage TestGetLength();
void TestGetLength();

//@searches through a varying list and finds the where valuse 0,20,40,60,80,and 100 are
//@post shows where certain positions of integers in the list are
//@usage TestSearch();
void TestSearch();

//@Retrieves the value in ith position and outputs it for the user
//@post the ith position is outputted
//@usage TestRetrieveIth();
void TestRetrieveIth();

//@Inserts a integer into the Ith position
//@post the list that has been created has a 99 in the ith position that is determined by the for loop
//@usage TestInsertIth();
void TestInsertIth();

//@outputs the intent of the program
//@post cout's the tests of the program
void Open();

int main ()
{
   PrintNewLines(2);
   
   Open();
   GoToNext();
   
   
   
   return 0;
}

//@outputs the intent of the program
//@post cout's the tests of the program
void Open()
{
   cout << "===================================================" << endl;
   
}

//@test the IsEmpty member function of clist.h
//@post a list has been created and incremented 0 to 2 to show how it handles different lists
//@     while still giving the proper outcome of empty or not.
//@return couts appropriate tests for IsEmpty();
//@usage TestIsEmpty(); 
void TestIsEmpty()
{
   List list;
   
   cout << "_}_TEST IS EMPTY_{_" << endl << endl;
   for (int k = 0; k <= 2; k ++)
   {
      if (list.IsEmpty()) {
         cout << "Empty ";
         TestPrint(list);
      } else {
         cout << "Non-Empty ";
         TestPrint(list);
      }
      MakeList(k, list);
      PrintNewLines(2);
   }
}

//@tests the print function 
//@pre list exists
//@post couts the list or the word nothing if empty
//@usage TestPrint(list);
void TestPrint(List printList)
{
   cout << "List -> ";
   if (printList.IsEmpty()) {
      cout << "Nothing";
   } else {
      printList.Print();
   }
}

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void PrintNewLines(int num)
{
   for (int k = 0; k < num; k++)
   {
      cout << endl;
   }
}

//@Opens the input file in9.txt in this case so that it may be read by the program
//@pre infile and a bool variable must be made
//@post infile is open to be read else ok is returned false if there is an error
//@param infile
//@      ok
//@returns an open file in9.txt
//@usage OpenInputFile(infile, ok);
void OpenInputFile(ifstream& infile, bool& ok)
{
   infile.open("in9.txt");
   if (infile.fail()) {
      cout << "Error" << endl;
      ok = false;
   }
}

//@Makes the list using the file in9.txt
//@pre a int of how many items to take from the file and the list where they are stored
//@post the list numlist has integers filled to the tot amount
//@param tot
//@      numlist
//@returns numlist with integers from the file
//@usage MakeList(9, list);
void MakeList(int tot, List& numlist)
{
   ifstream infile;
   int num;
   bool ok;
   ItemType item;
   
   OpenInputFile(infile, ok);
   for (int i = 0; i <= tot; i++)
   {
      infile >> num;
      numlist.InsertIth(i, num, ok);
   }
}

//@Waits for user to hit enter to move on
//@usage GoToNextTest();
void GoToNext()
{
   PrintNewLines(2);
   cout << "Press <enter> to continue ->";
   cin.get();
   PrintNewLines(3);
}

//@tests the copy constructor of clist.h
//@post the List list has be passed by value to another function making a copy that will be outputed
//@usage TestCopy();
void TestCopy()
{
   bool ok;
   List list;
   
   cout << "_}_TEST COPY LIST_{_" << endl << endl;
   for (int i = 0; i < 3; i++) 
   {
      cout << "This original list looks like ->" << endl;
      cout << "      ";
      list.Print();
      PrintNewLines(2);
   
      cout << "The copy looks like ->" << endl;
      cout << "      ";
      TestPrint(list);
      MakeList(2, list);
      PrintNewLines(2);
   }
}

//@This will make a few scenarios in a list that the clist.h will then print in reverse order
//@post the lists are outputted backward
//@usage TestReversePrint();
void TestReversePrint()
{
   List list;
   bool ok = true;
   int tempLength;
   
   MakeList(9, list);
   cout << "_}_TEST REVERSE PRINT_{_" << endl << endl;
   for (int i = 1; i <= 3; i++)
   {
      cout << "We can take the list:" << endl;
      list.Print();
      cout << endl << "And reverse the order:" << endl;
      list.ReversePrint();
      PrintNewLines(2);
      tempLength = list.GetLength();
      for (int i = list.GetLength(); i >= tempLength - 3; i--)
      { 
         list.DeleteIth(i, ok);
      }
   }
}

//@This will test DeleteIth from clist.h by creating 3 list and having it delete from it
//@in different ways
//@post List del_list has been sent to DeleteTests to be deleted.
//@uage TestDeleteIth();
void TestDeleteIth() 
{
   List del_list;
   bool ok = true;
   
   MakeList(9, del_list);
   
   cout << "_}_TEST DELETE ITH_{_" << endl << endl;
   cout << "First we will delete from the beginning:" << endl;
   DeleteTests(del_list, 1, ok);
   GoToNextTest();
   
   cout << "Then we will delete from the end:" << endl;
   DeleteTests(del_list, 2, ok);
   GoToNextTest();
   
   cout << "Then we will delete every other position using a copy and an original:" << endl;
   DeleteTests(del_list, 3, ok);
}

//@This responds the the certain list that delete ith is acting upon it 1, 2, or 3
//@pre dellist holds integers and test is assigned whish test the function will preform ok is true
//@post del_list has been altered by the DeleteIth and if where you try to delete is outside the 
//@     list then ok is returned as false
//@param del_list
//@      test
//@      ok
//@return del_list has been deleted from
void DeleteTests(List del_list, int test, bool& ok)
{
   if (test == 1) {
      for (int num = 0; num <= 10; num++)
      {
         del_list.Print();
         cout << endl;
         del_list.DeleteIth(0, ok);
      }
   } else if (test == 2) {
      for (int num = 9; num >= 0; num--)
      {
         del_list.Print();
         cout << endl;
         del_list.DeleteIth(num, ok);
      }
   } else {
      del_list.Print();
      cout << endl;
      for (int num = 1; num <= 10; num = num + 2)
      {
         DelPrint(del_list, num, ok);
      }
   }
      
}

//@This makes a copy to have deleteith act upon it so that we can see that it has no effect
//@on the copy constructors original
//@pre del_list is an exiting list, num is the position to delete and ok is true
//@post del_list has been deleted and altered and ok is returned false if num is outside the length of list
//@param del_list
//@      num
//@      ok
//@return ok is false if num is outside the length of del_list
//@usage DelPrint(Del_list, num, ok);
void DelPrint(List del_list, int num, bool& ok)
{
   del_list.DeleteIth(num, ok);
   del_list.Print();
   cout << endl;
}

//@returns the value associated with the list that is created in the program
//@post a list has been created and the get length function returns a value
//@returns a list and its length 
//@usage TestGetLength();
void TestGetLength()
{
   List list;
   
   cout << "_}_TEST GET LENGTH_{_" << endl << endl;
   for(int count = 0; count < 9; count = count + 3)
   {
      cout << "The Length the list -> " << endl;
      TestPrint(list);
      cout << endl << "= " << list.GetLength();
      PrintNewLines(2);
      MakeList(count, list);
   }
}

//@searches through a varying list and finds the where valuse 0,20,40,60,80,and 100 are
//@post shows where certain positions of integers in the list are
//@usage TestSearch();
void TestSearch()
{
   List list;
   
   MakeList(9, list);
   cout << "_}_TEST SEARCH_{_" << endl << endl;
   TestPrint(list);
   PrintNewLines(2);
   for (int search = 0; search <= 100; search = search + 20)
   {
      cout << "The integer " << search << " is in position " << (list.Search(search)) << ".";
      PrintNewLines(2);
   }
}

//@Retrieves the value in ith position and outputs it for the user
//@post the ith position is outputted
//@usage TestRetrieveIth();
void TestRetrieveIth()
{
   List list; 
   bool ok = true;
   ItemType item;
   
   MakeList(9, list);
   cout << "_}_TEST RETRIEVE ITH_{_" << endl << endl;
   cout << "For the ";
   TestPrint(list);
   PrintNewLines(2);
   for (int retrieve = 1; retrieve < 10; retrieve = retrieve + 2)
   {
      list.RetrieveIth(retrieve, item, ok);
      cout << "We will retrieve a " <<  item << " from position " << retrieve + 1 << ".";
      PrintNewLines(2);
   }
}

//@Inserts a integer into the Ith position
//@post the list that has been created has a 99 in the ith position that is determined by the for loop
//@usage TestInsertIth();
void TestInsertIth()
{
   List list; 
   bool ok = true;
   ItemType item;
   
   MakeList(9, list);
   cout << "_}_TEST INSERT ITH_{_" << endl << endl;
   cout << "For the ";
   TestPrint(list);
   PrintNewLines(2);
   for (int insert = 2; insert <= 12; insert = insert + 3)
   {
      cout << "We will insert the number 99 into position" << insert + 1 << endl;
      list.InsertIth(insert, 99, ok);
      cout <<  "To give us the ";
      TestPrint(list);
      PrintNewLines(2);
   }
}
