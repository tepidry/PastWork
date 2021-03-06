

// Required by for routine
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 64
#define READ_END 0;
#define WRITE_END 1;


void writer(int inpipe)
{
    char read_msg [BUFFER_SIZE];
    FILE *fw;
    pid_t pid;
    int i;
    int fd[2];
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
        read(fd[0], read_msg, BUFFER_SIZE);
        close(fd[0]);
        return;
    }
    else {  //parent, p2()
	
        read(inpipe, read_msg, BUFFER_SIZE);
        fw = fopen ("WriteOut.txt", "wt");
        close(fd[0]);
        fprintf(fw,"%s",read_msg); 
        close(fd[1]);
    }
    return;
}

void munch2(int inpipe)
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
	writer(fd[0]);
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
        write(fd[1],read_msg,(unsigned long)(strlen(read_msg)+1));
        close(fd[1]);
    }
    return;
}

void munch1(int inpipe)
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
	printf("herem2 \n");
        munch2(fd[0]);
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
        close(fd[0]);
        write(fd[1],read_msg,(unsigned long)(strlen(read_msg)+1));
        close(fd[1]);
    }
    return;
}

int main(int argc, char **argv) {
    char line[BUFFER_SIZE];
    FILE *fr;
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
    while (fgets(line, 64, fr) != NULL)
    {
    if(pid==0) { //child
        close(fd[1]);
	write(fd[1],line,strlen(line)+1);
	printf("herem1 \n");
        munch1(fd[0]);
        close(fd[0]);
    }
    }
    if(pid > 0) {  //parent, main(), reader
        //reading from the file and put it into the pipe[1]
        close(fd[0]);
	write(fd[1],line,strlen(line)+1);
        close(fd[1]);
    }
    
    //printf("waiting for all childred...\n");
    wait(NULL);
    printf("finishing the main()\n");
    
    return EXIT_SUCCESS;
}


