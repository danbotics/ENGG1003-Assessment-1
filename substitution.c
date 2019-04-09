#include <stdio.h>
#include <string.h>

void capitalise(char []);
void encrypt(char []);
//void decrypt(char []);
char ekey[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
char dkey[1024];


int main() {

char str[1024] = "The quick brown fox jumps over the lazy dog";

char encrypted[1024];
int choice = 0;

printf("-----------------------------------\n");
printf("ENGG1003 - Programming Assessment 1\n");
printf("-----------------------------------\n");
printf("\n");
printf("Would you like to:\n");
printf("  [1] Encrypt some text\n");
printf("  [2] Decrypt some text\n");
printf("\n");
printf("Your choice: ");
scanf("%d", &choice);
getchar();

switch(choice){
    case 1:
    {
//        printf("\n");
//        printf("Enter the text to encrypt (it will be capitalised automatically): ");
//        fgets(str, sizeof(str), stdin);
//        printf("Substitution cipher key text: ");
//        fgets(str, sizeof(str), stdin);
//        getchar();
//        printf("\n");

        capitalise(str);
        printf("Your original text: %s\n", str);
        printf("Cipher key text: %s\n", ekey);

        printf("Your encrypted string: ");
        encrypt(str);
        printf("\n");
        break;
    } 
    case 2: 
    {
        printf("\n");
        printf("Enter the encrypted text: ");
        fgets(encrypted, sizeof(encrypted), stdin);
        printf("Substitution cipher key text: ");
        fgets(dkey, sizeof(dkey), stdin);
//      getchar();
        printf("\n");

        printf("Decrypted: ");
        decrypt(encrypted);
        printf("\n");
        break;    
    }
}

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
    //int n;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] <= 'Z' && string[i] >= 'A')
        {
            printf("%c", ekey[string[i] - 'A']);
        }
        else printf("%c", string[i]);
    }
}

void decrypt(char string[]){
    int i;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] <= 'Z' && string[i] >= 'A'){
        printf("%c", (string[i] - 'A' -dkey) % 26 + 'A');    
        }
        else printf("%c", string[i]);
    }
}