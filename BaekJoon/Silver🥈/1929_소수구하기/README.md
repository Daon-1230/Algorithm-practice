# [🥈Silver Ⅲ][소수 구하기](https://www.acmicpc.net/problem/1929)
## 문제
> M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
## 입력
> 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
## 출력
> 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|3 16|3</br>5</br>7</br>11</br>13|

## 분류
+ 수학
+ 정수론
+ 소수 판정
+ 에라토스테네스의 체

---------
## 풀이
+ 에라토스테네스의 체 라는 소수 찾기 알고리즘을 사용
  + M보다 작은 소수를 찾는 거면 그거보다 작은 자연수들 중에서 2의 배수들을 다 없애고 3의 배수, 5의 배수 ... 이런 식으로 루트M 까지의 소수의 배수들을 다 제거함
+ 처음부터 모든 배수들을 탐색하는 방식의 이중 for문은 시간초과나서 안됨ㅜ

### C++
```C++
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
```