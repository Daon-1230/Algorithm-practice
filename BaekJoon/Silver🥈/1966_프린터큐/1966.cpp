#include <iostream>
#include <vector>
using namespace std;

int main() {
	// �׽�Ʈ ���̽� ����
	int T;
	cin >> T;

	// �׽�Ʈ ���̽���ŭ �ݺ�
	for (int i = 0; i < T; i++) {
		// �Է°� ù��
		int N, M;
		cin >> N >> M;

		// �켱������ ���� �迭
		vector<int> arr;

		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}

		// ������ �ε����� �˱� ���� cur
		// �μ� Ƚ���� ���� ���� cnt
		int cur = M, cnt = 0;
		// �켱������ ���缭 �μ��ϴ� ����
		while (1) {
			// �� ���� ��
			int now = arr.front();
			// ���� ���� ������ �� ū ��(�켱����)�� �ִٸ� flag 1�� ��ȯ
			int flag = 0;
			for (int j = 1; j < N - cnt; j++) {
				if (arr[0] < arr[j]) {
					flag = 1;
					break;
				}
			}

			// �� ���� ���� ���� ū �켱�����̸� �׸� ���(�迭���� ����)
			if (flag == 0) {
				// ���Ƚ�� ����
				cnt++;
				// ���� ���� ���� ã�� ���̾����� �ݺ��� ����
				if (cur == 0) break;
				// ���� �� ����
				arr.erase(arr.begin());
				// ������ �ε����� �˱� ����
				cur--;
			}
			else {
				// ���� ���� ���� �� �ڿ� �߰�
				arr.erase(arr.begin());
				arr.push_back(now);
				// ���� ���� ���� ã�� ���̾�����
				// ã���� �ϴ� ���� �ε����� �ٲ����� �ٲ� �ε��� ���� �ο�
				if (cur == 0) {
					cur = N - cnt - 1;
				}
				else {
					cur--;
				}
			}
		}

		cout << cnt << endl;

	}

	return 0;
}