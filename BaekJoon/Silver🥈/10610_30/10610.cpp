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