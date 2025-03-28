#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    
    int current = atoi(argv[1]);
    char input[100];
    int count = 0;
    char ops[100][4];
    int vals[100];

    while (scanf("%s", input) != EOF) {
        if (strcmp(input, "n") == 0) {
            // 在 main 里面直接做 apply 操作
            for (int i = 0; i < count; i++) {
                if (strcmp(ops[i], "add") == 0) {
                    current += vals[i];
                } else if (strcmp(ops[i], "sub") == 0) {
                    current -= vals[i];
                } else if (strcmp(ops[i], "mul") == 0) {
                    current *= vals[i];
                } else if (strcmp(ops[i], "div") == 0) {
                    current /= vals[i];
                }
            }
            printf("%d\n", current);
        } else {
            if (count >= 100) {
                printf("Error\n");
                return 1;
            }

            strcpy(ops[count], input);
            int val;
            if (scanf("%d", &val) != 1) {
                printf("Error\n");
                return 1;
            }
            vals[count] = val;
            count++;
        }
    }

    return 0;
}
