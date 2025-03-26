#include <stdio.h>

// connect char and num
int value(char ch) {
    if (ch == 'I') return 1;
    if (ch == 'V') return 5;
    if (ch == 'X') return 10;
    if (ch == 'L') return 50;
    if (ch == 'C') return 100;
    if (ch == 'D') return 500;
    if (ch == 'M') return 1000;
    return 0;
}

int trans(const char *string) {
    int total = 0;  //sum of number
    int prev = 0;  //last value
    
    // go though string
    while (*string) {
        int current = value(*string);  //current = value from string now
        
        if (current > prev) {  //if current > prev
            total += current - 2 * prev; // current devide 2 pre in 2 term
        } else {
            total += current;  //common way
        }

        prev = current;  //update value
        string++;  //update position to next string
    }
    
    return total;
}

int main() {
    char roman[100]; // store data
    int c, i = 0;

    // read char until \n or EOF
    while ((c = getchar()) != EOF && c != '\n') {
        if (c != ' ' && c != '\t') { // delet space
            roman[i++] = c;
        }
    }

    // trans
    printf("%d\n", trans(roman));

    return 0;
}
