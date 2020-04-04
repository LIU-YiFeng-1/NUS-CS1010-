#include <stdio.h>

float computeFare(int, int, int);

int main(){
	int type, hour, minute, time, distance;
	float fare;
	printf("Day type: ");
	scanf("%d", &type);
	printf("Boarding hour and minute: ");
	scanf("%d%d", &hour, &minute);
	printf("Distance: ");
	scanf("%d", &distance);
	time = 60*hour + minute;
	/*all testing printf below
	printf("The entered type is: %d\n", type);
	printf("The entered hour and minute is: %d %d\n", hour, minute);	
	printf("The entered board time is: %d\n", time);
	printf("The entered distance is: %d\n", distance);

	all testing prinf on top*/

	fare = computeFare(type, time, distance);
	printf("Boarding time is %d minutes\n", time);
	printf("Total taxi fare is $%0.2lf\n", fare); 
	return 0;
}

float computeFare(int dayType, int boardTime, int distance){
	int count;
	float basic=0, fare;
	if(distance <= 1000){
		basic=3.40;
	}
	else if(distance>1000 && distance <=10200){
		basic=3.40;
		if((distance-1000)%400==0){
			count = (distance-1000)/400;
			basic += count*0.22;
		}
		else{
			count = (distance-1000)/400 +1;
			basic += count*0.22;
		}
	}
	else if(distance>10200){
		basic=3.40+5.06;
		if((distance-10200)%350==0){
			count = (distance-10200)/350;
			basic += count*0.22;
		}
		else{
			count = (distance-10200)/350 +1;
			basic += count*0.22;
		}
	}
	
	if(dayType==0){
		if(boardTime<=359){
			fare = 1.5*basic;
		}
		else if(boardTime>=1080 && boardTime<=1439){
			fare = 1.25*basic;
		}
		else{
			fare=basic;
		}
	}
	if(dayType==1){
		if(boardTime<=359){
			fare = 1.5*basic;
		}
		else if(boardTime>=360 && boardTime<=569){
			fare = 1.25*basic;
		}
		else if(boardTime>=1080 && boardTime<=1439){
			fare = 1.25*basic;
		}
		else{
			fare=basic;
		}
	}
	
	return fare;
}
