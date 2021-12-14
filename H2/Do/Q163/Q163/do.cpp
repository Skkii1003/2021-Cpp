#include "LinkedList.h"
#include<iostream>
using namespace std;
using namespace cpp;

#define size 5000

int main() {
	ListNode *head = ListNode::construct();
	int visit[size] = { 0 };
	int i = 0;
	ListNode *node = head;
	ListNode *tmp;
	int seq;

	while (node != nullptr) {
		seq = node->seq_num;
		visit[i] = seq;
		for (int j = 0; j < i; j++) {
			if (visit[j] == seq) {
				cout << (i - j);
				return 0;
			}
		}
		tmp = node->next;
		node = tmp;
		i++;
	}
	cout << -1;
}