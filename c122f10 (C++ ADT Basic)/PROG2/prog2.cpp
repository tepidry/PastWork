//@file: Program 2
//@author: Ryan Draper(draper)
//@date: September 12, 2010

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//@ gets a high fahrenheit temperature from the user
//@ after a prompt.
//@post: returns a Fahrenheit temperature 
//@usage  highTemp = GetHighFahrenheit();
int GetHighFahrenheit();


//@Gets a low fahrenheit temperature from the user
//@after a prompt. 
//@pre: you have already entered the high temperature in fahrenheit. 
//@post: returns a Fahrenheit temperature that has 
//@been checked using a while loop that it is less than
//@or equal to highTemp 
//@usage:  lowTemp = GetLowFahrenheit(highTemp);
int GetLowFahrenheit(int highTemp);

//@This program allows the user to input an integer for low temperature
// and high temperature in Fahrenheit. It will then compute the 
//equivalent Celsius temperature for all Fahrenheit temperatures 
//between the low and the high temperatures.
//@pre: The user will enter a high and low temp.
//@post: finds equivalent celsius temps for all fahrenheit temps between
//@and including high and low temp from the user input.
//@param:
//@int highTemp;
//@int lowTemp;
//@int tempCount;
//@int counter;
//@float celsius;
//@float celsius
//@return: all equivalent celsius temps and fahrenheit temps between and
//@including high and low Temp.
//@throw: If low temp is higher than high temp it will ask you to reenter.
int main()
{
   int highTemp;
   int lowTemp;
   int tempCount;
   int counter;
   float celsius;
	
   cout << endl << endl;
	
   highTemp = GetHighFahrenheit(); 
   lowTemp = GetLowFahrenheit(highTemp);
	
   cout << "   Fahrenheit " << " Celsius ";
   cout << " Fahrenheit " << " Celsius ";
   cout << " Fahrenheit " << " Celsius " << endl;

   counter = 0;
   for(tempCount = lowTemp; tempCount <= highTemp; ++tempCount)
   {
      celsius = (tempCount - 32.0) * (5.0 / 9.0);
		
      cout << setw(9) << tempCount;
      cout << setprecision(3) << fixed << right << showpoint;
      cout << setw(12) << celsius;
		
      ++counter;
      if(counter % 3 == 0)
      {
         cout << endl;
      }
   }
	
   cout << endl << endl;
	
   return 0;
}

//@ gets a high fahrenheit temperature from the user
//@ after a prompt.
//@post: returns a Fahrenheit temperature 
//@usage  highTemp = GetHighFahrenheit();
//@param: int highTemp;
//@returns: highTemp as an integer
int GetHighFahrenheit()
{
   int highTemp;
	
   cout << "Please enter you high temp in Fahrenheit--> ";
   cin >> highTemp;
	
   return highTemp;
}

//@Gets a low fahrenheit temperature from the user
//@after a prompt.  
//@post: returns a Fahrenheit temperature that has 
//@been checked using a while loop that it is less than
//@or equal to highTemp 
//@param: int lowTemp;
//@usage:  lowTemp = GetLowFahrenheit(highTemp);
//@returns: lowTemp so that it is equal or less than highTemp
int GetLowFahrenheit(int highTemp)
{
   int lowTemp;
	
   cout << "Please enter you low temp in Fahrenheit---> ";
   cin >> lowTemp;
	
   while(lowTemp > highTemp)
   {
      cout << "Please make your sure the temp entered is less " << endl;
      cout << "than, or equal to your high temp and re-enter--> ";
      cin >> lowTemp;
   }
	
   return lowTemp;
}
