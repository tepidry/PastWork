//file:--- prog1
//@author:- Ryan Michael Draper (draper)
//@date:--- September, 7th 2010

//@description: This program will take the retail price of any item
//and return to the user; the price given, the tax of the item with the given
//tax of 8.2%, the the total amount.
//@pre: The item price given to be found the actual tax value given that
//the tax is 8.2%.
//@post: It will take in a user entered value for 'price'. Then find the tax at 
//8.2% and store that in 'tax'. This programm will then add the original 'price' 
//and 'tax to and store that in the variable 'total'. 
//@param: A line with the parameter name and its description
//@return: It will return the values stored in 'price', 'total', and 'tax' rounding
//total to a 2 decimal float so that it is a monetary value.
//@throw: No Exceptions.\

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double price;
	double tax;
	double total;
	
	cout << endl << endl;

	cout << "What is the retail price of the item? --->" << endl;
	cin >> price;
	
	tax = price * .082;
	total = tax + price;
	

	
	cout << "Retail Price:---->" << price << endl;
	cout << "The tax at 8.2%:->" << tax << endl;
	cout << "---------------- +" << endl;
    cout << "Total Price:----->" << setprecision(2) << fixed << total << endl;
    
    cout << endl << endl;
	
	return 0;
}

