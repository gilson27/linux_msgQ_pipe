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
	
	pid = fork();
	
	if(pid == 0) {
		fprintf(stdout, "In child process \n");
	} else {
		fprintf(stdout, "In parent process");
	}
}
