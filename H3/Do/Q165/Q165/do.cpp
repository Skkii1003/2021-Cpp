#include <iostream>
#include <string>
using namespace std;

class myString {
public:
	char head[100];
	myString(char* Head) {
		for (int i = 0; i < 100; i++) {
			head[i] = *(Head + i);
			if (*(Head + i) == '\0')
				break;
		}
	};
	void Reverse();
	void Print();
};
void myString::Reverse() {
	int st = 0;
	int end = 0;
	char tmp;
	while (head[end] != '\0') {
		end++;
	}
	end--;
	int times = (end + 1) / 2;
	for (int i = 0; i < times; i++) {
		tmp = head[st];
		head[st] = head[end];
		head[end] = tmp;
		st++;
		end--;
	}
}

void myString::Print() {
	int i = 0;
	while (head[i] != '\0') {
		cout << head[i];
		i++;
	}
}

int main() {
	string str;
	getline(cin, str);
	str = str + '\0';
	char* head = &str.at(0);

	myString my = myString(head);
	my.Reverse();
	my.Print();
}