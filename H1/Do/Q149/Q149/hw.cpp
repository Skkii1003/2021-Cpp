#include<iostream>
#include<fstream>
#include<string>
using namespace std;



string encode(string str);
int getIndex(string str);
string toBinary(string str);
string chartoBinary(char c);
//F:\gitrepository\C++\H1\Q149\b.txt

int main() {

	string re = "";
	string fname;
	cin >> fname;
	string path = "F:\\gitrepository\\C++\\H1\\Q149\\" + fname;

	ifstream fin(path, ios_base::binary);

	if (!fin.is_open()) {
		cout << "FILE NOT FOUND" << endl;
	}
	else {
		string data = "";
		char c;
		c = fin.get();
		while (c != EOF) {
			data = data + c;
			c = fin.get();
		}

		//cout << data;
		int len = data.length();

		while (len > 0) {
			string str;
			if (len >= 3) {
				str = data.substr(0, 3);
				data = data.substr(3, len - 3);
				str = toBinary(str);
				re = re + encode(str);
				len = len - 3;
			}
			else if (len == 2) {
				str = data.substr(0, 2);
				str = toBinary(str);
				re = re + encode(str);
				len = len - 2;
			}
			else {
				str = data.substr(0, 1);
				str = toBinary(str);
				re = re + encode(str);
				len = len - 1;
			}
		}
		cout << re;
	}
}

string encode(string str) {
	string base[] = { "A","B","C","D","E", "F", "G", "H", "I", "J","K","L","M",
"N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h",
"i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
"0","1","2","3","4","5","6","7","8","9","+","/" };
	int len = str.length();
	string str1;
	string str2;
	string str3;
	string str4;

	int one;
	int two;
	int three;
	int four;

	if (len == 24) {
		str1 = "00" + str.substr(0, 6);
		str2 = "00" + str.substr(6, 6);
		str3 = "00" + str.substr(12, 6);
		str4 = "00" + str.substr(18, 6);
		
		one = getIndex(str1);
		two = getIndex(str2);
		three = getIndex(str3);
		four = getIndex(str4);

		str = base[one] + base[two] + base[three] + base[four];
		return str;
	}
	else if (len == 16) {
		str1 = "00" + str.substr(0, 6);
		str2 = "00" + str.substr(6, 6);
		str3 = "00" + str.substr(12, 4) + "00";
		one = getIndex(str1);
		two = getIndex(str2);
		three = getIndex(str3);

		return base[one] + base[two] + base[three] + "=";
	}
	else {
		str1 = "00" + str.substr(0, 6);
		str2 = "00" + str.substr(6, 2) + "0000";
		one = getIndex(str1);
		two = getIndex(str2);
		return base[one] + base[two] + "==";
	}
}

int getIndex(string str)  {
	int p = 7;
	int re = 0;
	char bit;
	while (p >= 0) {
		bit = str.at(7 - p);
		if (bit == '1')
			re = re + pow(2, p);
		p--;
	}
	return re;
}

string toBinary(string str) {
	int len = str.length();
	int ctl = len;
	string re = "";
	char c;
	while (ctl > 0) {
		c = str.at(len - ctl);
		re = re + chartoBinary(c);
		ctl--;
	}
	return re;
}

string chartoBinary(char c) {
	int x = c;
	int bit;
	string re = "";
	while (x != 0) {
		bit = x % 2;
		re = std::to_string(bit) + re;
		x = x / 2;
	}
	int len = re.length();
	while (len != 8) {
		re = "0" + re;
		len++;
	}
	return re;
}








