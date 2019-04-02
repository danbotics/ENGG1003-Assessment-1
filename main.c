#include <stdio.h>


int main() {

char str[1024];
int i;

printf("Enter a string of characters: ");
fgets(str, sizeof(str), stdin);
printf("\n");

printf("Your original string: %s\n", str);

printf("Your encrypted string: ");

for(i = 0; str[i] != NULL; i++){
    printf("%c", str[i] + 1);
}
	

	
	
	return 0;
}
