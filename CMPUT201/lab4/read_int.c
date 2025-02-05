#include <stdio.h>

int readint() {
  /*
   * This function takes no parameters, reads in an integer
   * from the stdin stream (using the getchar function),
   * and returns that integer. This should skip over any leading
   * whitespace, and then stop reading the integer the first
   * time a non-digit character is read.
   */
    int num = 0;
        char c;

        // pass space
        while ((c = getchar()) == ' ');

        // read int
        while (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            c = getchar();
        }
        return num;
}

int main() {
  // This program reads one integer from the standard input stream
  // and prints out that integer multiplied by 3!
  int x = readint();
  printf("%d\n", x*3);
}
