#include <stdio.h>
#include <string.h>

void count(const char *codeword, const char *guess, int *bulls, int *cows) {
    int length = strlen(codeword);  //make sure wont over the length
    *bulls = 0;  //count bulls
    *cows = 0;  //count cows
    int matched[10] = {0};  //matched
    
    //count bulls
    for (int i = 0; i < length; i++) {
        if (guess[i] == codeword[i]) {
            (*bulls)++;
            matched[i] = 1;
        }
    }
    
    //count cows
    for (int i = 0; i < length; i++) {
        if (guess[i] != codeword[i]) {
            for (int j = 0; j < length; j++) {
                if (guess[i] == codeword[j] && guess[j] != codeword[j] && !matched[j]) {
                    (*cows)++;
                    matched[j] = 1;  //matched
                    break;
                }
            }
        }
    }
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <codeword>\n", argv[0]);
    return 1;
  }
    if (strlen(argv[1]) > 10) {
        fprintf(stderr, "Error: codeword can be at most 10 characters\n");
    return 1;
  }
    
    const char * const codeword = argv[1];
    
    int attempts = 0;  //count attempts
    
    char guess[11];
    
    while (attempts < 6) {
        scanf("%10s", guess);
        
        if (strlen(guess) < strlen(codeword)) {
                    printf("Error: length of guess must always match codeword\n");
                    printf("       Invalid Guess was \"%s\" and codeword is \"%s\"\n", guess, codeword);
                    return 0;
                }
        
        
        int bulls = 0, cows = 0;  //count bulls and cows
        count(codeword, guess, &bulls, &cows);
        
        if (strcmp(guess, codeword) == 0){
            printf("Congratulations, you won!\n");
            return 0;
        } else {
            printf("%d bulls, %d cows\n", bulls, cows);
        }
        
        attempts++;
    }
    
    printf("Sorry, you lost. The codeword was %s\n", codeword);
    return 0;
}
