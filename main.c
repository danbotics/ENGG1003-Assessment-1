#include <stdio.h>

void capitalise(char []);
void encrypt(char []);
void decrypt(char []);

int main() {

char str[1024];
char encrypted[1024];
int key = 0;
int choice = 0;

// Starting menu

printf("-----------------------------------\n");
printf("ENGG1003 - Programming Assessment 1\n");
printf("-----------------------------------\n");
printf("\n");
printf("Would you like to:\n");
printf("[1] Encrypt some text\n");
printf("[2] Decrypt some text\n");
printf("Your choice: ");
scanf(%d, &choice);

printf("Enter a string of characters: ");
fgets(str, sizeof(str), stdin);
printf("\n");

printf("Your original string: %s\n", str);

capitalise(str);
printf("Your capitalised string: %s\n", str);

printf("Your encrypted string: ");
encrypt(str);
printf("\n");	
	
return 0;
}

void capitalise(char string[]){
    int i;
    // CAPITALISE string input
    for(i = 0; string[i] != '\0'; i++){ 
        // If the letter at string position 'i' is lower case, subtract 32 and write it back to the same position (makes it a capital)
        if(string[i] <= 'z' && string[i] >= 'a') string[i] = string[i] - 32;
    }
}

void encrypt(char string[]){
    int i;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] <= 'Z' && string[i] >= 'A') printf("%c", string[i] + key);
        else printf("%c", string[i]);
    }
}

void encrypt(char string[]){
    int i;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] <= 'Z' && string[i] >= 'A') printf("%c", string[i] - key);
        else printf("%c", string[i]);