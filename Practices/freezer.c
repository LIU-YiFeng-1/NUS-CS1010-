/*this program is for practic
*it calculates the termperature of the freezer
*after certain time of power failure
*/

#include <stdio.h>
#include <math.h>

double compute_temp(int, int);

int main(void){
	
	int hr, mins;
	double temp;

	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hr, &mins);
	
	temp = compute_temp(hr, mins);
	printf("Temperature in freezer = %0.2f\n", temp);

	return 0;
	
}

double compute_temp(int a, int b){
	double time;

	time = a + (double)b/60;

	return (4*(pow(time , 2)) / (time+2)) - 20;
		
}
