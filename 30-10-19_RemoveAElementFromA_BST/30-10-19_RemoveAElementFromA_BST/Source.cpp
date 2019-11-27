#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Node
{
public:
	int data;
	Node* left = NULL;
	Node* right = NULL;

};

class BinaryTree
{
private:
	Node* root = NULL;

	void print(Node* root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			print(root->left);
			print(root->right);
		}
	}

	bool insert(Node*& root, int value) {
		if (root == NULL) {
			root = new Node();
			root->data = value;
			return true;
		}
		else if (root->data > value) {
			return insert(root->left, value);
		}
		else return insert(root->right, value);
	}
	// TODO

	Node* searchNodeByValue(int value, Node* _root) {
		if (_root == NULL)
			return NULL;
		else if (value < _root->data)
			return searchNodeByValue(value, _root->left);
		else if (value > _root->data)
			return searchNodeByValue(value, _root->right);
		return root;
	}

	bool remove(int value, Node*& root) {
		if (root == NULL)
			return false;
		else if (value > root->data)
			return remove(value, root->right);
		else if (value < root->data)
			return remove(value, root->left);
		// Node found
		else {
			// For leaf node
			if (root->left == NULL) {
				Node* rmNode = root;
				root = root->right;
				free(rmNode);
				return true;
			}
			else if (root->right == NULL) {
				Node* rmNode = root;
				root = root->left;
				free(rmNode);
				return true;
			}
			// For internal node
			else {
				Node* rmNode = root->right;
				while (rmNode->left != NULL)
					rmNode = rmNode->left;
				//Node found, exchange data and remove node
				root->data = rmNode->data;
				return remove(rmNode->data, root->right);
			}
		}

	}

	int height(Node* root) {
		if (root == NULL)
			return 0;
		int lH =  height(root->left);
		int rH =  height(root->right);
		if (lH > rH)
			return lH + 1;
		return rH + 1;
	}

public:

	bool insert(int value)
	{
		return insert(root, value);
	}

	void print()
	{
		print(root);
	}

	bool remove(int value)
	{
		//TODO
		return remove(value, root);
	}
	bool find(int value) {
		Node* fNode = searchNodeByValue(value, root);
		if (fNode)
			return true;
		return false;
	}

	int height() {
		return height(root);
	}
};




int main() {
	BinaryTree* bst = new BinaryTree();
	int val[] = { 15, 10, 20, 8, 12, 16, 25 };
	for (int i = 0; i < 7; i++)
		bst->insert(val[i]);
	/*bst->print();
	bst->remove(20);
	cout << endl;
	bst->print();*/
	cout << bst->height();

	return 0;
}