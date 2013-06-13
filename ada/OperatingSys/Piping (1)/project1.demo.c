//
//  main.c
//  PipeTest
//
//  Created by Kefei Wang on 9/27/12.
//  Copyright (c) 2012 Kefei Wang. All rights reserved.
//
// main()->p1()->p2()->writer()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 64

void p2(int inpipe)
{
    char read_msg[BUFFER_SIZE];
    
    pid_t pid;
    int fd[2], i;
    if(pipe(fd) == -1) {
		perror("Pipe error");
		return;
	}
    
    pid = fork();
    if(pid<0) {  //error
        perror("Fork Failed");
        return;
    }
    else if(pid==0) { //child
        close(fd[1]);
	printf("here \n");
        read(fd[0], read_msg, BUFFER_SIZE);
        printf("In P2, the msg is: %s\n",read_msg);
        close(fd[0]);
        return;
    }
    else {  //parent, p2()
        read(inpipe, read_msg, BUFFER_SIZE);
        for ( i = 0; i < 64 && read_msg[i] != '\n'; i++)
	{
        	if (isspace(read_msg[i]))
		{
			read_msg[i] = '*';
		}
	}
        close(fd[0]);
	printf("here2b \n");
        write(fd[1],read_msg,(unsigned long)(strlen(read_msg)+1));
        close(fd[1]);
    }
    return;
}

void p1(int inpipe)
{

	printf("in p1, the pipe port: %d\n",inpipe);
    char read_msg[BUFFER_SIZE];

    pid_t pid;
    int fd[2], i;
    if(pipe(fd) == -1) {
		perror("Pipe error");
		return;
	}
    
    pid = fork();
    if(pid<0) {  //error
        perror("Fork Failed");
        return;
    }
    else if(pid==0) { //child
        close(fd[1]);
	printf("here1a \n");
        p2(fd[0]);
        close(fd[0]);
        return;
    }
    else {  //parent, p1()
        read(inpipe, read_msg, BUFFER_SIZE);
        for (i = 0; i < 64 && read_msg[i] != '\n'; i++)
	{
		if (islower(read_msg[i]))
		{
			read_msg[i] = toupper(read_msg[i]);	
		}
	}
        printf("In P1, the msg is: %s\n",read_msg);
        close(fd[0]);
	printf("here1b \n");
        write(fd[1],read_msg,(unsigned long)(strlen(read_msg)+1));
        close(fd[1]);
    }
    return;
}

int main(int argc, char **argv) {
    char write_msg[BUFFER_SIZE] = "Greetings You";
    char line[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    FILE *fr;
    printf("Starting the main().\n");
    printf("in Reader, the msg is: %s\n",write_msg);
    pid_t pid;
    int fd[2];
    fr = fopen ("ReadIn.txt", "rt"); 
    if(pipe(fd) == -1) {
		perror("Pipe error");
		return 1;
	}
    
    pid = fork();
    if(pid<0) {  //error
        perror("Fork Failed");
        return 1;
    }
    else if(pid==0) { //child
        close(fd[1]);
	printf("herea \n");
        p1(fd[0]);
        close(fd[0]);
    }
    else {  //parent, main(), reader
        //reading from the file and put it into the pipe[1]
        close(fd[0]);
	fgets(line, 64, fr);
        write(fd[1],line,strlen(line)+1);
	printf("hereb \n");
        close(fd[1]);
    }
    
    //printf("waiting for all childred...\n");
    wait(NULL);
    printf("finishing the main()\n");
    
    return EXIT_SUCCESS;
}
