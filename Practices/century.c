// CS1010 AY2011/2 Semester 1
// PE1 Ex1: century.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:
#include <stdio.h>

void printCentury(int);
void printOrdinal(int);

int main(void)
{
	int year; // user's input

	printf("Enter year: ");
    scanf("%d", &year);

    printCentury(year);

	return 0;
}

void printOrdinal(int num){
    if((num%100)==11 || (num%100)==12 || (num%100)==13){
        printf("th century.\n");
    }
    else if((num%10)==1){
        printf("st century.\n");
    }
    else if((num%10)==2){
        printf("nd century.\n");
    }
    else if((num%10)==3){
        printf("rd century.\n");
    }
    else if((num%10)==4||(num%10)==5||(num%10)==6||(num%10)==7||(num%10)==8||(num%10)==9||(num%10)==0){
        printf("th century.\n");
    }
}

void printCentury(int year){
    int num;
    num = year/100+1;

    printf("The year %d falls in the %d", year, num);
    printOrdinal(num);

}
