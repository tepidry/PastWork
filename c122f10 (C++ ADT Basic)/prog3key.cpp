//@file: prog3.cpp
//@author anon with Dr. Y's changes
//@date: 9/19/10

//@description:  This program finds the mean and the median of a list
//@              of numbers, which can be entered by the user, or made
//@              by the computer.

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 10;

//@prints the menu options
//@post outputs the menu
//@usage PrintMenu();
void PrintMenu();

//@gets the menu selection input from the user after a prompt
//@post optionNumber has been assigned an integer value within the
//@      range of the menu values
//@param optionNumber is the menu choice value input by the user
//@usage GetOption(menuOption);
void GetOption(int& optionNumber);

//@completes a menu option
//@pre menuOption has been assigned an integer from 1 to 4
//@post completes that menu option
//@param menuOption 
//@usage DoOption(menuOption);
void DoOption(int menuOption);

//@test if the user has entered an option not available to them
//@pre: menuOption has been assigned a value
//@post: if menuOption is 3, outputs an error and returns true
//@      or if menuOption isn't 3, returns false
//@param: menuOption
//@usage: error = CheckError(menuOption);
bool CheckError(int menuOption);

//@fills the list with three numbers input by the user after a prompt
//@post numberList[0..2] has been assigned
//@      numberListLength has been assigned the integer 3
//@usage FillListInput(numberList, numberListLength);
void FillListInput(int numberList[], int& numberListLength);

//@the computer fills the list with 10 numbers
//@post: numberList[0..9] has been assigned and
//@      numberListLength has been assigned 10
//@usage: FillListComp(numberList, numberListLength);
void FillListComp(int numberList[], int& numberListLength);

//@computes the mean of a list of numbers
//@pre numberList[0..numberListLength-1] is assigned
//@post mean or average of values in numberList is computed
//@param numberList is the list of numbers
//@returns mean 
//@usage mean = ComputeMean(numberList, numberListLength);
double ComputeMean(int numberList[], int numberListLength);

//@finds the median of of a list of numbers
//@pre numberList[0..numberListLength-1] is assigned
//@post returns the median of the values in numberList
//@param numberList 
//@returns the middle or average of two middle values
//@usage median = FindMedian(numberList, numberListLength);
double FindMedian(int numberList[], int numberListLength);

//@prints the median and mean in a report
//@pre median and mean have been assigned
//@post prints the median and mean with labels
//@param median 
//@param mean 
//@usage PrintReport(mean, median);
void PrintReport(double mean, double median);

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintNewLines(2);
void PrintNewLines(int num);

//@prints a list
//@pre list[0..size-1] is assigned
//@post prints the values in list[0..size-1]
//@param list
//@param size
//@usage PrintList(list, 3);
void PrintList(int list[], int size);

int main()
{
   int menuOption;
   
   PrintNewLines(2);
   GetOption(menuOption);
   DoOption(menuOption);
   
   return 0;
}

//@prints the menu options
//@post outputs the menu
//@usage PrintMenu();
void PrintMenu()
{
   cout << "1) user enters 3 numbers in a list" << endl;
   cout << "2) computer makes a list of 10 numbers (no user input)" << endl;
   cout << "3) computes and prints the mean and median of the list" << endl;
   cout << "4) exit" << endl;
   
   PrintNewLines(1);
}

//@gets the menu selection input from the user after a prompt
//@post optionNumber has been assigned an integer value within the
//@      range of the menu values
//@param optionNumber is the menu choice value input by the user
//@usage GetOption(menuOption);
void GetOption(int& optionNumber)
{
   PrintMenu();
   
   cout << "Enter option number -> ";
   cin >> optionNumber;
   
   while (optionNumber < 1 || optionNumber > 4)
   {
      cout << endl << endl;
      cout << "Not a menu option.  Enter 1, 2, 3 or 4 -->";
      cin >> optionNumber;
       
      PrintNewLines(2);
   }
}

//@completes a menu option
//@pre menuOption has been assigned an integer from 1 to 4
//@post completes that menu option
//@param menuOption 
//@usage DoOption(menuOption);
void DoOption(int menuOption)
{
   bool error = true;
   int numberList[MAXSIZE];
   int numberListLength;
   double mean;
   double median;
   
   while (error)
   {
      error = CheckError(menuOption);
      if (error)
      {
         GetOption(menuOption);
         PrintNewLines(2);
      }
   }
   
   while (menuOption == 1 || menuOption == 2 || menuOption == 3)
   {
      if (menuOption == 1)
      {
         FillListInput(numberList, numberListLength);
         PrintNewLines(2);
         GetOption(menuOption);
      }
      if (menuOption == 2)
      {
         FillListComp(numberList, numberListLength);
         PrintNewLines(2);
         GetOption(menuOption);
      }
      if (menuOption == 3)
      {
         mean = ComputeMean(numberList, numberListLength);
         median = FindMedian(numberList, numberListLength);
         PrintList(numberList, numberListLength);
         PrintReport(mean, median);
         PrintNewLines(2);
         GetOption(menuOption);
      }    
   }
   
   PrintNewLines(2);
}

//@test if the user has entered an option not available to them
//@pre: menuOption has been assigned a value
//@post: if menuOption is 3, outputs an error and returns true
//@      or if menuOption isn't 3, returns false
//@param: menuOption
//@usage: error = CheckError(menuOption);
bool CheckError(int menuOption)
{
   bool error;  

   if (menuOption == 3)
   {
      PrintNewLines(2);
      cout << "You must fill the list before calculating the mean or median." << endl;
      cout << "Choose 1, 2 or 4." << endl;
      PrintNewLines(2);
      error = true;
   }
   if (menuOption == 1 || menuOption == 2 || menuOption == 4)
   {
      error = false;
   }
   return error;
}
   
//@fills the list with three numbers input by the user after a prompt
//@post numberList[0..2] has been assigned
//@      numberListLength has been assigned the integer 3
//@usage FillListInput(numberList, numberListLength);
void FillListInput(int numberList[], int& numberListLength)
{
   numberListLength = 3;
   
   PrintNewLines(2);
   cout << "Enter a sorted, ascending list of three integers." << endl;
   PrintNewLines(1);
   
   for (int i = 0; i < numberListLength; i++)
   {
      cout << "Enter a value for list entry number " << i+1 << " -> ";
      cin >> numberList[i];
   }
}

//@the computer fills the list with 10 numbers
//@post: numberList[0..9] has been assigned and
//@      numberListLength has been assigned 10
//@usage: FillListComp(numberList, numberListLength);
void FillListComp(int numberList[], int& numberListLength)
{
   numberListLength = 10;
   
   for (int i = 0; i < numberListLength; i++)
   {
      numberList[i] = i + 1;
   }
}

//@computes the mean of a list of numbers
//@pre numberList[0..numberListLength-1] is assigned
//@post mean or average of values in numberList is computed
//@param numberList is the list of numbers
//@returns mean 
//@usage mean = ComputeMean(numberList, numberListLength);
double ComputeMean(int numberList[], int numberListLength)
{
   int sum = 0;
   double mean;
    
   for (int i = 0; i < numberListLength; i++)
   {
      sum = sum + numberList[i];
   }
   mean = sum * 1.0 / numberListLength;
   
   return mean;
}

//@finds the median of of a list of numbers
//@pre numberList[0..numberListLength-1] is assigned
//@post returns the median of the values in numberList
//@param numberList 
//@returns the middle or average of two middle values
//@usage median = FindMedian(numberList, numberListLength);double FindMedian(int numberList[], int numberListLength)
double FindMedian(int numberList[], int numberListLength)
{
   double median;
   int middle = numberListLength / 2;
   
   if (numberListLength % 2 == 1)
   {
      median = numberList[middle];
   }
   else
   {
      median = (numberList[middle - 1] + numberList[middle]) * 1.0 / 2.0;
   }
   
   return median;
}
 
//@prints the median and mean in a report
//@pre median and mean have been assigned
//@post prints the median and mean with labels
//@param median 
//@param mean 
//@usage PrintReport(mean, median);
void PrintReport(double mean, double median)
{
   PrintNewLines(2);
   
   cout << "The mean value for the list is ---> " << setw(6) << right << mean << endl;
   cout << "The median value for the list is -> " << setw(6) << right << median << endl;
}

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintNewLines(2);
void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}

//@prints a list
//@pre list[0..size-1] is assigned
//@post prints the values in list[0..size-1]
//@param list
//@param size
//@usage PrintList(list, 3);
void PrintList(int list[], int size)
{
	PrintNewLines(2);
	cout << "The list is: ";
	for (int k = 0; k < size - 1; k++)
	   cout << list[k] << " , ";
	cout << list[size - 1] << endl;
}

