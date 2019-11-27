#include <iostream>
#include <queue>
using namespace std;

class treeNode {
public:
	int data;
	treeNode* left = NULL;
	treeNode* right = NULL;
};


treeNode* recursiveInsert(treeNode* subroot, treeNode* newNode) {
	if (subroot == NULL) {
		return newNode;
	}
	else {
		if (newNode->data < subroot->data)
			subroot->left = recursiveInsert(subroot->left, newNode);
		else
			subroot->right = recursiveInsert(subroot->right, newNode);
	}
	return subroot;
}

// Traversal
void printBFT(treeNode* root) {
	queue<treeNode*> q;
	treeNode* traverse;
	q.push(root);
	while (q.empty() == false) {
		traverse = q.front();
		cout << traverse->data << ' ';
		q.pop();
		if (traverse->left != NULL) {
			q.push(traverse->left);
		}
		if (traverse->right != NULL) {
			q.push(traverse->right);
		}

	}
}
void printLNR(treeNode* root) {
	if (root == NULL)
		return;

	printLNR(root->left);
	cout << root->data << " ";
	printLNR(root->right);
}
void printNLR(treeNode* root) {
	if (root == NULL)
		return;
	cout << root->data << ' ';
	printNLR(root->left);
	printNLR(root->right);
}

// Count leaves and internal
int countLeaves(treeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return countLeaves(root->left) + countLeaves(root->right);
}
int countNode(treeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}

int main() {
	treeNode* root = NULL;
	int val[] = {15, 10, 20, 8, 12, 16, 25};
	for (int i = 0; i < 7; i++) {
		treeNode* newNode = new treeNode();
		newNode->data = val[i];
		root = recursiveInsert(root, newNode);
	}
	printBFT(root);
	cout << endl;
	printLNR(root);
	cout << endl;
	printNLR(root);
	cout << endl;
	cout << countLeaves(root) << endl;
	cout << countNode(root) - 1 << endl;

	return 0;
}