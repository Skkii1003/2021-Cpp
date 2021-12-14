#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class poly {
public:
	int r = 0;
	int g = 0;
	int b = 0;
	string rank;
	vector<string> gid;

	//rank
	virtual void set_rank(string str) = 0;
	virtual string get_rank() = 0;

	//rgb
	virtual void set_rgb(int R, int G, int B) = 0;
	virtual string get_rgb() = 0;

	//gray
	virtual double get_gray() = 0;

	//gid
	virtual void set_gid(string id) = 0;
	virtual string get_gid() = 0;
	
};

class normal : public poly {
public:
	int r = 0;
	int g = 0;
	int b = 0;
	string rank;
	vector<string> gid;

	virtual void set_rgb(int R, int G, int B) {
		r = R;
		g = G;
		b = B;
	}

	virtual void set_rank(string str) {
		rank = str;
	}

	virtual double get_gray() {
		return r * 0.299 + g * 0.587 + b * 0.114;
	}

	virtual void set_gid(string id) {
		gid.push_back(id);
	}

	virtual string get_rank() {
		return rank;
	}

	virtual string get_rgb() {
		return std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);
	}

	virtual string get_gid() {
		int size = gid.size();
		string re = "";
		for (int i = 0; i < size; i++) {
			if (i != 0)
				re = re + " ";
			re = re + gid[i];
		}
		return re;
	}
};

class Reverse : public poly {
public:
	int r = 0;
	int g = 0;
	int b = 0;
	string rank;
	vector<string> gid;

	virtual void set_rgb(int R, int G, int B) {
		r = 255 - R;
		g = 255 - G;
		b = 255 - B;
	}

	virtual void set_rank(string str) {
		rank = str;
	}

	virtual double get_gray() {
		return r * 0.299 + g * 0.587 + b * 0.114;
	}

	virtual void set_gid(string id) {
		gid.push_back(id);
	}

	virtual string get_rank() {
		return rank;
	}

	virtual string get_rgb() {
		return std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);
	}

	virtual string get_gid() {
		int size = gid.size();
		string re = "";
		for (int i = 0; i < size; i++) {
			if (i != 0)
				re = re + " ";
			re = re + gid[i];
		}
		return re;
	}
};

class single : public poly {
public:
	int r = 0;
	int g = 0;
	int b = 0;
	string rank;
	vector<string> gid;

	virtual void set_rgb(int R, int G, int B) {
		r = R;
		g = 0;
		b = 0;
	}

	virtual void set_rank(string str) {
		rank = str;
	}

	virtual double get_gray() {
		return r * 0.299 + g * 0.587 + b * 0.114;
	}

	virtual void set_gid(string id) {
		gid.push_back(id);
	}

	virtual string get_rank() {
		return rank;
	}

	virtual string get_rgb() {
		return std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);
	}

	virtual string get_gid() {
		int size = gid.size();
		string re = "";
		for (int i = 0; i < size; i++) {
			if (i != 0)
				re = re + " ";
			re = re + gid[i];
		}
		return re;
	}
};


class square {
public:
	//vector<poly*> list;
	poly* list[50];
	int p = 0;

	void add(string type, string rank);

	void set(string rank, int R, int G, int B);

	void print();

	void print_gray();

	void group(int len, string g[], string gid);

	void set_group(string gid, int R, int G, int B);
};

void square::group(int len, string g[], string gid) {
	//int size = list.size();
	int size = p;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < len; j++) {
			if (list[i]->get_rank() == g[j]) {
				list[i]->set_gid(gid);
				break;
			}
		}
	}
}

void square::set_group(string gid, int R, int G, int B) {
	//int size = list.size();
	int size = p;
	for (int i = 0; i < size; i++) {
		string str = list[i]->get_gid();
		stringstream ss(str);
		string id;
		while (ss >> id) {
			if (id == gid) {
				list[i]->set_rgb(R, G, B);
			}
		}
	}
}

void square::print() {
	//int size = list.size();
	int size = p;
	vector<poly*> g;

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			g.push_back(list[0]);
			continue;
		}
		int insert = std::stoi(list[i]->get_rank().substr(1));
		for (int j = 0; j < i; j++) {
			int front = std::stoi(g[j]->get_rank().substr(1));

			if (insert < front) {
				g.insert(g.begin()+j, list[i]);
				break;
			}
			else {
				if (j == i - 1) {
					g.push_back(list[i]);
					break;
				}
				else
					continue;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << g[i]->get_rank() << " " << g[i]->get_rgb();
		if (i < size - 1)
			cout << endl;
	}
}

void square::print_gray() {
	//int size = list.size();
	int size = p;
	vector<poly*> g;
	
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			g.push_back(list[0]);
			continue;
		}

		double insert = list[i]->get_gray();
		for (int j = 0; j < i; j++) {
			double front = g[j]->get_gray();

			if (insert < front) {
				g.insert(g.begin()+j, list[i]);
				break;
			}
			else if (insert == front) {
				int rank_i = std::stoi(list[i]->get_rank().substr(1));
				int rank_f = std::stoi(g[j]->get_rank().substr(1));
				if (rank_i < rank_f) {
					g.insert(g.begin() + j, list[i]);
					break;
				}
				else {
					if (j == i - 1) {
						g.push_back(list[i]);
						break;
					}
					else
						continue;
				}
			}
			else {
				if (j == i - 1) {
					g.push_back(list[i]);
					break;
				}
				else
					continue;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << g[i]->get_rank() << " " << g[i]->get_rgb();
		if (i < size - 1)
			cout << endl;
	}
}

void square::set(string rank, int R, int G, int B) {
	poly* po = nullptr;
	//int size = list.size();
	int size = p;
	for (int i = 0; i < size; i++) {
		if (list[i]->get_rank() == rank) {
			po = list[i];
			break;
		}
	}
	if (po == nullptr) {
		cout << "poly is not found!";
		return;
	}

	po->set_rgb(R, G, B);
}

void square::add(string type, string rank) {
	poly* po;
	if (type == "normal") {
		//poly* po = new normal();
		po = new normal();
		po->set_rank(rank);
		//list.push_back(po);
		list[p] = po;
		p++;
	}
	else if (type == "reverse") {
		//poly* po = new Reverse();
		po = new Reverse();
		po->set_rank(rank);
		//list.push_back(po);
		list[p] = po;
		p++;
	}
	else if (type == "single") {
		//poly* po = new single();
		po = new single();
		po->set_rank(rank);
		//list.push_back(po);
		list[p] = po;
		p++;
	}
	else
		cout << "error when adding!";
}

int main() {
	int n;
	cin >> n;
	getchar();

	square sq;
	
	int i = 0;
	while ( i <= n ) {
		string ins;
		string input;
		getline(cin, input);
		stringstream ss(input);
		ss >> ins;
		if (ins == "Add") {
			string type;
			string rank;
			ss >> type >> rank;
			sq.add(type, rank);
		}
		else if (ins == "Set") {
			string rank;
			int r;
			int g;
			int b;
			ss >> rank >> r >> g >> b;
			if (rank.at(0) == 'G')
				sq.set_group(rank, r, g, b);
			else
				sq.set(rank, r, g, b);
			//sq.set(rank, r, g, b);
		}
		else if (ins == "Normal") {
			sq.print();
			if (i == n)
				break;
			else
				i--;
		}
		else if (ins == "Gray") {
			sq.print_gray();
			if (i == n)
				break;
			else
				i--;
		}
		else if (ins == "Group") {
			int size;
			ss >> size;
			string g[10];
			for (int i = 0; i < size; i++)
				ss >> g[i];
			string gid;
			ss >> gid;

			sq.group(size, g, gid);
		}
		else {
			cout << "invalid ins!";
			break;
		}
		i++;
	}
}