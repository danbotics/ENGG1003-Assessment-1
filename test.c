#include <stdio.h>
#include <string.h>

int main(){
    
    FILE *dictionary;
    char wordtest[1024] = " that this by and you the ";
    char word[30];
    int found = 0;
    char space[5] = " ";
    
    dictionary = fopen("wordlist.txt", "r");
    
    for(int i = 0 ; i < 1000 ; i++){
        char temp[20] = " ";
        fscanf(dictionary, "%s", word);
        strcat(temp, word);
        strcat(temp, space);
        if (strstr(wordtest, temp) > 0){
            found++;
            printf("%s found in %s\n", word, wordtest);
        }
    }
    
    printf("%d words found!\n", found);

}