#include <stdio.h>

char generateCode(int);

int main(void){
	
	int nric;
//	int code;
	char code;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &nric);

	code = generateCode(nric);
	printf("Check code is %c\n", code);
//	printf("Check code is %d\n", code);
	
	return 0;	
	
}

char generateCode(int a){

	// step 1
	int num1, num2, num3, num4, num5, num6, num7, numSum;
	int numR, numF;

	char cha1, cha2, cha3, cha4, cha5, cha6, cha7, cha8, cha9, cha10, cha11;

	num1 = a/1000000%10;
	num2 = a/100000%10;
	num3 = a/10000%10;
	num4 = a/1000%10;
	num5 = a/100%10;
	num6 = a/10%10;
	num7 = a%10;
	numSum = 2*num1+7*num2+6*num3+5*num4+4*num5+3*num6+2*num7;
	
	numR = numSum % 11;
	numF = 11 - numR;
	
	cha1 = 'A';
	cha2 = 'B';
	cha3 = 'C';
	cha4 = 'D';
	cha5 = 'E';
	cha6 = 'F';
	cha7 = 'G';
	cha8 = 'H';
	cha9 = 'I';
	cha10 = 'Z';
	cha11 = 'J';
	switch(numF)
	{
	case 1:
		return cha1;
	case 2:
		return cha2;
	case 3:
		return cha3;
	case 4:
		return cha4;
	case 5:
		return cha5;
	case 6:
		return cha6;
	case 7:
		return cha7;
	case 8:
		return cha8;
	case 9:
		return cha9;
	case 10:
		return cha10;
	case 11:
		return cha11;
		
	}
}
