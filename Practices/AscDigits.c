#include <stdio.h>

int isAsc(int, int, int);

int main(){
	int num1, num2, num3, result; 
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("The integers are %d, %d and %d\n", num1, num2, num3);
	result = isAsc(num1, num2, num3);
	
	if(result==1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}

int isAsc(int a, int b, int c){
	int rem1, rem2, rem3;
	int yes=1, no=0;
	rem1 = (a/100)%10;
	rem2 = (b/100)%10;
	rem3 = (c/100)%10;
		
	if(rem1<rem2 && rem2<rem3){
		return yes;
	}
	else{
		return no;
	}


}

