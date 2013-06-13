//@author Ryan Draper(draper)
//@date April 14, 2011
//@file prog8.cpp
//@description: This program will test many cases and subcases that occure with a 2-3-4 tree

#include <iostream>
#include <iomanip>
#include <fstream>
#include "c234node.h"

using namespace std;
/*
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
void InsertInTree(ifstream& infile, ofstream& outfile, C234tree temp);

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@      testItem
//@usage Insert(cbsTest, testItem)
void BuildTree(ifstream& infile, ofstream& outfile, c234Tree& tree);

//@Goes through a number of examples of the case Has No pivot of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage HasNoPivot(cavlFileItems, prog6File);
void HasNoPivot(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the case Added to Short Side case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage ShortSide(cavlFileItems, prog6File);
void ShortSide(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the case Single Rotate Right case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage RotateRight(cavlFileItems, prog6File);
void RotateRight(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the case Single Rotate Left case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage RotateLeft(cavlFileItems, prog6File);
void RotateLeft(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the Double Left Right case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage DoubleLeftRight(cavlFileItems, prog6File);
void DoubleLeftRight(ifstream& infile, ofstream& outfile);

//@Goes through a number of examples of the case Double Right Left of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage DoubleRightLeft(cavlFileItems, prog6File);
void DoubleRightLeft(ifstream& infile, ofstream& outfile);
/**/
int main()
{
   C234node node;
   Citem item;
   
   cin >> item;
   node.Insert(item);
   cout << node << " <- 1" << endl;
   
   
   cin >> item;
   node.Insert(item);
   cout << node << "2" << endl;
   
   
   cin >> item;
   node.Insert(item);
   cout << node << "3" << endl;
   sleep(2);
   
   
/*
	cavltree avlTree;
   ifstream cavlFileItems;
	ofstream prog6File;
   bool fileOk;
   

   OpenInputAndOutputFile(prog6File, cavlFileItems, fileOk);
	
	AttatchName(prog6File);
	
	HasNoPivot(cavlFileItems, prog6File);
	ShortSide(cavlFileItems, prog6File);
	RotateRight(cavlFileItems, prog6File);
	RotateLeft(cavlFileItems, prog6File);
	DoubleLeftRight(cavlFileItems, prog6File);
	DoubleRightLeft(cavlFileItems, prog6File);
	
	FileClose(prog6File, cavlFileItems);
   /**/
	
}
/*
//@Attatches a creators header
//@pre outfile is a opened outfile waiting to be written to
//@post outfile has the creators header
//@param outfile
//@usage AttatchName(prog6File);
void AttatchName(ofstream& outfile)
{
	outfile << "Ryan Draper (draper)" << endl;
	outfile << "March 28, 2011" << endl;
	outfile << "PROGRAM 6" << endl;
}

//@Goes through a number of examples of the case Has No pivot of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage HasNoPivot(cavlFileItems, prog6File);
void HasNoPivot(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree;
	int i;
	
	PrintMessage(outfile, "+Has Not Pivot+");
	
	BuildTree(infile, outfile, baseTree);
	for (i = 0; i < 2; i++)
	{
	   InsertInTree(infile, outfile, baseTree);
	}
	
	InvisibleBuildTree(infile, outfile, baseTree, 2);
	
	for (i = 0; i < 4; i++)
	{
		InsertInTree(infile, outfile, baseTree);
	}
	
}

//@Goes through a number of examples of the case Added to Short Side case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage ShortSide(cavlFileItems, prog6File);
void ShortSide(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree, secondTree, thirdTree, fourthTree;
	int i;
	
	PrintMessage(outfile, "+Is Added On Short Side+");
	
	InvisibleBuildTree(infile, outfile, baseTree, 2);
	BuildTree(infile, outfile, baseTree);
	
	InvisibleBuildTree(infile, outfile, secondTree, 2);
	BuildTree(infile, outfile, secondTree);
	
	InvisibleBuildTree(infile, outfile, thirdTree, 11);
	for (i = 0; i < 2; i++)
	{
	   InsertInTree(infile, outfile, thirdTree);
	}
	
	InvisibleBuildTree(infile, outfile, fourthTree, 11);
	
	for (i = 0; i < 2; i++)
	{
		InsertInTree(infile, outfile, fourthTree);
	}
	
}

//@Goes through a number of examples of the case Single Rotate Right case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage RotateRight(cavlFileItems, prog6File);
void RotateRight(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree, secondTree, thirdTree, lastTree;
	int i;
	
	PrintMessage(outfile, "+Single Rotate Right+");
	
	InvisibleBuildTree(infile, outfile, baseTree, 2);
	BuildTree(infile, outfile, baseTree);
	
	InvisibleBuildTree(infile, outfile, secondTree, 4);
	BuildTree(infile, outfile, secondTree);
	
	InvisibleBuildTree(infile, outfile, thirdTree, 4);
	BuildTree(infile, outfile, thirdTree);

	InvisibleBuildTree(infile, outfile, lastTree, 6);
	for (i = 0; i < 2; i++)
	{
		InvisibleTempBuildTree(infile, outfile, lastTree, 2);
	}
	BuildTree(infile, outfile, lastTree);
	
}

//@Goes through a number of examples of the case Single Rotate Left case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage RotateLeft(cavlFileItems, prog6File);
void RotateLeft(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree, secondTree, thirdTree, lastTree;
	int i;
	
	PrintMessage(outfile, "+Single Rotate Left+");
	
	InvisibleBuildTree(infile, outfile, baseTree, 2);
	BuildTree(infile, outfile, baseTree);
	
	InvisibleBuildTree(infile, outfile, secondTree, 4);
	BuildTree(infile, outfile, secondTree);
	
	InvisibleBuildTree(infile, outfile, thirdTree, 4);
	BuildTree(infile, outfile, thirdTree);
	
	InvisibleBuildTree(infile, outfile, lastTree, 6);
	for (i = 0; i < 3; i++)
	{
		InvisibleTempBuildTree(infile, outfile, lastTree, 2);
	}
}

//@Goes through a number of examples of the Double Left Right case of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage DoubleLeftRight(cavlFileItems, prog6File);
void DoubleLeftRight(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree, secondTree, lastTree;
	int i;
	PrintMessage(outfile, "+Double Left Right Rotate+");
	
	InvisibleBuildTree(infile, outfile, baseTree, 5);
	BuildTree(infile, outfile, baseTree);

	InvisibleBuildTree(infile, outfile, secondTree, 10);
	BuildTree(infile, outfile,secondTree);
	
	InvisibleBuildTree(infile, outfile, secondTree, 5);
	BuildTree(infile, outfile,secondTree);
	
	InvisibleBuildTree(infile, outfile, lastTree, 9);
	BuildTree(infile, outfile, lastTree);
	
	InvisibleBuildTree(infile, outfile, lastTree, 8);
	BuildTree(infile, outfile, lastTree);
	
}

//@Goes through a number of examples of the case Double Right Left of a AVL tree
//@pre infile is a read file outfile is written to
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@usage DoubleRightLeft(cavlFileItems, prog6File);
void DoubleRightLeft(ifstream& infile, ofstream& outfile)
{
	C234tree baseTree, secondTree, thirdTree, lastTree;
	
	PrintMessage(outfile, "+Double Right Left Rotate+");
	
	InvisibleBuildTree(infile, outfile, baseTree, 5);
	BuildTree(infile, outfile, baseTree);
	
	InvisibleBuildTree(infile, outfile, secondTree, 4);
	BuildTree(infile, outfile, secondTree);
	
	InvisibleBuildTree(infile, outfile, thirdTree, 9);
	BuildTree(infile, outfile, thirdTree);
	BuildTree(infile, outfile, thirdTree);
	
	InvisibleBuildTree(infile, outfile, lastTree, 9);
	BuildTree(infile, outfile, lastTree);
	
	InvisibleBuildTree(infile, outfile, lastTree, 5);
   BuildTree(infile, outfile, lastTree);
	
	InvisibleBuildTree(infile, outfile, lastTree, 6);
	BuildTree(infile, outfile, lastTree);

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
			//avlTree.Insert(item);
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
			//avlTree.Insert(item);
		}
		catch (cexception ex)
		{
			outfile << ex.what() << endl;  
		}
	}
	BuildTree(infile, outfile, avlTree);
	
}



//@inserts items into a tree temperarily to show the effect different items have on a avl tree without effecting the tree's base
//@pre infile is a file to be read from outfile is to be written to and cavltree is a existing cavltree
//@post infile has been read from outfile has been written too
//@param infile
//@param outfile
//@param temp
//@usage InsertInTree(infile, outfile, avlTree);
void InsertInTree(ifstream& infile, ofstream& outfile, C234tree tree)
{
	Citem item;
	
	infile >> item;
	PrintLines(2, outfile);
	PrintTreeMessage(outfile, item, "Pre-Case");
	temp.prettyDisplay(outfile);
		
	try
	{
		temp.Insert(item);
		PrintTreeMessage(outfile, item, "Post-Case");
		//temp.prettyDisplay(outfile);
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
void BuildTree(ifstream& infile, ofstream& outfile, C234tree& tree)
{
	Citem item;
	
	PrintLines(2, outfile);
	infile >> item;
	PrintTreeMessage(outfile, item, "Pre-Case");
	avlTree.prettyDisplay(outfile);
				 
	try
	{
		//avlTree.Insert(item);
		PrintTreeMessage(outfile, item, "Post-Case");
		//avlTree.prettyDisplay(outfile);
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
   infile.open("in6.dat");
   if (infile.fail())
   {
      ok = false;
      PrintLines(2, outfile);
      cout << "Error: in6.dat file does not exist, Please Check it's existance.";
      PrintLines(2, outfile);
   } else {
      ok = true;
		outfile.open("avl.dat");
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
   outfile << "--------> Testing The *** " << whatCase << " *** case!!!! <---------";
}
				 
//@prints a message to the file
//@pre which is a string item is a Ckey object and outfile is a open output file to be written to
//@post which and item are written to outfile
//@param outfile
//@param item
//@which
//@usage PrintTreeMessage(outfile, item, "Pre");
void PrintTreeMessage (ofstream& outfile, Ckey item, const char* which)
{
   PrintLines(2, outfile);
   outfile << "::: AVL tree -- " << which << "*** " << item << " *** insert :::";
	PrintLines(2, outfile);
}
				 
//@prints a number of newlines in the file
//@pre num is nonnegative
//@post num newlines are wrote to the outfile
//@param num
//@param outfile
//@usage PrintLines(3, outfile);
void PrintLines (int num, ofstream& outfile)
{
   for (int k = 0; k < num; k++)
      outfile << endl;
}

//@closes both the output and input file and shoots one output to the screen to show that the file ran through completely
//@pre both outfile and infile are open files for reading and writing
//@post both files are closed
//@param outfile
//@param infile
//@usage FileClose(outfile, infile);
void FileClose(ofstream& outfile, ifstream& infile)
{
	cout << endl << endl << "PROGRAM 6 DID IT'S THING IN :: avl.dat" << endl << endl;
	outfile.close();
   infile.close();
}
/**/







	
