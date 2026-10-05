import std;

bool polindrom(const char* str) {
	int n = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		++n;
	}
	for (int i = 0; i < n / 2; ++i) {
		if (str[i] != str[n - i - 1]) return false;
	}
	return true;
}