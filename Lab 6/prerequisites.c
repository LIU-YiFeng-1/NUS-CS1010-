/*CS1010 AY2019/20 Semester 1 Lab6 Ex1
* prerequisites.c
* <This program checks if the module has prerequisite in the list>
* <LIU YIFENG>
* <C06>
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_MOD 10
#define MAX_LEN 7

//Function prototype
int firstdigit(char [], char []);
int sameChars(char [], char []);
int otherDigits(char [], char []);
int scanModules(char[][MAX_LEN]);
int computePrereq(char[][MAX_LEN], int, char[], char[][MAX_LEN]);
void printPrereq(char[][MAX_LEN], int, char[]);

int main(void)
{
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],        // the list of modules
		 target[MAX_LEN],                 // target module
		 prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target 

	numModules = scanModules(codes);
	printf("Choose a module: ");
	scanf("%s", target);
	numPrereq = computePrereq(codes, numModules, target, prerequisites);
	printPrereq(prerequisites, numPrereq, target);
	return 0;
}
//This function determines if the target module has a prerequisite.
int computePrereq(char codes[][MAX_LEN], int numModules, char target[], char prerequisites[][MAX_LEN]){
	int i, check ,j = 0, validMod = 0;

	for(i = 0; i < numModules; i++) { //Checks if the target module exists in the input list 
		if(!strcmp(codes[i],target))
			validMod = 1;
	}
	if(validMod != 1)
		return -1; 

	for(i = 0; i < numModules; i++) {

		check = (sameChars(codes[i], target)); //Check if the first 2 characters are the same.
		if(check == 0){
			continue;
		}        
		check = (firstdigit(codes[i], target)); //Check if the first digit is less than the target module. 
		if(check == 0){
			continue;
		}
		check = (otherDigits(codes[i], target)); //Check if the last four digits are less or equal than target module's.
		if(check == 0){
			continue;
		}
		strcpy(prerequisites[j],codes[i]); //Copy module into prerequisites list when criteria are met.
		j++;
	}
	if(j == 0) //condition for zero prequisite is met.
		return 0;
	else
		return j;
}

//This function checks if the first 2 characters are the same.
int sameChars(char codes[], char target[])
{
	if(codes[0] == target[0] && codes[1] == target[1])
		return 1;
	return 0;
}

//This function checks if the module's first digit is less than target module's first digit.
int firstdigit(char codes[], char target[]){
		if(codes[2] < target[2])
			return 1;
		return 0;
	}

//This function checks the module's last four digit and check if it is equal or less than target module's digits.
int otherDigits(char codes[], char target[]){
	int i;
	for(i = 3; i <MAX_LEN - 1; i ++){
		if(!(codes[i] <= target[i]))
			return 0;
	}
	return 1;
}

// This function prints the prerequisites
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[])
{
	int i;

	if(numPrereq == -1) {
		printf("No such module %s\n", target);
	} else if(numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	} else {
		printf("Prerequisites for %s:", target);
		for(i = 0; i < numPrereq; i++) {
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}
//This function scans in the number of modules & module codes
int scanModules(char codes[][MAX_LEN])
{
	int size, i;
	printf("Enter number of modules: ");
	scanf("%d", &size);
	printf("Enter %d modules:\n", size);
	for(i = 0; i < size; i++) {
		scanf("%s", codes[i]);
	}

	return size;
}
