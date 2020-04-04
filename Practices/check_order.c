// check_order.c
// Repeatedly reads positive integer, until the input value
// is zero, or the data are not in increasing order.

#include <stdio.h>

int main(void) {
    int temp=0, num;
    do{
        printf("Enter positive integer: ");
        scanf("%d", &num);
        if(num==0){
            printf("Data are in increasing order.\n");
            break;
        }
        if(temp>num){
            printf("Data are not in increasing order.\n");
            break;
        }
        if(temp==num){
            printf("Data are not in increasing order.\n");
            break;
        }
        temp=num;
    }while(num!=0 );

	return 0;
}
