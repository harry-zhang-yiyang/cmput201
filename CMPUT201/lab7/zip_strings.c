#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *zipStrings(const char *s1, const char *s2) {
  // Takes two string parameters s1 and s2 of the same length
  // and returns a new heap allocated string that is the result of
  // "zipping" the two strings together.
  // e.g. zipStrings("abc", "xyz") -> "axbycz"

	int lens, len1, len2;
	len1 = strlen(s1);
	len2 = strlen(s2);

	char *result = (char *)malloc((2 * lens + 1) * sizeof(char));

	if (len1 < len2) {
		lens = len1;
	} else {
		lens = len2;
	}
	int i;
	int index = 0;
	for (i = 0; i< lens; i++) {
		if (s1[i] != s2[i]) {
			result[index++] = s1[i];
			result[index++] = s2[i];
		}
	}
	result[index] = '\0';
	return result;
}		

int main() {
  char s1[256];
  char s2[256];
  scanf("%s", &s1);
  scanf("%s", &s2);
  char *p = zipStrings(s1, s2);
  printf("%s\n", p);
  free(p);
}
