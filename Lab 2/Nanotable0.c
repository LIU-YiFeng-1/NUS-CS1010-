/**
 *CS1010 AY2019/20 Semester 1 Lab2
 *Nanotable0.c
 *This program is a mini data storage system which
 *parse commands and take actions accordingly.
 *It follows REPL style.
 *Available commands are: help, exit, sum and ave,
 *where sum calculates the sum of N integers entered by user
 *and ave calculates the average of N integers entered by user
 *Name: LIU YIFENG
 *Group: C06
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

//Function prototypes 
int parse_command();
int check_command(char* input);
void print_help();
int simple_sum();
int simple_average();


int main() {
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	parse_command();

	return 0;
}

/*This function prase the command entered by the user and
carry out actions accordingly*/
int parse_command() {
	char tmp_command[100] = "";
	int command_code;
	
	/*When the command enter by user is not EXIT, the loop will run
	When the command enter by user is EXIT, the loop will break*/
	while (command_code != COMMAND_EXIT){
	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	}
	else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
	}
	else if (command_code == COMMAND_SUM) {
		simple_sum();
	}
	else if (command_code == COMMAND_AVE) {
		simple_average();
	}
	else {
		//when user enters invaild command 
		printf("No such command: %s, please input command again!\n", tmp_command);
	}
	}
	return 0;
}

/*This function calculates the sum of integers. The number of integers, N, is 
determined by the user and the user has to input N integers*/
int simple_sum() {
	//declaring of variables
	int numInt, count, value,  sum=0;

	printf("Please indicate the number of integers:\n");
	scanf("%d", &numInt);

	/*initialising count to 1 and when the count is larger than the numInt,
	the loop will break.*/
	for (count=1; count <= numInt; count++){
		//choosing the corrct ordinal form
		if(count%100==11 || count%100==12 || count%100==13){
			printf("Please input the %dth number:\n", count);
		}
		else if(count%10==1){
			printf("Please input the %dst number:\n", count);
		}
		else if(count%10==2){
			printf("Please input the %dnd number:\n", count);
		}
		else if(count%10==3){
			printf("Please input the %drd number:\n", count);
		}
		else{
			printf("Please input the %dth number:\n", count);
		}

	scanf("%d", &value);
	sum = sum + value;
	}

	printf("sum is %d\n", sum);
	return 0;
}

/*This function calculates the average of integers. The number of integers, N, 
is determined by the user and the user had to enter N integers*/
int simple_average() {
	//declaring variables
	int numInt, count, value, sum=0;
	float average;
	
	printf("Please indicate the number of integers:\n");
	scanf("%d", &numInt);

	/*initialising count to 1 and when the count is larger than the numInt,
	the loop will break.*/
	for (count=1; count <= numInt; count++){
		//choosing correct ordinal form
		if(count%100==11 || count%100==12 || count%100==13){
			printf("Please input the %dth number:\n", count);
		}
		else if(count%10==1){
			printf("Please input the %dst number:\n", count);
		}
		else if(count%10==2){
			printf("Please input the %dnd number:\n", count);
		}
		else if(count%10==3){
			printf("Please input the %drd number:\n", count);
		}
		else{
			printf("Please input the %dth number:\n", count);
		}

	scanf("%d", &value);
	sum = sum + value;
	}
	//cast typing of sum, so that the data type for average is float
	average = (float)sum / numInt;

	printf("average is %.0f\n", round(average));
	return 0;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

