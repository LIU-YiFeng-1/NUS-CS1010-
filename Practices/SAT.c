// CS1010 AY2012/3 Semester 1
// PE1 Ex1: sat.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:

#include <stdio.h>

int compute_percentile(int,int,int);
float compute_IQ(int,int);

int main(void) {

	int verbal, math, writing, percentile; // user's input
    float iq;
	printf("Enter scores: ");
	scanf("%d%d%d",&verbal, &math, &writing);
	percentile = compute_percentile(verbal, math, writing);
	iq = compute_IQ(math, verbal);
    printf("The SAT score is in the %d percentile.\n",percentile);
    printf("The IQ score is %0.2f\n", iq);

    if((verbal>600 && math>600 && writing>600)|| (iq>=120)){
            printf("Wow, this is amazing!\n");
    }

	return 0;
}

int compute_percentile(int verbal,int math,int writing){
    int sum, percentile;
    sum = verbal+math+writing;
    if(sum>=2200)
        percentile=99;
    else if(sum>=2000 && sum<2200)
        percentile=95;
    else if(sum>=1500 && sum<2000)
        percentile=50;
    else if(sum<1500)
        percentile=10;
    return percentile;
}
float compute_IQ(int math,int verbal){
    float iq;
    iq = 0.095*(float)math + 0.003*(float)verbal + 50.241;
    return iq;
}
