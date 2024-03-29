# [🥈Silver Ⅱ][랜선 자르기](https://www.acmicpc.net/problem/1874)
## 문제
> 스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.
> 
> 1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.
## 입력
> 첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.
## 출력
> 입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|8</br>4</br>3</br>6</br>8</br>7</br>5</br>2</br>1|+</br>+</br>+</br>+</br>-</br>-</br>+</br>+</br>-</br>+</br>+</br>-</br>-</br>-</br>-</br>-|
|2|5</br>1</br>2</br>5</br>3</br>4|NO|
## 힌트
> 1부터 n까지에 수에 대해 차례로 [push, push, push, push, pop, pop, push, push, pop, push, push, pop, pop, pop, pop, pop] 연산을 수행하면 수열 [4, 3, 6, 8, 7, 5, 2, 1]을 얻을 수 있다.

## 분류
+ 자료 구조
+ 스택
---------
## 풀이
+ 시간초과를 줄이기 위해 몇개의 구문을 추가해야함
  + `cin.tie(NULL);`
  + `cout.tie(NULL);`
  + `ios::sync_with_stdio(false);`

### C++
```C++
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
```