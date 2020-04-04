/**
* CS1010 AY2019/20 Semester 1 Lab4 Ex2
* subsequence.c
* This program reads in a list of integers and find the
* k-interval subsequence with the largest sum.
* <LIU YIFENG>
* <C06>
*/

#include <stdio.h>

//function prototype
int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) {
	int list[10]={0}, size; // array and actual number of elements entered
	int answers[3]={0};     // stores the required answers

	size = scan_list(list); //calling function 'scan_list'

	sum_subsequence(list, size, answers); //calling function 'sum_subsquence'

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

// This function read in the array element in K-interval and
// finds the maximum sum
// ans[0] = maximum sum of solution subsequence
// ans[1] = interval k of the solution subsequence
// ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {
	int start, j, k, sum;

	for(k=1; k<=size; k++){
		for(start=0; start<k; start++){
			sum=0;
			for(j=start; j<size; j+=k){
				sum = sum + arr[j];
			}
			if(sum>ans[0]){
				ans[0]=sum;
				ans[1]=k;
				ans[2]=start;;
			}
		}
	}

}

