#include <stdio.h>

int count_multiples(int);

int main(void) {
	int num;
	int count;
	
	printf("Enter positive integer: ");
	scanf("%d", &num);
	count = count_multiples(num);
	if(count==0){
		printf("There are no multiples of 5 or 7 in [1,%d].\n", num);
	}
	else if(count==1){
		printf("There is 1 multiple of 5 or 7 in [1,%d].\n", num);
	}
	else{
		printf("There are %d multiples of 5 or 7 in [1,%d].\n", count,num);
	}
	return 0;
}

// Precond: value > 0
int count_multiples(int value) {
	int i, sum;
	int count = 0, duplicate = 0;
	for(i=1; i<=value; i++){
		if(i%5==0 || i%7==0){
			count++;
		}
//		if(i%5==0 && i%7==0){
//			duplicate++;
//		}
	}
	sum = count;

	return sum;
}

