// pointers.c
// Exercise on using pointers.
#include <stdio.h>

void loop(int*, float*);

int main(void) {
	int a, *a_ptr;
	float b, *b_ptr;

	printf("Enter an integer: ");
	scanf("%d", &a);
	printf("Enter a real number: ");
	scanf("%f", &b);

	printf("Values entered are %d and %0.2f\n", a,b);

    loop(&a, &b);
    printf("Final value of a = %d\n", a);

	return 0;
}

void loop(int* A, float* B){
    while(*A<(*B * *B)){
        *A = *A * *B;
    }



}

