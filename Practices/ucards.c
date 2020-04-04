
// CS1010 AY2012/3 Semester 1
// PE1 Ex2: ucard.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:

#include <stdio.h>

int luhnah(int);
void issued(int);

int main(void) {
	int uCardNo;
    int checkNum;
	printf("Enter uCard Number: ");
	scanf("%d", &uCardNo);

    checkNum = luhnah(uCardNo);
    printf("The check number is %d\n", checkNum);

    if(checkNum%7!=0){
        printf("Invalid\n");
    }
    else{
        printf("Valid\n");
        issued(uCardNo);
    }

	return 0;
}

int luhnah(int uCardNo){
    int digit, count=1;
    int checkNum=0;
    while(uCardNo!=0){
        digit = uCardNo%10;

        if(count%2!=0){
            checkNum += digit;
        }
        else if(count%2==0){
            digit*=2;
            checkNum += ((digit/10)+(digit%10));
        }
        uCardNo = uCardNo/10;
        count++;
    }
    return checkNum;
}

void issued(int uCardNo){
    int first2D;
    while(uCardNo>100){
        uCardNo = uCardNo/10;
    }
    if(uCardNo>=31 && uCardNo<=35){
         printf("Issued by East branch\n");
    }
    else if(uCardNo>=51 && uCardNo<=55){
        printf("Issued by West branch\n");
    }
    else{
    printf("Issued by Central branch\n");
    }
}
