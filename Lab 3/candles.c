/*CS1010 AY2019/20 Semester 1 Lab3 Ex1
* candles.c
* This program calculates the total number of candles burnt
* by asking user to enter the initial number of candles and
* number of residual wax needed to form a new candle.
* Name: LIU YIFENG
* Group: C06
*/

#include <stdio.h>

//function prototype
int count_candles(int, int);

int main(){
	//declaring variables
	int candleNum, residualNum, candlesBurn;
	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	
	scanf("%d%d", &candleNum, &residualNum);
	//calling function "count_candles"
	candlesBurn = count_candles(candleNum, residualNum);
	
	printf("Total candles burnt = %d\n", candlesBurn);

	return 0;
}

/*
*This function computes the number of candles burnt 
*from a given number of total candles and the number of
*residual candles need to form a new candle
*pre-condition for function, b>1
*/
int count_candles(int a, int b){
	
	int reminder, set, sum; //declear variable
	sum = a;
	//conditions for 'for loop'
	for(a=a; a/b != 0; a = set+reminder){
		set = a/b;
		reminder = a%b;
		sum += set;
	}
	return sum;
}

