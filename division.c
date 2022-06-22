////////////////////////////////////////////////////////////////////////////////
// This File:		division.c
// Other Files:		intdate.c, sendsig.c
// Semester:		CS 354 Fall 2018
// Lecture:		001
//
// Author:		Jaclyn Windorff
// Email:		jwindorff@wisc.edu
// CS Login:		jaclyn
//
///////////////////////////////////////////////////////////////////////////////
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sigaction divz;
struct sigaction ctrlc;
int count = 0;

/* This function prints out a statement and the number of operations completed
 * when the SIGFPE is recieved, and then exits
 */
int a() {
	printf("Error: a division by 0 operation was attempted.\nTotal number of operations completed successfully: %d\nThe program will be terminated.\n", count);
	exit(0);
}

/* This function prints out the number of operations completed
 * and then exits when the SIGINT signal is recieved
 */
int b() {
	printf("\nTotal number of operations successfully completed: %d\nThe program will be terminated.\n", count);
	exit(0);
}

/* This function houses the main functionallity of the program
 * It sets up the two funtions that will be called when different 
 * signals are recieved and then goes into an infinate loop
 * where it asks the user for two numbers and then prints the quotient
 * and the remainder that restults from deviding the given numbers
 */
int main() {
	memset (&divz, 0, sizeof(divz));
	memset (&ctrlc, 0, sizeof(ctrlc));
	divz.sa_handler = (void(*)(int))a;
	ctrlc.sa_handler = (void(*)(int))b;
	struct sigaction *d = &divz;
	struct sigaction *c = &ctrlc;
	sigaction(SIGFPE, d, NULL);
	sigaction(SIGINT, c, NULL);
	char *num1 = malloc(10);
	char *num2 = malloc(10);
	if (num1 == NULL || num2 == NULL) {
		printf("Error allocating memory\n");
		exit(0);
	}
	int n1;
	int n2;
	int div;
	int rem;
	while (1) {
		printf("Enter first integer: ");
		fgets(num1, 100, stdin);
		printf("Enter second integer: ");
		fgets(num2, 100, stdin);
		n1 = atoi(num1);
		n2 = atoi(num2);
		div = n1 / n2;
		count++;
		rem = n1 % n2;
		printf("%d / %d is %d with a remainder of %d\n", n1, n2, div, rem);
	}
}
