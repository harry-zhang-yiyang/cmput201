#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *readString() {
    int capacity = 256;
    char *arr = (char *)malloc(capacity);
    if (!arr) return NULL;

    int index = 0;
    int ch;

    // 跳过前导空格
    while (isspace(ch = getchar()) && ch != EOF);

    if (ch == EOF) {
        free(arr);
        return NULL;
    }

    int quoted = (ch == '"'); // 判断是否是引号模式
    if (!quoted) {
        arr[index++] = ch; // 不是引号，存入第一个字符
    }

    while ((ch = getchar()) != EOF) {
        if (quoted) {
            if (ch == '"') break; // 遇到第二个引号结束
        } else {
            if (isspace(ch)) break; // 非引号模式，遇到空格结束
        }

        // 扩容
        if (index + 1 >= capacity) {
            capacity *= 2;
            char *newArr = (char *)realloc(arr, capacity);
            if (!newArr) {
                free(arr);
                return NULL;
            }
            arr = newArr;
        }

        arr[index++] = ch;
    }

    arr[index] = '\0';
    return arr;
}

int main() {
    char *p;
    while ((p = readString())) {
        printf("%s\n", p);
        free(p);
    }
    return 0;
}
