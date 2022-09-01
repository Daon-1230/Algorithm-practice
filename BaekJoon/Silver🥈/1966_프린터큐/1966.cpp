#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 테스트 케이스 개수
	int T;
	cin >> T;

	// 테스트 케이스만큼 반복
	for (int i = 0; i < T; i++) {
		// 입력값 첫줄
		int N, M;
		cin >> N >> M;

		// 우선순위를 담을 배열
		vector<int> arr;

		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}

		// 원래의 인덱스를 알기 위한 cur
		// 인쇄 횟수를 세기 위한 cnt
		int cur = M, cnt = 0;
		// 우선순위에 맞춰서 인쇄하는 과정
		while (1) {
			// 맨 앞의 값
			int now = arr.front();
			// 만약 앞의 값보다 더 큰 값(우선순위)가 있다면 flag 1을 반환
			int flag = 0;
			for (int j = 1; j < N - cnt; j++) {
				if (arr[0] < arr[j]) {
					flag = 1;
					break;
				}
			}

			// 맨 앞의 값이 가장 큰 우선순위이면 그를 출력(배열에서 제거)
			if (flag == 0) {
				// 출력횟수 증가
				cnt++;
				// 만약 현재 값이 찾는 값이었으면 반복문 종료
				if (cur == 0) break;
				// 현재 값 제거
				arr.erase(arr.begin());
				// 원래의 인덱스를 알기 위함
				cur--;
			}
			else {
				// 현재 값을 제거 맨 뒤에 추가
				arr.erase(arr.begin());
				arr.push_back(now);
				// 만약 현재 값이 찾는 값이었으면
				// 찾고자 하는 값의 인덱스가 바꼈으니 바뀐 인덱스 값을 부여
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