#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int K, N, ans = 0;
	cin >> K >> N;
	// K개의 길이를 받을 lenK 배열
	int lenK[10000] = { 0 };
	
	// 랜선의 최대 길이, 초기값 0 / 작은 랜선 값 초기값 1
	// largeL의 값이 int 자료형의 최댓값일 때 
	// mid를 계산하는 과정에서 int 범위를 넘어서므로 long long자료형을 사용해야한다.
	long long largeL = 0, smallL = 1, mid;

	for (int i = 0; i < K; i++) {
		cin >> lenK[i];
		if (lenK[i] > largeL) largeL = lenK[i];
	}

	// 이분탐색 이용 
	// 작은 랜선의 길이가 큰 랜선의 길이보다 커질 경우 탐색종료
	while(smallL <= largeL) {
		// 각 길이들에게서 나올 수 있는 랜선의 개수를 저장할 cnt 배열
		int sum = 0;
		// 시작과 끝의 중간값
		mid = abs(largeL + smallL) / 2;

		for (int i = 0; i < K; i++) {
			// 각 K의 길이에서 랜선의 길이를 나눠 나올 수 있는 랜선의 개수를 저장하고 모두 합침
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