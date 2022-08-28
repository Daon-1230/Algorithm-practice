#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	//�ð��� �ٿ��ֱ� ����,,
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, input[100000], cnt = 1;
	stack<int> st;
	string result;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];

		//���� stack�� �� ��(cnt)�� �Էµ� ������ �۴ٸ� Ŀ�� ������ ��� �Է�
		while (cnt <= input[i]) {
			st.push(cnt);
			cnt++;
			result.push_back('+');
		}
		// stack �� ���� ���� �Է°��̶� ������ stack���� ���ְ�
		if (st.top() == input[i]) {
			st.pop();
			result.push_back('-');
		}
		// �Ȱ����� �Ұ����� ����
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.length(); i++) {
		// �� �̰� endl ��ٰ� \n���ϱ� �ٷ� �ð��ʰ� �ذ�;; ��û����
		cout << result[i] << "\n";
	}
	
	return 0;
}