#include<iostream>
using namespace std;

//int transform(char ma[3000], int st, int ed);
int main() {
	int m, n;
	cin >> m >> n;
	//cout << m << n;
	int mat[100][100];
	//char row[3000];
	//char c = cin.get();
	/*for (int i = 0; i < m; i++) {
		int j = 0;
		while (cin.get(c)) {
			if (c == '\n')
				break;
			row[j] = c;
			j++;
		}
		//cout << row;
		int st = 0;
		int ed = 0;
		for (int t = 0; t < n; t++) {
			while (row[ed] != ' '&& ed < j) {
				ed++;
			}
			mat[i][t] = transform(row, st, ed);
			ed++;
			st = ed;
		}
	}*/
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	char c = ' ';
	int st_row = 0;
	int st_col = 0;
	while (true) {
		for (int i = st_col; i < n; i++) {
			if (st_col == 0 && i == 0 && st_row == 0)
				cout << mat[st_row][i];
			else
				cout << c << mat[st_row][i];
		}
		st_row++;
		if (st_row == m)
			break;

		for (int i = st_row ; i < m ; i++) {
			cout << c <<mat[i][n - 1];
		}
		n = n - 1;
		if (st_col == n)
			break;

		for (int i = n - 1; i >= st_col; i--)
			cout << c << mat[m - 1][i];
		m = m - 1;
		if (st_row == m)
			break;

		for (int i = m - 1; i >= st_row; i--)
			cout << c << mat[i][st_col];
		st_col++;
		if (st_col == n)
			break;
		
	}
}
/*
int transform(char ma[3000], int st, int ed) {
	int len = ed - st;
	int re = 0;
	int p = 1;
	while (len > 0) {
		re = re + (ma[ed-1] - '0')*p;
		len--;
		ed--;
		p = p * 10;
	}
	return re;
}
*/