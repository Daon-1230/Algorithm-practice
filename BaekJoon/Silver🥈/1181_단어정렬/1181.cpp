#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//���ڱ��� ���ؼ� ���� �� ��ȯ
//���� ���� ���� ���� ���������� ���ڿ��� ������ ��ȯ
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
	//algorithm ���̺귯���� �ִ� �����Լ� 
	sort(input, input + N, comp);

	for (int i = 0; i < N; i++) {
		//�ߺ��� ���� ���x
		if (i > 0 && input[i] == input[i - 1]) continue;
		else cout << input[i] << endl;
	}

	return 0;
}