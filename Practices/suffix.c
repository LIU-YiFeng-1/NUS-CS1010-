#include <stdio.h>

void printSuffix(int);

int main(){
	int value;

	printf("Enter value: ");
	scanf("%d", &value);

	printSuffix(value);
	
	return 0;
}
	
void printSuffix(int a){
	if(a%100==11 || a%100==12 || a%100==13){
		printf("%dth\n", a);
	}
	else if(a%10==1){
		printf("%dst\n", a);
	}
	else if(a%10==2){
		printf("%dnd\n", a);
	}
	else if(a%10==3){
		printf("%drd\n", a);
	}
	else{
		printf("%dth\n", a);
	}
}
