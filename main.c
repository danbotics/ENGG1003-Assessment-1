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

            rDecrypt(encryptedText);
            printf("Decrypted: %s\n", decryptedOutput);
            break;
            
        case 4: // DECRYPT USING SUBSTITUTION CIPHER
            printf("\n");
            printf("Enter the encrypted text: ");
            fgets(encryptedText, sizeof(encryptedText), stdin);
            printf("Substitution cipher key text: ");
            fgets(sDkey, sizeof(sDkey), stdin);
            printf("\n");
            sDecrypt(encryptedText, sDkey);
            printf("Decrypted: %s\n", decryptedOutput);
            break;
        
        default: // Default case catched any other option not covered by the previous cases
            printf("That function hasn't been implemented yet - stay tuned!");
        
    }

return 0;
}

/*
CAPITALISE FUNCTION - takes an array then capitalises every lower case letter by looking at each letter and subtracting 32 
(Changes 'a' (ASCII 97) to 'A' (ASCII 65)
*/
void capitalise(char string[])
{
    int i;
    // CAPITALISE string input
    for(i = 0; string[i] != '\0'; i++)
    { 
        // If the letter at string position 'i' is lower case, subtract 32 and write it back to the same position (makes it a capital)
        if(string[i] <= 'z' && string[i] >= 'a') string[i] = string[i] - 32;
    }
}

void rEncrypt(char string[], int key)
{
    int i;
    for(i = 0; string[i] != '\0'; i++)
    {
        // If array element 'i' is a capital letter, subtract 'A' from the element, add the key, calculate the result % 26 and add 'A' again
        // This shifts each letter by the rotation key, assigning the result to encryptedOutput[i] - the % 26 operation allows the digits to
        // wrap around if already at the end of the alphabet.
        if(string[i] <= 'Z' && string[i] >= 'A') encryptedOutput[i] = (string[i] - 'A' + key) % 26 + 'A');
        else encryptedOutput[i] = string[i]; // If array element is not a capital letter, send it straight to output unchanged
    }
}

void decrypt(char string[], int key)
{
    int i;
    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] <= 'Z' && string[i] >= 'A') // If array element is a letter, continue to decryption - otherwise skip to line 144
        {
            // If input array element will be above 0 when decrypted, perform decryption
            if((string[i] - 'A' - key) >= 0) decryptedOutput[i] = ((string[i] - 'A' - key) + 'A');
            else decryptedOutput[i] = (((string[i] - 'A' - key) + 26) + 'A'); // If input array element will be below 0, add 26 to make it a positive number
        }
        else decryptedOutput[i] = string[i]; // If input array element is NOT a letter, sent it straight to decryptedOutput[i] without modification
    }
}