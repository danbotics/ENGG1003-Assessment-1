#include <stdio.h>
#include <string.h>

int main(){
    
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ekey[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char encrypted[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU.";
    
    for(int shift = 1; shift < 26; shift++)
    {
        for(int i = 0; encrypted[i] != '\0'; i++)
        {
            if(encrypted[i] <= 'Z' && encrypted[i] >= 'A'){
                if((encrypted[i] - 'A' - shift) >= 0) printf("%c", (encrypted[i] - 'A' - shift) + 'A');
                else printf("%c", ((encrypted[i] - 'A' - shift) + 26) + 'A');
            }
            else printf("%c", encrypted[i]);
        }
    printf("\n");    
    }

    printf("\n");
//  printf("Element: %d\n", position);
    
}