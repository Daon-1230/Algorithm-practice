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