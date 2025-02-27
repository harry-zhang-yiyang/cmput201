#include <stdio.h>

int decimal_hamming(unsigned int num1, unsigned int num2) {
    int count = 0;

    while (num1 > 0 && num2 > 0) {
        if ((num1 % 10) != (num2 % 10)) {  //get the last number
            count++;
        }
        num1 /= 10;  //next number
        num2 /= 10;
    }

    return count;
}

int main() {
    unsigned int num1, num2;

    scanf("%u", &num1);
    scanf("%u", &num2);

    int distance = decimal_hamming(num1, num2);

    printf("%d\n", distance);
    return 0;
}

