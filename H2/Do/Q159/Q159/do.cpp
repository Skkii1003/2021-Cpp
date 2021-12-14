#include<iostream>
using namespace std;

struct T {
	char name[10] = {'\0'};
	int time;
	int amt;
	char city[10] = {'\0'};
};

bool same(char x[10], char y[10]);

int main() {
	int n;
	cin >> n;
	T t[100];
	T invalid[100];
	int j = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i].name >> t[i].time >> t[i].amt >> t[i].city;
	}

	for (int i = 0; i < n; i++) {
		if (t[i].amt > 1000) {
			invalid[j] = t[i];
			j++;
		}
		else {
			for (int x = 0; x < n; x++) {
				if (same(t[x].name ,t[i].name)&&!same(t[x].city ,t[i].city)) {
					int diff = abs(t[x].time - t[i].time);
					if (diff <= 60) {
						invalid[j] = t[i];
						j++;
						break;
					}
				}
			}
		}
	}
	if (j == 0)
		cout << "[]";
	else {
		char c = ',';
		cout << "[";
		for (int i = 0; i < j; i++) {
			if (i == 0)
				cout << "\"" << invalid[i].name << c << invalid[i].time << c << invalid[i].amt << c << invalid[i].city << "\"";
			else
				cout << c << "\"" << invalid[i].name << c << invalid[i].time << c << invalid[i].amt << c << invalid[i].city << "\"";
		}
		cout << "]";
	}
}

bool same(char x[10], char y[10]) {
	for (int i = 0; i < 10; i++) {
		if (x[i] == y[i])
			continue;
		else
			return false;
	}
	return true;
}