// Place the following picture as a comment at the beginning of 
// your memory_segments.cpp file.

// Add the significant addresses to diagram to the right of the boxes.
// The first address, x10000, i.e., 10000 hex, is shown.
// Add edata, end, and the names of the variables to right as well.
// As an example, etext is shown.  Fill in its address.
       
//       +------------------+
//       |  TEXT            | x8000000?
//       |                  | 
//       |  instructions in | x80485f4 = proc1
//       |  machine code    | x80484c4 = proc2
//       |                  |
//       +------------------+ x8048a04 = etext
//       |  DATA            | x804a1f0 = g1 	global intilized 
//       |  - initialized   | x804a1f4 = g3
//       |    variables     | x804a1fc = ls1 	static initialized
//       |                  | x804a1f8 = ls3
//		 |                  |
//       |------------------| 
//       |  - uninitialized | x804a200 = edata
//       |    variables     | x804b1e8 = ls0 	static unitialized
//       |                  | x804b1e4 = ls2
//       |                  | x804a220 = g0		global unintialized
//       |                  | x804b1e0 = g4
//       |                  | x804a240 = g2		global array uninitialized
//       |                  |
//       |------------------|
//       |  - heap for      | x9cbd008 = pointed to heap 1 space
//       |  dynamic         | x9cbd018 = pointed to heap 2 space
//       |  allocation      |
//       |                  |
//       |                  |
//       +------------------+ 
//                |
//                |
//                V
//
//                .
//                .
//                .
//
//                ^
//                |
//                |
//       +------------------+                       | Activation record
//       |  STACK           | xbf8866f4 = lc3, lc5  | lc4, lc3  proc 1
//       |  - function      | xbf8866f0 = lc4, lc6  | lc5, lc6  proc 2
//       |    activation    |
//       |    records       | xbf886728 = lc0		| Activation record for 
//       |  - local         | xbf886724 = lc1		| main
//       |    automatic     | xbf886720 = lc2
//       |    variables     |
//       +------------------+ 

#include <stdio.h>
#include <stdlib.h>

int g0;       /* global variable, uninitialized */
int g1 = 14;  /* global variable, initialized */
int g2[1000]; /* global variable, uninitialized */
int g3 = 16;  /* global variable, initialized */
int g4;       /* global variable, uninitialized */

void proc1();
void proc2();
int fib(int x);

int main()
{
	extern int etext[], edata[], end[];

	int lc0;      /* local variable, stored on stack */
	int lc1 = 27; /* local variable, stored on stack; mix init and uninit */
	int lc2;      /* local variable, stored on stack */
        static int ls0; /* local static variable, uninitialized data */
        static int ls1 = 19;      /* local static variable, initialized data */
        int *pheap1;
        int *pheap2;

        pheap1 = (int *) malloc(sizeof(int));
        pheap2 = (int *) malloc(sizeof(int));

        printf("\n\n---------- main -------------------\n\n");
        printf("%8p (%10lu): Last address\n", 0xffffffff, 0xffffffff);

        printf("%8p (%10lu): Address etext\n", etext, etext);
        printf("%8p (%10lu): Address edata\n", edata, edata);
        printf("%8p (%10lu): Address end\n", end, end);

        printf("%8p (%10lu): Address of code for proc1\n", &proc1, &proc1);
        printf("%8p (%10lu): Address of code for proc2\n", &proc2, &proc2);
        printf("%8p (%10lu): Address of code for fib\n", &fib, &fib);

        printf("%8p (%10lu): Address of uninitialized global variable g0\n", &g0, &g0);
        printf("%8p (%10lu): Address of initialized   global variable g1\n", &g1, &g1);
        printf("%8p (%10lu): Address of uninitialized global array    g2\n", &g2[0], &g2[0]);
        printf("%8p (%10lu): Address of initialized   global variable g3\n", &g3, &g3);
        printf("%8p (%10lu): Address of uninitialized global variable g4\n", &g4, &g4);

        printf("%8p (%10lu): Address heap1 in heap space\n", pheap1, (unsigned long) pheap1);
        printf("%8p (%10lu): Address heap2 in heap space\n", pheap2, (unsigned long) pheap2);

	printf("%8p (%10lu): Address of local variable lc0\n", &lc0, &lc0);
	printf("%8p (%10lu): Address of local variable lc1\n", &lc1, &lc1);
	printf("%8p (%10lu): Address of local variable lc2\n", &lc2, &lc2);

	printf("%8p (%10lu): Address of local uninitialized static var ls0\n", &ls0, &ls0);
	printf("%8p (%10lu): Address of local initialized   static var ls1\n", &ls1, &ls1);

	proc1();
	proc2();
	printf("\n%d", fib(5));

	return 0;
}

// will return the x number of the fibonacci sequence.
int fib(int x) {
	printf("\n\n----------- fib() ------------------\n\n");
	printf("%8p (%10lu): Address of code for fib\n", &fib, &fib);
	printf("%8p (%10lu): Address of code for x\n", &x, &x);
	
	//printf("fib result %d\n", x);
    if (x < 2) {
    	return x;
	} else {
    	return(fib(x-1) + fib(x-2));
	}
    

    
}

void proc1() {
	int lc3;
	int lc4 = 37;

	printf("\n\n----------- proc1 ------------------\n\n");
	printf("%8p (%10lu): Address of code for proc1\n", &proc1, &proc1);
	printf("%8p (%10lu): Address of global variable g0\n", &g0, &g0);
	printf("%8p (%10lu): Address of global variable g1\n", &g1, &g1);
	printf("%8p (%10lu): Address of global variable g2\n", &g2[0], &g2[0]);
	printf("%8p (%10lu): Address of global variable g3\n", &g3, &g3);
	printf("%8p (%10lu): Address of global variable g4\n", &g4, &g4);
	printf("%8p (%10lu): Address of local variable lc3\n", &lc3, &lc3);
	printf("%8p (%10lu): Address of local variable lc4\n", &lc4, &lc4);
}

void proc2() {
	int lc5;
	int lc6 = 51;
	static int ls2;
	static int ls3 = 47;

	printf("\n\n------------ proc2 -----------------\n\n");
	printf("%8p (%10lu): Address of code for proc2\n", &proc2, &proc2);
	printf("%8p (%10lu): Address of global variable g0\n", &g0, &g0);
	printf("%8p (%10lu): Address of global variable g1\n", &g1, &g1);
	printf("%8p (%10lu): Address of global variable g2\n", &g2[0], &g2[0]);
	printf("%8p (%10lu): Address of global variable g3\n", &g3, &g3);
	printf("%8p (%10lu): Address of global variable g4\n", &g4, &g4);
	printf("%8p (%10lu): Address of local variable lc5\n", &lc5, &lc5);
	printf("%8p (%10lu): Address of local variable lc6\n", &lc6, &lc6);
	printf("%8p (%10lu): Address of local uninitialized static var ls2\n", &ls2, &ls2);
	printf("%8p (%10lu): Address of local initialized   static var ls3\n", &ls3, &ls3);
}
