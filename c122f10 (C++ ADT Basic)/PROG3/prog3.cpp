//@author Ryan Draper(draper)
//@file prog3.cpp
//@date 9/21/10


#include <iomanip>
#include <iostream>
using namespace std;

const int MAXSIZE = 10;
 
//@prints the menu stated in the description above as:
//@       1) user enters 3 integers in a list
//@       2) computer makes a list of 10 integers (no user input)
//@       3) computes and prints the mean and median of the list
//@       4) exit
//@usage PrintMenu();
void PrintMenu();

//@asks for corresponding number the user has entered then calls
//@functioin complete to accomplish.
//@post there will be a int in variable choice that corresponds with the menu
//@usage GetOption(list, listLeng, opt);
//@param double mean;
//@      double median;
void GetOption(int list[], int& listLeng, int& opt);

//@Completes the option that the user chooses
//@pre list must be a array with integers, listLeng must have the length of
//@    the array list, and opt must have a user generated integer in it.
//@post mean gets the mean of the array list in it, and median gets the 
//@     median of the array in it.
//@usage Complete(list, listLeng, opt);
void Complete(int list[], int& listLeng, int opt);
   
//@finds the median of a list of numbers
//@pre list[0..number - 1] is assigned
//@post returns the median of list[0..number - 1]
//@param int center;
//@      double med;
//@usage median = FindMedian(list, listLeng);
double FindMedian(int list[], int listLeng);

//@returns the mean or average of the list of integers
//@pre the array list must be filled  with integers
//@post assigns the variable mean a value
//@param double mean;
//@      int counter;
//@usage mean = FindMean(list[], listLeng);
double FindMean(int list[], int listLeng);

//@fills the array of list with appropiate integers entered by user.
//@post list[] will be filled with 3 integers of the users choosing
//@param listLeng = 3;
//@      int i = 0;
//@usage FillListUser(list[], listLeng);
void FillListUser(int list[], int& listLeng);

//@fills the array of list with appropiate integers
//@post list[] will be filled with 10 integers of the users choosing
//@param i = 0;
//@      listLeng = 10
//@usage FillListComp(list[], listLeng);
void FillListComp(int list[], int& listLeng);

//@prints out median and mean of the list
//@pre must have a list two variables that have the mean and median in them
//@PrintMeanMedian(double mean, double median); 
void PrintMeanMedian(double mean, double median);

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@usage PrintNewLines(2);
void PrintNewLines(int num);

//@description allows user to to choose from a menu to either 
//@            1) user enters 3 integers in a list
//@            2) computer makes a list of 10 integers (no user input)
//@            3) computes and prints the mean and median of the list
//@            4) exit. 
//@            it will then accomplish any said task will then reprint the list
//@pre must define the constant MAXSIZE = 10
//@post will fill the array with the user specified integers
//@param int opt;
//@      int listLeng;
//@      int list[MAXSIZE];
int main()
{
   int opt = 0; 
   int listLeng;
   int list[MAXSIZE];
   
   
   PrintNewLines(2);
   GetOption(list, listLeng, opt);
   PrintNewLines(2);
   
   return 0;
}

//@prints the menu stated in the description above as:
//@       1) user enters 3 integers in a list
//@       2) computer makes a list of 10 integers (no user input)
//@       3) computes and prints the mean and median of the list
//@       4) exit
//@usage PrintMenu();
void PrintMenu()
{
   cout << "1) user enters 3 integers in a list" << endl;
   cout << "2) computer makes a list of 10 integers (no user input)" << endl;
   cout << "3) computes and prints the mean and median of the list" << endl;
   cout << "4) exit" << endl << endl;
   cout << "Enter choice -> ";
}

//@asks for corresponding number the user has entered then calls
//@functioin complete to accomplish.
//@post there will be a int in variable choice that corresponds with the menu
//@usage GetOption(list, listLeng, opt);
//@param double mean;
//@      double median;
void GetOption(int list[], int& listLeng, int& opt)
{  
   double mean;
   double median;

   while (!(opt == 4))
   {
      PrintMenu();
      if (opt == 0)
      {
         cin >> opt;
         
         while (opt == 3)
         {
            PrintNewLines(1);
            cout << "Please select 1 or 2 first to create "; 
            cout << "a list before you select 3-->";
            PrintNewLines(2);
            cout << "Enter choice -> ";
            cin >> opt;
         }
      } else 
      {
         cin >> opt;
      }
      
      PrintNewLines(2);
      
      Complete(list, listLeng, opt);
   }
}

//@Completes the option that the user chooses
//@pre list must be a array with integers, listLeng must have the length of
//@    the array list, and opt must have a user generated integer in it.
//@post mean gets the mean of the array list in it, and median gets the 
//@     median of the array in it.
//@usage Complete(list, listLeng, opt);
void Complete(int list[], int& listLeng, int opt)
{
   double mean;
   double median;

   if (opt == 1)
   {
      FillListUser(list, listLeng);
   } else if (opt == 2)
   {
      FillListComp(list, listLeng);
   } else if (opt == 3)
   {
      median = FindMedian(list, listLeng);
      mean = FindMean(list, listLeng);
      PrintMeanMedian(mean, median);
   }
}

//@finds the median of a list of numbers
//@pre list[0..number - 1] is assigned
//@post returns the median of list[0..number - 1]
//@param int center;
//@      double med;
//@usage median = FindMedian(list, listLeng);
double FindMedian(int list[], int listLeng)
{
   int center;
   double med;

   if(listLeng % 2 == 0)
   {
      center = listLeng / 2;
      med = (list[center - 1] + list[center]) / 2.0;
   } else
   {
      center = listLeng / 2;
      med = list[center];
   }  

   return med;
}

//@returns the mean or average of the list of integers
//@pre the array list must be filled  with integers
//@post assigns the variable mean a value
//@param double mean;
//@      int counter;
//@usage mean = FindMean(list[], listLeng);
double FindMean(int list[], int listLeng)
{
   double mean;
   int counter = 0;

   for (int i = 0; i < listLeng; i++)
   {
      counter = list[i] + counter;
      mean = 1.0 * counter / listLeng;
   }
   
   return mean;
}

//@fills the array of list with appropiate integers entered by user.
//@post list[] will be filled with 3 integers of the users choosing
//@param listLeng = 3;
//@      int i = 0;
//@usage FillListUser(list[], listLeng);
void FillListUser(int list[], int& listLeng)
{ 
   listLeng = 3;

   PrintNewLines(2);

   cout << "Please enter 3 integers in increasing value.(ex. 1, 2, 3)" << endl << endl;
   for (int i = 0; i < listLeng; i++)
   {
      cout << "Enter integer " << i + 1 << "--> ";
      cin >> list[i];
   }
   PrintNewLines(2);
}

//@fills the array of list with appropiate integers
//@post list[] will be filled with 10 integers of the users choosing
//@param i = 0;
//@      listLeng = 10
//@usage FillListComp(list[], listLeng);
void FillListComp(int list[], int& listLeng)
{
   listLeng = 10;
   
   for (int i = 0; i < listLeng; i++)
   {
      list [i] = i + 1;
   }
}

//@prints out median and mean of the list
//@pre must have a list two variables that have the mean and median in them
//@PrintMeanMedian(double mean, double median);
void PrintMeanMedian(double mean, double median)
{
   cout << "  Mean " << "  Median" << endl;
   cout << setprecision(2) << fixed << right << showpoint; 
   cout << setw(6) << mean << setw(8) << median << endl;
   PrintNewLines(2);
}

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@usage PrintNewLines(2);
void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}


