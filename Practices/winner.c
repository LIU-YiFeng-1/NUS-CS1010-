// CS1010 AY2011/2 Semester 1
// PE1 Ex2: winners.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:
#include <stdio.h>

int checkWinner(int, int, int);
void printWinner(int, int, int);

int main(void)
{
	int factor, key, numPax;

	printf("Enter factor-digit: ");
	scanf("%d", &factor);
	printf("Enter must-have-digit: ");
	scanf("%d", &key);
	printf("Enter number of participants: ");
    scanf("%d", &numPax);

    printWinner(factor, key, numPax);

	return 0;
}

int checkWinner(int factor, int key, int i){
    int count, Q, R;
    if(i%factor!=0){
        return 0;
    }
    else{
        while(i>0){
            if(i%10==key){
                return 1;
            }
            i=i/10;
        }
        //return 0;
    }
}

void printWinner(int factor, int key, int numPax){
    int sum=0, count, i;

    for(i=1; i<=numPax; i++){
        count=checkWinner(factor,key,i);
        sum+=count;
    }
    printf("Number of winners: %d\n", sum);
}
