#include "BinaryTree.h"
#include<iostream>
using namespace std;

int main() {
	int x,i;
	cin >> x;
	cpp::TreeNode root(x);
	cpp::TreeNode *node;
	cpp::TreeNode *next;
	while (cin >> x) {
		char po[100] = { '\0' };
		node = &root;
		i = 0;
		cin >> po;
		while (po[i] != '\0') {
			if (po[i + 1] == '\0') {
				if (po[i] == 'R') {
					node->right = new cpp::TreeNode(x);
					break;
				}
				else {
					node->left = new cpp::TreeNode(x);
					break;
				}
			}
			else{
				if (po[i] == 'R') {
					next = node->right;
					node = next;
			}
				else {
					next = node->left;
					node = next;
				}
			}

			i++;
		}
		
	}
	cpp::print_tree(&root);
}