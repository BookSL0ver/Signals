////////////////////////////////////////////////////////////////////////////////
// This File: 		sendsig.c
// Other Files:		division.c, intdate.c
// Semester:		CS 354 Fall 2018
// Lecture:		001
//
// Author:		Jaclyn Windorff
// Email:		jwindorff@wisc.edu
// CS Login: 		jaclyn
//
///////////////////////////////////////////////////////////////////////////////


#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/* This function holds all of the functionality of this program
 * It takes the arguments given and either sends a SIGUSR1 or a
 * SIGINT signal to another process, which is indicated by the pid
 * 
 * argc: number of arguments given
 * argv: a list of the arguments given
 */
int main(int argc, char *argv[]) {
	//check number of arguments
	if (argc != 3) {
		printf("Usage: <signal type> <pid>\n");
		exit(0);
	}
	char *type = argv[1];
	int pid = atoi(argv[2]);
	char *u = "u";
	char *i = "i";
	if ( ( *(type + 1) ) == *u) {
		kill(pid, SIGUSR1);
	}
	else if (type[1] == *i) {
		kill(pid, SIGINT);
	}
}
