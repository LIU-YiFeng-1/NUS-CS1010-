#include <stdio.h>

int gdc(int, int);
int count_coprime(int);

int main(){
	int limit;

	printf("Enter limit: ");
	scanf("%d", &limit);

	printf("Answer = %d\n", count_coprime(limit));

	return 0;
}

int count_coprime(int i){
	int x, y, ans=0;

	for(x=2; x<i; x++){
		for(y=x+1;y<=i;y++){
			
			if(gdc(x,y)==1){
				ans++;
			}
		}
	}
	return ans;
}

int gdc(int a, int b){
	int r;
	
	while(a%b!=0){
		r=a%b;
		a = b;
		b = r;
	}
	
	return b;
}



