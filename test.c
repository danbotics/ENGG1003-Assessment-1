#include <stdio.h>
#include <string.h>

int main(){
    
    void capitalise(char string[]);
    
    FILE *dictionary;
    dictionary = fopen("wordlist.txt", "r");
    
    char word[30];
    int found = 0;
    char space[5] = " ";
    
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ekey[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char encrypted[] = " TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. ";
    char decrypted[(sizeof(encrypted)-1)];
    
    printf("--------------------------\n");
    printf("Rotation cipher decryption\n");
    printf("--------------------------\n");
    printf("\n");
    printf("Encrypted text:%s\n\n", encrypted);
    
    for(int shift = 1; shift < 26; shift++)
    {
        for(int i = 0; encrypted[i] != '\0'; i++)
        {
            if(encrypted[i] <= 'Z' && encrypted[i] >= 'A'){
                if((encrypted[i] - 'A' - shift) >= 0) decrypted[i] = ((encrypted[i] - 'A' - shift) + 'A');
                else decrypted[i] = (((encrypted[i] - 'A' - shift) + 26) + 'A');
            }
            else decrypted[i] = encrypted[i];
        }
        //printf("%s", decrypted);
        for(int n = 0 ; n < 1000 ; n++)
        {
            char temp[20] = " ";
            fscanf(dictionary, "%s", word);
            capitalise(word);
            strcat(temp, word);
            strcat(temp, space);
            //printf("Search: %s ", temp);
            if (strstr(decrypted, temp) != 0) found++;
        }
        //printf("Found: %d\n", found);
        if(found >= 3){
            printf("Found cipher key to be: %d\n", shift);
            printf("Decrypted text:%s\n", decrypted);
            break;
        } else {
            found = 0;
            fseek(dictionary, 0, SEEK_SET);
        }
        //getchar();
    }

    printf("\n");
//  printf("Element: %d\n", position);
}

void capitalise(char string[]){
    int i;
    // CAPITALISE string input
    for(i = 0; string[i] != '\0'; i++){ 
        // If the letter at string position 'i' is lower case, subtract 32 and write it back to the same position (makes it a capital)
        if(string[i] <= 'z' && string[i] >= 'a') string[i] = string[i] - 32;
    }
}