#include <stdio.h>

int is_prime(int);

int main (){
	int i, limit, check, count=0;
	printf("Enter limit: ");
	scanf("%d", &limit);
	
	for(i=1; i<=limit; i++){
		check = is_prime(i);
		if(check==1){
			count++;	
		}	
	}
	
	printf("Number of primes (1-%d): %d\n", limit, count);

	return 0;
}

int is_prime(int a){
	int i, result=0;

	if(a==1){
			return 0;
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
			return 1;
		}	

		else{
			return 0;
		}
	}	
}
