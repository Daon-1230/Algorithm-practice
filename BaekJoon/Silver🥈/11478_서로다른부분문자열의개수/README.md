# [🥈Silver Ⅲ][서로 다른 문자열의 개수](https://www.acmicpc.net/problem/11478)
## 문제
> 문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 프로그램을 작성하시오. 
> 
> 부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같아야 한다. 
> 
> 예를 들어, ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.
## 입력
> 첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000 이하이다.
## 출력
> 첫째 줄에 S의 서로 다른 부분 문자열의 개수를 출력한다.
## 예제
| 번호 | 입력값 | 출력값 |
|:---:|:---|:---|
|1|ababc|12|

## 분류
+ 자료구조
+ 문자열
+ 해시를 사용한 집합과 맵
+ 트리를 사용한 집합과 맵

---------
## 풀이
+ `<set>` 라이브러리 사용
    + 기본적으로 오름차순으로 정렬되는 집합
    + 같은 원소는 존재하지 않고 정렬되어 있는 컨테이너
        + 중복 원소를 원하면 Multiset 사용
    + set<자료형> 변수명 
    
+ 처음에 무지성으로 for문을 돌렸으나 시간초과 남😥

### C++
```C++
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> S;

	set<string> _set;

	// 1개부터 길이만큼의 개수로 이뤄진 문자열들
	for (int i = 1; i <= S.length(); i++)
	{
		// 각 길이마다 겹치는 것이 있는지 체크
		for (int j = 0; j <= S.length() - i; j++)
		{
			string temp = S.substr(j, i);
			_set.insert(temp);
			/*
			int sum = 0;
			for (int l = 0; l < i; l++)
			{
				sum += temp[l] - 'a';
			}

			if (!dat[sum])
			{
				dat[sum] = true;
				cnt++;
				continue;
			}

			int flag = 0;
			for (int k = 0; k < j; k++)
			{
				string temp_check = S.substr(k, i);
				if (temp == temp_check)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
			*/
		}
	}

	cout << _set.size();

	return 0;
}
```