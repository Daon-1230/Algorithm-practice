#include <iostream>
#include <cstring>
using namespace std;

int main() {

	while (1) {
		char input[100000];
		cin >> input;
		if (strcmp(input, "0") == 0) break;

		int flag = 0;
		for (int i = 0; i < strlen(input) / 2; i++) {
			if (input[i] != input[strlen(input) - i - 1]) {
				flag = 1;
				break;
			}
		}
		
		if (flag == 1) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}