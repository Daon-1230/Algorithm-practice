#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int distance;

	if (x > y) {
		distance = y;
	}
	else distance = x;
	
	if (distance > w - x) distance = w - x;
	if (distance > h - y) distance = h - y;

	cout << distance;

	return 0;
}