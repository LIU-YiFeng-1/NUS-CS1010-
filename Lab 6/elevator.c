/*CS1010 AY2019/20 Semester 1 Lab6 Ex3
* elevator.c
* <This program simulates an elevator's movement and return the end result>
* <LIU YIFENG>
* <C06>
*/

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

//define structures
typedef struct { 
	int floor;
	int passenger;
	int usage;
} elevator_t;

//function prototype
void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	//declare variables
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];

	printf("Enter number of elevators: ");
	scanf("%d", &size);
	//calling functions
	setupElevators(elevators, size);
	readSequences(sequences, size);

	runElevators(elevators, sequences, size);

	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));

	return 0;
}

//this function setup elevator at initial stage
void setupElevators(elevator_t elevators[], int size){
	int i;
	for(i=0 ; i<size; i++){
		elevators[i].floor=1;
		elevators[i].passenger=0;
		elevators[i].usage=0;
	}
}	

// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;

	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

//this function runs the elevators to the given floor seqence
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int i, j, len;
	for(i=0; i<size; i++){
		len=strlen(sequences[i]);
		for(j=0; j<len; j++){
			goToFloor(&elevators[i], sequences[i][j]-48);//minus 48 because the sequence is Char, taking into account of ACSII value
		}
	}
}
//this function helps to determine the sub-data in the structure, based on the giving floor sequence
void goToFloor(elevator_t *elevator, int floor){
	if(elevator->floor < floor){//when current floor is lower than the new floor, it will go up and passenger will board only
		elevator->passenger += floor;
		if(elevator->passenger > 15){
			elevator->passenger = 15;
		}
		elevator->floor = floor; //update floor number, no need update usage as no one is leaving the elevator
	}
	if(elevator->floor > floor){//when the current floor is higher than the new floor, it will go down and passenger will leave only
		if(elevator->passenger >0){//checks whether the elevator is empty, if yes, update the floor number immediately
			if(elevator->passenger > floor){
				elevator->passenger -= floor;
				elevator->usage += floor;
			}
			else{
				elevator->usage += elevator->passenger;
				elevator->passenger =0; //empty the elevator when the number of passenger is smaller than the floor number
			}
		}
		elevator->floor = floor; //update the floor number
	}
}

void printElevators(elevator_t elevators[], int size){
	int i;
	for (i=0; i<size; i++){
		printf("Elevator %d:\n", i+1); 
		printf("Floor: %d\n", elevators[i].floor);
		printf("Number of passengers: %d\n", elevators[i].passenger);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

int mostUsedElevator(elevator_t elevators[], int size){
	int i, max=0, mostUsed;
	for(i=0; i<size; i++){
		if(elevators[i].usage >=max){
			max = elevators[i].usage;
			mostUsed =i+1;
		}
	}	
	return mostUsed;
}

