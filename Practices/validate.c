#include <stdio.h>

int main(){
	int age, count=1;
	printf("Enter age: ");
	scanf("%d", &age);
	
	while(age<=0 || age>100){
		printf("Enter age: ");
		scanf("%d", &age);
		count++;
	}	

	printf("Your age is %d.\n", age);
	printf("Number of attempts = %d\n", count);



	return 0;
}
