#include<iostream>
using namespace std;

int arr[100] = {0};
int p = 0;
int cap = 0;

void add(int x);
void remove(int x);
int get(int x);
int getSize();
int getCapacity();

int main() {
	int n,x;
	cin >> n;
	char ins[15] ;                                                                                                                                                                                                                                                                                                                                                                          
	for (int i = 0; i < n; i++) {
		cin >> ins;
		if (ins[0] == 'a') {
			cin >> x;
			add(x);
		}
		else if (ins[0] == 'r') {
			cin >> x;
			remove(x);
		}
		else if (ins[3] == 'C') {
			cout << getCapacity() << endl;
			
		}
		else if (ins[3] == 'S') {
			cout << getSize() << endl;
		}
		else {
			cin >> x;
			cout << get(x) << endl;
		}
			
	}
}

void add(int x) {
	arr[p] = x;
	p++;
	if (p == 1)
		cap = 10;
	else {
		while (p > cap) {
			cap = cap + (cap >> 1);
		}
	}
}
void remove(int x) {
	for (int i = 0; i < p; i++) {
		if (arr[i] == x) {
			for (int j = i; j < p; j++) {
				arr[j] = arr[j + 1];
			}
			p--;
			break;
		}
	}
}
int get(int x) {
	if (x >= p || x < 0)
		return -1;
	else {
		return arr[x];
	}
}
int getSize() {
	return p;
}
int getCapacity() {
	return cap;
}






