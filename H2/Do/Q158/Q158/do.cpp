#include<iostream>
using namespace std;


bool check9(char mat[9][9], int st_row, int st_col);
int main() {
	char mat[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
		}
	}
	
	int tmp;
	for (int i = 0; i < 9; i++) {
		int sign[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (mat[i][j] == '.')
				continue;
			tmp = mat[i][j] - '0';
			if (sign[tmp - 1] == 0)
				sign[tmp - 1] = 1;
			else {
				cout << "false";
				return 0;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		int sign[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (mat[j][i] == '.')
				continue;
			tmp = mat[j][i] - '0';
			if (sign[tmp - 1] == 0)
				sign[tmp - 1] = 1;
			else {
				cout << "false";
				return 0;
			}
		}
	}

	for (int i = 0; i < 9; i = i + 3) {
		for (int j = 0; j < 9; j += 3) {
			if (!check9(mat, i, j)) {
				cout << "false";
				return 0;
			}
		}
	}
	cout << "true";
}



bool check9(char mat[9][9], int st_row, int st_col) {
	int tmp;
	int sign[9] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mat[st_row + i][st_col + j] == '.')
				continue;

			tmp = mat[st_row + i][st_col + j] - '0';
			if (sign[tmp - 1] == 0)
				sign[tmp - 1] = 1;
			else
				return false;
		}
	}
	return true;
}