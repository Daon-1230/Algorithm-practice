# [🥉Bronze Ⅲ][직사각형에서 탈출](https://www.acmicpc.net/problem/1085)
## 문제
> 한수는 지금(x,y)에 있다. 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0,0), 오른쪽 위 꼭짓점은 (w,h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
## 입력
> 첫째 줄에 x, y, w, h가 주어진다.
## 출력
> 첫째 줄에 문제의 정답을 출력한다.
## 제한
+ 1 ≤ w, h ≤ 1,000
+ 1 ≤ x ≤ w-1
+ 1 ≤ y ≤ h-1
+ x, y, w, h는 정수
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|6 2 10 3| 1 |
|2|1 1 5 5| 1|
|3|653 375 1000 1000| 347|
|4|161 181 762 375|161|

## 분류
+ 수학
+ 기하학

---------
## 풀이
+ x,y좌표가 각각 x,y좌표축과 주어진 w,h값에서 더 가까운 값을 선택

### C++
```C++
#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int distance;

	if (x > y) {
		distance = y;
	}
	else distance = x;
	
	if (distance > w - x) distance = w - x;
	if (distance > h - y) distance = h - y;

	cout << distance;

	return 0;
}
```