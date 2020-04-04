/**
*S1010 AY2019/20 Semester 1 Lab5 Ex1
*Square.c
*Given the size of a square and the value in
*the square, this program determines whether 
*the given square is a semi-magic square.
*Name: LIU YIFENG
*Group C06
*/
#include <stdio.h>
#define MAXSIZE 9

//function prototype
int scanSquare(int [][MAXSIZE]);
int isSemiMagic(int [][MAXSIZE], int);

int main(void) {
	int square[9][9];//declare int array 
	int size;//declare variable
	size = scanSquare(square);//calling function scanSquare
	
	//callin function isSemiMagic
	if(isSemiMagic(square, size)){
		printf("It is a semi-magic square.\n");
	}
	else{
		printf("It is not a semi-magic square.\n");
	}
	return 0;
}

// Read in size of square and values in the square.
// Return the size of square.
int scanSquare(int square[][MAXSIZE]) {
	int r, c, size;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}

	return size;
}

//Check if a array is SemiMagic
int isSemiMagic(int arr[][MAXSIZE], int count){
	int i, j, colSum, rowSum, sumCheck=0, firstSum=0, fixSum=0; //declare variables

	sumCheck = ((count*count)*((count*count)+1))/2;//finding the total sum of 1-n*n
	
	//finding the total sum of the array elements
	for(i=0; i<count; i++){
		for(j=0; j<count; j++){
			fixSum += arr[i][j];
		}
	}
	//setting a sum to check against sums for all rows and columns
	for(i=0; i<count; i++){
		firstSum += arr[i][0];
	}
	//if the sum of all elements in the array is not equal to the total sum of 1-n*n
	//the array is not SemiMagic
	if(fixSum != sumCheck){
		return 0;
	}
	//find all the rowSum and colSum and check against with the reference sum
	for(i=0; i<count; i++){
		rowSum=0;
		colSum=0;
		for(j=0; j<count; j++){
			rowSum += arr[i][j];
			colSum += arr[j][i];
		}
		if(rowSum!=firstSum || colSum!=firstSum){
			return 0;
		}
	}
	return 1;
}

