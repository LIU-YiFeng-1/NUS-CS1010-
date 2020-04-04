/*
* CS1010 AY2019/20 Semester 1 Lab4 Ex1
* nanotable1.c
* This program takes in student ID and score to store as a table
* LIU YIFENG
* C06
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100

/* Function prototypes */
void print_help();
void insert_table(int[][100], int);
int sum(int[][100]);
int ave(int[][100], int);
void rank(int[][100], int);

int main(void) {
	char input[MAX_COMMAND_LENGTH];
	int table[2][100]={}; //initialising 2D array
	int i, j, average, total=0, count=0; //declaring variables

	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	while (TRUE) {
		printf("Waiting for command...\n");
		scanf("%s", input);
		total = sum(table); //calling function 'sum'

		if (strcmp(input,"help") == 0) {
			print_help();
		} else if (strcmp(input,"exit") == 0){
			printf("See you!\n");
			break;
		} else if (strcmp(input,"sum") == 0) {
			
			if (total==0){  //determine whether the table is empty
				printf("The table is empty\n");
			} else {
				printf("The sum of score is %d\n", total);
			}
		} else if (strcmp(input,"ave") == 0) {
			if (total==0){ //determine whether the table is empty
				printf("The table is empty\n");
			} else {
				average = ave(table, count); //calling function 'ave'
				printf("The average of score is %d\n", average);
			}
		}
		else if (strcmp(input,"insert") == 0) {
			insert_table(table, count); //calling function 'insert_table'
			count++;

		} else if (strcmp(input,"init") == 0) { //to initialise the table
			for(i=0; i<2; i++){
				for(j=0; j<100; j++){
					table[i][j]=0;
				}
			}
			count=0;
			printf("Initializing table...\n");

		} else if (strcmp(input,"rank") == 0) {
			if (total==0) {
				printf("The table is empty\n");
			} else {
				rank(table,count); //calling funtion 'rank'
			}
		} else {
			printf("No such command: %s, please input command again!\n", input);
		}
	}
	return 0;
}

// This function prints the help information
void print_help() {
	printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}
//This function scans for student ID and Score to store in a 2D array
void insert_table(int arr[][100], int i){

	printf("Please input the student's ID...\n");
	scanf("%d", &arr[0][i]);
	printf("Please input the student's score...\n");
	scanf("%d", &arr[1][i]);
}
//This function calculates the sum of all scores in the 2D array
int sum(int arr[][100]){
	int sum=0;
	int i;
	for(i=0; i<100; i++){
		sum += arr[1][i];
	}
	return sum;
}
//This funcion calculates the average of all scores in the 2D array
int ave(int arr[][100], int count){
	int sum=0;
	int i;
	double average=0;
	for(i=0; i<count; i++){
		sum += arr[1][i];
	}
	average = (double)sum / count;
	return round(average);
}
//This function ranks the ID and Scores accoringly
void rank(int arr[][100], int count){
	int num, i, j, temp1, temp2, temp3;
	printf("Please input the rank (1 - %d)...\n", count);
	scanf("%d", &num);
	while(num>count){
		printf("Invalid rank: %d\n", num);
		printf("Please input the rank (1 - %d)...\n", count);
		scanf("%d", &num);
	}
	//to sort all data in ascending order and make sure ID and Score are paired
	for(i=0; i<count; i++){
		for(j=i+1; j<count; j++){
			if(arr[1][i]>arr[1][j]){
				temp1=arr[0][i];
				temp2=arr[1][i];
				arr[0][i]=arr[0][j];
				arr[1][i]=arr[1][j];
				arr[0][j]=temp1;
				arr[1][j]=temp2;

			}
			//sort by ID if the scores are found to be the same
			if(arr[1][i]==arr[1][j]){
				if(arr[0][i]>arr[0][j]){
					temp3=arr[0][i];
					arr[0][i]=arr[0][j];
					arr[0][j]=temp3;
				}
			}
		}
	}
	printf("ID: %d, Score: %d\n", arr[0][num-1], arr[1][num-1]);
}

