#include <stdio.h>

void is_prime(int);

int main (){
	int num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);
	
	is_prime(num);

	return 0;
}

void is_prime(int a){
	int i, result=0;

	if(a==1){
			printf("%d is not a prime.\n", a);
	}
	else{
		for(i=1; i<=a; i++){
			if(a%i==0){
			result++;}

			if(result==3){
				break;
				}
			}
		

		if(result==2){
			printf("%d is a prime.\n", a);
		}	

		else{
			printf("%d is not a prime.\n", a);
		}
	}	
}
