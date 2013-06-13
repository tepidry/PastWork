#include <iostream>
using namespace std;

struct WhatNot
{
	int myint;
	char mychar;
};

int main()
{
   int* ptr;
   int b = 3;
   ptr = &b;
   *ptr = 6;
   
   cout << "ptr's contents: " << ptr << endl;
   cout << "ptr dereferenced: " << *ptr << endl;
   cout << "-----------------------------------------------" << endl;
   
   int* aptr;
   int* bptr;
   aptr = new int;
   *aptr = 4;
   bptr = new int;
   *bptr = 6;
   
   cout << "ptrs' contents: " << aptr << " and " << bptr << endl;
   cout << "ptrs' dereferenced: " << *aptr << " and " << *bptr << endl;
   
   bptr = aptr;
   *bptr = 8;
   
   cout << "ptrs' contents: " << aptr << " and " << bptr << endl;
   cout << "ptrs' dereferenced: " << *aptr << " and " << *bptr << endl;
   cout << "-------------------------------------------------" << endl;
   
   WhatNot w;
   w.myint = 12;
   w.mychar = 'a';
   
   cout << "fields of record/struct WhatNot are " << w.myint << " and " << w.mychar << endl;
   cout << "------------------------------------------------" << endl;
   
   WhatNot* wptr;
   wptr = new WhatNot;
   (*wptr).myint = 37;
   wptr -> mychar = 'b';
   
   cout << "contents of pointer wptr is " << wptr << endl;
   cout << "contents of wptr dereferenced are " << wptr -> myint << " and " << wptr -> mychar << endl;
   cout << "------------------------------------------------" << endl;
   
   cout << "size of memory locations in bytes" << endl;
   cout << "a pointer location is " << sizeof(aptr) << " bytes" << endl;
   cout << "an integer location is " << sizeof(b) << " bytes" << endl;
   cout << "a character location is " << sizeof(w.mychar) << " bytes" << endl;
   cout << "record WhatNot is " << sizeof(WhatNot) << " bytes" << endl;
   cout << endl << endl;
   return 0;
}
