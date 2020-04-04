#include <stdio.h>
#include <math.h>

float speed_of_sound(float);

int main(void){
	
	float temp, speed;

	printf("Temperature in degree Fahrenheit: ");
	scanf("%f", &temp);

	speed = speed_of_sound(temp);
	printf("Speed of sound in air of %0.2f degree = %0.2f ft/sec\n", temp, speed);
	
	
	return 0;	
}

float speed_of_sound(float a){
	
	return 1086 * pow(((5*a+297)/247),0.5);	
	
}
