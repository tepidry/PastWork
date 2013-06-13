//@author Ryan Draper(rdraper)
//@date Feb. 4 2013
//@file prog1.cpp

//@description: This program will take a base 10 number and use a division by 2 method to convert it to a base 2 number.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@takes in a new number in base ten to convert it to base two
//@pre base ten is a number 0 or greater
//@post base ten is a nonnegative number that is to be converted 
//@param baseTen
//@usage inputNumber(baseTen);
void InputNumber(int& baseTen);

//@converts a base ten number to a base two number
//@pre baseTwo[] is an array and baseTen in a int
//@post baseTwo[] is an array with the binary representation for the baseTen number 
//@param baseTen
//@ 	 baseTwo[]
//@usage inputNumber(baseTen);
void ConvertToBaseTwo(int baseTen, int baseTwo[]);

//@decides how big the array should be according to the base ten number entered.
//@pre baseTwo is an array
//@post baseTwo is a correct size of the array according to the baseTen numver entered.
//@usage baseTwo [sizeOfArray()];
int SizeOfArray(int baseTen);

//@outputs the array that is the binary representation of the base ten number that was entered
//@pre baseTwo is an array
//@post baseTwo contents is displayed on the screen in terminal
//@param baseTwo
//@	 lengthOfBinary
//@usage outputbinaryArray(baseTwo, lengthOfBinary)
void OutputBinaryArray(int baseTen, int baseTwo[], int lengthOfBinary);

//@checks whether or not to loop the program to convert another number
//@pre continue is true
//@post continue is a value according to the users wishes
//@param continue
//@usagecheckForContinue(continue);
void CheckForContinue(bool& proceed);


////~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~```
int main()
{
	int baseTen = 0;
	bool proceed = true;

	while (proceed)
	{
		InputNumber(baseTen);

		int lengthOfBinary = SizeOfArray(baseTen);
		int baseTwo[lengthOfBinary];
	
		ConvertToBaseTwo(baseTen, baseTwo);
		OutputBinaryArray(baseTen, baseTwo, lengthOfBinary);
		CheckForContinue(proceed);
	}

	return 0;   
}
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~```

//@checks whether or not to loop the program to convert another number
//@pre continue is true
//@post continue is a value according to the users wishes
//@param continue
//@usagecheckForContinue(continue);
void CheckForContinue(bool& proceed)
{	
	char toContinue;
	PrintLines(1);
	cout << "Would you like to convert another number? (y/n) ";
	cin >> toContinue;
	if (toContinue == 'n') {
		proceed = false;
		PrintLines(1);
	}
	else if (toContinue != 'y') {
		cout << "Please Try Again!";
		CheckForContinue(proceed);
	}
}

//@outputs the array that is the binary representation of the base ten number that was entered
//@pre baseTwo is an array
//@post baseTwo contents is displayed on the screen in terminal
//@param baseTwo
//@	 lengthOfBinary
//@usage outputbinaryArray(baseTwo, lengthOfBinary)
void OutputBinaryArray(int baseTen, int baseTwo[], int lengthOfBinary)
{
	PrintLines(1);
	cout << "For the number " << " the binary representation is --> ";
	for (int i = lengthOfBinary - 1; i >= 0; i--)
	{
		cout << baseTwo[i];
	}
	PrintLines(2);
}

//@decides how big the array should be according to the base ten number entered.
//@pre baseTwo is an array
//@post baseTwo is a correct size of the array according to the baseTen numver entered.
//@usage baseTwo [sizeOfArray()];
int SizeOfArray(int baseTen)
{
	int tempTen = baseTen;
	int i;
	for (i = 0; tempTen >= 1; i++)
	{
		tempTen = tempTen / 2;
	}
	return i;
}

//@converts a base ten number to a base two number
//@pre baseTwo[] is an array and baseTen in a int
//@post baseTwo[] is an array with the binary representation for the baseTen number 
//@param baseTen
//@ 	 baseTwo[]
//@usage inputNumber(baseTen);
void  ConvertToBaseTwo(int baseTen, int baseTwo[])
{
	int tempBaseTen = baseTen;
	for(int i = 0; tempBaseTen > 0; i++)
	{
		baseTwo[i] = tempBaseTen % 2;
		tempBaseTen = tempBaseTen / 2;
	}	
}

//@takes in a new number in base ten to convert it to base two
//@pre base ten is a number 0 or greater
//@post base ten is a nonnegative number that is to be converted 
//@param baseTen
//@usage inputNumber(baseTen);
void InputNumber(int& baseTen)
{
	int temp;
	bool inputOK = true;
	while (inputOK)
	{
		PrintLines(1);
		cout << "Enter a POSITIVE base ten integer to convert to binary. --> ";
		cin >> temp;
		PrintLines(1);
		if (temp > 0)
		{
			baseTen = temp;
			inputOK = false;
		} else {
			cout << ":: Please make sure the number is positive ::";
		}
	}
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

