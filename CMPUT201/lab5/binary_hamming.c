#include <stdio.h>

// trans from base-10 to base-2
void binary(unsigned int num, char *binary_num) {
    for (int i = 31; i >= 0; i--) {
        binary_num[i] = (num % 2);  //trans to binary
        num /= 2; // next
    }
}
        
//
unsigned int binary_hamming(const char *bin1, const char *bin2) {
    unsigned int count = 0;
    for (int i = 0; i < 32; i++) {
        if (bin1[i] != bin2[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    unsigned int num1, num2;
    char bin1[32], bin2[32]; // 32bits

    // read input
    if (scanf("%u %u", &num1, &num2) != 2) {
        return 1;
    }

    // trans
    binary(num1, bin1);
    binary(num2, bin2);
    
    // print
    printf("%u\n", binary_hamming(bin1, bin2));
    return 0;
}

