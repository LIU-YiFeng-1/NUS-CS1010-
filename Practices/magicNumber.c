#include <stdio.h>

int get_magic(int);

int main(void){
	
	int num1, num2, magicNum;

	printf("Enter 1st value: ");
	scanf("%d", &num1);

	magicNum = get_magic(num1);
	printf("Magic number = %d\n", magicNum);

	printf("Enter 2nd value: ");
	scanf("%d", &num2);

	magicNum = get_magic(num2);
	printf("Magic number = %d\n", magicNum); 
	
	
	return 0;	
}

int get_magic(int a){
	
	int reNum1, reNum2, reNum3, sumNum;

	reNum1 = a % 10;
	reNum2 = a / 100 % 10;
	reNum3 = a / 10000 % 10;
	sumNum = reNum1+reNum2+reNum3;
	return sumNum % 10;
	
}
