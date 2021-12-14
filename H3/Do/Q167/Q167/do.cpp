#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Operation {
	double a;
	double b;
public:
	virtual double GetResult() = 0;
	double getA();
	double getB();
	virtual void setA(double x);
	virtual void setB(double x);
};

double Operation::getA() {
	return a;
}
double Operation::getB() {
	return b;
}
void Operation::setA(double x) {
	a = x;
}
void Operation::setB(double x) {
	b = x;
}

class OperationAdd : public Operation {
public:
	virtual double GetResult() {
		double a = getA();
		double b = getB();
		return a + b;
	}
};

class OperationSub : public Operation {
public:
	virtual double GetResult() {
		double a = getA();
		double b = getB();
		return a - b;
	}
};

class OperationMul : public Operation {
public:
	virtual double GetResult() {
		double a = getA();
		double b = getB();
		return a * b;
	}
};

class OperationDiv : public Operation {
public:
	virtual double GetResult() {
		double a = getA();
		double b = getB();
		if (b == 0.0)
			return -1.0;
		else
			return a / b;
	}
};

class OperationFactory {
public:
	static Operation* CreateOperation(char op) {
		Operation * p;
		switch (op) {
		case '+':
			p = new OperationAdd();
			break;
		case '-':
			p = new OperationSub();
			break;
		case '*':
			p = new OperationMul();
			break;
		case '/':
			p = new OperationDiv();
			break;
		default:
			p = new OperationAdd();
			break;
		}
		return p;
	}
};

int main() {
	char op;
	double a,b;
	string input;
	getline(cin, input);
	stringstream s(input);
	s >> op >> a >> b;
	Operation* p = OperationFactory::CreateOperation(op);
	p->setA(a);
	p->setB(b);
	int re = (int) p->GetResult();
	cout << re;
}