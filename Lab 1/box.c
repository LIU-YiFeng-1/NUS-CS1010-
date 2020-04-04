/**
*CS1010 AY2019/20 Semester 1 Lab1 Ex2
*box.c
*This program calculates the surface area of the box
*and the length of the diagonal between two vertices
*of the box that are furthest apart.
*Name: LIU YIFENG
*Group: C06
*/

#include <stdio.h>
#include <math.h>

//prototyping of functions
int compute_surface_area(int a, int b , int c);
double compute_diagonal(int, int, int);

int main (void){
	//declare variables and their respective  data types
	int length, width, height,surface_area;
	double diagonal;
	
	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);
	
	//calling of pre-defined function
	surface_area = compute_surface_area(length, width, height);
	printf("Surface area = %d\n", surface_area);
	
	//calling of pre-defined function
	diagonal = compute_diagonal(length, width, height);
	printf("Diagonal = %0.2f\n", diagonal);

	return 0;	
	
}

//define function to calculate the surface area of a box
int compute_surface_area(int a, int b, int c){
	
	return 2*(a*b + a*c + b*c);

}

/*define function to calculate the hypotenuse of the base
*then use the hypotenuse and height to find diagonal
*/
double compute_diagonal(int a, int b, int c){

	double hypotenuse;
	hypotenuse = sqrt(pow(a,2) + pow(b,2));

	return sqrt(pow(hypotenuse,2) + pow(c,2));

}


