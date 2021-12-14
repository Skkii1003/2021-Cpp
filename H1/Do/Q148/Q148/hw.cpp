#include<iostream>
#include<string>
using namespace std;

int main() {
	string x;
	int n;
	string re = "";
	cin>>n;
	x = std::to_string(n);
	int len = x.length();

	for (int i = len - 1; i >= 0; i--) {
		if (x.at(i) == '-')
			re = x.at(i) + re;
		else if (x.at(i) == '0')
			continue;
		else
			re = re + x.at(i);
	}
	if (n == 0)
		cout << 0;
	else {
		long long min = pow(-2, 31);
		long long max = pow(2, 31) - 1;
		long long check = std::stoll(re);

		if (check<min || check>max)
			cout << -1;
		else
			cout << check;
	}
	
}