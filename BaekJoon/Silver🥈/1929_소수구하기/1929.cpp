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

	// ��� �ð��ʰ����� �ȵ�
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


	// '�����佺�׳׽��� ü' ��� �Ҽ� ã�� �˰���
	// M���� ���� �Ҽ���� ã�°Ÿ�
	// �װź��� ���� �ڿ����� �߿��� 2�� ������� �� ���ְ�
	// 3�� ���, 5�� ���... �̷������� ��ƮM������ �Ҽ��� ������� �� ������
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