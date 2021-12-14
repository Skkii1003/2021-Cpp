#include<iostream>
using namespace std;


int main() {
	int n, ceta;
	cin >> n >> ceta;
	int mat[100][100];
	int tmp[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	int times = ceta / 90 % 4;
	
	while (times > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[j][n-i-1] = mat[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = tmp[i][j];
			}
		}
		times--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0)
				cout << mat[i][j];
			else
				cout << " " << mat[i][j];
		}
		if (i != n - 1)
			cout << endl;
	}
}