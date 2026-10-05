import std;

int count_sym(const char* string, const char a) {
	int count = 0;
	for (int i = 0; string[i] != '\0'; ++i) {
		if (string[i] == a)	++count;
	}
	return count;
}