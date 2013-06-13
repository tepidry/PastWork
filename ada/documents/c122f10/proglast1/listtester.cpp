//@author Dr Y
//@date November 19, 2010
//@file listtester.cpp
//@description: This program tests the member functions
//              of class List. Those functions are:
//     constructor, Copy constructor, destructor,
//     InsertIth, DeleteIth, RetrieveIth,
//     GetLength, IsEmpty, Search,
//     Print, ReversePrint.


#include <iostream>
#include <fstream>
#include "clist.h"
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

//@tests the member function InsertIth in class List
//@pre infile's pointer is before an integers
//@    infile is organized as integer space integer space ...
//@post oneList contains one integer
//@     manyList contains four integers
//@     Shows the results of tests to InsertIth
//@param empty
//@param oneList
//@param manyList
//@usage TestInsertIth(infile, oneList, manyList);
void TestInsertIth(ifstream& infile, List& oneList, List& manyList);

//@prints the value of a boolean as true or false
//@pre ok is assigned
//@post value of ok is output on the screen
//@param ok
//@usage PrintBool(ok);
void PrintBool(bool ok);

//@tests the member function InsertIth in class List
//@pre infile's pointer is before an integers
//@    infile is organized as integer space integer space ...
//@post oneList contains one integer
//@     manyList contains four integers
//@     Shows the results of tests to InsertIth
//@param empty
//@param oneList
//@param manyList
//@usage TestInsertIth(infile, oneList, manyList);void TestInsertIth(ifstream& infile, List& oneList, List& manyList);
void TestCopy(List empty, List oneList, List manyList);

//@Tests function GetLength in class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of GetLength on those lists
//@usage TestGetLength(empty, oneList, manyList);
void TestGetLength(List empty, List oneList, List manyList);

//@Tests function ReversePrint in class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of ReversePrint on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestReversePrint(empty, oneList, manyList);
void TestReversePrint(List empty, List oneList, List manyList);

//@Tests the function RetrieveIth in class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of RetrieveIth on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestRetrieveIth(empty, oneList, manyList);
void TestRetrieveIth(List empty, List oneList, List manyList);

//@Tests the function DeleteIth of class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of DeleteIth on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestDeleteIth(empty, oneList, manyList);
void TestDeleteIth(List empty, List oneList, List manyList);

//@Tests the function Search of class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of Search on those lists
//@param empty
//@param oneList
//@param manyList
//@usage Search(empty, oneList, manyList);
void TestSearch(List empty, List oneList, List manyList);

//@Tests the function IsEmpty of class List
//@pre empty and oneList have been assigned
//@post shows the results of the tests on the screen
//@param empty
//@param oneList
//@usage TestIsEmpty(empty, oneList);
void TestIsEmpty(List empty, List oneList);

//@pauses the screen until user hits the enter key
//@post accepts enter key from the user
//@usage ToContinue();
void ToContinue();

int main()
{
   ifstream infile;
   List empty, oneList, manyList;
   bool fileOk;
   
   OpenInputFile(infile, fileOk);
   PrintNewLines(3);
   if (fileOk)
   {
      TestInsertIth(infile, oneList, manyList);
      ToContinue(); 
      TestCopy(empty, oneList, manyList);
      ToContinue(); 
      TestGetLength(empty, oneList, manyList);
      ToContinue(); 
      TestReversePrint(empty, oneList, manyList);
      ToContinue(); 
      TestRetrieveIth(empty, oneList, manyList);
      ToContinue(); 
      TestDeleteIth(empty, oneList, manyList);
      ToContinue(); 
      TestSearch(empty, oneList, manyList);
      ToContinue(); 
      TestIsEmpty(empty, oneList); 
  }
   PrintNewLines(3);
   return 0;
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
   infile.open("in.txt");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@prints the value of a boolean as true or false
//@pre ok is assigned
//@post value of ok is output on the screen
//@param ok
//@usage PrintBool(ok);
void PrintBool(bool ok)
{
   if (ok)
   {
      cout << "true: ";
   } else {
      cout << "false: ";;
   }
}

//@tests the member function InsertIth in class List
//@pre infile's pointer is before an integers
//@    infile is organized as integer space integer space ...
//@post oneList contains one integer
//@     manyList contains four integers
//@     Shows the results of tests to InsertIth
//@param empty
//@param oneList
//@param manyList
//@usage TestInsertIth(infile, oneList, manyList);
void TestInsertIth(ifstream& infile, List& oneList, List& manyList)
{
   bool ok;
   ItemType item;
   
   PrintNewLines(3);
   cout << "*********** Testing InsertIth *********************" << endl;
   PrintNewLines(2);   
   
  
   cout << "    Inserting into an Empty List with i = 0" << endl;
   cout << "         Before -> ";
   oneList.Print(); cout << endl;
   infile >> item.custNum;
   infile >> item.arrivalTime;
   infile >> item.transactionTime;
   oneList.InsertIth(0, item, ok);
   cout << "         After => ";
   oneList.Print(); 
   cout << endl;
   cout << "         ok = ";
   PrintBool(ok);
   PrintNewLines(2);
   cout << "     Successive Inserts into a List, starting with Empty List, with: " << endl;
   for (int i = 0; i < 3; i++)
   {
      cout << "        i = " << i << ": ";
      infile >> item.custNum;
      infile >> item.arrivalTime;
      infile >> item.transactionTime;
      manyList.InsertIth(i, item, ok);
      cout << "        ok = ";   
      PrintBool(ok); cout << "List -> ";
      manyList.Print();
      PrintNewLines(2);
   }
   
   cout << "     Inserting into the middle of a list of length 3 at i = 2: " << endl;
   infile >> item.custNum;
   infile >> item.arrivalTime;
   infile >> item.transactionTime;
   manyList.InsertIth(2, item, ok);
   cout << "         ok = ";
   PrintBool(ok); cout << "List -> ";
   manyList.Print();
   PrintNewLines(2);
   
   cout << "     Trying to insert with bad values for i: " << endl;
   cout << "         Before List: "; manyList.Print();
   cout << "i = -1: ";
   manyList.InsertIth(-1, item, ok);
   cout << "         ok = ";
   PrintBool(ok); cout << "List -> ";
   manyList.Print();
   PrintNewLines(2);
   
   cout << "     Trying to insert with bad values for i: " << endl;
   cout << "          Before List: "; manyList.Print();
   cout << "i = 5: ";
   manyList.InsertIth(5, item, ok);
   cout << "         ok = ";
   PrintBool(ok); cout << "List -> ";
   manyList.Print();
   PrintNewLines(3);
}

//@Tests the copy constructor in class List by passing by value
//@pre empty, oneList, manyList have been assigned
//@post shows the result of copying through passing by value
//@param empty
//@param oneList
//@param manyList
//@usage TestCopy(empty, oneList, manyList);
void TestCopy(List empty, List oneList, List manyList)
{
   PrintNewLines(3);
   cout << "Testing Copy by Passing by Value *********************";
   PrintNewLines(2);   
   cout << "    Before entering function: " << endl;
   cout << "       Empty list was empty " << endl;
   cout << "       One item List was 3" << endl;
   cout << "       Four item List was 5 7 11 9 " << endl;
   cout << "    After entering function: " << endl;
   cout << "       Empty list is "; empty.Print(); cout << endl;
   cout << "       One item List is "; oneList.Print();
   cout << endl;
   cout << "       Four item List is "; manyList.Print();
   PrintNewLines(3);
}

//@Tests function GetLength in class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of GetLength on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestGetLength(empty, oneList, manyList);
void TestGetLength(List empty, List oneList, List manyList)
{
   PrintNewLines(3);
   cout << "Testing GetLength ******************************************";
   PrintNewLines(2);   
   cout << "    Empty List has length     =  " << empty.GetLength() << endl;
   cout << "    One Item list has length  =  " << oneList.GetLength() << endl;
   cout << "    Four Item list has length =  " << manyList.GetLength() << endl;
   PrintNewLines(3);
}

//@Tests function ReversePrint in class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of ReversePrint on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestReversePrint(empty, oneList, manyList);
void TestReversePrint(List empty, List oneList, List manyList)
{
   PrintNewLines(3);
   cout << "Testing ReversePrint **************************************";
   PrintNewLines(2);   

   cout << "    Before List: "; empty.Print(); cout << endl;
   cout << "    ReverseList: "; empty.ReversePrint();
   PrintNewLines(2);
   cout << "    Before List: "; oneList.Print(); cout << endl;
   cout << "    ReverseList: "; oneList.ReversePrint(); cout << endl;
   PrintNewLines(2);
   cout << "    Before List: "; manyList.Print(); cout << endl;
   cout << "    ReverseList: "; manyList.ReversePrint(); cout << endl;
   PrintNewLines(3);
}

//@Tests the function RetrieveIth in class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of RetrieveIth on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestRetrieveIth(empty, oneList, manyList);
void TestRetrieveIth(List empty, List oneList, List manyList)
{
   bool ok;
   ItemType item;
   
   PrintNewLines(3);
   cout << "Testing RetrieveIth ***************************************";
   PrintNewLines(2);   
   cout << "     On an empty list: ";
   empty.RetrieveIth(0, item, ok);
   PrintBool(ok); cout << endl << endl;
   cout << "     On a one-item list: ";
   oneList.Print(); cout << endl;
   cout << "        i = 0: ";
   oneList.RetrieveIth(0, item, ok);
   cout << " item = " << item.custNum << " and ok = "; PrintBool(ok); cout << endl;
   cout << " item = " << item.arrivalTime << " and ok = "; PrintBool(ok); cout << endl;
   cout << " item = " << item.transactionTime << " and ok = "; PrintBool(ok); cout << endl;
   cout << "        i = 1: ";
   oneList.RetrieveIth(1, item, ok);
   cout << "ok = "; PrintBool(ok);
   PrintNewLines(2);
   cout << "     On a four-item list: ";
   manyList.Print(); cout << endl;
   cout << "        i = 0: ";
   manyList.RetrieveIth(0, item, ok);
   cout << " item = " << item.custNum << " and ok = "; PrintBool(ok); cout << endl;
   cout << " item = " << item.arrivalTime << " and ok = "; PrintBool(ok); cout << endl;
   cout << " item = " << item.transactionTime << " and ok = "; PrintBool(ok); cout << endl;
   cout << "        i = 2: ";
   manyList.RetrieveIth(2, item, ok);
   cout << " item = " << item.custNum << " and ok = "; PrintBool(ok); cout << endl;
   cout << " item = " << item.arrivalTime << " and ok = "; PrintBool(ok); cout << endl;
   cout << " item = " << item.transactionTime << " and ok = "; PrintBool(ok); cout << endl;
   cout << "        i = 4: ";
   manyList.RetrieveIth(4, item, ok);
   cout << "ok = "; PrintBool(ok);
   PrintNewLines(3);
}

//@Tests the function DeleteIth of class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of DeleteIth on those lists
//@param empty
//@param oneList
//@param manyList
//@usage TestDeleteIth(empty, oneList, manyList);
void TestDeleteIth(List empty, List oneList, List manyList)
{
   bool ok;
   PrintNewLines(3);
   cout << "Testing DeleteIth ********************************* ";
   PrintNewLines(2);   

   cout << "   Empty List: with i = 0 so ok = ";
   empty.DeleteIth(0, ok);
   PrintBool(ok); cout << endl;
   cout << "   One item List with i = 1 so ok = ";
   oneList.DeleteIth(1,ok);
   PrintBool(ok); cout << endl;
   PrintNewLines(2);
   cout << "   One item List with i = 0" << endl;
   cout << "      Before List: "; 
   oneList.Print(); cout << endl;
   oneList.DeleteIth(0, ok);
   cout << "      After List: "; 
   oneList.Print(); cout << endl;
   cout << "      and ok = "; PrintBool(ok); cout << endl;
   PrintNewLines(2);
   cout << "   Four item List with i = 2" << endl;
   cout << "      Before List: "; 
   manyList.Print(); cout << endl;
   manyList.DeleteIth(2, ok);
   cout << "      After List: "; 
   manyList.Print(); cout << endl;
   cout << "      and ok = "; PrintBool(ok); cout << endl;
   PrintNewLines(2);
}

//@Tests the function Search of class List
//@pre empty, oneList, manyList have been assigned
//@post shows the tests of Search on those lists
//@param empty
//@param oneList
//@param manyList
//@usage Search(empty, oneList, manyList);
void TestSearch(List empty, List oneList, List manyList)
{
   PrintNewLines(3);
   cout << "Testing Search *****************************" << endl;
   PrintNewLines(2);   
   cout << "     On an empty List return value = ";
   cout << empty.Search(1);
   PrintNewLines(2);
   cout << "     On a one item List with target = 3 " << endl;
   cout << "        Before List: ";
   oneList.Print(); cout << endl;
   cout << "        return value = ";
   cout << oneList.Search(3);
   PrintNewLines(2);
   cout << "     On a one item List with target = 2 " << endl;
   cout << "        Before List: ";
   oneList.Print(); cout << endl;
   cout << "        return value = ";
   cout << oneList.Search(2);
   PrintNewLines(2);
   cout << "     On a four item List with target = 9 " << endl;
   cout << "        Before List: ";
   manyList.Print(); cout << endl;
   cout << "        return value = ";
   cout << manyList.Search(9);
   PrintNewLines(2);
   cout << "     On a four item List with target = 10 " << endl;
   cout << "        Before List: ";
   manyList.Print(); cout << endl;
   cout << "        return value = ";
   cout << manyList.Search(10);
   PrintNewLines(2);
}

//@pauses the screen until user hits the enter key
//@post accepts enter key from the user
//@usage ToContinue();
void ToContinue()
{
   cout << "Press the Enter key to continue -> ";
   char enter;
   cin.get(enter);
}

//@Tests the function IsEmpty of class List
//@pre empty and oneList have been assigned
//@post shows the results of the tests on the screen
//@param empty
//@param oneList
//@usage TestIsEmpty(empty, oneList);
void TestIsEmpty(List empty, List oneList)
{
   PrintNewLines(3);
   cout << "Testing IsEmpty *************************";
   PrintNewLines(2);   
   cout << "     On an empty list, return value = ";
   PrintBool(empty.IsEmpty()); cout << endl;
   cout << "     On a nonempty list, return value = ";
   PrintBool(oneList.IsEmpty()); 
   PrintNewLines(3);
}
