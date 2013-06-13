//@file: prog6.cpp
//@author: Jamie Haddock (jhaddock2) and Ryan Draper (rdraper)
//@date: 4/15/13
//@description: Does the Warshall algorithm and the Depth-First-Search Algorithm to two adjacency matrices the first a 4x4 and the second 
//@				 a 8x8 and returns the trasitive closure matrix. It will do this in a step by step method for the user to better understand
//@				 both algorithms.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include "matrix.h"

using namespace std;

// PrintLines prints num lines
//@pre: num must be a nonnegative integer
//@post: num lines are printed
//@param: int num
//@return: none
//@throw: none
//@usage: PrintLines(2);
void PrintLines(int num);

// GenerateMatrix reads matrix bool values into a two dimensional array from an input file
//@pre: matrix 1 and matrix 2 exist and have been set to a default
//@post: matrix 1 and matrix 2 's elements holds the matrix values in in6.dat
//@param: matrix1
//@param: matrix2
//@return: none
//@throw: none
//@usage: GenerateMatrix(Adj1, Adj2);
void GenerateMatrix(Matrix& matrix1, Matrix& matrix2);

//@completes the Depth-First-Search algorithm from the adjacency 'matrix' and gets the trasitive closure matrix 'DFSmatrix'
//@pre:matrix and DFS matrix are instances of the matrix class
//@post:'DFSmatrix' has been acted upon by the Depth First Search algorithm and is now the transitive closure matrix of the variable 'matrix'
//@param: matrix
//@param: DFSmatrix
//@return: none
//@throw: none
//@usage: DFSVisualization(Adj1, DFSmatrix1);
void DFSVisualization(Matrix& matrix, Matrix& DFSmatrix);

//@Displays steps and explains the warshall algorithms as it happens to the variable 'matrix'
//@pre: matrix is a instance of the class Matrix and is an adjacency matrix
//@post: matrix is now the trasitive closre matrix as found by the Warshall Algorithm
//@param: matrix
//@return: none
//@throw: none
//@usage: WarshallsVisualization(Adj1);
void WarshallsVisualization(Matrix& matrix);

int main(){
   Matrix Adj1, Adj2;
   GenerateMatrix(Adj1, Adj2);
   Matrix DFSmatrix1;
   Matrix DFSmatrix2;
   DFSmatrix1.setSize(Adj1.getSize());
   DFSmatrix2.setSize(Adj2.getSize());
   
   DFSVisualization(Adj1, DFSmatrix1);
   WarshallsVisualization(Adj1);
   DFSVisualization(Adj2, DFSmatrix2);
   WarshallsVisualization(Adj2);

   return 0;
}

// GenerateMatrix reads matrix bool values into a two dimensional array from an input file
//@pre: matrix 1 and matrix 2 exist and have been set to a default
//@post: matrix 1 and matrix 2 's elements holds the matrix values in in6.dat
//@param: matrix1
//@param: matrix2
//@return: none
//@throw: none
//@usage: GenerateMatrix(Adj1, Adj2);
void GenerateMatrix(Matrix& matrix1, Matrix& matrix2){
   ifstream matrixFile ("in6.dat");
   string line;
   if (matrixFile.is_open())
   {
      matrixFile >> matrix1;
      matrixFile >> matrix2;
      matrixFile.close();
   }
   else cout << "Unable to open file.";
}

// PrintLines prints num lines
//@pre: num must be a nonnegative integer
//@post: num lines are printed
//@param: int num
//@return: none
//@throw: none
//@usage: PrintLines(2);
void PrintLines(int num){
   for (int i = 0; i < num; i++)
      cout << endl;
}

//@Displays steps and explains the warshall algorithms as it happens to the variable 'matrix'
//@pre: matrix is a instance of the class Matrix and is an adjacency matrix
//@post: matrix is now the trasitive closre matrix as found by the Warshall Algorithm
//@param: matrix
//@return: none
//@throw: none
//@usage: WarshallsVisualization(Adj1);
void DFSVisualization(Matrix& matrix, Matrix& DFSmatrix){
	cout << "************ Visualization of Depth First Search Algorithm ****************" << endl;

	cout << "The Algorithm Depth-First Search is a decrease-by-one technique that visits" << endl;
   cout << "vertices in a graph by traversing edges. We use this algorithm to determine" << endl;
   cout << "the graph's transitive closure." << endl;
	cout << "" << endl;
	cout << "The original adjacency matrix: " << endl;
   PrintLines((8 - matrix.getSize())/2);
   cout << matrix;
   PrintLines((8 - matrix.getSize())/2);
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Press Enter to go on!";
   cin.get();
	matrix.DFSWithDisplay(DFSmatrix);
   cout << "Now, we have successfully completed calculating the transitive closure matrix:" << endl;
   PrintLines(7);
   PrintLines((8 - matrix.getSize())/2);
   cout << DFSmatrix;
   PrintLines((8 - matrix.getSize())/2);
   PrintLines(6);
   cout << "Press enter to continue!";
   cin.get();
}

void WarshallsVisualization(Matrix& matrix){
   cout << "**************** Visualization of Warshall's Algorithm ********************" << endl;
   
   cout << "Warshall's Algorithm calculates the transitive closure, or the n x n matrix" << endl;
   cout << "that demonstrates whether there exists a non-trivial directed path from vertex" << endl;
   cout << "i to vertex j by placing a 1 in the ith row and jth column entry.  It does so " << endl;
   cout << "by calculating a series of n x n matrices - which we call R(0), R(1),..., R(n)" << endl;
   cout << "with R(0) the original " << matrix.getSize() << " x " << matrix.getSize() <<" adjacency matrix: " << endl;
   PrintLines((8 - matrix.getSize())/2);
   cout << matrix;
   PrintLines((8 - matrix.getSize())/2);
   cout << "and R(n) the transitive closure matrix." << endl;
   PrintLines(1);
   cout << "It computes R(k) by defining: " << endl;
   cout << "R(k)[i][j] = R(k-1)[i][j] or (R(k-1)[i][k] and R(k-1)[k][j])." << endl;
   cout << "In other words, there exists a path from vertex i to vertex j using only the" << endl;
   cout << "first k vertices if there either existed a path between the vertices using" << endl;
   cout << "only the first k-1 vertices, OR if there existed both a path from vertex i to" << endl;
   cout << "vertex k using the first k-1 vertices AND a path from vertex k to vertex j" << endl;
   cout << "using the first k-1 vertices." << endl;
   cout << "Press Enter to go on!";
   cin.get();
   
   Matrix copy = matrix;
   int numTimes = copy.getSize();
   for (int k = 0; k < numTimes; k++){
      cout << "***************** Computing R(" << k+1 << ") using R(" << k << ") *********************" << endl;
      PrintLines((8 - copy.getSize())/2);
      cout << "R(" << k << "): " << endl;
      copy.printMatrix(k, k);
      PrintLines((8 - copy.getSize())/2);
      cout << "R(" << k+1 << ") is computed by choosing either the element that was previously" << endl;
      cout << "in the matrix entry we are calculating (if it was 1) or by assigning it 1 only" << endl;
      cout << "if both the ith row, " << k + 1 << "th column entry and the " << k + 1 << "th row, jth column entries are 1." << endl;
      PrintLines(1);
      cout << "Thus, R(" << k+1 << "): " << endl;
      copy.WarshallStep(k);
      PrintLines((8 - copy.getSize())/2);
      cout << copy;
      PrintLines((8 - copy.getSize())/2);
      cout << "Press Enter to go on!";
      cin.get();
   }
   PrintLines(7);
   cout << "Thus the transitive closure has been calculated!" << endl;
   PrintLines((8 - matrix.getSize())/2);
   matrix.Warshall();
   cout << matrix;
   PrintLines((8 - matrix.getSize())/2);
   PrintLines(6);
   cout << "Press enter to continue!";
   cin.get();
}


