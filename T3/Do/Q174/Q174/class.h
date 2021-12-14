#pragma once
#include<iostream>
#include<string>

using namespace std;


class server {
public:
	int id;
	int times;
	int prior;

	server(int id) {
		this->id = id;
		times = 0;
		prior = 0;
	}
};

class request {
public:
	string tag;
	int seid;

	request(string tag) {
		this->tag = tag;
	}
};