#include <stdio.h>

int main(){
    
    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    while(feof(input) == 0){
        char c;
        fscanf(input, "%c", &c);
        
        printf("%c", c);
    }
    printf("\n");
    
}

