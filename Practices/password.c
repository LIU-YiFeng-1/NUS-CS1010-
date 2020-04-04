#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 15

// function prototypes
int isValidPassword(char [], char [], char [], char []);

// main function complete, not to be changed!
int main(void) {
	char domain[LEN+1], userID[LEN+1], 
		 oldPasswd[LEN+1], newPasswd[LEN+1], confirmPasswd[LEN+1];

	printf("Domain: ");
	scanf("%s", domain);

	printf("UserID: ");
	scanf("%s", userID);

	printf("Old password: ");
	scanf("%s", oldPasswd);

	printf("New password: ");
	scanf("%s", newPasswd);

	printf("Confirm new password: ");
	scanf("%s", confirmPasswd);

	if ( isValidPassword(userID, oldPasswd, newPasswd, confirmPasswd) )
		printf("Password changed successfully!\n");
	else
		printf("Error: Invalid userID or password!\n");

	return 0;
}

// Check whether a new password is valid
int isValidPassword(char userID[], char oldPasswd[],
		char newPasswd[], char confirmPasswd[]) {
	int i, length;
	int upper=0, lower=0, dash=0;
	char* check;
	length = strlen(newPasswd);
	// 1. New password must be at least 8 characters in length
	if(length < 8){
		return 0;
	}
	//worked!!!
	//2. New password ust be complex
	for(i=0;i<length;i++){
		if(isupper(newPasswd[i])){
			upper++;
			}
		else if(islower(newPasswd[i])){
			lower++;
		}
		else if(newPasswd[i]=='_'){
			dash++;
		}
		else if(ispunct(newPasswd[i])&&newPasswd[i]!='_'){
			return 0;
		}
	}
	if((upper==0 || lower==0)&&(dash!=0 || dash==0)){
		return 0;
	}
	//worked!!!
	// 3. The new password must not contain UserID
	check = strstr(newPasswd, userID);
	if(check){
		return 0;
	}
	// 4. The confirmation for the new password must match the new password.
	if(strcmp(confirmPasswd, newPasswd)!=0){
		return 0;
	}
	// 5. The new password must not be the same as old password. 
	if(strcmp(oldPasswd, newPasswd)==0){
		return 0;
	}
	return 1; // stub, to be replaced by your code
}

// You may write additional functions below if needed.
// However every function must be preceeded with a function description.

