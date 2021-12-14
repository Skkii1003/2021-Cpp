#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class food {
public:
	int rank = 0;
	double ch = 13.3;
	double pt = 13.5;
	double df = 3.3;
	double fat = 10.3;

	virtual double get_ch(){ return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class rice : public food {
public:
	int rank = 1;
	double ch = 16.2;
	double pt = 3.7;
	double df = 0;
	double fat = 0;
	virtual double get_ch() { return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class beef : public food {
public:
	int rank = 2;
	double ch = 1.8;
	double pt = 17.5;
	double df = 0;
	double fat = 7.2;
	virtual double get_ch() { return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class bro : public food {
public:
	int rank = 3;
	double ch = 0.2;
	double pt = 0.4;
	double df = 3.6;
	double fat = 0;
	virtual double get_ch() { return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class oat : public food {
public:
	int rank = 4;
	double ch = 12.3;
	double pt = 5.7;
	double df = 7.3;
	double fat = 3;
	virtual double get_ch() { return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class duck : public food {
public:
	int rank = 5;
	double ch = 6.9;
	double pt = 9;
	double df = 0;
	double fat = 9.3;
	virtual double get_ch() { return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class cab : public food {
public:
	int rank = 6;
	double ch = 2.1;
	double pt = 0.8;
	double df = 4.3;
	double fat = 0;
	virtual double get_ch() { return ch; }
	virtual double get_pt() { return pt; }
	virtual double get_df() { return df; }
	virtual double get_fat() { return fat; }
};

class diet {
public:
	vector<food*> list;

	void operator +=(food* f) {
		list.push_back(f);
	}

	void if_healthy() {
		food f;
		double sum_ch = 0.0;
		double sum_pt = 0.0;
		double sum_df = 0.0;
		double sum_fat = 0.0;

		int size = list.size();

		for (int i = 0; i < size; i++) {
			sum_ch += list[i]->get_ch();
			sum_pt += list[i]->get_pt();
			sum_df += list[i]->get_df();
			sum_fat += list[i]->get_fat();
		}
		if (sum_ch >= f.get_ch() && sum_pt >= f.get_pt() && sum_ch >= f.get_df() && sum_fat <= f.get_fat())
			cout << "healthy";
		else
			cout << "unhealthy";
	}
};

int main() {
	string input;
	getline(cin, input);
	stringstream ss(input);
	int i;
	diet d;
	food* f;

	while (ss >> i) {
		if (i < 1 || i > 6) {
			cout << -1;
			return 0;
		}

		switch (i) {
		case 1:
			f = new rice();
			d += f;
			break;
		case 2:
			f = new beef();
			d += f;
			break;
		case 3:
			f = new bro();
			d += f;
			break;
		case 4:
			f = new oat();
			d += f;
			break;
		case 5:
			f = new duck();
			d += f;
			break;
		case 6:
			f = new cab();
			d += f;
			break;
		}
	}
	d.if_healthy();
}