//@author Ryan Draper(rdraper)
//@date Feb. 15 2013
//@file prog2.cpp

//@description: This program computes the fibonacci sequence three separate ways: the iterative method, by the phi approximation by rounding up, and
//@             by matrix multiplication.  It then displays them all in a wonderfully easy to read format.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

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
void InputNumber(int& numberN);

//@checks whether or not to loop the program to convert another number
//@pre continue is true
//@post continue is a value according to the users wishes
//@param continue
//@usagecheckForContinue(continue);
void CheckForContinue(bool& proceed);

//@creates a user determined size array of the fibonacci sequence in a dynamic array
//@pre dynamic array fibonacciSequence is empyt
//@post dynamic array fibonacciSequence is filled to the fibonacciSize number in the sequence
//@param fibonacciSequence
//@      fibonacciSize
//@usage CreateIterativeFibonacci();
int CreateIterativeFibonacci(unsigned int* fibonacciSequence, int fibonacciSize, unsigned int unsignedLimit);

//@This prings out the one-dimensional dynamic array fibonacciSequence that holds the fibonacci sequence
//@pre fibonacciSequence holds the fibonacci sequence to the largestNumInSequence which is the largest possible unsigned int can hold
//@post the array fibonacciSequence has been printed out to the kth position, where k = largestNumInSequence, in a pleasing fashion
//@param fibonacciSequence
//@      largestNumInSequence
//@usage PrintOutFibonacci(fibonacciSequence, largestNumInSequence);
void PrintOutFibonacci(unsigned int* fibonacciSequence, int largestNumInSequence);

//@computes the kth position of the fibonacci sequence where k = largestNumInSequence
//@pre largestNumInSequence is the largest lumber found by the iterative method
//@post the largestNumInSequence of the fibonacci sequence is computed and returned
//@param largestNumInSequence
//@return a unsigned int that is the kth position of the fibonacci sequence k = largestNumInSequence
//@usage cout << "Fib(k/2) =" << setw(15) << right << ComputeUsingPhi(largestNumInSequence/2);
unsigned int ComputeUsingPhiMethod(int largestNumInSequence);

//@prints out the kth and k/2 position in the fibonacci sequence using the phi appoximation method, where k = largestNumInSequence
//@pre k is the largest lumber found by the iterative method
//@post both the k and k/2 number in the fibonacci sequence have been printed out
//@param largestNumInSequence
//@usage PrintLargestKForPhiMethod(largestNumInSequence);
void PrintLargestKForPhiMethod(int largestNumInSequence);

//@Computes the fibonacci number of the kth position where k = largestNumInSequence
//@pre k is decided by the iterative method that it can fit into a unsigned int variable
//@post the kth number in the fibonacci sequence is computed and returned
//@return an unsigned in that is the kth position in the fibonacci sequence
//@param largestNumInSequence
//@usage cout << "Fib(k/2) =" << setw(15) << right << FibonacciMatrixMethod(largestNumInSequence / 2);
unsigned int FibonacciMatrixMethod(int largestNumInSequence);

//@makes the leftMatrix equal to the rightMatrix
//@pre leftMatrix is a one-dimensional array of 4 and the rightMatrix is a one dimenstional array of 4
//@post both the left and the right Matices one-dimensional arrays are equal
//@param leftMatrix
//@      rightMatrix
//@usage MatrixEqual(returnedMat, temp);
void MatrixEqual(unsigned int* leftMatrix, unsigned int* rightMatrix);

//@multiplies two matrices and returns the product in the returnedMat
//@pre leftMatrix, rightMatrix, and the returnedMat are all one-dimensional array with the type unsigned int
//@post the returnedMat is the product of matrix multiplication between the rightMatrix and leftMatrix
//@param leftMatrix
//@      rightMatrix
//@      returnedMat
//@usage MatrixMultiplication(fibMatrix, start, fibMatrix);
void MatrixMultiplication (unsigned int* leftMatrix, unsigned int* rightMatrix, unsigned int* returnedMat);

//@prints out the fibonacci number that is the kth and k/2 postion relating to k = largestNumInSequence
//@pre k is decided by the iterative method that it can fit into a unsigned int variable
//@post both the k and k/2 fibonacci number is displayed using the matrix method to find them
//@param largestNumInSequence
//@usage MatrixOutput(largestNumInSequence);
void MatrixOutput(int largestNumInSequence);

////~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//unsignedLimit = (2^32-1)
int main()
{
	int fibonacciSize = 0;
     unsigned int* fibonacciSequence;
     bool proceed = true;
     unsigned int unsignedLimit = pow(2.0, 32) - 1;
     int largestNumInSequence;
     
	while (proceed)
	{
          InputNumber(fibonacciSize);
          fibonacciSequence = new unsigned int [fibonacciSize];
          largestNumInSequence = CreateIterativeFibonacci(fibonacciSequence, fibonacciSize, unsignedLimit);
          PrintOutFibonacci(fibonacciSequence, largestNumInSequence);
          PrintLargestKForPhiMethod(largestNumInSequence);
          MatrixOutput(largestNumInSequence);
          CheckForContinue(proceed);
	}
    
	return 0;
}

////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//@prints out the fibonacci number that is the kth and k/2 postion relating to k = largestNumInSequence
//@pre largestNumInSequence is decided by the iterative method that it can fit into a unsigned int variable
//@post both the k and k/2 fibonacci number is displayed using the matrix method to find them
//@param largestNumInSequence
//@usage MatrixOutput(largestNumInSequence);
void MatrixOutput(int largestNumInSequence)
{
     cout << "~~~~~~~~~~~~~~~~~The Fibonacci Sequence using Matrices~~~~~~~~~~~~~~~~~" << endl;
     cout << "k       ->" << setw(15) << right << largestNumInSequence << endl;
     cout << "Fib(k)   =" << setw(15) << right << FibonacciMatrixMethod(largestNumInSequence) << endl;
     cout << "Fib(k/2) =" << setw(15) << right << FibonacciMatrixMethod(largestNumInSequence / 2);
     PrintLines(2);
}

//@Computes the fibonacci number of the kth position where k = largestNumInSequence
//@pre largestNumInSequence is decided by the iterative method that it can fit into a unsigned int variable
//@post the kth number in the fibonacci sequence is computed and returned
//@return an unsigned in that is the kth position in the fibonacci sequence
//@param largestNumInSequence
//@usage cout << "Fib(k/2) =" << setw(15) << right << FibonacciMatrixMethod(largestNumInSequence / 2);
unsigned int FibonacciMatrixMethod(int largestNumInSequence)
{
     unsigned int start[4] = {0, 1, 1, 1};
     unsigned int fibMatrix[4] = {0,1,1,1};
     int numDifference = 0;
     int squares = 0;
     int iteration = 1;
     
     if (largestNumInSequence <= 1) {
          return start[largestNumInSequence];
     }
     
     while(iteration * 2 < largestNumInSequence)
     {
          iteration = iteration * 2;
          squares++;
     }
     numDifference = largestNumInSequence - iteration;
     
     for (int k = 0; k < squares; k++)
     {
          MatrixMultiplication(fibMatrix, fibMatrix, fibMatrix);
     }
     
     for (int k = 0; k < numDifference; k++)
     {
          MatrixMultiplication(fibMatrix, start, fibMatrix);
     }
     return fibMatrix[1];
}

//@makes the leftMatrix equal to the rightMatrix
//@pre leftMatrix is a one-dimensional array of 4 and the rightMatrix is a one dimenstional array of 4
//@post both the left and the right Matices one-dimensional arrays are equal
//@param leftMatrix
//@      rightMatrix
//@usage MatrixEqual(returnedMat, temp);
void MatrixEqual(unsigned int* leftMatrix, unsigned int* rightMatrix)
{
     leftMatrix[0] = rightMatrix[0];
     leftMatrix[1] = rightMatrix[1];
     leftMatrix[2] = rightMatrix[2];
     leftMatrix[3] = rightMatrix[3];
}

//@multiplies two matrices and returns the product in the returnedMat
//@pre leftMatrix, rightMatrix, and the returnedMat are all one-dimensional array with the type unsigned int
//@post the returnedMat is the product of matrix multiplication between the rightMatrix and leftMatrix
//@param leftMatrix
//@      rightMatrix
//@      returnedMat
//@usage MatrixMultiplication(fibMatrix, start, fibMatrix);
void MatrixMultiplication(unsigned int* leftMatrix, unsigned int* rightMatrix, unsigned int* returnedMat)
{
     unsigned int temp[4];
     temp[0] = leftMatrix[0] * rightMatrix[0] + leftMatrix[1] * rightMatrix[2];
     temp[1] = leftMatrix[0] * rightMatrix[1] + leftMatrix[1] * rightMatrix[3];
     temp[2] = leftMatrix[2] * rightMatrix[0] + leftMatrix[3] * rightMatrix[2];
     temp[3] = leftMatrix[2] * rightMatrix[1] + leftMatrix[3] * rightMatrix[3];
     MatrixEqual(returnedMat, temp);
}

//@This prings out the one-dimensional dynamic array fibonacciSequence that holds the fibonacci sequence
//@pre fibonacciSequence holds the fibonacci sequence to the largestNumInSequence which is the largest possible unsigned int can hold
//@post the array fibonacciSequence has been printed out to the kth position, where k = largestNumInSequence, in a pleasing fashion
//@param fibonacciSequence
//@      largestNumInSequence
//@usage PrintOutFibonacci(fibonacciSequence, largestNumInSequence);
void PrintOutFibonacci(unsigned int* fibonacciSequence, int largestNumInSequence)
{
     cout << "~~~~~~~~~~~~~The Fibonacci Sequence using Iterative Method~~~~~~~~~~~~~" << endl;
     int line, rowN, rowFN;
     for (line = 0; line <= (largestNumInSequence / 5) ; line++){
          cout << "   n:";
          for (rowN = line * 5; rowN < line * 5 + 5 && rowN <= largestNumInSequence; rowN++)
          {
               cout << setw(13) << right << rowN;
          }
          cout << endl;
          cout << "F(n):";
          for (rowFN = line * 5; rowFN < line * 5 + 5 && rowFN <= largestNumInSequence; rowFN++)
          {
               cout << setw(13) << right << fibonacciSequence[rowFN];
          }
          PrintLines(2);
     }
}

//@prints out the kth and k/2 position in the fibonacci sequence using the phi appoximation method, where k = largestNumInSequence
//@pre largestNumInSequence is the largest lumber found by the iterative method
//@post both the k and k/2 number in the fibonacci sequence have been printed out
//@param largestNumInSequence
//@usage PrintLargestKForPhiMethod(largestNumInSequence);
void PrintLargestKForPhiMethod(int largestNumInSequence)
{
     cout << "~~~~~~~~~~~~~~~~~~~The Fibonacci Sequence using Phi~~~~~~~~~~~~~~~~~~~~" << endl;
     cout << "k       ->" << setw(15) << right << largestNumInSequence << endl;
     cout << "Fib(k)   =" << setw(15) << right << ComputeUsingPhiMethod(largestNumInSequence) << endl;
     cout << "Fib(k/2) =" << setw(15) << right << ComputeUsingPhiMethod(largestNumInSequence/2);
     PrintLines(2);

}

//@computes the kth position of the fibonacci sequence where k = largestNumInSequence
//@pre largestNumInSequence is the largest lumber found by the iterative method
//@post the largestNumInSequence of the fibonacci sequence is computed and returned
//@param largestNumInSequence
//@return a unsigned int that is the kth position of the fibonacci sequence k = largestNumInSequence
//@usage cout << "Fib(k/2) =" << setw(15) << right << ComputeUsingPhiMethod(largestNumInSequence/2);
unsigned int ComputeUsingPhiMethod(int largestNumInSequence)
{
     int nSequence = largestNumInSequence;
     double fibResult = 1;
     double lastPhi = 1;
     double rootFive = sqrt(5);
     
     double phi = (1 + rootFive) / 2.0;
     double phiResult = phi;
     int k = nSequence;
     
     
     if (nSequence == 0)
     {
          phiResult = 1;
     }
     for (k; k > 1; k = k / 2)
     {

          if(k % 2 == 1)
          {
               k = k - 1;
               lastPhi = phiResult * lastPhi;
          }
          phiResult = phiResult * phiResult;
     }
     fibResult = phiResult * lastPhi;
     return (fibResult / rootFive + .5);

}

//@creates a user determined size array of the fibonacci sequence in a dynamic array
//@pre dynamic array fibonacciSequence is empyt
//@post dynamic array fibonacciSequence is filled to the fibonacciSize number in the sequence
//@param fibonacciSequence
//@      fibonacciSize
//@usage CreateIterativeFibonacci();
int CreateIterativeFibonacci(unsigned int* fibonacciSequence, int fibonacciSize, unsigned int unsignedLimit)
{
     bool testNumber = true;
     fibonacciSequence[0] = 0;
     fibonacciSequence[1] = 1;
     int i;
     
     if(fibonacciSize == 0)
     {
          return 0;
     }else if (fibonacciSize == 1) {
          return 1;
     }
     
     
     for (i = 2; i <= fibonacciSize && testNumber == true; i++)
     {
          if ((fibonacciSequence[i - 1]) < unsignedLimit / 2)
          {
               fibonacciSequence[i] = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
          } else {
               testNumber = false;
               i = i - 1;
          }
          
     }
     return i - 1;
     
}

//@takes in a new number in base ten to convert it to base two
//@pre base ten is a number 0 or greater
//@post base ten is a nonnegative number that is to be converted
//@param baseTen
//@usage inputNumber(baseTen);
void InputNumber(int& numberN)
{
	int temp;
	bool inputOK = true;
	while (inputOK)
	{
		PrintLines(1);
		cout << "Enter a POSITIVE integer for 'n' of the Fibonacci Sequence. --> ";
		cin >> temp;
		PrintLines(1);
		if (temp >= 0)
		{
			numberN = temp;
			inputOK = false;
		} else {
			cout << ":: Please make sure the number is gr ::";
		}
	}
}

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


//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
	for (int k = 0; k < num; k++)
		cout << endl;
}

