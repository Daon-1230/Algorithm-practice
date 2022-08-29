#include <iostream>
using namespace std;

char board[50][50];
int N, M;

int checkPattern(int y, int x) {
	int cntW = 0, cntB = 0;

	for (int i = y; i < 8 + y; i++) {
		for (int j = x; j < 8 + x; j++) {
			if ((i + j) % 2 == 0 && board[i][j] == 'W') {
				cntW++;
			}
			else if ((i + j) % 2 == 1 && board[i][j] == 'B') {
				cntW++;
			}
		}
	}
	
	for (int i = y; i < 8 + y; i++) {
		for (int j = x; j < 8 + x; j++) {
			if ((i + j) % 2 == 0 && board[i][j] == 'B') {
				cntB++;
			}
			else if ((i + j) % 2 == 1 && board[i][j] == 'W') {
				cntB++;
			}
		}
	}

	if (cntW > cntB) return cntB;
	else return cntW;
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	int min = 9999;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int temp = checkPattern(i, j);
			if (min > temp) min = temp;
		}
	}

	cout << min;

	return 0;
}