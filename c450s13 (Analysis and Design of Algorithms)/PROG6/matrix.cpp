//@Implementation of Matrix
//@data object: This clas Matrix represents a graph that can be directed or undirected with possible edges 
//@             connecting vertices represented by true or 1 and non connections repsented by false or 0.
//@				ex. 4x4
//@				   v1  v2  v3  v4               (v1)-->(v2)
//@				v1 0   1   0   0                  |^\   |
//@				v2 0   0   0   1  representing:   |  \  |
//@				v3 0   0   0   0                  |   \ |
//@				v4 1   0   1   0                (v3)<--(v4)

//@data structure: A two dimensional array
//@Operations: create, destroy, copy, Depth-First-Search, IsDeadEnd, WarshallStep,
//@            Warshall, getSize, getMatValue, setMatValue, setSize, printMatrix 
//@file: Matrix.cpp
//@author: Jamie Haddock (jhaddock2) and Ryan Draper (rdraper)
//@date: 4/14/13


#include "matrix.h"
#include <iostream>

using namespace std;

//@Creates an instance of the bool two dimensional array for the matrix
//@pre The array of bool for Matrix does not exist 
//@post The array of bool for Matrix does exist 
//@param non
//@return non
//@throw non
//@usage Matrix newMatrix;
Matrix::Matrix()
{
    matSize = MAXSIZE;
    for (int i = 0; i < matSize; i++){
       for (int j = 0; j < matSize; j++)
          mat[i][j] = false;
    }
}

//@Copies a already created matrix into the rhs matrix
//@pre rhs matrix and this* matrix exist
//@post rhs is a copy of this* matrix
//@param rhs
//@return none
//@throw none
//@usage rhs = matrix;
Matrix& Matrix::operator=(const Matrix& rhs)
{
   matSize = rhs.matSize;
   for (int i = 0; i < matSize; i++){
      for (int j = 0; j < matSize; j++){
         mat[i][j] = rhs.mat[i][j];
      }
   } 
}

//@Destroys an instance of the matrix class
//@pre matrix exists
//@post matrix doesn't exist
//@param none
//@return none
//@throw none
//@usage none
Matrix::~Matrix()
{}

//@ Does the Depth-First-Search Algorithm with visualization for each step to show what is happening
//@pre matrix T is a matrix and this* is the adjacency matrix 
//@post The depth first search algorithm turns the T matrix into the trasitive closure of this* matrix
//@param T
//@return none
//@throw none
//@usage adjMatrix.DFS(trasitiveClosureMatrix);
void Matrix::DFSWithDisplay(Matrix& T)
{
   bool visited[matSize];
   stack <int> vertexStack;
   
   for (int currentStart = 0; currentStart < matSize; currentStart++){//interates row
      int i = currentStart;
      
      for (int l = 0; l < matSize; l++) //empty the visited list
         visited[l] = false;
      
      vertexStack.push(i);
      cout << "We begin finding the vertices we can reach from vertex v" << i + 1 << " by" << endl;
      cout << "pushing that vertex onto the stack:" << endl;
      PrintNewLines(9 - returnStackSize(vertexStack) / 2);
		printStack(vertexStack);
		PrintNewLines(9 - returnStackSize(vertexStack) / 2);
		toContinue();

      PrintNewLines(11);
      cout << "We iterate over the rows elements, beginning at 1 until we find a vertex "<< endl;
      cout << "we can reach from vertex v" << i + 1 << " in the Adjacency Matrix" << endl;
      PrintNewLines(10);
      toContinue();
		
      

      int j = 0;
      while (not vertexStack.empty()){

         if (IsDeadEnd(i, visited)){//row had been visited
            cout << "We have encountered a dead end with vertex v" << i + 1 << " which is at the top of the stack:" << endl;
            printStack(vertexStack);
				cout << "Press enter to continue!";
      		cin.get();
            PrintNewLines((25 - returnStackSize(vertexStack))/2);
            cout << "so we pop and have the stack:" << endl;
            vertexStack.pop();
            printStack(vertexStack);
            toContinue();
				PrintNewLines(3);
            if (not vertexStack.empty()){
               i = vertexStack.top();
               j = 0;
            }
         }
         
         else{
            while ((j < matSize) and (not mat[i][j])) //finds first j such that mat[i][j] is true
               j++;

	         if (j == currentStart){              //found a cycle
	            T.setMatValue(currentStart, j, true);
	            cout << "Vertex v" << currentStart + 1 << " is the starting vertex, so we have"<< endl;
	            cout << "found a cycle - change the entry to 1." << endl;
               PrintNewLines(2);
               PrintNewLines(7 - getSize() / 2);
	            T.printMatrix(currentStart, currentStart);
               PrintNewLines(8 - getSize() / 2);
               PrintNewLines(2);
	            toContinue();
	            visited[j] = true;
	            j++;
	         }
	         else if ((j < matSize) and (not visited[j])){  //if j has not been visited, add to stack and continue

	            vertexStack.push(j);
               PrintNewLines(1);
					PrintNewLines(10 - getSize() / 2);
	            cout << "The Adjacency Matrix: " << endl;
	            printMatrix(i,j);
					PrintNewLines(9 - getSize() / 2);
	            cout <<"tells us that there is an edge between vertex v" << i + 1 << " and vertex v" << j + 1 << endl;
					toContinue();      

					cout << "Vertex v" << j + 1 << " has not been visited, so we add it to stack" << endl;
					PrintNewLines(11 - returnStackSize(vertexStack));
					printStack(vertexStack);
					PrintNewLines(11 - returnStackSize(vertexStack));
					toContinue();

					cout << "Then change the entry in our transitive matrix for row " << currentStart + 1  << endl;
					cout << "and column " << j + 1 << " to '1'." << endl;
				
	            visited[j] = true;
	            T.setMatValue(currentStart, j, true);
					PrintNewLines(9 - T.getSize()/2);
					T.printMatrix(currentStart,j);
					PrintNewLines(10 - T.getSize()/2);
					toContinue();

	            i = j;
	            j = 0;
	         }
            else if (j > matSize){                    //if j is too big, we have found a dead end, pop and continue
               cout << "We have encountered a dead end with vertex v" << i << " which is at the top of the stack:" << endl;
               printStack(vertexStack);
               cout << "so we pop and have stack:" << endl;
               vertexStack.pop();
               printStack(vertexStack);
               toContinue();
               i = vertexStack.top();
               j = 0;
            }
	         else                                      //found a j with mat[i][j] true, but has already been visited
	            j++;                                   //iterate j and continue
   	   }
     }
   }
         
}

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
bool Matrix::IsDeadEnd(int i, bool visited[])
{
   for (int j = 0; j < matSize; j++){
      if ((mat[i][j]) and (not visited[j]))
         return false;
   }
   return true;
}

//@turns the data member from R^(k-1) to R^(k)
//@pre Matrix A^(k-1) exists. output is open.
//@post contents of A^(k-1) are now A^(k)
//@param k
//@return none
//@throw none
//@usage copy.WarshallStep(k);
void Matrix::WarshallStep(int newK)
{
	for(int i = 0; i < getSize(); i++)
	{
		for(int j = 0; j < getSize(); j++)
		{
			mat[i][j] = (mat[i][j] || mat[i][newK] && mat[newK][j]);
		}
	}

}

//@turns the data member from R^(k-1) to R^(k)
//@pre Matrix A^(k-1) exists. output is open.
//@post contents of A^(k-1) are now A^(k)
//@param k
//@return none
//@throw none
//@usage Warshall(copy);
void Matrix::Warshall()
{
	for(int k = 0; k < getSize(); k++)
	{
		WarshallStep(k);
	}
}

//@returns the size n of a n x n matrix
//@pre matrix exists
//@post returns size of matrix
//@param none
//@return n of a n x n matrix
//@throw none
//@usage PrintNewLines(12 - T.getSize());
int Matrix::getSize() const
{
	return matSize;
}

//@returns a matrix bool value in the row and col position of the two dimensional array
//@pre matrix exists with values in all (matSize) by (matSize) elements
//@post returns the bool value in the two dimensional matrix[row][col] element
//@param row
//@param col
//@return bool
//@throw none
//@usage T.getMatValue(i,j);
bool Matrix::getMatValue(int row, int col) const
{
	return mat[row][col];
}

//@sets a value in the two dimensional bol matrix bool in the row and col position to the 'val' value
//@pre matrix exists with values in all (matSize) by (matSize) elements
//@post sets the bool value in the two dimensional matrix[row][col] element
//@param row
//@param col
//@param val
//@return none
//@throw none
//@usage T.setMatValue(i,j,true);
void Matrix::setMatValue(int row, int col, bool val)
{
	mat[row][col] = val;
}

//@sets the private datamember matSize to the int size
//@pre matrix exists of size matSize by matSize dimensions
//@post matrix exists with matSize now set to size
//@param size
//@return none
//@throw none
//@usage rhsA.setSize(size); 
void Matrix::setSize(int size)
{
   matSize = size;
}

//@prints the stack on the screen in a top down method
//@pre vertexStack is a stack
//@post the elements of the vertexStack are output on the screen
//@param vertexStack
//@return none
//@throw none
//@usage printStack(vertexStack);
void Matrix::printStack(stack <int> vertexStack)
{
	
	if(not vertexStack.empty())
	{
		while(not vertexStack.empty())
		{
			cout << "| v" << vertexStack.top() + 1 << " |" << endl;
			vertexStack.pop();
		}
		cout << " ----" << endl;
	} else {
		cout << "Vertex Stack Empty!!!" << endl;
	}
}

//@returns the depth of the stack
//@pre vertexStack exists as a stack
//@post returns the depth of the stack as an int
//@param vertexStack
//@return int
//@throw none
//@usage PrintNewLines(11 - returnStackSize(vertexStack));
int Matrix::returnStackSize(stack <int> vertexStack)
{
	int numCount = 0;
	if(not vertexStack.empty())
	{
		while(not vertexStack.empty())
		{
			vertexStack.pop();
			numCount++;
		}
	} else {
		cout << "Vertex Stack Empty!!!" << endl;
	}
	return numCount;
}

//@prints the matrix with indicators pointing at the row and col of the two dimensional array that represents the matrix
//@pre matrix exists
//@postmatrix is output on the screen with indicators pointing to the matrix[row][col]
//@param row
//@param col
//@return none
//@throw none
//@usage T.printMatrix(currentStart,j);
void Matrix::printMatrix(int row, int col)
{
	int i, j;
	for(i = 0; i < getSize(); i++)
	{
		for(j = 0; j < getSize(); j++)
		{
			if(getMatValue(i, j) == true)
				cout << 1 << " ";
			else
				cout << 0 << " ";
			
		}
		if(i == row)
			{
				cout << "<";
			}
      cout << endl;
	}
	for(int k = 0; k< getSize(); k++)
	{
		if (k == col)
			cout << "^ ";
		else
            cout << "  ";
	}
	cout << endl;
}

//PrintLines prints num lines
//@pre: num must be a nonnegative integer
//@post: num lines are printed
//@param: int num
//@return: none
//@throw: none
//@usage: PrintLines(2);
void Matrix::PrintNewLines(int num){
   for (int i = 0; i < num; i++)
      cout << endl;
}

//@Asks the user to hit enter to continue
//@pre Matrix class exists
//@post the user has been asked to continue
//@param none
//@return none
//@throw none
//@usage toContinue();
void Matrix::toContinue()
{
	cout << "Press enter to continue!";
   cin.get();
	PrintNewLines(5);
}

//@outputs to a file or the monitor a matrix object
//@pre Matrix A exists. output is open.
//@post contents of A have been output
//@param output
//@param A
//@usage cout << rhsMatrix << endl;   
ostream& operator<< (ostream& output, const Matrix& rhsA)
{
   if (&output != &cout)
      output << rhsA.getSize() << endl;
   if (rhsA.getSize() != 0)
   { 
		for(int i = 0; i < rhsA.getSize(); i++)
		{
			for(int j = 0; j < rhsA.getSize(); j++)
			{
				if(rhsA.getMatValue(i, j) == true)
					output << 1 << " ";
				else
					output << 0 << " ";
			}
         output << endl;
		}
	               
   } else {
      output << "Empty";
   }
   return output;
}
   
//@inputs to a file or the monitor a matrix object
//@pre Matrix A exists. input is open.
//@post contents input from each line of file or from keyboard
//@param input
//@param A
//@usage cout << rhsMatrix << endl;
istream& operator>> (istream& input, Matrix& rhsA)
{  
   if(&input == &cin)
   {
      cout << "Enter matrix rank: " << endl;
   }
   int size;
   input >> size;
   rhsA.setSize(size); 
	for(int i = 0; i < rhsA.getSize(); i++)
	{  
		for(int j = 0; j < rhsA.getSize(); j++)
		{
			if(&input == &cin)
			{
				cout << "Enter matrix[" << i << "][" << j << "]: ";
			}
         int num;
         input >> num;
         if (num == 1)
			   rhsA.setMatValue(i,j,true);
         else
            rhsA.setMatValue(i,j,false);
		}
	}
   
   return input;
}




