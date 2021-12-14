#include<iostream>
using namespace std;
#define size 10000

char re[size] = {'\0'};


void add(char n1[size], char n2[size]);
void sub(char n1[size], char n2[size]);

//void add8(char n1[size], char n2[size]);

int main() {
	char n1[size] = {'\0'};
	char n2[size] = {'\0'};
	char op;
	cin >> n1 >> op >> n2;
	if (op == '+') {
		if (n1[0] == '-' && n2[0] != '-') {
			for (int i = 0; i < size-1; i++) {
				n1[i] = n1[i + 1];
				if (n1[i] == '\0'&&n1[i + 1] == '\0')
					break;
			}
			sub(n2, n1);
		}
		else if (n2[0] == '-' && n1[0] != '-') {
			for (int i = 0; i < size-1; i++) {
				n2[i] = n2[i + 1];
				if (n2[i] == '\0' && n2[i + 1] == '\0')
					break;
			}
			sub(n1, n2);
		}
		else 
			add(n1, n2);
	}
	else {
		if (n1[0] == '-' && n2[0] != '-') {
			for (int i = size-1; i > 0; i--) {
				n2[i] = n2[i - 1];
			}
			n2[0] = '-';
			add(n1, n2);
		}
		else if (n2[0] == '-' && n1[0] != '-') {
			for (int i = 0; i < size-1; i++) {
				n2[i] = n2[i + 1];
				if (n2[i] == '\0' && n2[i + 1] == '\0')
					break;
			}
			add(n1, n2);
		}
		else if (n1[0] == '-' && n2[0] == '-') {
			for (int i = 0; i < size-1; i++) {
				n2[i] = n2[i + 1];
				n1[i] = n1[i + 1];
				if (n1[i+1] == '\0' && n2[i + 1] == '\0')
					break;
			}
			sub(n2, n1);
		}
		else
			sub(n1, n2);
	}	

	//remove 0
	for (int i = 0; i < size; i++) {
		if (re[i] == '-')
			continue;
		else if (re[i] != '0' && re[i] != '\0') {
			break;
		}
		else if (i == size-1)
			continue;
		else
			re[i] = '\0';
	}

	//output
	for (int i = 0; i < size; i++) {
		if (re[size - 2] == '-'&&re[size - 1] == '0') {
			cout << 0;
			break;
		}
		else if (re[i] != '\0')
			cout << re[i];
		else
			continue;
	}
}

void add(char n1[size], char n2[size]) {
	int go = 0;
	int b1;
	int b2;
	int st1 = 0;
	int st2 = 0;
	char sign;
	if (n1[0] == '-') {
		sign = '-';
		for (int i = 0; i < size-1; i++) {
			n1[i] = n1[i + 1];
			n2[i] = n2[i + 1];
			if (n1[i + 1] == '\0'&&n2[i + 1] == '\0')
				break;
		}
	}
	else
		sign = '+';


	while (n1[st1] != '\0')
		st1++;
	st1--;

	while (n2[st2] != '\0')
		st2++;
	st2--;

	for (int i = 0; i < size; i++) {
		if (st1 >= i && st2 >= i) {
			b1 = n1[st1 - i] - '0';
			b2 = n2[st2 - i] - '0';
			
		}
		else if (st1 >= i && st2 < i) {
			b1 = n1[st1 - i] - '0';
			b2 = 0;
		}
		else if (st2 >= i && st1 < i) {
			b1 = 0;
			b2 = n2[st2 - i] - '0';
		}
		else {
			if (go == 1)
				re[size - 1 - i] = go + 48;
			break;
		}
		re[size -1 - i] = ((b1 + b2 + go) % 10) + 48;
		go = (b1 + b2 + go) / 10;
	}
	if (sign == '-') {
		for (int i = 0; i < size; i++) {
			if (re[i] == '\0')
				continue;
			else if (re[i] == '0' && i != size-1)
				continue;
			else {
				re[i - 1] = '-';
				break;
			}
		}
	}
}

void sub(char n1[size], char n2[size]) {
	int st1 = 0;
	int st2 = 0;
	int bo = 0;
	int b1;
	int b2;
	int b;
	char sign = '+';

	while (n1[st1] != '\0')
		st1++;
	st1--;

	while (n2[st2] != '\0')
		st2++;
	st2--;

	if (st1 > st2)
		sign = '+';
	else if (st1 < st2)
		sign = '-';
	else {
		for (int i = 0; i < size; i++) {
			if (n1[i] > n2[i]) {
				sign = '+';
				break;
			}
			else if (n1[i] < n2[i]) {
				sign = '-';
				break;
			}
			else
				continue;
		}
	}


	for (int i = 0; i < size; i++) {
		if (st1 >= i && st2 >= i) {
			b1 = n1[st1 - i] - '0';
			b2 = n2[st2 - i] - '0';
		}
		else if (st1 >= i && st2 < i) {
			b1 = n1[st1 - i] - '0';
			b2 = 0;
		}
		else if (st1 < i && st2 >= i) {
			b1 = 0;
			b2 = n2[st2 - i] - '0';
		}
		else {
			b1 = 0;
			b2 = 0;
		}
		if (sign == '+')
			b = b1 - b2 - bo;
		else
			b = b2 - b1 - bo;

		if (b < 0) {
			b = b + 10;
			bo = 1;
		}
		else {
			bo = 0;
		}

		if (i > st1 && i > st2)
			break;

		re[size - 1 - i] = b + 48;
		
	}
	if (sign == '-') {
		for (int i = 0; i < size; i++) {
			if (re[i] == '\0')
				continue;
			else if (re[i] == '0'&&i != size - 1)
				continue;
			else {
				re[i - 1] = '-';
				break;
			}
		}
	}
}

/*
void add8(char n1[size], char n2[size]) {

	char sign;
	if (n1[0] == '-') {
		sign = '-';
		for (int i = 0; i < size - 1; i++) {
			n1[i] = n1[i + 1];
			n2[i] = n2[i + 1];
		}
	}
	else
		sign = '+';

	int st1 = 0;
	int st2 = 0;
	while (n1[st1] != '\0')
		st1++;
	while (n2[st2] != '\0')
		st2++;
	st1--;
	st2--;

	char p1[8] = { '\0' };
	char p2[8] = { '\0' };
	int i1;
	int i2;
	int go;
	int len;
	int is8 = 0;

	if (st1 > st2)
		len = st1;
	else if (st1 < st2)
		len = st2;
	else
		len = st1;
	
	for (int i = 0; i < len; i++){
		if (st1 >= i && st2 >= i) {

		}
	}
}
*/