#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, cnt = 0, num = 0;
	cin >> N;
	
	//cnt�� N���� �� �ݺ��� ����
	while (cnt != N) {
		//���ڸ� ������Ű�鼭 �ݺ��� ����. ���ڴ� ���ڿ��� ��ȯ �� ���
		num++;
		string temp = to_string(num);
		
		//���� ���ڿ��� 666�� �����ϸ� cnt����
		if (temp.find("666") != string::npos) cnt++;
	}

	cout << num;

	return 0;
}