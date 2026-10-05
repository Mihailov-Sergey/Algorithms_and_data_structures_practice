import std;

int Max(const char* str) {
	int max_count = 0;
	char max = '\0';
	for (int i = 0; str[i] != '\0'; ++i) {
		int count = 0;
		for (int j = 0; str[j] != '\0'; ++j) {
			if (str[i] == str[j]) {
				++count;
				if (count > max_count) {
					max = str[i];
					max_count = count;
				}
			}
		}
	}
	return max_count;
}

//int main() {
//	int n = Max("asfdff");
//	std::cout << n;
//}