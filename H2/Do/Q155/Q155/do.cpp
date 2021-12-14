#include<iostream>
using namespace std;

int main() {
	char c[70];
	char ch;
	int len = 0;
	int n;

	while (cin.get(ch)) {
		if (ch == '\n')
			break;
		c[len] = ch;
		len++;
	}
	if (c[len - 2] == ' ') {
		n = c[len - 1] - '0';
		len = len - 2;
	}
	else {
		n = (c[len - 1] - '0') + (c[len - 2] - '0') * 10;
		len = len - 3;
	}
	//cout << len << endl;
	//cout << n << endl;

	char z[100][100] = { '\0' };
	int i = 0;
	int j = 0;
	int col = 0;
	while (i < len) {

		for (j = 0; j < n; j++) {
			z[j][col] = c[i];
			i++;
			if (i == len)
				break;
		}
		col++;
		if (i == len)
			break;
		
		for (j = j-2; j > 0; j--) {
			z[j][col] = c[i];
			i++;
			col++;
			if (i == len)
				break;
		}
	
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < col; j++) {
			if (z[i][j] != '\0') {
				cout << z[i][j];
				len--;
			}
			if (len == 0)
				break;
			else
				continue;
		}
	}
}