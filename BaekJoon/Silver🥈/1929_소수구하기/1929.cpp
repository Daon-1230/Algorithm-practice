#include <iostream>
#include <cmath>
using namespace std;

bool prime[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	// 얘는 시간초과나서 안됨
	/*for (int i = M; i <= N; i++) {
		int flag = 0;
		if (i % 2 == 0) continue;
		int a = sqrt(i);
		for (int j = 3; j <= a; j = j + 2) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) printf("%d\n", i);
	}*/


	// '에라토스테네스의 체' 라는 소수 찾기 알고리즘
	// M보다 작은 소수라고 찾는거면
	// 그거보다 작은 자연수들 중에서 2의 배수들을 다 없애고
	// 3의 배수, 5의 배수... 이런식으로 루트M까지의 소수의 배수들을 다 제거함
	for (int i = 2; i < 1000000; i++) {
		prime[i] = true;
	}
	prime[1] = false;

	for (int i = 2; i <= sqrt(N); i++) {
		if (prime[i] == true) {
			for (int j = 2 * i; j <= N; j += i) {
				prime[j] = false;
			}
		}
	}
	
	for (int i = M; i <= N; i++) {
		if (prime[i]) cout << i << "\n";
	}

	return 0;
}