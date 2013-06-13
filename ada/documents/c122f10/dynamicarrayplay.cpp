//Playing with dynamic arrays

#include <iostream>
using namespace std;

int main()
{
	int listSize;
	int* list;
	
	cout << endl << endl;
	cout << "Enter desired list size -> ";
	cin >> listSize;
	
	cout << "value of list before new " << list << endl;
	list = NULL;
	cout << "value of list before new but after assigning NULL -> " << list << endl;
	list = new int [listSize];
	cout << "value of list after new -> " << list << endl;
	
	for (int i = 0; i < listSize; i++)
	{
		list[i] = 2 * i;
	}
	cout << endl << endl;
	cout << "printing the list " << endl;
	for (int i = 0; i < listSize; i++)
	{
		cout << i << " -> " << list[i] << endl;
	}
	cout << endl << endl;
	cout << "value of *list -> " << *list << endl;
	cout << "value of *(list + 1) -> " << *(list + 1) << endl;
	
	cout << "freeing the memory for the list " << endl;
	delete [] list;
	cout << "looking at *list after the delete " << endl;
	cout << *(list + 2) << endl;
	cout << endl << endl;
	
	return 0;
}
