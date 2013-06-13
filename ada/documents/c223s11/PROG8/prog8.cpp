//@author Ryan Draper(draper)
//@date April 14, 2011
//@file prog8.cpp
//@description: This program will test many cases and subcases that occure with a 2-3-4 tree

#include <iostream>
#include <iomanip>
#include <fstream>
#include "c234tree.h"

using namespace std;

//@Attatches a creators header
//@pre outfile is a opened outfile waiting to be written to
//@post outfile has the creators header
//@param outfile
//@usage AttatchName(prog6File);
void AttatchName(ofstream& outfile);

//@opens an external file for reading and creates another for writing
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and ok is
//@     true and outfile is opened, else ok is false
//@param infile
//@param outfile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputAndOutputFile(ofstream& outfile, ifstream& infile, bool& ok);

//@prints a number of newlines in the file
//@pre num is nonnegative
//@post num newlines are wrote to the outfile
//@param num
//@param outfile
//@usage PrintLines(3, outfile);
void PrintLines(int num, ofstream& outfile);

//@closes both the output and input file and shoots one output to the screen to show that the file ran through completely
//@pre both outfile and infile are open files for reading and writing
//@post both files are closed
//@param outfile
//@param infile
//@usage FileClose(outfile, infile);
void FileClose(ofstream& outfile, ifstream& infile);

//@prints a testing message in the outfile
//@pre whatCase is a string and outfile is a file to be written to
//@post whatCase is written to the file
//@param outfile
//@param whatCase
//@usage PrintMessage(outfile, "Has No Pivot");
void PrintMessage (ofstream& outfile, const char* whatCase);

//@prints a message to the file
//@pre which is a string item is a Ckey object and outfile is a open output file to be written to
//@post which and item are written to outfile
//@param outfile
//@param item
//@which
//@usage PrintTreeMessage(outfile, item, "Pre");
void PrintTreeMessage (ofstream& outfile, Citem item, const char* which);

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (ofstream& outfile, const char* which, const char* whatCase);

//@builds more of the tree from the infile 
//@pre infile is a open reading file, avlTree is a existing cavltree object and number
//@    represents the number of items to insert into the tree
//@post the tree has had items inserted into it from the file
//@param infile
//@param avlTree
//@number
//@usage InvisivibleBuildTree(infile, baseTree, 2);
void InvisibleBuildTree(ifstream& infile, ofstream& outfile, C234tree& tree, int number);

//@builds more of the tree from the infile 
//@pre infile is a open reading file, avlTree is a existing cavltree object and number
//@    represents the number of items to insert into the tree
//@post the tree has had items inserted into it from the file
//@param infile
//@param avlTree
//@number
//@usage InvisivibleTempBuildTree(infile, baseTree, 2);
void InvisibleTempBuildTree(ifstream& infile, ofstream& outfile, C234tree tree, int number);

//@inserts items into a tree temperarily to show the effect different items have on a avl tree without effecting the tree's base
//@pre infile is a file to be read from outfile is to be written to and cavltree is a existing cavltree
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@param temp
//@usage InsertInTree(infile, outfile, avlTree);
void TempInsertInTree(ifstream& infile, ofstream& outfile, C234tree temp);

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@      testItem
//@usage Insert(cbsTest, testItem)
void InsertInTree(ifstream& infile, ofstream& outfile, C234tree& tree);

//@builds more of the tree from the infile 
//@pre infile is a open reading file, avlTree is a existing cavltree object and number
//@    represents the number of items to insert into the tree
//@post the tree has had items inserted into it from the file
//@param infile
//@param avlTree
//@number
//@usage InvisivibleTempBuildTree(infile, baseTree, 2);
void TempBuildTree(ifstream& infile, ofstream& outfile, C234tree tree, int number);

//@Goes through a number of examples of the case insert into root of a 234 tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage IntoRootfileItems, prog8File);
void IntoRoot(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the case insert into 2nd level of a 234 tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage IntoRootfileItems, prog8File);
void SecondLevel(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the case insert into Double Split from a root of a 234 tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage IntoRootfileItems, prog8File);
void DoubleSplitFromRoot(ifstream& infile, ofstream& outfile);

int main()
{
   /*
   C234tree big, tree;
   int index;
   Citem item;
   
	cin >> index;
   for (int i = 0; i < index; i++)
   {
      cin >> item;
      big.Insert(item);
      
      big.DisplayTree();
      tree = big;
      tree.DisplayTree();
   }
   /**/
	
   ifstream fileItems;
	ofstream prog8File;
   bool fileOk;
   

   OpenInputAndOutputFile(prog8File, fileItems, fileOk);
	
	AttatchName(prog8File);
	
   IntoRoot(fileItems, prog8File);
	SecondLevel(fileItems, prog8File);
	DoubleSplitFromRoot(fileItems, prog8File);
	
	FileClose(prog8File, fileItems);
	/**/
}

//@Goes through a number of examples of the case insert into Double Split from a root of a 234 tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage IntoRootfileItems, prog8File);
void DoubleSplitFromRoot(ifstream& infile, ofstream& outfile)
{
   C234tree baseTree, secondTree, thirdTree;
   
   PrintMessage(outfile, "+Into Second-Level 4-node From a 4-node double Split+");
   outfile << endl << "NOTE:: I have shown that my node insert and pointer adjustments to work to the 3rd level." << endl;
   outfile << "       I will no longer iterate all subcases but only insert into the child case." << endl;

   InvisibleBuildTree(infile, outfile, baseTree, 11);
   secondTree = baseTree;
   InvisibleBuildTree(infile, outfile, baseTree, 1);
   InvisibleBuildTree(infile, outfile, secondTree, 1);
	PrintMessage (outfile, "sub-case", "Double-Split left");
   for (int i = 0; i < 4; i++)
	{
	   TempInsertInTree(infile, outfile, secondTree);
   }
	PrintMessage (outfile, "sub-case", "Double-Split mid-left");
   for (int i = 0; i < 4; i++)
	{
	   TempInsertInTree(infile, outfile, secondTree);
   }
	PrintMessage (outfile, "sub-case", "Double-Split mid-right");
   for (int i = 0; i < 4; i++)
	{
	   TempInsertInTree(infile, outfile, baseTree);
   }
	PrintMessage (outfile, "sub-case", "Double-Split right");
	for (int i = 0; i < 4; i++)
	{
	   TempInsertInTree(infile, outfile, baseTree);
   }
}

//@Goes through a number of examples of the case insert into 2nd level of a 234 tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage IntoRootfileItems, prog8File);
void SecondLevel(ifstream& infile, ofstream& outfile)
{
   C234tree baseTree, secondTree, thirdTree, fourthTree, fifthTree;
   
   PrintMessage(outfile, "+Into Second-Level From 2 node No Split+");
	PrintMessage (outfile, "sub-case", "2-node to a 2 and 3-node");
	InvisibleBuildTree(infile, outfile, baseTree, 3);
	secondTree = baseTree;
	InvisibleBuildTree(infile, outfile, baseTree, 1);
	thirdTree = baseTree;
	for (int i = 0; i < 5; i++)
	{
	   TempInsertInTree(infile, outfile, baseTree);
   }
   
   InvisibleBuildTree(infile, outfile, secondTree, 1);
   fourthTree = secondTree;
   for (int i = 0; i < 5; i++)
	{
	   TempInsertInTree(infile, outfile, secondTree);
   }
   PrintMessage(outfile, "+Into Second-Level From 2 node With Split+");
   PrintMessage (outfile, "sub-case", "2-node into a 4 node left child");
   baseTree = thirdTree;
   InvisibleBuildTree(infile, outfile, thirdTree, 1);
   
   for (int i = 0; i < 4; i++)
	{
	   TempInsertInTree(infile, outfile, thirdTree);
   }
   
   PrintMessage (outfile, "sub-case", "2-node into a 4 node right child");
   InvisibleBuildTree(infile, outfile, thirdTree, 2);
   for (int i = 0; i < 3; i++)
	{
	   TempInsertInTree(infile, outfile, thirdTree);
   }
   InsertInTree(infile, outfile, thirdTree);
   
   PrintMessage(outfile, "+Into Second-Level From 3 node No Split+");
	PrintMessage (outfile, "sub-case", "3-node to a 2-node left pointer");
	thirdTree = baseTree;
	secondTree = baseTree;
	
   InvisibleBuildTree(infile, outfile, thirdTree, 2);
   InvisibleBuildTree(infile, outfile, secondTree, 2);
   InvisibleBuildTree(infile, outfile, baseTree, 3);
   
   for (int i = 0; i < 2; i++)
	{
	   TempInsertInTree(infile, outfile, secondTree);
   }
   
	PrintMessage (outfile, "sub-case", "3-node to a 2-node middle");
	for (int i = 0; i < 2; i++)
	{
	   TempInsertInTree(infile, outfile, thirdTree);
   }
   
	PrintMessage (outfile, "sub-case", "3-node to a 2-node right");
   TempInsertInTree(infile, outfile, thirdTree);
   InsertInTree(infile, outfile, thirdTree);
   
	PrintMessage (outfile, "sub-case", "3-node to a 3-node left");
	fifthTree = thirdTree;
	for (int i = 0; i < 3; i++)
	{
	   TempInsertInTree(infile, outfile, thirdTree);
   }
   
	PrintMessage (outfile, "sub-case", "3-node to a 3-node middle");
	for (int i = 0; i < 3; i++)
	{
	   TempInsertInTree(infile, outfile, secondTree);
   }

	PrintMessage (outfile, "sub-case", "3-node to a 3-node right");
	for (int i = 0; i < 3; i++)
	{
	   TempInsertInTree(infile, outfile, thirdTree);
   }
   
   PrintMessage(outfile, "+Into Second-Level From 3 node With Split+");
   InvisibleBuildTree(infile, outfile, thirdTree, 1);
   InvisibleBuildTree(infile, outfile, secondTree, 1);
   InvisibleBuildTree(infile, outfile, baseTree, 1);
   PrintMessage (outfile, "sub-case", "3-node to the left 4-node");
   fourthTree = baseTree;
   for (int i = 0; i < 4; i++)
	{
      TempInsertInTree(infile, outfile, baseTree);
   }

   PrintMessage (outfile, "sub-case", "3-node to the middle 4-node");
   for (int i = 0; i < 4; i++)
	{
      TempInsertInTree(infile, outfile, secondTree);
   }

   PrintMessage (outfile, "sub-case", "3-node to the left 4-node");
   for (int i = 0; i < 4; i++)
	{
      TempInsertInTree(infile, outfile, thirdTree);
   }
   PrintMessage(outfile, "+Into Second-Level From a 4-node With Split+");
   baseTree = secondTree = thirdTree = fourthTree;
   PrintMessage (outfile, "sub-case", "3-node to the right 2-node");
   InvisibleBuildTree(infile, outfile, baseTree, 1);
   secondTree = baseTree;
   InvisibleBuildTree(infile, outfile, baseTree, 1);
   InvisibleBuildTree(infile, outfile, secondTree, 1);
   for (int i = 0; i < 2; i++)
	{
      TempInsertInTree(infile, outfile, baseTree);
   }
   PrintMessage (outfile, "sub-case", "3-node to the right 3-node");
   for (int i = 0; i < 3; i++)
	{
      TempInsertInTree(infile, outfile, secondTree);
   }
   
   PrintMessage (outfile, "sub-case", "3-node to the mid-right 2-node");
   for (int i = 0; i < 2; i++)
	{
      TempInsertInTree(infile, outfile, secondTree);
   }
   
   PrintMessage (outfile, "sub-case", "3-node to the mid-right 3-node");
   for (int i = 0; i < 3; i++)
	{
      TempInsertInTree(infile, outfile, baseTree);
   }
   InvisibleBuildTree(infile, outfile, thirdTree, 1);
   PrintMessage (outfile, "sub-case", "3-node to the mid-left 2-node");
   for (int i = 0; i < 2; i++)
	{
      TempInsertInTree(infile, outfile, secondTree);
   }
   PrintMessage (outfile, "sub-case", "3-node to the mid-left 3-node");
   for (int i = 0; i < 3; i++)
	{
      TempInsertInTree(infile, outfile, thirdTree);
   }
   InvisibleBuildTree(infile, outfile, fifthTree, 2);
   PrintMessage (outfile, "sub-case", "3-node to the left 2-node");
   for (int i = 0; i < 2; i++)
	{
      TempInsertInTree(infile, outfile, thirdTree);
   }
   PrintMessage (outfile, "sub-case", "3-node to the left 3-node");
   for (int i = 0; i < 3; i++)
	{
      TempInsertInTree(infile, outfile, fifthTree);
   }

}

//@Goes through a number of examples of the case insert into root of a 234 tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage IntoRootfileItems, prog8File);
void IntoRoot(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree;
	int i;
	
	PrintMessage(outfile, "+Into Root Node+");
	PrintMessage (outfile, "sub-case", "Empty to 2-node");
	InsertInTree(infile, outfile, baseTree);
	
	PrintMessage (outfile, "sub-cases", "2-node to 3-node");
	TempInsertInTree(infile, outfile, baseTree);
	InsertInTree(infile, outfile, baseTree);
	
	PrintMessage (outfile, "sub-cases", "3-node to 4-node");
	TempInsertInTree(infile, outfile, baseTree);
	TempInsertInTree(infile, outfile, baseTree);
	InsertInTree(infile, outfile, baseTree);
	
	PrintMessage(outfile, "+Splitting Root+:");
	PrintMessage(outfile, "sub-case", "new item to left child");
	TempInsertInTree(infile, outfile, baseTree);
	TempInsertInTree(infile, outfile, baseTree);
	
	PrintMessage(outfile, "sub-case", "new item to right child");
	TempInsertInTree(infile, outfile, baseTree);
	TempInsertInTree(infile, outfile, baseTree);
}

//@Attatches a creators header
//@pre outfile is a opened outfile waiting to be written to
//@post outfile has the creators header
//@param outfile
//@usage AttatchName(prog6File);
void AttatchName(ofstream& outfile)
{
	outfile << "Ryan Draper (draper)" << endl;
	outfile << "April 28, 2011" << endl;
	outfile << "PROGRAM 8" << endl;
	outfile << "2-3-4 Tree" << endl;
}

//@builds more of the tree from the infile 
//@pre infile is a open reading file, avlTree is a existing cavltree object and number
//@    represents the number of items to insert into the tree
//@post the tree has had items inserted into it from the file
//@param infile
//@param avlTree
//@number
//@usage InvisivibleBuildTree(infile, baseTree, 2);
void InvisibleBuildTree(ifstream& infile, ofstream& outfile, C234tree& tree, int number)
{
	Citem item;
	
	for (int i = 0; i < number; i++)
	{
		infile >> item;
		try
		{
			tree.Insert(item);
		}
		catch (cexception ex)
		{
			outfile << ex.what() << endl;  
		}
	}
	
}

//@builds more of the tree from the infile 
//@pre infile is a open reading file, avlTree is a existing cavltree object and number
//@    represents the number of items to insert into the tree
//@post the tree has had items inserted into it from the file
//@param infile
//@param avlTree
//@number
//@usage InvisivibleTempBuildTree(infile, baseTree, 2);
void InvisibleTempBuildTree(ifstream& infile, ofstream& outfile, C234tree tree, int number)
{
	Citem item;
	
	for (int i = 0; i < number; i++)
	{
		
		infile >> item;
		try
		{
			tree.Insert(item);
		}
		catch (cexception ex)
		{
			outfile << ex.what() << endl;  
		}
	}
	InsertInTree(infile, outfile, tree);
	
}

//@builds more of the tree from the infile 
//@pre infile is a open reading file, avlTree is a existing cavltree object and number
//@    represents the number of items to insert into the tree
//@post the tree has had items inserted into it from the file
//@param infile
//@param avlTree
//@number
//@usage InvisivibleTempBuildTree(infile, baseTree, 2);
void TempBuildTree(ifstream& infile, ofstream& outfile, C234tree tree, int number)
{
	Citem item;
	
	for (int i = 0; i < number; i++)
	{
		infile >> item;
	   PrintLines(2, outfile);
	   PrintTreeMessage(outfile, item, "Pre-Case");
	   tree.WriteTree(outfile);
		
	   try
	   {
		   tree.Insert(item);
		   PrintTreeMessage(outfile, item, "Post-Case");
		   tree.WriteTree(outfile);
	   }
		catch (cexception ex)
		{
			outfile << ex.what() << endl;  
		}
	}
	InsertInTree(infile, outfile, tree);
	
}


//@inserts items into a tree temperarily to show the effect different items have on a avl tree without effecting the tree's base
//@pre infile is a file to be read from outfile is to be written to and cavltree is a existing cavltree
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@param temp
//@usage InsertInTree(infile, outfile, avlTree);
void TempInsertInTree(ifstream& infile, ofstream& outfile, C234tree tree)
{
	Citem item;
	
	infile >> item;
	PrintLines(2, outfile);
	PrintTreeMessage(outfile, item, "Pre-Case");
	tree.WriteTree(outfile);
		
	try
	{
		tree.Insert(item);
		PrintTreeMessage(outfile, item, "Post-Case");
		tree.WriteTree(outfile);
	}
	catch (cexception ex)
	{
		outfile << ex.what() << endl;  
	}				 
}

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@usage Insert(cbsTest)
void InsertInTree(ifstream& infile, ofstream& outfile, C234tree& tree)
{
	Citem item;
	
	PrintLines(2, outfile);
	infile >> item;
	PrintTreeMessage(outfile, item, "Pre-Case");
	tree.WriteTree(outfile);
				 
	try
	{
		tree.Insert(item);
		PrintTreeMessage(outfile, item, "Post-Case");
		tree.WriteTree(outfile);
	}
	catch (cexception ex)
	{
		outfile << ex.what() << endl;  
	}
}

//@opens an external file for reading and creates another for writing
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and ok is
//@     true and outfile is opened, else ok is false
//@param infile
//@param outfile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputAndOutputFile(ofstream& outfile, ifstream& infile, bool& ok)
{
   infile.open("in8.dat");
   if (infile.fail())
   {
      ok = false;
      PrintLines(2, outfile);
      cout << "Error: in8.dat file does not exist, Please Check it's existance.";
      PrintLines(2, outfile);
   } else {
      ok = true;
		outfile.open("out8.dat");
   }
}

//@prints a testing message in the outfile
//@pre whatCase is a string and outfile is a file to be written to
//@post whatCase is written to the file
//@param outfile
//@param whatCase
//@usage PrintMessage(outfile, "Has No Pivot");
void PrintMessage (ofstream& outfile, const char* whatCase)
{
   PrintLines(2, outfile);
   outfile << "--------> Testing The *** " << whatCase << " *** case!!!! <---------" << endl;
}
				 
//@prints a message to the file
//@pre which is a string item is a Ckey object and outfile is a open output file to be written to
//@post which and item are written to outfile
//@param outfile
//@param item
//@which
//@usage PrintTreeMessage(outfile, item, "Pre");
void PrintTreeMessage (ofstream& outfile, Citem item, const char* which)
{
   
   outfile << endl << "::: 234 tree -- " << which << "*** " << item << " *** insert :::";
   PrintLines(2, outfile);
}
				 
//@prints a number of newlines in the file
//@pre num is nonnegative
//@post num newlines are wrote to the outfile
//@param num
//@param outfile
//@usage PrintLines(3, outfile);
void PrintLines(int num, ofstream& outfile)
{
   for (int k = 0; k < num; k++)
      outfile << endl;
}

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (ofstream& outfile, const char* which, const char* whatCase)
{
   outfile << endl << "Testing *** " << which << " *** in the " 
        << whatCase << " case";
}  


//@closes both the output and input file and shoots one output to the screen to show that the file ran through completely
//@pre both outfile and infile are open files for reading and writing
//@post both files are closed
//@param outfile
//@param infile
//@usage FileClose(outfile, infile);
void FileClose(ofstream& outfile, ifstream& infile)
{
	cout << endl << endl << "PROGRAM 8 EXECUTED :: Results in -> out8.dat" << endl << endl << endl;
	outfile.close();
   infile.close();
}







	
