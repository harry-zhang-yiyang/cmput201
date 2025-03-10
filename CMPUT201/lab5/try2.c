#include <stdio.h>
#include <string.h>

void binary(unsigned int num, int *bin) {
	for (int i = 31; i >= 0; i--) {
		bin[i] = num%2;
		num /= 2;
	}
}

int bi(const int *bin1, const int *bin2) {
	int diff = 0;
	for (int i=0; i < 32; i++) {
		if (bin1[i] != bin2[i]) {
			diff++;
		}
	}
	return diff;
}	


int main() {
	unsigned int num1;
	unsigned int num2;

	int bin2[32];
	int bin1[32];
	
	scanf("%u", &num1);
	scanf("%u", &num2);

	binary(num1, bin1);
	binary(num2, bin2);

	int diff = bi(bin1, bin2);

	printf("%d\n", diff);
	return 0;
}
