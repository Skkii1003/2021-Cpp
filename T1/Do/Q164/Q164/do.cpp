#include<iostream>
#include<string>
using namespace std;
#define size 10000

string gethead(int space, int status);
int transform(string s);

int main() {
	int size_stack;
	int num_ob;
	cin >> size_stack >> num_ob;
	int rows = size_stack / 4;
	
	int n;
	cin >> n;

	int stack[size][4];
	string head = gethead(size_stack - 8, 0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0 || i == rows - 1) {
				stack[i][j] = std::stoi(head.substr(j*2,2));
			}
			else {
				stack[i][j] = 0xdf;
			}
		}
	}

	string ins;
	int id;
	int size_ob;
	while (n > 0) {
		cin >> ins;
		if (ins == "ALLOC") {
			cin >> id >> size_ob;
			if (size_ob % 8 != 0) {
				size_ob = (size_ob / 8 + 1) * 8;
			}
			for (int i = 0; i < rows; i++) {
				if (stack[i][3] != 0xdf) {
					if (stack[i][3] % 2 != 0)
						continue;
					else {
						int space = stack[i][3] + stack[i][2] * 0x100 + stack[i][1] * 0x10000 + stack[i][0] * 0x1000000;
						if (space < size_ob||id>num_ob)
							cout << "failed to alloc object " << id << endl;
						else {
							cout << "succeeded to alloc object " << id << endl;
							head = gethead(size_ob, 1);
							for (int j = 0; j < 4; j++) {
								stack[i][j] = std::stoi(head.substr(j * 2, 2));
								stack[i + size_ob / 4 + 1][j] = std::stoi(head.substr(j * 2, 2));
							}
							i = i + size_ob / 4 + 2;
							head = gethead(space - size_ob - 8, 0);
							for (int j = 0; j < 4; j++) {
								stack[i][j] = std::stoi(head.substr(j * 2, 2));
								stack[rows - 1][j] = std::stoi(head.substr(j * 2, 2));
							}
						}
						break;
					}
				}
			}
		}
		else if (ins == "FREE") {
			cin >> id;
			int cnt = 0;
			for (int i = 0; i < rows; i++) {
				if (stack[i][3] != 0xdf && stack[i][3] % 2 == 1) {
					cnt++;
					if (cnt == id) {
						stack[i][3] = stack[i][3] - 1;
						cout << "succeeded to free object " << id << endl;
						break;
					}
				}
			}
			if (cnt != id)
				cout << "invalid memory access";
		}
		else {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < 4; j++) {
					if (stack[i][j] != 0xdf) {
						int x1 = stack[i][j] / 16;
						int x2 = stack[i][j] % 16;
						if (x1 < 10 && x2 < 10)
							cout << x1 << x2;
					}
					else
						cout << "df";
				}
				cout << endl;
			}
		}
		n--;
	}
}

string gethead(int space, int status) {
	int n[32] = {0};
	string re = "";
	int x = space;
	for (int i = 31; i >= 0; i--) {
		n[i] = x % 2;
		x = x / 2;
	}
	if (status == 1) {
		n[31] = 1;
	}
	for (int i = 0; i < 4; i++) {
		int p = 1;
		string s = "";
		for (int j = 7; j >= 0; j--) {
			s = std::to_string(n[j + i * 8]) + s;
		}
		re = re + std::to_string(transform(s));
	}
	while (re.length() != 8)
		re = "0" + re;
	return re;
}

int transform(string s) {
	int x = 0;
	int p = 1;
	string re = "";
	for (int i = 7; i >=4; i--) {
		if (s.at(i) == '0') {
			p = p * 2;
		}
		else {
			x = x + p;
			p = p * 2;
		}
	}
	re = std::to_string(x) + re;
	for (int i = 3; i >= 0; i--) {
		if (s.at(i) == '0') {
			p = p * 2;
		}
		else {
			x = x + p;
			p = p * 2;
		}
	}
	re = "0x" + std::to_string(x) + re;
	int z = std::stoi(re);
	return x;
}