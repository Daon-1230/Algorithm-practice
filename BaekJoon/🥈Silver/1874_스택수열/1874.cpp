#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	//시간을 줄여주기 위한,,
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, input[100000], cnt = 1;
	stack<int> st;
	string result;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];

		//만약 stack에 들어간 수(cnt)가 입력된 값보다 작다면 커질 때까지 계속 입력
		while (cnt <= input[i]) {
			st.push(cnt);
			cnt++;
			result.push_back('+');
		}
		// stack 맨 위의 값이 입력값이랑 같으면 stack에서 빼주고
		if (st.top() == input[i]) {
			st.pop();
			result.push_back('-');
		}
		// 안같으면 불가능한 수열
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.length(); i++) {
		// 와 이거 endl 썼다가 \n쓰니까 바로 시간초과 해결;; 엄청나네
		cout << result[i] << "\n";
	}
	
	return 0;
}