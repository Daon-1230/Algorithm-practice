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