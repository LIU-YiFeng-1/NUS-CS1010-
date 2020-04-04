/*CS1010 AY2019/20 Semester 1 Lab3 Ex2
 * square_free.c
 * This program reads 4 integers in the following sequence:
 * lower1, upper1, lower2, upper2, compute the number of square-free
 * integers in two ranges [lower1, upper1] (both inclusive) and
 * [lower2, upper2] (both inclusive), compare and report which
 * range has more square-free integers.
 * LIU YIFENG
 * Group C06
 */

#include <stdio.h>
#include <math.h>


//function prototyping
int compute_squareFreeNum(int, int);

int main(void) {
	//declear variables
	int lower1, upper1, lower2, upper2, range1, range2;

	printf("Enter four positive integers: ");
	scanf("%d%d%d%d", &lower1, &upper1, &lower2, &upper2);
	//calling function twice
	range1 = compute_squareFreeNum(lower1, upper1);
	range2 = compute_squareFreeNum(lower2, upper2);
	//if condition statements to compare the number of square number for 2 sets of numbers
	if(range1==range2){
		printf("Both ranges have the same number of square-free numbers: %d\n", range1);
	}
	else if(range1<range2){
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, range2);
	}
	else if(range1>range2){
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, range1);
	}

	return 0;
}

// this function takes 2 integers and cumpute the number of square-free integers
int compute_squareFreeNum(int a, int b){
	//declear variables
	int squareNum=0, squareFreeNum, num, i, n;
	//condition for 'for loop' and initialising n = a
	for(n=a; n<=b; n++){
		//condition for 'for loop' and initialising i = 2
		for(i=2; n/(pow(i,2))>=1; i++){
			//condition for if statement and cast typing the pow to int type
			if(n % ((int)(pow(i,2))) == 0){
				squareNum ++;
				break;
			}	
		} 	
	}
	num = b - a + 1;
	squareFreeNum = num - squareNum;
	return squareFreeNum; 
}
