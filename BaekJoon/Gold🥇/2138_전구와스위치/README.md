# [🥇Gold Ⅴ][전구와 스위치](https://www.acmicpc.net/problem/2138)
## 문제
> N개의 스위치와 N개의 전구가 있다. 각각의 전구는 켜져 있는 상태와 꺼져 있는 상태 중 하나의 상태를 가진다. i(1 < i < N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다. 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.
> 
> N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.
## 입력
> 첫째 줄에 자연수 N(2 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 0은 켜져 있는 상태, 1은 꺼져 있는 상태를 의미한다.
## 출력
> 첫째 줄에 답을 출력한다. 불가능한 경우에는 -1을 출력한다.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|3</br>000</br>010|3|

## 분류
+ 그리디 알고리즘
---------
## 풀이
+ 처음 전구 상태를 swap하고 시작할지 말지를 결정
+ 두개의 for문을 돌려서 원래의 경우와 swap한 경우 모두를 끝까지 탐색
+ output이랑 같을 때 break
+ 만약 탐색이 다 끝나고 output이랑 맞는 케이스가 없다면 -1을 반환(flag 사용)

### C++
```C++
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
```