#include<iostream>
using namespace std;

int main() {
	char c;
	int x1, y1, x2, y2, x3, y3;
	cin >> c >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2 >> c >> c >> x3 >> c >> y3 >> c;

	if (x1 == x2 && x2 == x3) {
		cout << 1;
	}
	else if (x1 == x2 || x1 == x3 || x2 == x3) {
		cout << 0;
	}
	else {
		double k1;
		double k2;

		k1 = (y2 - y1 + 0.0) / (x2 - x1 + 0.0);
		k2 = (y3 - y1 + 0.0) / (x3 - x1 + 0.0);
		
		if (k1 == k2)
			cout << 1;
		else
			cout << 0;
	}
}