//@Specification of a Matrix
//@description: This clas Matrix represents a graph that can be directed or undirected with possible edges 
//@             connecting vertices represented by true or 1 and non connections repsented by false or 0.
//@				ex. 4x4
//@				   v1  v2  v3  v4               (v1)-->(v2)
//@				v1 0   1   0   0                  |^\   |
//@				v2 0   0   0   1  representing:   |  \  |
//@				v3 0   0   0   0                  |   \ |
//@				v4 1   0   1   0                (v3)<--(v4)

//@Operations: create, destroy, copy, Depth-First-Search, IsDeadEnd, WarshallStep,
//@            Warshall, getSize, getMatValue, setMatValue, setSize, printMatrix 
//@file: Matrix.h
//@author: Jamie Haddock (jhaddock2) and Ryan Draper (rdraper)
//@date: 4/14/13

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stack>

using namespace std;

int const MAXSIZE = 8;

class Matrix
{
		//@outputs to a file or the monitor a matrix object
		//@pre Matrix A exists. output is open.
		//@post contents of A have been output
		//@param output
		//@param A
		//@usage cout << rhsMatrix << endl;  
		friend ostream& operator<< (ostream& output, const Matrix& rhsA);

		//@inputs to a file or the monitor a matrix object
		//@pre Matrix A exists. input is open.
		//@post contents input from each line of file or from keyboard
		//@param input
		//@param A
		//@usage cout << rhsMatrix << endl;
		friend istream& operator>> (istream& input, Matrix& rhsA);

	public:
		//@Creates an instance of the bool two dimensional array for the matrix
		//@pre The array of bool for Matrix does not exist 
		//@post The array of bool for Matrix does exist 
		//@param non
		//@return non
		//@throw non
		//@usage Matrix newMatrix;
		Matrix();

		//@Copies a already created matrix into the rhs matrix
		//@pre rhs matrix and this* matrix exist
		//@post rhs is a copy of this* matrix
		//@param rhs
		//@return none
		//@throw none
		//@usage rhs = matrix;
		Matrix& operator=(const Matrix& rhs);

		//@Destroys an instance of the matrix class
		//@pre matrix exists
		//@post matrix doesn't exist
		//@param none
		//@return none
		//@throw none
		//@usage none
		virtual~Matrix();

		//@ Does the Depth-First-Search Algorithm with visualization for each step to show what is happening
		//@pre matrix T is a matrix and this* is the adjacency matrix 
		//@post The depth first search algorithm turns the T matrix into the trasitive closure of this* matrix
		//@param T
		//@return none
		//@throw none
		//@usage adjMatrix.DFS(trasitiveClosureMatrix);
		void DFSWithDisplay(Matrix& T);

		//@Checks a row of the matix to see what values are true and have been visited to find dead ends for 
		//@the DFS algorithm
		//@pre matrix exists with an i row and 'visit' is an array of bool that represents what elements in  
		//@    the row hasbeen visited 
		//@post returns true if there is a a connection between vertex i and vertex j and that element in the 
		//@     row has not been visited
		//@param i
		//@param visited[]
		//@return bool
		//@throw none
		//@usage if (IsDeadEnd(i, visited)){//row had been visited
      bool IsDeadEnd(int i, bool visited[]);

		//@turns the data member from R^(k-1) to R^(k)
		//@pre Matrix A^(k-1) exists. output is open.
		//@post contents of A^(k-1) are now A^(k)
		//@param k
		//@return none
		//@throw none
		//@usage copy.WarshallStep(k);
		void WarshallStep(int newK);

		//@turns the data member from R^(k-1) to R^(k)
		//@pre Matrix A^(k-1) exists. output is open.
		//@post contents of A^(k-1) are now A^(k)
		//@param k
		//@return none
		//@throw none
		//@usage Warshall(copy);
		void Warshall();

		//@returns the size n of a n x n matrix
		//@pre matrix exists
		//@post returns size of matrix
		//@param none
		//@return n of a n x n matrix
		//@throw none
		//@usage PrintNewLines(12 - T.getSize());
		int getSize() const;

		//@returns a matrix bool value in the row and col position of the two dimensional array
		//@pre matrix exists with values in all (matSize) by (matSize) elements
		//@post returns the bool value in the two dimensional matrix[row][col] element
		//@param row
		//@param col
		//@return bool
		//@throw none
		//@usage T.getMatValue(i,j);
		bool getMatValue(int row, int col) const;

		//@sets a value in the two dimensional bol matrix bool in the row and col position to the 'val' value
		//@pre matrix exists with values in all (matSize) by (matSize) elements
		//@post sets the bool value in the two dimensional matrix[row][col] element
		//@param row
		//@param col
		//@param val
		//@return none
		//@throw none
		//@usage T.setMatValue(i,j,true);
		void setMatValue(int row, int col, bool val);

		//@sets the private datamember matSize to the int size
		//@pre matrix exists of size matSize by matSize dimensions
		//@post matrix exists with matSize now set to size
		//@param size
		//@return none
		//@throw none
		//@usage rhsA.setSize(size); 
      void setSize(int size);
		
		//@prints the matrix with indicators pointing at the row and col of the two dimensional array that represents the matrix
		//@pre matrix exists
		//@postmatrix is output on the screen with indicators pointing to the matrix[row][col]
		//@param row
		//@param col
		//@return none
		//@throw none
		//@usage T.printMatrix(currentStart,j);
		void printMatrix(int row, int col);
	protected:
		//@returns the depth of the stack
		//@pre vertexStack exists as a stack
		//@post returns the depth of the stack as an int
		//@param vertexStack
		//@return int
		//@throw none
		//@usage PrintNewLines(11 - returnStackSize(vertexStack));
		int returnStackSize(stack <int> vertexStack);

		//@prints the stack on the screen in a top down method
		//@pre vertexStack is a stack
		//@post the elements of the vertexStack are output on the screen
		//@param vertexStack
		//@return none
		//@throw none
		//@usage printStack(vertexStack);
		void printStack(stack <int> vertexStack);
		
		//@Asks the user to hit enter to continue
		//@pre Matrix class exists
		//@post the user has been asked to continue
		//@param none
		//@return none
		//@throw none
		//@usage toContinue();
		void toContinue();

		// PrintLines prints num lines
		//@pre: num must be a nonnegative integer
		//@post: num lines are printed
		//@param: int num
		//@return: none
		//@throw: none
		//@usage: PrintNewLines(2);
		void PrintNewLines(int num);
	private:
      bool mat[MAXSIZE][MAXSIZE];
		int matSize;
			
	
        
};

#endif // MATRIX_H
