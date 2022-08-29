# [🥈Silver Ⅴ][단어 정렬](https://www.acmicpc.net/problem/1181)
## 문제
> 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
>
> 1. 길이가 짧은 것부터
> 2. 길이가 같으면 사전 순으로
## 입력
> 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.
## 출력
> 조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|13</br>but</br>i</br>wont</br>hesitate</br>no</br>more</br>no</br>more</br>it</br>cannot</br>wait</br>im</br>yours|i</br>im</br>it</br>no</br>but</br>more</br>wait</br>wont</br>yours</br>cannot</br>hesitate|

## 분류
+ 문자열
+ 정렬
---------
## 풀이
+ 문제의 조건대로 comp 함수를 만들어서 `sort`를 사용하여 정렬
+ 처음부터 쭉 출력하면서 중복인 경우는 출력하지 않음

### C++
```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//문자길이 비교해서 작은 값 반환
//문자 길이 같을 때는 사전순으로 문자열이 작은거 반환
bool comp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	} else return a.length() < b.length();
}

int main() {
	int N;
	cin >> N;

	string input[20000];

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	//algorithm 라이브러리에 있는 정렬함수 
	sort(input, input + N, comp);

	for (int i = 0; i < N; i++) {
		//중복된 값은 출력x
		if (i > 0 && input[i] == input[i - 1]) continue;
		else cout << input[i] << endl;
	}

	return 0;
}
```