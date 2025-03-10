#include <stdio.h>
#include <string.h>

int main () {
    int diff = 0;
    char num1[100];
    char num2[100];
    
    scanf("%s", num1);
    scanf("%s", num2);
    
    if (strlen(num1) != strlen(num2)) {
        printf("Error");
    }
        
    unsigned int size = strlen(num1);
    
    for (unsigned int i=0; i<size; ++i) {
        if (num1[i] != num2[i]) {
            diff++;
        }
    }
            
    printf("%d\n", diff);
    return 0;
}
