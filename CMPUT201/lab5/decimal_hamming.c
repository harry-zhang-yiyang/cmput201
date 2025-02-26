#include <stdio.h>

int decimal_hamming_distance(unsigned int num1, unsigned int num2) {
    int count = 0;

    while (num1 > 0 && num2 > 0) {
        if ((num1 % 10) != (num2 % 10)) {  // 取最后一位进行比较
            count++;
        }
        num1 /= 10;  // 去掉最后一位
        num2 /= 10;
    }

    return count;
}

int main() {
    unsigned int num1, num2;

    scanf("%u", &num1);
    scanf("%u", &num2);

    int distance = decimal_hamming_distance(num1, num2);

    printf("%d\n", distance);
    return 0;
}

