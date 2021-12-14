#include<iostream>
#include<string>
using namespace std;


int simple(int nu, int de) {
	if (nu == 0||de == 0)
		return 1;
	else {
		int min;
		if (nu < 0)
			nu = -nu;
		if (de < 0)
			de = -de;

		if (nu >= de)
			min = de;
		else
			min = nu;

		int s = 1;
		for (int i = 2; i <= min; i++) {
			if ((nu%i == 0) && (de%i == 0))
				s = i;
		}
		return s;
	}
}
int common(int d1, int d2) {
	int sign = 1;
	if (d1 < 0 && d2>0) {
		d1 = -d1;
		sign = -1;
	}
	else if (d1 > 0 && d2 < 0) {
		d2 = -d2;
		sign = -1;
	}
	else if (d1 < 0 && d2 < 0) {
		d1 = -d1;
		d2 = -d2;
	}
	else
		sign = 1;

	int s = simple(d1, d2);
	return (d1 / s) * (d2 / s) * s * sign;
}

class Rational {
	int nu;
	int de;

	//1
	friend Rational operator+(Rational& x1, Rational& x2);
	friend Rational operator-(Rational& x1, Rational& x2);
	friend Rational operator*(Rational& x1, Rational& x2);
	friend Rational operator/(Rational& x1, Rational& x2);

	//4
	friend bool operator<(Rational& x1, Rational& x2);
	friend bool operator<=(Rational& x1, Rational& x2);
	friend bool operator>(Rational& x1, Rational& x2);
	friend bool operator>=(Rational& x1, Rational& x2);

	//5
	friend ostream& operator<<(ostream& out, Rational& x);
	friend istream& operator>>(istream& in, Rational& x);


public:

	Rational() {
		nu = 0;
		de = 0;
	}
	Rational(int n, int d) {
		nu = n;
		de = d;
	}

	//2
	Rational operator=(Rational& x) {
		return Rational(x.nu, x.de);
	}
	Rational operator-() {
		int s = simple(nu, de);
		return Rational(-(nu / s), de / s);
	}

	//3
	Rational operator++() {
		nu = nu + de;
		int s = simple(nu, de);
		nu = nu / s;
		de = de / s;
		return Rational(nu, de);
	}
	Rational operator++(int) {
		Rational R(nu, de);
		nu = nu + de;
		int s = simple(nu, de);
		nu = nu / s;
		de = de / s;
		return R;
	}
	Rational operator--() {
		nu = nu - de;
		int s = simple(nu, de);
		nu = nu / s;
		de = de / s;
		return Rational(nu, de);
	}
	Rational operator--(int) {
		Rational R(nu, de);
		nu = nu - de;
		int s = simple(nu, de);
		nu = nu / s;
		de = de / s;
		return R;
	}

	void simplify() {
		int s = simple(nu, de);
		nu = nu / s;
		de = de / s;
		if (de < 0) {
			nu = -nu;
			de = -de;
		}
	}
};

Rational operator+(Rational& x1,Rational& x2) {
	Rational re;
	re.de = common(x1.de, x2.de);
	re.nu = x1.nu * (re.de / x1.de) + x2.nu * (re.de / x2.de);

	re.simplify();
	return re;
}
Rational operator-(Rational& x1, Rational& x2) {
	Rational re;
	re.de = common(x1.de, x2.de);
	re.nu = x1.nu * (re.de / x1.de) - x2.nu * (re.de / x2.de);

	re.simplify();
	return re;

}
Rational operator*(Rational& x1, Rational& x2) {
	
	if (x1.nu == 0 || x2.nu == 0) {
		return Rational(0, 1);
	}
	Rational re;
	int s1 = simple(x1.nu, x2.de);
	int s2 = simple(x1.de, x2.nu);
	re.nu = (x1.nu / s1) * (x2.nu / s2);
	re.de = (x1.de / s2) * (x2.de / s1);

	re.simplify();
	return re;
}
Rational operator/(Rational& x1, Rational& x2) {
	if (x1.nu == 0) {
		return Rational(0, 1);
	}

	Rational re;
	int s1 = simple(x1.nu, x2.nu);
	int s2 = simple(x1.de, x2.de);
	re.nu = (x1.nu / s1) * (x2.de / s2);
	re.de = (x1.de / s2) * (x2.nu / s1);

	re.simplify();
	return re;
}

bool operator<(Rational& x1, Rational& x2) {
	long long n1 = x1.nu * x2.de;
	long long n2 = x2.nu * x1.de;

	if (n1 < n2)
		return true;
	else
		return false;
}
bool operator<=(Rational& x1, Rational& x2) {
	long long n1 = x1.nu * x2.de;
	long long n2 = x2.nu * x1.de;

	if (n1 <= n2)
		return true;
	else
		return false;
}
bool operator>(Rational& x1, Rational& x2) {
	long long n1 = x1.nu * x2.de;
	long long n2 = x2.nu * x1.de;

	if (n1 > n2)
		return true;
	else
		return false;
}
bool operator>=(Rational& x1, Rational& x2) {
	long long n1 = x1.nu * x2.de;
	long long n2 = x2.nu * x1.de;

	if (n1 >= n2)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Rational& x) {
	if (x.de < 0) {
		x.de = -x.de;
		x.nu = -x.nu;
	}

	if (x.de == 1 || x.nu == 0)
		out << x.nu;
	else
		out << x.nu << "/" << x.de;
	return out;
}
istream& operator>>(istream& in, Rational& x) {
	in >> x.nu >> x.de;
	return in;
}



int main() {
	Rational a, b;
	cin >> a >> b;

	a.simplify();
	b.simplify();

	Rational add = a + b;
	Rational sub = a - b;
	Rational mul = a * b;
	Rational div = a / b;
	Rational rev = -a;
	Rational leftadd = ++a;
	Rational leftsub = --a;
	Rational rightadd = a++;
	Rational rightsub = a--;

	cout << add << endl;
	cout << sub << endl;
	cout << mul << endl;
	cout << div << endl;
	cout << rev << endl;
	cout << leftadd << endl;
	cout << leftsub << endl;
	cout << rightadd << endl;
	cout << rightsub << endl;
	if (a < b)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (a <= b)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (a > b)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (a >= b)
		cout << "true";
	else
		cout << "false";
}