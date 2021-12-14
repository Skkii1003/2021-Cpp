#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

class plane {
public:
	int fly;
	int task;
	int land;
	int id;

	int st;
	int ed;

	int down;
	
	//id
	virtual void set_id(int id_) = 0;
	virtual int get_id() = 0;

	//time
	virtual void set_time(int f, int t, int l) = 0;
	virtual int get_fly() = 0;
	virtual int get_task() = 0;
	virtual int get_land() = 0;

	//print
	virtual void print() = 0;

	//st
	virtual void set_st(int t) = 0;
	virtual int get_st() = 0;

	//ed
	virtual void set_ed(int t) = 0;
	virtual int get_ed() = 0;

	//priority
	virtual int prior_up() = 0;
	virtual int prior_down() = 0;
	virtual void set_down(int d) = 0;

};

class battleplane : public plane {
public:
	int fly = 2;
	int task = 0;
	int land = 2;
	int id;

	int st = 0;
	int ed = 0;

	int down = 2;

	//id
	virtual void set_id(int id_) {
		id = id_;
	}
	virtual int get_id() {
		return id;
	}

	//time
	virtual void set_time(int f, int t, int l) {
		fly = f;
		task = t;
		land = l;
	}
	virtual int get_fly() { return fly; }
	virtual int get_task() { return task; }
	virtual int get_land() { return land; }

	//print
	virtual void print() {
		cout << "p" << id << " battleplane " << fly << " " << task << " " << land;
	}

	//st
	virtual void set_st(int t) {
		st = t;
	}
	virtual int get_st() {
		return st;
	}

	//ed
	virtual void set_ed(int t) {
		ed = t;
	}
	virtual int get_ed() {
		return ed;
	}

	//priority
	virtual int prior_up() {
		return 2;
	}
	virtual int prior_down() {
		return down;
	}
	virtual void set_down(int d) {
		down = d;
	}
};

class transportplane : public plane {
public:
	int fly = 3;
	int task = 0;
	int land = 3;
	int id;

	int st = 0;
	int ed = 0;

	int down = 3;

	//id
	virtual void set_id(int id_) {
		id = id_;
	}
	virtual int get_id() {
		return id;
	}

	//time
	virtual void set_time(int f, int t, int l) {
		fly = f;
		task = t;
		land = l;
	}
	virtual int get_fly() { return fly; }
	virtual int get_task() { return task; }
	virtual int get_land() { return land; }

	//print
	virtual void print() {
		cout << "p" << id << " transportplane " << fly << " " << task << " " << land;
	}

	//st
	virtual void set_st(int t) {
		st = t;
	}
	virtual int get_st() {
		return st;
	}

	//ed
	virtual void set_ed(int t) {
		ed = t;
	}
	virtual int get_ed() {
		return ed;
	}

	//priority
	virtual int prior_up() {
		return 1;
	}
	virtual int prior_down() {
		return down;
	}
	virtual void set_down(int d) {
		down = d;
	}
};

class helicopter : public plane {
public:
	int fly = 1;
	int task = 0;
	int land = 1;
	int id;

	int st = 0;
	int ed = 0;

	int down = 1;

	//id
	virtual void set_id(int id_) {
		id = id_;
	}
	virtual int get_id() {
		return id;
	}

	//time
	virtual void set_time(int f, int t, int l) {
		fly = f;
		task = t;
		land = l;
	}
	virtual int get_fly() { return fly; }
	virtual int get_task() { return task; }
	virtual int get_land() { return land; }

	//print
	virtual void print() {
		cout << "p" << id << " helicopter " << fly << " " << task << " " << land;
	}

	//st
	virtual void set_st(int t) {
		st = t;
	}
	virtual int get_st() {
		return st;
	}

	//ed
	virtual void set_ed(int t) {
		ed = t;
	}
	virtual int get_ed() {
		return ed;
	}

	//priority
	virtual int prior_up() {
		return 3;
	}
	virtual int prior_down() {
		return down;
	}
	virtual void set_down(int d) {
		down = d;
	}
};

class carrier {
public:
	vector<plane*> deck;

	//base re
	void add(string type, int id);
	void set(int id, int f, int t, int l);
	void print();

	plane* find(int id);
};

void carrier::add(string type, int id) {
	plane* wait;

	if (type == "battleplane") {
		wait = new battleplane();
		wait->set_id(id);
		deck.push_back(wait);
	}
	else if (type == "transportplane") {
		wait = new transportplane();
		wait->set_id(id);
		deck.push_back(wait);
	}
	else if (type == "helicopter") {
		wait = new helicopter();
		wait->set_id(id);
		deck.push_back(wait);
	}
	else {
		cout << "unknown type of plane!";
	}
}

void carrier::set(int id, int f, int t, int l) {
	int size = deck.size();

	for (int i = 0; i < size; i++) {
		if (deck[i]->get_id() == id) {
			deck[i]->set_time(f, t, l);
			return;
		}
	}

	cout << "plane is not found!";
}

bool cmp(plane* p1,plane* p2){
	return p1->get_id() < p2->get_id();
}
void carrier::print() {
	sort(deck.begin(), deck.end(), cmp);

	int size = deck.size();
	for (int i = 0; i < size; i++) {
		deck[i]->print();
		if (i != size - 1)
			cout << endl;
	}
}

plane* carrier::find(int id) {
	int size = deck.size();
	for (int i = 0; i < size; i++) {
		if (deck[i]->get_id() == id) {
			return deck[i];
		}
	}
	return nullptr;
}

class Deck{
public:
	vector<plane*> up;
	vector<plane*> down;
	vector<plane*> prior;
	int times = 0;
	
	void join(plane* pl, int t);
	void schedule();
	void landfirst(plane* pl,int t);
};

void Deck::join(plane* pl, int t) {
	pl->set_st(t);
	up.push_back(pl);
}
bool cmp_st(plane* p1, plane* p2) {
	if (p1->get_st() < p2->get_st())
		return true;
	else if (p1->get_st() > p2->get_st())
		return false;
	else if (p1->prior_up() != p2->prior_up())
		return p1->prior_up() > p2->prior_up();
	else
		return p1->get_id() < p2->get_id();
}
bool cmp_ed(plane* p1, plane* p2) {
	if (p1->get_ed() < p2->get_ed())
		return true;
	else if (p1->get_ed() > p2->get_ed())
		return false;
	else if(p1->prior_down() != p2->prior_down())
		return p1->prior_down() > p2->prior_down();
	else
		return p1->get_id() < p2->get_id();
}
void Deck::schedule() {
	sort(up.begin(), up.end(), cmp_st);
	int size = up.size();
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			times = up[i]->get_st();
			times = times + up[i]->get_fly();
			if (up[i]->get_ed() == 0)
				up[i]->set_ed(times + up[i]->get_task());
			continue;
		}
		if (up[i]->get_st() > times)
			times = up[i]->get_st();

		up[i]->set_st(times);
		times = times + up[i]->get_fly();
		if (up[i]->get_ed() == 0)
			up[i]->set_ed(times + up[i]->get_task());
	}

	
	down.assign(up.begin(), up.end());

	sort(down.begin(), down.end(), cmp_ed);

	int size_prior = prior.size();

	for (int i = 0; i < size_prior; i++) {
		for (int j = 0; j < size; j++) {
			if (down[j]->get_id() == prior[i]->get_id()) {
				down.erase(down.begin() + j);
				size = down.size();
				break;
			}
		}
	}

	times = up[0]->get_st() + up[0]->get_fly();
	int i = 1;
	int land = 0;
	int p = 0;
	int x = 0;
	size = up.size();
	while ((p+land) < size) {

		if (i<size && up[i]->get_st() <= times) {
			times = times + up[i]->get_fly();
			i++;
		}
		else if (p < size_prior && prior[p]->get_ed() <= times) {
			times = times + prior[p]->get_land();
			prior[p]->set_ed(times);
			p++;
		}
		else if (land<size && down[land]->get_ed() <= times) {
			times = times + down[land]->get_land();
			down[land]->set_ed(times);
			land++;
		}
		else {
			times++;
		}
	}

	down.insert(down.end(), prior.begin(), prior.end());
	sort(down.begin(), down.end(), cmp_ed);
	for (int i = 0; i < size; i++) {
		cout << "p" << down[i]->get_id() << " " << down[i]->get_st() << " " << down[i]->get_ed();
		if (i != size - 1)
			cout << endl;
	}
}

void Deck::landfirst(plane* pl, int t) {
	pl->set_ed(t);
	prior.push_back(pl);
}


int main() {
	int n;
	cin >> n;
	getchar();

	string input;
	carrier c;
	Deck de;
	int first = 4;

	while (n >= 0) {
		getline(cin, input);
		stringstream ss(input);
		string ins;
		ss >> ins;
		if (ins == "add") {
			string type;
			string rank;
			int id;

			ss >> type >> rank;
			id = std::stoi(rank.substr(1));
			c.add(type, id);
		}
		else if (ins == "set") {
			string rank;
			int id;
			int fly;
			int task;
			int land;
			ss >> rank >> fly >> task >> land;
			id = std::stoi(rank.substr(1));
			c.set(id, fly, task, land);
		}
		else if (ins == "normal") {
			c.print();
			break;
		}
		else if (ins == "join") {
			string rank;
			int id;
			int t;

			ss >> rank >> t;
			id = std::stoi(rank.substr(1));
			de.join(c.find(id), t);
		}
		else if (ins == "schedule") {
			de.schedule();
			break;
		}
		else if (ins == "landfirst") {
			int t;
			string rank;
			int id;

			ss >> t >> rank;
			id = std::stoi(rank.substr(1));
			c.find(id)->set_down(first);
			de.landfirst(c.find(id), t);
			first++;
		}
		else {
			cout << "invalid ins!";
			break;
		}
		n--;
	}
}


/*
10
add battleplane p1
add transportplane p2
add helicopter p3
set p1 2 2 2
set p2 3 1 3
set p3 1 4 1
join p1 0
join p3 0
join p2 1
schedule

10
add battleplane p1
add battleplane p2
add battleplane p3
join p1 0
join p2 10
join p3 20
schedule

10
add battleplane p1
add battleplane p2
add battleplane p3
join p1 0
join p2 0
join p3 0
schedule
*/