//@author Ryan Draper(draper)
//@date February 7, 2011
//@file prog3.cpp
//@description: This program will build 3 binary trees from a file 

#include <iostream>
#include <fstream>
#include "cbintree.h"

using namespace std;



//@opens an external file for reading
//@post if the external file "in3.dat" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);
   
//@returns true if the dummy amount is the next item in the input file
//@pre node is the next item read from the tree File
//@post returns true unless the char read is '@' which is located at the end of each tree
//@param node
//@usage while(NotEndOfInputFile(node));
bool NotEndOfInputFile(Cnode node);

//@makes an Cnode that corresponds to the first info fromt the treeFile
//@pre infile is the treeFile with the binary tree items that are put into a Cnode and then returned
//@post returns a Cnode that is in the treeFile
//@param infile
//@usage node = GetFromTreeFile(treeFile);
Cnode GetFromTreeFile(ifstream& infile);            
     
//@this will output what this program does as it acts upon the que
//@post outputs words
//@usage Start();
void Start();  

//@ Uses infile to to create the binary tree
//@pre a existing tree and infile is a file to be read from
//@post Cbintree is filled with data from the infile
//@param tree
//@      infile
//@usage MakeTree(tree, treeFile);
void MakeTree(Cbintree tree, ifstream& infile);

//@prints out on a line the post, pre and in order from the tree
//@pre tree is a existing tree int is a reference to what tree is being called
//@post prints the three traversals on the tree
//@param tree
//@param diagram
//@usage PrintTree(tree);
void PrintTree(Cbintree tree);

//@prints the type of tree that is displayed in pre post and in order
//@pre diagram is the index to tell what tree is being used
//@post tells the tree that is being used
//@param diagram
//@usage TreeType(i);
void TreeType(int diagram);

int main()
{
   Cbintree tree;
   ifstream treeFile;
   bool ok;
    
   Start();
   OpenInputFile(treeFile, ok);
   
   for (int i = 1; i <= 3; i++)
   {
      TreeType(i);
      MakeTree(tree, treeFile);
      ToContinue();
   }
   

   return 0;   
}
 
//@this will output what this program does as it acts upon the que
//@post outputs words
//@usage Start();
void Start()
{    
	PrintLines(2);
	cout << "                 ++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "                    This program will read from a file to make 3" << endl;
	cout << "                                     Binary Trees" << endl;
	cout << "                 ++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	ToContinue();
}
 

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("in3.dat");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR: opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   PrintLines(2);
   cout << "                           Hit <Enter> to continue -> ";
   PrintLines(2);
   cin.get(ch);
}

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase)
{
   PrintLines(2);
   cout << "Testing *** " << which << " *** in the " 
        << whatCase << " case";
   PrintLines(2);
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

//@returns true if the dummy amount is the next item in the input file
//@pre node is the next item read from the tree File
//@post returns true unless the char read is '@' which is located at the end of each tree
//@param node
//@usage while(NotEndOfInputFile(node));
bool NotEndOfInputFile(Cnode node) 
{          
   return (node.GetItem() != '@');
}
    
//@makes an Cnode that corresponds to the first info fromt the treeFile
//@pre infile is the treeFile with the binary tree items that are put into a Cnode and then returned
//@post returns a Cnode that is in the treeFile
//@param infile
//@usage node = GetFromTreeFile(treeFile);
Cnode GetFromTreeFile(ifstream& infile) 
{    
   Cnode leaf;
   ItemType item;
   int index1, index2;
   
   infile >> item;
   leaf.SetItem(item);
   infile >> index1;
   leaf.SetLeft(index1);
   infile >> index2;
   leaf.SetRight(index2);

   return leaf;   
}

//@ Uses infile to to create the binary tree
//@pre a existing tree and infile is a file to be read from
//@post Cbintree is filled with data from the infile
//@param tree
//@      infile
//@usage MakeTree(tree, treeFile);
void MakeTree(Cbintree tree, ifstream& infile)
{
   Cnode node = GetFromTreeFile(infile);
   
   while(NotEndOfInputFile(node))
   {
      tree.addNode (node);
      node = GetFromTreeFile(infile);
   }
   PrintTree(tree);
}

//@prints out on a line the post, pre and in order from the tree
//@pre tree is a existing tree
//@post prints the three traversals on the tree
//@param tree
//@usage PrintTree(tree);
void PrintTree(Cbintree tree)
{
  	
   PrintLines(2);
   tree.postOrderPrint();
   PrintLines(2);
   tree.preOrderPrint();
   PrintLines(2);
   tree.inOrderPrint();
   PrintLines(2);
}

//@prints the type of tree that is displayed in pre post and in order
//@pre diagram is the index to tell what tree is being used
//@post tells the tree that is being used
//@param diagram
//@usage TreeType(i);
void TreeType(int diagram)
{
   if (diagram == 1) {
      cout << "Tree One: 10-6b pg. 504" << endl;
   } else if (diagram == 2) {
      cout << "Tree Two: 10-6c pg. 504" << endl;
   } else {
      cout << "Tree Three: (a + b) * (c / d + e)" << endl;
   }
	
}
