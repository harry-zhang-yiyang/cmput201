#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <codeword>\n", argv[0]);
		return 1;
	}
	
	if (strlen(argv[1]) > 10) {
		fprintf(stderr, "Error: codeword can be at most 10 characters\n");
		return 1;
	}
	
	const char * const codeword = argv[1];  //based on the argv1
	
	int attempt = 0;  //count attempts
	int lens = strlen(codeword);

	while (attempt<=6) {
		char guess[11];  //largest is 10 char
		scanf("%10s", guess);  //get guess
		attempt++;  //add attempt
        
        if (strlen(codeword) != strlen(guess)) {  //same length
            printf("Error: length of guess must always match codeword\n");
            printf("       Invalid Guess was \"%s\" and codeword is \"%s\"\n", guess, codeword);
            return -1;
        }
        
        if (attempt > 6) {//more than 6 times game end
            printf("Sorry, you lost. The codeword was %s\n", codeword);
            return -1;
        }
        
        int cow = 0;  //count cow
        int bull = 0;  //count bull
        int matched[10] = {0};
		
        for (int i=0; i<lens; ++i) {
            if (codeword[i] == guess[i]) {
                bull++;
                matched[i] = 1;
            }
        }
            
            for (int i=0; i<lens; ++i) {
                if (guess[i] != codeword[i]) {
                    for (int j=0; j<lens; ++j) {
                        if (guess[i] == codeword[i] && guess[j] != codeword[i]) {
                            cow++;
                            matched[j] = 1;
                        }
                    }
                }
            }
        
            if (strcmp(codeword, guess) == 0) {
            printf("Congratulations, you won!\n");
            return 0;
        } else {
            printf("%d bulls, %d cows\n", bull, cow);
        }
    }
    // If max attempts reached
    printf("Sorry, you lost. The codeword was %s\n", codeword);
    return 0;
}
