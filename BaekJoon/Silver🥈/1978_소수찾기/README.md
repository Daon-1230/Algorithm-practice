# [🥈Silver Ⅴ][소수 찾기](https://www.acmicpc.net/problem/1978)
## 문제
> 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
## 입력
> 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
## 출력
> 주어진 수들 중 소수의 개수를 출력한다.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|4</br>1 3 5 7|3|

## 분류
+ 수학
+ 정수론
+ 소수 판정
+ 에라토스테네스의 체
---------
## 풀이
+ [1929](./../1929_소수구하기/README.md)번의 문제와 비슷함
+ 동일하게 에라토스테네스의 체를 사용하여 문제 풀이

### C++
```C++
#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		
		if (temp == 1) continue;
		if (temp % 2 == 0) {
			if (temp == 2) cnt++;
			continue;
		}
		int flag = 0;
		for (int j = 3; j * j <= temp; j = j + 2) {
			if (temp % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) cnt++;
	}

	cout << cnt;

	return 0;
}
```