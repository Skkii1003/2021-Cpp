#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

template<class T>
class list {
public:
	int end = 0;
	T l[500];

	void reverse();
	void Sort();
	void binary(T n);

};

template<class T>
void list<T>::reverse() {
	for (int i = end - 1; i >= 0; i--) {
		if (i != end - 1)
			cout << " ";
		cout << l[i];
	}
	cout << endl;
}
template<class T>
void list<T>::Sort() {
	sort(l, l + end);

	for (int i = 0; i < end; i++) {
		if (i != 0)
			cout << " ";
		cout << l[i];
	}
	cout << endl;
}

template<class T>
void list<T>::binary(T n) {
	int st = 0;
	int ed = end - 1;
	int mid = st + (ed - st) / 2;
	int times = 0;

	while (st <= ed) {
		if (n < l[mid]) {
			ed = mid - 1;
			mid = st + (ed - st) / 2;
			times++;
		}
		else if (n > l[mid]) {
			st = mid + 1;
			mid = st + (ed - st) / 2;
			times++;
		}
		else {
			times++;
			break;
		}
	}
	cout << times;
}


int main() {
	int n;
	char type;

	cin >> n >> type;
	getchar();
	string input;
	getline(cin, input);
	stringstream ss(input);

	if (type == 'i') {
		list<int> li;
		li.end = n;
		for (int i = 0; i < n; i++) {
			ss >> li.l[i];
		}
		li.reverse();
		li.Sort();
		int find;
		cin >> find;
		li.binary(find);
	}
	else if (type == 'd') {
		list<double> li;
		li.end = n;
		for (int i = 0; i < n; i++) {
			ss >> li.l[i];
		}
		li.reverse();
		li.Sort();
		double find;
		cin >> find;
		li.binary(find);
	}
	else {
		list<char> li;
		li.end = n;
		for (int i = 0; i < n; i++) {
			ss >> li.l[i];
		}
		li.reverse();
		li.Sort();
		char find;
		cin >> find;
		li.binary(find);
	}


}