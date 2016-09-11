/**
	@file fork_pipe.c
	@desc Program to send message through pipe to child process-
			created using fork
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include "fork_pipe.h"

int main() {
	int pid;
	int pipeFD[2];
	pipe(pipeFD);
	char readBytes[64];
	
	pid = fork();
	
	if(pid == 0) {
		write(pipeFD[1], "TEST", (strlen("TEXT") + 1));
		fprintf(stdout, "In child process \n");
	} else {
		read(pipeFD[0], readBytes, sizeof(readBytes));
		fprintf(stdout, "In parent process received %s", readBytes);
	}
	return 0;
}
