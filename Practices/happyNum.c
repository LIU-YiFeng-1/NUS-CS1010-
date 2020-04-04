// CS1010 AY2014/5 Semester 1
// PE1 Ex2: happy.c
// Name:
// Matriculation number:
// plab-id:
// Discussion group:
// Description:
#include <stdio.h>

int computeHappyNumbers(int, int);
int checkHappyNumbers(int);

int main(void){
	int lower1, upper1, lower2, upper2, number1, number2;

	printf("Enter first range: ");
	scanf("%d %d", &lower1, &upper1);

	printf("Enter second range: ");
    scanf("%d %d", &lower2, &upper2);

    number1=computeHappyNumbers(lower1, upper1);
    number2=computeHappyNumbers(lower2, upper2);
	printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);
    if(number1 > number2)
	printf("There are more happy numbers in the first range.\n");
    else if(number2 > number1)
	printf("There are more happy numbers in the second range.\n");
    else
	printf("The numbers of happy numbers in both ranges are the same.\n");

	return 0;
}

int computeHappyNumbers(int lower, int upper) {
    int count=0, i;
    int checkNum;
    for(i=lower;i<=upper;i++){
        checkNum=checkHappyNumbers(i);
            if(checkNum==1){
                count++;
                //printf("the count is: %d\n", count);
            }
        }

    return count;
}

int checkHappyNumbers(int num){
    int checkNum;

    while(checkNum!=1&&checkNum!=0&&checkNum!=4&&checkNum!=16&&checkNum!=20&&checkNum!=37&&checkNum!=42&&checkNum!=58&&checkNum!=89&&checkNum!=145){
        checkNum=0;
        while(num>0){
            checkNum += (num%10)*(num%10);
            num = num/10;
        }
        num=checkNum;
    }
    return checkNum;
}
