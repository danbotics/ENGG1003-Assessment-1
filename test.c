#include <stdio.h>
#include <string.h>

int main(){
    
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ekey[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char encrypted[] = "ZIT JXOEA WKGVF YGB PXDHL GCTK ZIT SQMN RGU";
    
    char *positionPointer;
    int position, i;
    
    for(i = 0; encrypted[i] != '\0'; i++)
    {
        if(encrypted[i] <= 'Z' && encrypted[i] >= 'A'){
            positionPointer = strchr(ekey, encrypted[i]);
            position = positionPointer - ekey;
            printf("%c", alphabet[position]);
        }
        else printf("%c", encrypted[i]);
    }
    
    printf("\n");
//  printf("Element: %d\n", position);
    
}