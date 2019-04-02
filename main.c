#include <stdio.h>


int main() {

char str[1024];
int i;

printf("Enter a string of characters: ");
fgets(str, sizeof(str), stdin);
printf("\n");

printf("Your original string: %s\n", str);

// CAPITALISE string input
for(i = 0; str[i] != '\0'; i++){ 
    // If the letter at string position 'i' is lower case, subtract 32 and write it back to the same position (makes it a capital)
    if(str[i] <= 'z' && str[i] >= 'a') str[i] = str[i] - 32;
}
printf("Your capitalised string: %s\n", str);

printf("Your encrypted string: ");

for(i = 0; str[i] != '\0'; i++){
    
    if(str[i] <= 'Z' && str[i] >= 'A') printf("%c", str[i] + 1);
    else printf("%c", str[i]);
}
	

	
	
	return 0;
}
