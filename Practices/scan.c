#include <stdio.h>

int main(){
	int num, i=0, count=1;
	printf("Enter integers, terminate with ctrl-d\n");
	
	while(i==0){
		scanf("%d\n", &num);
		count++;
	}

	if((scanf("%d", &num) >=1)){
		printf("Number of vaules entered = %d\n", count);
	}




	return 0;
}
