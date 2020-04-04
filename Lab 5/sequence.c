/**
 * CS1010 AY2019/20 Semester 1 Lab5 Ex2
 *sequence.c
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in
 * the array horizontally, vertically or diagonally.
 * <LIU YIFENG>
 * <C06>
 */

#include <stdio.h>
#define MAX 12

// function prototypes
int scanBoard(int [][MAX]);
void search(int [][MAX], int , int[]);

int main(void) {
	//declare variable and initialising array
	int board[MAX][MAX] = { {0} };
	int search_digit;
	int ans[3]={0};
	search_digit = scanBoard(board);//calling function scanBoard
	search(board, search_digit,ans);//calling function search

	if (ans[0] > 0) {
		printf("Length of longest sequence = %d\n", ans[0]);
		printf("Start at (%d,%d)\n", ans[1], ans[2]);
	}
	else
		printf("No such sequence.\n");
	return 0;
}

// This function scan and stor a array of 12X12
// and read in the value for search_digit
int scanBoard(int arr[][MAX]) {
	int i, j, num;
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d", &num);

	return num;
}

// This function search through the array and look for
// the longest sequence of the search digit
// ans array with ans[0]=length of longest sequence
// ans array with ans[1]=starting position row
// ans array with ans[2]=starting position col
// need not to check for sequence with the same longest length as the
// function will automatically return the nearest position
void search(int arr[MAX][MAX], int num, int ans[]) {
	//declare variable and initialise array
	int count, i, j, row, col, count2, count3;
	ans[0]=0;
	ans[1]=0;
	ans[2]=0;
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			//if element is same as the search digit,
			//check sequence horizontally
			if (arr[i][j]==num){
				col=j;
				count=0;
				while(arr[i][col]==num && col<MAX){
					col++;
					count++;
				}
			//if element is same as the search digit,
			//check sequence vertically
				if (arr[i][j]==num){
					row=i;
					count2=0;
					while(arr[row][j]==num && row<MAX){
						row++;
						count2++;
					}
				}
			//if element is same as the search digit,
			//check sequence diagonally
				if (arr[i][j]==num){
					row=i;
					col=j;
					count3=0;
					while(arr[row][col]==num && (row<MAX || col<MAX)){
						row++;
						col++;
						count3++;
					}
				}
				//if count or count2 or count3 is larger than ans[0], 
				//replace ans[0], ans[1], ans[2]
				if(count>ans[0]){
					ans[0]=count;
					ans[1]=i;
					ans[2]=j;
				}
				if(count2>ans[0]){
					ans[0]=count2;
					ans[1]=i;
					ans[2]=j;
				}
				if(count3>ans[0]){
					ans[0]=count3;
					ans[1]=i;
					ans[2]=j;
				}
			}
		}
	}
}



