#include <stdio.h>
#include <math.h>

double compute_temp(int, int);

int main(void){
	int hr, mins;
	double temp;
	
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hr, &mins);

	temp = compute_temp(hr,mins);
	printf("Temperature in freezer = %0.2f\n", temp);
	
	return 0;	
}

double compute_temp(int a, int b){
	double tempV1, tempV2;

	tempV2 = pow((a+(double)b/60),9);
	tempV1 = pow((a+(double)b/60),10);

	return (4*tempV1)/(tempV2+2) - 20;
	
}
