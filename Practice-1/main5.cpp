import std;

int len_max(const char* text) {
	int count = 0;
	int max_len = 0;
	for (int i = 0; text[i] != '\0'; ++i) {
		if (text[i] == ' ') {
			if (max_len < count) {
				max_len = count;
				count = 0;
			}
			continue;
		}
		++count;
	}
	return max_len;
}

int main() {
	int n = len_max("fhd   ka sd");
	std::cout << n;
}