/*CS1010 AY2019/20 Semester 1 Lab1 Ex3
* packing.c
* This program reads the dimensions of a tray and a slab,
* and computes the maximum possible number of slabs that
* can be packed onto the tray.
* LIU YIFENG
* C06
*/

#include <stdio.h>

//prototyping of function
int compute_num_slab(int, int, int, int);

int main(void) {

	int trayLength, trayWidth, slabLength, slabWidth, maxSlabs;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayLength, &trayWidth);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabLength, &slabWidth);
	
	//calling function "cumpute_num_slab"
	maxSlabs = compute_num_slab(trayLength, trayWidth, slabLength, slabWidth);
	printf("Maximum number of slabs = %d\n", maxSlabs);
	
	return 0;
}

/*This function computes the maximum number of slabs that  can be packed
*onto the tray. The slabs can only be packed vertically or horizontally
*/
int compute_num_slab(int a, int b, int c, int d){
	
	int numVertical, numHorizontal;
	//this computes the numer of slabs that can be packed horizontally
	//using (trayLength/slabLength)*(trayWidth/slabWidth)
	numHorizontal = ((a/c) * (b/d));
	//this computes the number of slabs that can be packed vertically
	//using (trayLength/slabWidth)*(trayWidth/slabLength)
	numVertical = ((a/d) * (b/c));

	if ( numVertical > numHorizontal)
	{	
		return numVertical;		
	}	
	else
	{
		return numHorizontal;		
	}
}

