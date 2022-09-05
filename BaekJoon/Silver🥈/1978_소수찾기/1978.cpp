#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		
		if (temp == 1) continue;
		if (temp % 2 == 0) {
			if (temp == 2) cnt++;
			continue;
		}
		int flag = 0;
		for (int j = 3; j * j <= temp; j = j + 2) {
			if (temp % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) cnt++;
	}

	cout << cnt;

	return 0;
}