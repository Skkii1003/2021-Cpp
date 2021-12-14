#include<iostream>
#include<string>
using namespace std;

int main() {
	char c;
	int nums = 0;
	int rows = 0;
	int words = 0;
	string text = "";
	while (cin.get(c)) {
		if (c == EOF)
			break;
		else {
			nums++;
			text = text + c;
			if (c == '\n')
				rows++;
		}
	}
	int len = text.length();

	for (int i = 0; i < len; i++) {
		c = text.at(i);
		if ((c == ' ' || c == '\n') && i != 0) {
			if (text.at(i - 1) != ' ' && text.at(i - 1) != '\n')
				words++;
		}
	}

	cout << nums << " " << words << " " << rows;

}