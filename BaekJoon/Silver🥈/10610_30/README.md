# [🥈Silver Ⅳ][30](https://www.acmicpc.net/problem/10610)
## 문제
> 어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
> 
> 미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.
## 입력
> N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.
## 출력
> 미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|30|30|
|2|102|210|
|3|2931|-1|
|4|80875542|88755420|

## 분류
+ 수학
+ 문자열
+ 그리디 알고리즘
+ 정렬
+ 정수론

---------
## 풀이
+ 3의 배수는 모든 자릿수를 합하면 3의 배수가 나옴
+ 0이 있는지 체킹 후 모든 자릿수를 합해서 3의 배수인지 확인
+ 만약 3의 배수가 아니라면, 0이 없다면 -1 출력
+ 3의 배수이고 0이 있다면 30의 배수가 존재하므로 `sort`사용하여 정렬 후 출력
+ 자릿수를 확인하기 위해서 입력값을 `string`으로 받음

### C++
```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string N;
	cin >> N;
	
	int sum = 0;
	int flag = 0;
	for (int i = 0; i < N.length(); i++)
	{
		sum += N[i];
		if (N[i] == '0') flag = 1;
	}

	if (sum % 3 != 0 || flag == 0)
	{
		cout << -1; 
		return 0;
	}
	sort(N.begin(), N.end());

	for (int i = N.length() - 1; i >= 0; i--)
	{
		cout << N[i];
	}

	return 0;
}
```