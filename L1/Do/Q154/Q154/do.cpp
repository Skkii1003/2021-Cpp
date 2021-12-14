#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool isTan(int tan[3][2]);
bool isIn(int x, int y,int tan[3][2]);
bool isSide(int x, int y, int tan[3][2]);

int main() {
	int tan[3][2];
	int n;

	cin >> tan[0][0] >> tan[0][1] >>tan[1][0] >> tan[1][1] >> tan[2][0] >> tan[2][1];
	cin >> n;

	if (!isTan(tan))
		cout << -1;
	else {
		//cout << "go on";
		int x, y;
		int in = 0;
		int side = 0;
		int out = 0;

		while (n > 0) {
			cin >> x >> y;
			if (isSide(x, y,tan))
				side++;
			else if (isIn(x, y,tan))
				in++;
			else
				out++;
			n--;
		}
		string c = " ";
		cout << in << c << side << c << out;
	}
}

bool isTan(int tan[3][2]) {
	int x1 = tan[1][0] - tan[0][0];
	int y1 = tan[1][1] - tan[0][1];
	int x2 = tan[2][0] - tan[0][0]; 
	int y2 = tan[2][1] - tan[0][1];

	int re = x1 * y2 - x2 * y1;
	if (re == 0)
		return false;
	else
		return true;
}

bool isSide(int x, int y, int tan[3][2]) {
	int x1, y1, x2, y2;
	int re;

	x1 = tan[1][0] - tan[0][0];
	y1 = tan[1][1] - tan[0][1];
	x2 = x - tan[0][0];
	y2 = y - tan[0][1];
	re = x1 * y2 - x2 * y1;
	if (re == 0) {
		if ((x <= tan[0][0] && x >= tan[1][0]) || (x <= tan[1][0] && x >= tan[0][0])) {
			if ((y <= tan[0][1] && y >= tan[1][1]) || (y <= tan[1][1] && y >= tan[0][1]))
				return true;
		}
	}

	x1 = tan[2][0] - tan[1][0];
	y1 = tan[2][1] - tan[1][1];
	x2 = x - tan[1][0];
	y2 = y - tan[1][1];
	re = x1 * y2 - x2 * y1;
	if (re == 0) {
		if ((x <= tan[2][0] && x >= tan[1][0]) || (x <= tan[1][0] && x >= tan[2][0])) {
			if ((y <= tan[2][1] && y >= tan[1][1]) || (y <= tan[1][1] && y >= tan[2][1]))
				return true;
		}
	}


	x1 = tan[0][0] - tan[2][0];
	y1 = tan[0][1] - tan[2][1];
	x2 = x - tan[2][0];
	y2 = y - tan[2][1];
	re = x1 * y2 - x2 * y1;
	if (re == 0) {
		if ((x <= tan[0][0] && x >= tan[2][0]) || (x <= tan[2][0] && x >= tan[0][0])) {
			if ((y <= tan[0][1] && y >= tan[2][1]) || (y <= tan[2][1] && y >= tan[0][1]))
				return true;
		}
	}
	return false;
}

bool isIn(int x, int y, int tan[3][2]) {
	int x1, y1, x2, y2;
	int side = 0;
	int re;

	x1 = tan[1][0] - tan[0][0];
	y1 = tan[1][1] - tan[0][1];
	x2 = x - tan[0][0];
	y2 = y - tan[0][1];
	re = x1 * y2 - x2 * y1;
	if (re > 0)
		side++;
	else
		side--;

	x1 = tan[2][0] - tan[1][0];
	y1 = tan[2][1] - tan[1][1];
	x2 = x - tan[1][0];
	y2 = y - tan[1][1];
	re = x1 * y2 - x2 * y1;
	if (re > 0)
		side++;
	else
		side--;

	x1 = tan[0][0] - tan[2][0];
	y1 = tan[0][1] - tan[2][1];
	x2 = x - tan[2][0];
	y2 = y - tan[2][1];
	re = x1 * y2 - x2 * y1;
	if (re > 0)
		side++;
	else
		side--;

	if (side == 3 || side == -3)
		return true;
	else
		return false;
}

