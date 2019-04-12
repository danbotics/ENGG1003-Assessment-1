#include <stdio.h>
#include <string.h>

int main(){
    
    FILE *dictionary;
    dictionary = fopen("wordlist.txt", "r");
    
    char word[30];
    int found = 0;
    char space[5] = " ";
    
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ekey[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char encrypted[] = " TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. ";
    char decrypted[strlen(encrypted)-1];
    // printf("Length of encrypted[]: %d\n", (int)strlen(encrypted));
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
        for(int n = 0 ; n < 1000 ; n++)
        {
            char temp[20] = " ";
            fscanf(dictionary, "%s", word);
            strcat(temp, word);
            strcat(temp, space);
            printf("Search: %d ", (int)strstr(decrypted, temp));
            if (strstr(decrypted, temp) != 0) found++;
        }
        printf("Found: %d\n", found);
        if(found >= 3){
            printf("%s\n", decrypted);
            break;
        } else found = 0;
    }

    printf("\n");
//  printf("Element: %d\n", position);
}