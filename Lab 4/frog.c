/*
* CS1010 AY2019/20 Semester 1 Lab4 Ex3
* Frog.c
* This program allows the user to play a game by moving frogs from the left to the right and vice versa
* <LIU YIFENG>
* <C06>
*/
#include <stdio.h>

//Function Prototypes
int jump(int, int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int[]);

int main(void) {

	int bridge[1000];
	int i, len_Bridge, position, validity;
	int numMoves = 0;
	int gameState = 1;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &len_Bridge);

	for (i=0; i<len_Bridge; i++) {
		int frogType;
		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);
		bridge[i] = frogType;
	}
	printf("Input completed\n");
	printBridge(len_Bridge, bridge);
	printf("Please start moving the frogs\n");
	while(gameState == 1){ //Valid moves are still left to be made
		printf("Move the frog at position: ");
		scanf("%d",&position);
		validity = jump(position,len_Bridge,bridge);
		while(validity == 0){
			printf("Invalid move!\n");
			printf("Move the frog at position: ");
			scanf("%d",&position);
			validity = jump(position,len_Bridge,bridge);
		}
		printBridge(len_Bridge, bridge);
		numMoves++;
		gameState = checkGameState(len_Bridge,bridge);
	}
	if(gameState == 0) //No valid Moves
		printf("Oh no! It seems like the two clans of frogs are stuck!");
	else if(gameState == 2) //Game finished
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n",numMoves);
	/** Insert your code below **/

	return 0;
}

//Prints out the current state on the bridge
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}

/* This function "jumps" the frog based on its position and returns 1 if valid.
 * Returns 0 if no valid move.
 */
int jump(int position, int size, int bridge[]){
	int validMove = 0;
	switch(bridge[position]){
		case 1:
			if(bridge[position+1] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position+1] = 1;
				bridge[position] = 0; //previous position becomes 0.
				validMove++;
			}
			else if(bridge[position+2] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position+2] = 1;
				bridge[position] = 0; //previous position becomes 0.
				validMove++;
			}
			else
				validMove = 0; //not able to move
			break;

		case -1:
			if(bridge[position-1] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position-1] = -1;
				bridge[position] = 0; //previous position becomes 0.
				validMove++;
			}
			else if(bridge[position-2] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position-2] = -1;
				bridge[position] = 0; //previous position becomes 0.)
				validMove++;
			}
			else
				validMove = 0; //not able to move
			break;

		case 0:
			validMove = 0; //blank space
	}
	return validMove;
}
/*
 * This function checks the following conditions:
 * 1)There is valid moves left to be made. Returns 1.
 * 2)There is no more valid moves to be made. Returns 0.
 * 3)End of game state. Returns 2.
 */
int checkGameState(int size, int bridge[]){
	int i,j,k, flag = 0;
	for(i = 0; i < size; i++){
		if(bridge[i] == 1){ //If position holds value "1" frog, and there is still a valid move for it, return 1.
			if(bridge[i+1] == 0 || bridge[i+2] == 0 ){
				flag = 1;
				return flag;
			}
		}
		else if(bridge[i] == -1){ //If position holds value "-1" frog, and there is still a valid move for it, return 1.
			if(bridge[i - 1] == 0 || bridge[i - 2] == 0) {
				flag = 1;
				return flag;
			}
		}
		else if(bridge[i] == 0){ //If position is 0 then to check end game state
			for(j = i+1; j < size; j++){
				if(bridge[j] == -1)
					break;
				else if(bridge[j] == 1 && j == size-1){
					for(k = i-1; j > 0;k--){
						if(bridge[k] == 1)
							break;
						else{
							flag =2; //the game has been completed.
							return flag;
						}
					}
				}
			}

		}

	}

	flag = 0; //no possible move
	printf("Flag value: %d\n",flag);
	return flag;
}



