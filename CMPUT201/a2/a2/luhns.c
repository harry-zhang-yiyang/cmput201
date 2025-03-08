#include <stdio.h>

int main() {
    int sum = 0;
    int check;  //check digits
    int digits[20]; //store data
    int position = 0;
    char ch;

    // read file
    while ((ch = getchar()) >= '0' && ch <= '9') {
        digits[position++] = ch - '0'; // store data
    }

    // at least 2 number
    if (position < 2) {
        printf("Invalid\n");
        return 0;
    }

    // reversed string
    int reversed[20];
    for (int i = 0; i < position; i++) {
        reversed[i] = digits[position - 1 - i];
    }

    // first number is check
    check = reversed[0];

    // thought the string
    for (int i = 1; i < position; i++) {
        int digit = reversed[i];

        if (i % 2 == 1) {
            digit *= 2;
            if (digit >= 10) {
                digit -= 9;
            }
        }

        sum += digit;
    }

    // last step
    sum = (sum * 9) % 10;

    if (sum == check) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}

