#include <stdio.h>
#include <math.h>

/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * Name: LIU YIFENG
 * Group Number: C06
 */

 int main(void)
 {
	//declare int variables (principal amount, interest rate and number of years)
	int principal, rate, numYears;
	//declare float variable (final calculated amount)
	float Amount;

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);

	//cast typing for int variable to float, such that the answer can be output as float  
	Amount = (principal * (1-pow(((float)rate/100),((float)numYears+1)))) / (1-(float)rate/100);
	printf("Amount = $%0.2f\n", Amount);
	 
	return 0;	 
 }
