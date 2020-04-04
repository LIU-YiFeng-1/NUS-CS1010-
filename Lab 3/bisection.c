/*CS1010 AY2019/20 Semester 1 Lab3 Ex3
* bisection.c
* This program computes the root of a continuous
* function by using the bisection method.
* Name: LIU YIFENG
* Group: C06
*/

#include <stdio.h>

//function prototype
double polynomial(double, int, int, int, int);

int main(void) {
	//declaring variables and contants
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
		   pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint
	const double threshold = 0.0001; //constant variable for threshold

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);
	
	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);
	//condition for while loop where the difference between a & b has to be larger than threshold 
	while ((b-a)>threshold){
		m = (a+b)/2;
		pA = polynomial(a, c3, c2, c1, c0); //calling function of p(a)
		pB = polynomial(b, c3, c2, c1, c0); //calling function of p(b)
		pM = polynomial(m, c3, c2, c1, c0); //calling function of p(m)
		//when pM is zero, the vaule of m will be the root and while loop breaks
		if(pM==0){
			break;
		}
		else if(pA*pM >0){
			a=m;
		}
		else if(pB*pM>0){
			b=m;
		}
	}

	m = (a+b)/2;
	pM = polynomial (m, c3, c2, c1, c0); //calling function of p(m) which is p(root)
	printf("root = %0.6lf\n", m);
	printf("p(root) = %0.6lf\n", pM);

	return 0;
}

//function polynomial which computes and returns a function value
double polynomial(double x, int a, int b, int c, int d){
	return a*x*x*x+b*x*x+c*x+d;
}
