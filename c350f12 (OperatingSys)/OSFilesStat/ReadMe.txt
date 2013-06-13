author: Ryan Draper
date: December 7, 2012
file: osFileStat.cpp  

A program using iNode integer identifier to work the same as a pwd command line for linux
First I assign the parent NodeDirectory the current '.' and use that pointer to move to that parents directory from the one that I 
currently am in. Then I check the inode number to find the directory I was just in.  I continue to do this to check each node
until I "." == ".." once this is true I know that I am in the root and I have the string that is the list on my current working directory.  
I could not work out how to get rid of the double slash on my directory string though when I'm in the root.  

In order to compile and run: 

$g++ osFileStat.cpp
$./a.out             




