////////////////////////////////////////////////////////////////////////////////
// This File:		intdate.c
// Other Files:		division.c, sendsig.c
// Semester:		CS 354 Fall 2018
// Lecture:		001
//
// Author:		Jaclyn Windorff
// Email:		jwindorff@wisc.edu
// CS Login:		jaclyn
//
////////////////////////////////////////////////////////////////////////////////


#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct sigaction act;
struct sigaction usr;
struct sigaction end;
time_t t;
int count = 0;


/* This function prints the pid and current time when ever the SIGALRM is recieved 
 */
int a() {
	t = time(NULL);
	time_t *r = &t;
	printf("PID: %d | Current Time: %s", getpid(), ctime(r));
	alarm(3);
	return 1;
}

/* This function increments count and prints a statment when the SIGUSR1 is recieved
 */
int b() {
	count++;
	printf("SIGUSR1 caught!\n");
	return 1;
}

/* This function tells the user the amount of times SIGUSR1 was recieved and exits when SIGINT is recieved
 */
int c() {
	printf("SIGINT recieved.\n");
	printf("SIGUSR1 was recieved %d times. Exiting now.\n", count);
	exit(0);
}

/* This function holds the main usage of the program
 * It sets up an alarm to go off every three seconds and 
 * sets up the three functions to catch three different signals.
 * It also has an empty while loop so the program will run until outside action is taken.
 */
int main() {
	printf("Pid and time will be printed every 3 seconds.\nEnter ^C to end program.\n");
	memset (&act, 0, sizeof(act));	
	memset (&usr, 0, sizeof(usr));
	memset (&end, 0, sizeof(end));
	act.sa_handler = ( void (*) (int) )a;
	usr.sa_handler = ( void (*) (int) )b;
	end.sa_handler = ( void (*) (int) )c;
	struct sigaction *s = &act;
	struct sigaction *z = &usr;
	struct sigaction *v = &end;
	sigaction(SIGALRM, s, NULL);
	sigaction(SIGUSR1, z, NULL);
	sigaction(SIGINT, v, NULL);
	alarm(3);
	while (1) {
	}
	return 1;
}


