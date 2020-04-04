#include <stdio.h>

int min_unused_area(int, int, int, int);
float min_perimeter(float, float);

int main(void) {
	int trayHeight, trayWidth, slabHeight, slabWidth, minArea;
	float minPer;

	printf("Enter size of tray: ");
	scanf("%d %d", &trayHeight, &trayWidth);

	printf("Enter size of slab: ");
	scanf("%d %d", &slabHeight, &slabWidth);

    minArea = min_unused_area(trayHeight, trayWidth, slabHeight, slabWidth);
	printf("Minimum unused area = %d\n", minArea);

    minPer = min_perimeter((float)trayHeight,(float)trayWidth);
	printf("Minimum perimeter after folding = %0.2f\n", minPer);

	return 0;
}

float min_perimeter(float trayHeight, float trayWidth){
    float ans;
    int count=0;
    while(count!=3){
        if(trayHeight>trayWidth){
            trayHeight /= 2;
        }
        else{
            trayWidth /= 2;
        }
     count++;
    }
    ans = 2*trayHeight + 2*trayWidth;
    return ans;
}


int min_unused_area(int trayHeight, int trayWidth, int slabHeight, int slabWidth){
    int trayArea, slabArea, count, ans;
    int slabNum1, slabNum2;
    trayArea = trayHeight * trayWidth;
    slabArea = slabHeight * slabWidth;
    slabNum1 = (trayHeight/slabHeight)*(trayWidth/slabWidth);
    slabNum2 = (trayWidth/slabHeight)*(trayHeight/slabWidth);
    if(slabNum1 > slabNum2){
        count=slabNum1;
    }
    else{
        count=slabNum2;
    }
    ans = trayArea - (slabArea * count);

    return ans;
}
