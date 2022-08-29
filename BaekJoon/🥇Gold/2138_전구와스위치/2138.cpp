#include <iostream>
using namespace std;

int swapNum(char a) {
	if (a == '0') a = '1';
	else if (a == '1')  a = '0';

	return a;
}

int main() {
	int N, result;
	cin >> N;

	string input, output;
	cin >> input;
	cin >> output;

	// 처음 input에 대해 스왑횟수 계산할 a
	// 두번째 input에 대한 b. 맨 처음 index를 이미 스왑해준 상태이기 때문에 1부터 시작
	int a = 0, b = 1;
	// 처음 input에 대해 output과 동일한 값을 찾았는지 알기 위한 flag1,
	// 두번째 input에 대한 flag2
	int flag1 = 0, flag2 = 0;
	// 맨처음 index에서 상태를 스왑한다는 가정을 배제한 알고리즘이기 때문에 이를 고려한 케이스 필요
	// 맨처음 index에서 상태를 스왑한 input데이터의 케이스도 돌려줌
	string input2 = input;
	input2[0] = swapNum(input2[0]);
	input2[1] = swapNum(input2[1]);

	// N-1번 인덱스까지 탐색했을 때 만약 그 전값이 output의 값이랑 다르면 전구 상태 스왑
	for (int i = 1; i < N; i++) {
		if (input[i - 1] != output[i - 1]) {
			input[i - 1] = swapNum(input[i - 1]);
			input[i] = swapNum(input[i]);
			// N-1번 인덱스이면 i+1번째 인덱스가 없기 때문에 해당하지 X
			if (i != N - 1) {
				input[i + 1] = swapNum(input[i + 1]);
			}

			a++;
		}
		// input이랑 output이랑 같으면 끗
		if (input == output) {
			flag1 = 1;
			break;
		}
	}

	// input2의 경우(두번 같은 알고리즘 쓸거면 처음 index를 입력값으로 받는 함수를 만드는게 더 나았을 듯 
	for (int i = 1; i < N; i++) {
		if (input2[i - 1] != output[i - 1]) {
			input2[i - 1] = swapNum(input2[i - 1]);
			input2[i] = swapNum(input2[i]);
			// N-1번 인덱스이면 i+1번째 인덱스가 없기 때문에 해당하지 X
			if (i != N - 1) {
				input2[i + 1] = swapNum(input2[i + 1]);
			}

			b++;
		}
		// input이랑 output이랑 같으면 끗
		if (input2 == output) {
			flag2 = 1;
			break;
		}
	}

	// 만약 둘다 존재하지 않았으면 -1
	if (flag1 == 0 && flag2 == 0) result = -1;
	// 둘 중에 존재하는 값
	else if (flag1 == 0) result = b;
	else if (flag2 == 0) result = a;
	// 더 작은값
	else if (a > b) result = b;
	else result = a;

	cout << result;

	return 0;
}