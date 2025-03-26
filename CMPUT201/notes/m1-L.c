void parseString() {
	char c = getchar();
	while (c == ' ' || c == '\n') {
		c = getchar();
	}
	if (c = '"') {
		c = getchar();
		while (c != '"') {
			printf("%c", c);
			c = getchar();
		}
	} else {
		printf("%c", c);
		while (c != '\n' && c != ' ') {
			printf("%c", c);
			c = getchar();
	}
}
