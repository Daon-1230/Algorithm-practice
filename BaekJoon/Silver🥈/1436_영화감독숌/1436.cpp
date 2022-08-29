#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, cnt = 0, num = 0;
	cin >> N;
	
	//cnt가 N개일 때 반복문 종료
	while (cnt != N) {
		//숫자를 증가시키면서 반복문 진행. 숫자는 문자열로 변환 후 사용
		num++;
		string temp = to_string(num);
		
		//만약 문자열에 666이 존재하면 cnt증가
		if (temp.find("666") != string::npos) cnt++;
	}

	cout << num;

	return 0;
}