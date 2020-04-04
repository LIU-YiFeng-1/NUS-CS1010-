#include <stdio.h>

int count_number(int, int, int, int);

int main(){
	int div1, div2, lim1, lim2, result;
	
	printf("Enter 2 divisors: ");
	scanf("%d %d", &div1, &div2);
	while( div1<1 || div2<1 || div1==div2){
		printf("Enter 2 divisors: ");
		scanf("%d %d", &div1, &div2);
	}
	
	printf("Enter lower and upper limits: ");
	scanf("%d %d", &lim1, &lim2);

	while(lim1<1 || lim2<1 || lim1==lim2 || lim1>lim2){
		printf("Enter lower and upper limits: ");
		scanf("%d %d", &lim1, &lim2);
	}

	result = count_number(div1, div2, lim1, lim2);
	printf("Answer = %d\n", result);
	return 0;
}

int count_number(int a, int b, int c, int d){
	int i, ans=0;
	for(i=c; i<=d;i++){
		while(i%a!=0 && i%b!=0){
			ans++;
			break;
		}
	}
	return ans;
}
