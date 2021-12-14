#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "class.h"

using namespace std;



vector<server> ser;
vector<request> re;

void print() {
	int size = re.size();
	for (int i = 0; i < size; i++) {
		cout << re[i].tag << " " << re[i].seid;

		if (i != size - 1)
			cout << endl;
	}
}

void st1(int n,int m) {
	int s = 1;
	for (int i = 0; i < m; i++) {
		if (s > n)
			s = 1;
		re[i].seid = ser[s - 1].id;
		s++;
	}
}

void st2(int n, int m) {
	int s = 1;
	int a = 1;

	for (int i = 0; i < m; i++) {
		if (s > n) {
			s = n - 1;
			a = -1;
		}
		if (s < 1) {
			s = 2;
			a = 1;
		}
		re[i].seid = ser[s - 1].id;
		s = s + a;
	}
}

void st3(int n, int m) {
	int odd = 1;
	int oven = 2;

	for (int i = 0; i < m; i++) {
		if (odd <= n) {
			re[i].seid = ser[odd - 1].id;
			odd += 2;
		}
		else if (oven <= n) {
			re[i].seid = ser[oven - 1].id;
			oven += 2;
		}
		else {
			odd = 1;
			oven = 2;
			i--;
		}
	}
}

bool cmp(server s1, server s2) {
	if (s1.prior != s2.prior)
		return s1.prior > s2.prior;
	else
		return s1.id < s2.id;
}

void st4(int n, int m) {
	//sort(ser.begin(), ser.end(), cmp);
	int s = 0;

	for (int i = 0; i < m; i++) {
		if (ser[s].times < ser[s].prior) {
			re[i].seid = ser[s].id;
			ser[s].times++;
		}
		if (ser[s].times == ser[s].prior) {
			ser[s].times = 0;
			s++;
		}
		if (s == n)
			s = 0;
	}
}



int main() {
	int m, n, s;

	cin >> m >> n >> s;
	getchar();

	for (int i = 1; i <= n; i++) {
		ser.push_back(server(i));
	}
	if (s == 4) {
		for (int i = 0; i < n; i++) {
			cin >> ser[i].prior;
		}
		getchar();
	}

	string tag;
	for (int i = 0; i < m; i++) {
		getline(cin, tag);
		re.push_back(request(tag));
	}

	if (s == 1)
		st1(n, m);
	else if (s == 2)
		st2(n, m);
	else if (s == 3)
		st3(n, m);
	else
		st4(n, m);

	print();

}

/*
4 3 2
a
b
c
d




*/