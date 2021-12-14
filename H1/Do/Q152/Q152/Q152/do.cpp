#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string input;
	getline(cin, input);
	istringstream is(input);
	string s;
	int re = 0;
	int tmp;
	while (is >> s) {
		tmp = std::stoi(s);
		re = re xor tmp;
	}
	cout << re;
}