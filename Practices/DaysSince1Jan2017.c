#include <stdio.h>

int compute_days(int, int);



int main(){
	int day, month, dayNum;
	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);

	dayNum = compute_days(day, month);

	printf("Day %d of month %d is the %dth day of 2017.\n", day, month, dayNum);


	return 0;
}

int compute_days(int a, int b){
	int num;

	switch (b){
		case 1:
			num = a;
			break;
		case 2:
			num = a + 31;
			break;
		case 3:
			num = a + 31 + 28;
			break;
		case 4:
			num = a + 31 + 28 + 31;
			break;
		case 5:
			num = a+31+28+31+30;
			break;
		case 6:
			num = a+31+28+31+30+31;
			break;
		case 7:
			num = a+31+28+31+30+31+30;
			break;
		case 8:
			num = a+31+28+31+30+31+30+31;
			break;
		case 9:
			num = a+31+28+31+30+31+30+31+31;
			break;
		case 10:
			num = a+31+28+31+30+31+30+31+31+30;
			break;
		case 11:
			num = a+31+28+31+30+31+30+31+31+30+31;
			break;
		case 12:
			num = a+31+28+31+30+31+30+31+31+30+31+30;
			break;
	}

	return num;

}
