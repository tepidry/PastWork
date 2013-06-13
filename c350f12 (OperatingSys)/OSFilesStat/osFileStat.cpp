//
//  osFileStat.cpp
//  
//
//  Created by Ryan Draper on 12/7/12.
//  This is a c++ program that will use the iNode to act as the pwd in a Linux command line.

#include <iostream>
#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char *argv[]) 
{
    //Here we set up basic strings and the stat filestat to read in the directories that I will search
    bool stayInLoop = true;
    string *currentWorkingDirectory = new string;
    int iNode;
    struct stat filestat;
    struct dirent *upperDirent;
    DIR *parentDir;

    //this makes the current directory you are running the program in as the argument that 
    argv[1] = ".";
    //This reads the first directory by location of address
    string *parentNodeDirectory = new string(argv[1]);
    
    do {

        if((stat(parentNodeDirectory->c_str(), &filestat)) == -1)
        {
            perror("fstat");
            return 1;
        }
        
        if(iNode == filestat.st_ino)
        {
            cout << *currentWorkingDirectory << '\n';
            free(parentNodeDirectory);
            return 1;
        }

        iNode = filestat.st_ino;
        parentNodeDirectory->append("/..");
        parentDir = opendir(parentNodeDirectory->c_str());
        //cout << parentDir << "/" << endl;
        
        
        while(upperDirent = readdir(parentDir))
        {
            if(upperDirent->d_ino == iNode)
            {
                iNode = upperDirent->d_ino;
                currentWorkingDirectory-> insert(0, 1, '/');
                if(strlen(upperDirent->d_name) != 1 && upperDirent->d_name[0] != '.')
                {
                    currentWorkingDirectory->insert(0, upperDirent->d_name);
                }
            }
        }
        
    } while(stayInLoop);
    
    cout << *currentWorkingDirectory << '\n';
    free(parentNodeDirectory);
    return 0;
    
    
        
    
}

