#include <iostream>
using namespace std;

int swapNum(char a) {
	if (a == '0') a = '1';
	else if (a == '1')  a = '0';

	return a;
}

int main() {
	int N, result;
	cin >> N;

	string input, output;
	cin >> input;
	cin >> output;

	// ó�� input�� ���� ����Ƚ�� ����� a
	// �ι�° input�� ���� b. �� ó�� index�� �̹� �������� �����̱� ������ 1���� ����
	int a = 0, b = 1;
	// ó�� input�� ���� output�� ������ ���� ã�Ҵ��� �˱� ���� flag1,
	// �ι�° input�� ���� flag2
	int flag1 = 0, flag2 = 0;
	// ��ó�� index���� ���¸� �����Ѵٴ� ������ ������ �˰����̱� ������ �̸� ����� ���̽� �ʿ�
	// ��ó�� index���� ���¸� ������ input�������� ���̽��� ������
	string input2 = input;
	input2[0] = swapNum(input2[0]);
	input2[1] = swapNum(input2[1]);

	// N-1�� �ε������� Ž������ �� ���� �� ������ output�� ���̶� �ٸ��� ���� ���� ����
	for (int i = 1; i < N; i++) {
		if (input[i - 1] != output[i - 1]) {
			input[i - 1] = swapNum(input[i - 1]);
			input[i] = swapNum(input[i]);
			// N-1�� �ε����̸� i+1��° �ε����� ���� ������ �ش����� X
			if (i != N - 1) {
				input[i + 1] = swapNum(input[i + 1]);
			}

			a++;
		}
		// input�̶� output�̶� ������ ��
		if (input == output) {
			flag1 = 1;
			break;
		}
	}

	// input2�� ���(�ι� ���� �˰��� ���Ÿ� ó�� index�� �Է°����� �޴� �Լ��� ����°� �� ������ �� 
	for (int i = 1; i < N; i++) {
		if (input2[i - 1] != output[i - 1]) {
			input2[i - 1] = swapNum(input2[i - 1]);
			input2[i] = swapNum(input2[i]);
			// N-1�� �ε����̸� i+1��° �ε����� ���� ������ �ش����� X
			if (i != N - 1) {
				input2[i + 1] = swapNum(input2[i + 1]);
			}

			b++;
		}
		// input�̶� output�̶� ������ ��
		if (input2 == output) {
			flag2 = 1;
			break;
		}
	}

	// ���� �Ѵ� �������� �ʾ����� -1
	if (flag1 == 0 && flag2 == 0) result = -1;
	// �� �߿� �����ϴ� ��
	else if (flag1 == 0) result = b;
	else if (flag2 == 0) result = a;
	// �� ������
	else if (a > b) result = b;
	else result = a;

	cout << result;

	return 0;
}