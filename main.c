#include <stdio.h>
#include <string.h>

void capitalise(char string[],); // Prototype for function that is passed a string and capitalises and lower case letters
void rEncrypt(char string[], int key); // Protype for rotation (Caeser) cipher ENCRYPTION function
void rDecrypt(char string[], int key); // Protype for rotation (Caeser) cipher DECRYPTION function
void sEncrypt(char string[], char key[]); // Protype for substitution cipher ENCRYPTION function
void sDecrypt(char string[], char key); // Protype for substitution cipher DECRYPTION function

int rEkey = 1, rDkey = 1; // Declare and intialise variables to store the keys for encrypting and decrypting rotation ciphers
char sEkey[26], sDkey[26]; //Declare arrays used to store user specified substitution cipher keys (26 letters in non-standard order)

int main()
{
    char inputText[1024]; //Array to store plain text input to be encrypted
    char encryptedOutput[sizeof(inputText) - 1]; // Array to store output of rEncrypt() function (encrypted text)
    char encryptedText[1024]; // Array to store encrypted text to be decrypted
    char decryptedOutput[sizeof(EncryptedText) - 1]; // Array to store output of rDecrypt() function (decrypted text)
    int choice = 0; // Variable to store choice in menu system
    
    // Menu System for function selection
    printf("-----------------------------------\n");    
    printf("ENGG1003 - Programming Assessment 1\n");    
    printf("-----------------------------------\n");    
    printf("\n");                                       
    printf("Would you like to:\n");                     
    printf("  [1] Encrypt text using rotation (Caesar) cipher\n");                
    printf("  [2] Encrypt text using substitution cipher\n");                
    printf("  [3] Decrypt text encrypted using rotation (Caesar) cipher\n");
    printf("  [4] Decrypt text encrypted using substitution cipher\n");
    printf("  [5] Break rotation encrypted text\n");
    printf("  [6] Break substitution encrypted text\n");
    printf("\n");                                       
    printf("Your choice: ");                            
    scanf("%d", &choice);
    getchar();  // This function is required to absorb the 'newline' character after scanf() - without this, fgets() does not work

    switch(choice)
    {
        case 1: // ENCRYPT USING ROTATION CIPHER
            printf("\n");
            printf("Enter the text to encrypt (it will be capitalised automatically): ");
            fgets(inputText, sizeof(inputText), stdin); // Capture plain text string from user input (stdin) to be encrypted
            printf("Rotation cipher key: ");
            scanf("%d", &rEkey); // User inputs desired rotation cipher key (amount to shift letters by)
            getchar();
            printf("\n");

            capitalise(inputText); // Change any lower case characters in user input to upper case
            printf("Your original text: %s\n", inputText); // Verify user input text (now also capitalised)

            rEncrypt(inputText, rEkey); // Call function to encrypt using rotation cipher - passed inputText array and integer key as arguments
            printf("Your encrypted string: ");
            printf("%s", encryptedOutput); // Print new encrypted text to console
            break; // Leave switch function
            
        case 2: // ENCRYPT USING SUBSTITUTION CIPHER
            printf("\n");
            printf("Enter the text to encrypt (it will be capitalised automatically): ");
            fgets(inputText, sizeof(inputText), stdin);
            printf("Substitution cipher key text: ");
            fgets(sEkey, sizeof(sEkey), stdin);
            printf("\n");

            capitalise(inputText); // Change any lower case characters in user input to upper case
            printf("Your original text: %s\n", inputText); // Verify user input text (now also capitalised)
            printf("Cipher key text: %s\n\n", sEkey);  // Verify user input cipher key

            sEncrypt(inputText, sEkey); // Call function to encrypt using substitution cipher - passed inputText and key arrays as arguments
            printf("Your encrypted string: ");
            printf("%s \n\n", encryptedOutput);  // Print new encrypted text to console
            break; // Leave switch function
            
        case 3: // DECRYPT USING ROTATION CIPHER
            printf("\n");
            printf("Enter the encrypted text: ");
            fgets(encryptedText, sizeof(encrypted), stdin);
            printf("Rotation cipher key: ");
            scanf("%d", &rDkey);
            getchar();
            printf("\n");

            printf("Decrypted: ");
            rDecrypt(encryptedText);
            printf("%s\n", decryptedOutput);
            break;
            
        case 4: // DECRYPT USING SUBSTITUTION CIPHER
    }

return 0;
}

    
    
}
