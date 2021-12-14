#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;



class Weibo {
public:
	int id;
	int type;
	int time;

	Weibo(){}
	Weibo(int wbid, int ty,int t) {
		id = wbid;
		type = ty;
		time = t;
	}
	
	int get_type() { return type; }
	int get_id() { return id; }
};



class User {
public:
	int id;
	vector<Weibo*> weibo;
	vector<User*> following;
	vector<User*> fans;
	vector<User*> pyq;

	User(){}
	User(int userid) { id = userid; }

	int get_id() { return id; }
	int get_follow() { return following.size(); }
	int get_fans() { return fans.size(); }
	int get_wb() { return weibo.size(); }

	void delete_follow(int id);
	void delete_fan(int id);

	void update();
};

void User::delete_follow(int id) {
	int size = following.size();
	for (int i = 0; i < size; i++) {
		if (following[i]->id==id) {
			following[i] = following[size - 1];
			following.pop_back();
			size = following.size();
		}
	}
}
void User::delete_fan(int id) {
	int size = fans.size();
	for (int i = 0; i < size; i++) {
		if (fans[i]->id == id) {
			fans[i] = fans[size - 1];
			fans.pop_back();
			size = fans.size();
		}
	}
}
void User::update() {
	int size_follow = following.size();
	int size_fans = fans.size();

	pyq.clear();
	for (int i = 0; i < size_follow; i++) {
		for (int j = 0; j < size_fans; j++) {
			if (following[i]->id == fans[j]->id) {
				pyq.push_back(following[i]);
				break;
			}
		}
	}
}


class Web {
public:
	vector<User*> user;
	int time = 0;

	void post(int userid,int wbid, int type);

	void addUser(int userid) {
		user.push_back(new User(userid));
	}

	User* getUser(int id);
	void getRecent(int id, int num, int type);

	void follow(int erid, int eeid);
	void unfollow(int erid, int eeid);

};

void Web::post(int userid,int wbid, int type) {
	User* u = Web::getUser(userid);
	u->weibo.push_back(new Weibo(wbid,type,time));
	time++;
}

bool cmp(Weibo* w1, Weibo* w2) {
	return w1->time > w2->time;
}

User* Web::getUser(int id) {
	int size = user.size();
	for (int i = 0; i < size; i++) {
		if (user[i]->get_id() == id) {
			return user[i];
		}
	}
	Web::addUser(id);
	return Web::getUser(id);
}
void Web::getRecent(int id, int num, int type) {
	User* u = Web::getUser(id);

	vector<Weibo*> find(u->weibo);

	if (type == 1) {
		int size = u->pyq.size();
		for (int i = 0; i < size; i++) {
			User* tmp = u->pyq[i];
			int top = tmp->weibo.size();
			for (int j = 0; j < top; j++) {
				if (tmp->weibo[j]->get_type() == 0)
					continue;
				else
					find.push_back(tmp->weibo[j]);
			}
		}
	}
	else {
		int size = u->following.size();
		for (int i = 0; i < size; i++) {
			User* tmp = u->following[i];
			int top = tmp->weibo.size();
			for (int j = 0; j < top; j++) {
				if (tmp->weibo[j]->get_type() == 0)
					continue;
				else if(tmp->weibo[j]->get_type() == 2)
					find.push_back(tmp->weibo[j]);
				else {
					int x = tmp->pyq.size();
					continue;
				}
			}
		}
	}

	sort(find.begin(), find.end(), cmp);
	int size = find.size();

	for (int i = 0; i < size; i++) {
		if (i == num)
			break;
		if (i == 0) {
			cout << find[i]->get_id();
		}
		else {
			cout << " " << find[i]->get_id();
		}
	}
	cout << endl;
}

void Web::follow(int erid, int eeid) {
	User* er = Web::getUser(erid);
	User* ee = Web::getUser(eeid);

	ee->fans.push_back(er);
	er->following.push_back(ee);
	er->update();
	ee->update();
}
void Web::unfollow(int erid, int eeid) {
	User* er = Web::getUser(erid);
	User* ee = Web::getUser(eeid);

	er->delete_follow(eeid);
	ee->delete_fan(erid);
	er->update();
	ee->update();
}


int main() {
	int n;
	cin >> n;
	getchar();

	Web web;

	

	while (n > 0) {
		string input;
		getline(cin, input);
		stringstream ss(input);
		string ins;
		ss >> ins;

		if (ins == "post") {
			int userid;
			int wbid;
			int type;

			ss >> userid >> wbid >> type;
			web.post(userid, wbid, type);
		}
		else if (ins == "getFollows") {
			int userid;
			ss >> userid;

			cout << web.getUser(userid)->get_follow() << endl;
		}
		else if (ins == "getFans") {
			int userid;
			ss >> userid;

			cout << web.getUser(userid)->get_fans() << endl;
		}
		else if (ins == "getWeibos") {
			int userid;
			ss >> userid;

			cout << web.getUser(userid)->get_wb() << endl;
		}
		else if (ins == "getRecent") {
			int userid;
			int num;
			int type;
			ss >> userid >> num >> type;

			web.getRecent(userid, num, type);
		}
		else if (ins == "follow") {
			int erid;
			int eeid;
			ss >> erid >> eeid;

			web.follow(erid, eeid);
		}
		else if (ins == "unfollow") {
			int erid;
			int eeid;
			ss >> erid >> eeid;
			web.unfollow(erid, eeid);
		}
		else {
			cout << "invalid ins!";
			break;
		}
		n--;
	}
}