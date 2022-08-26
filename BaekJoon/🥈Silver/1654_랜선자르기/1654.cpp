#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int K, N, ans = 0;
	cin >> K >> N;
	// K���� ���̸� ���� lenK �迭
	int lenK[10000] = { 0 };
	
	// ������ �ִ� ����, �ʱⰪ 0 / ���� ���� �� �ʱⰪ 1
	// largeL�� ���� int �ڷ����� �ִ��� �� 
	// mid�� ����ϴ� �������� int ������ �Ѿ�Ƿ� long long�ڷ����� ����ؾ��Ѵ�.
	long long largeL = 0, smallL = 1, mid;

	for (int i = 0; i < K; i++) {
		cin >> lenK[i];
		if (lenK[i] > largeL) largeL = lenK[i];
	}

	// �̺�Ž�� �̿� 
	// ���� ������ ���̰� ū ������ ���̺��� Ŀ�� ��� Ž������
	while(smallL <= largeL) {
		// �� ���̵鿡�Լ� ���� �� �ִ� ������ ������ ������ cnt �迭
		int sum = 0;
		// ���۰� ���� �߰���
		mid = abs(largeL + smallL) / 2;

		for (int i = 0; i < K; i++) {
			// �� K�� ���̿��� ������ ���̸� ���� ���� �� �ִ� ������ ������ �����ϰ� ��� ��ħ
			sum += lenK[i] / mid;
		}

		if (sum < N) largeL = mid - 1;
		else {
			smallL = mid + 1;
			if (ans < mid) ans = mid;
		}
	}
	
	cout << ans;

	return 0;
}