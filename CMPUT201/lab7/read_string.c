#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *readString() {
    int cap = 256;  //max 256
    int index = 0;  //index
    int ch;  //character
    
    
    char *arr = (char *)malloc(cap);  //size the memory
    
    while (isspace(ch = getchar()) && ch != EOF);  //space or eof end

    if (!arr) return NULL;  //test3 empty file
    
    if (ch == EOF) { //if empty line pass
        free(arr);
        return NULL;
    }

    int quote = (ch == '"');  //direct print line without " "
    if (!quote) {
        arr[index++] = ch;
    }

    while ((ch = getchar()) != EOF) {
        if (quote) {  //read until char meet " return
            if (ch == '"') break;
        } else {  //others meet space return
            if (isspace(ch)) break;
        }

        if (index + 1 >= cap) {  //add memory if it is larger
            char *new = (char *)realloc(arr, cap*2);
            arr = new;
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

