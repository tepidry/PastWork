#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int val = 5;
int main()
{
	pid_t pid;
	/* fork another process*/
	pid = fork();
	if(pid < 0) { /*error occured*/
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0){/*child process*/
		printf("CHILD Pid: %d\n", getpid());
		printf("ParentPid : %d\n", getppid());
		val += 15;
	}
	else { /*parent process*/
		/*parent will wait for the child to complete */
		wait(NULL);
		printf("Child Complete %d\n", val);
	}
	return 0;
}
