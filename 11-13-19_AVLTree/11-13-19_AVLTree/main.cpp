#include <iostream>
#include <queue>

using namespace std;

class AVLNode
{
public:
	int data;
	int height;
	AVLNode* left, * right;
};

/*
AVLNode* insert(AVLNode* root, AVLNode* newNode);
AVLNode* remove(AVLNode* root, AVLNode* newNode);
void printLNR();
void printNLR();
void printBFS();
----  Helper functions   ----
AVLNode* leftRotate(AVLNode* node);
AVLNode* rightRotate(AVLNode* node);
int getBalance(AVLNode* node);
*/

AVLNode* leftRotate(AVLNode*);
AVLNode* rightRotate(AVLNode*);
int getBalance(AVLNode*);
int height(AVLNode*);
int max(int, int);
AVLNode* newNode(int);
AVLNode* minValueNode(AVLNode*);

AVLNode* insert(AVLNode* root, int data) {
	// Insert new node
	if (root == NULL)
		return(newNode(data));

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	else // Equal keys are not allowed in BST 
		return root;

	// Update new height of this ancestor
	root->height = 1 + max(height(root->left), height(root->right));
	
	// Get balance factor and rotate if necessary
	int balance = getBalance(root);
	//cout << bFactor << endl;

	if (balance > 1 && data < root->left->data)
		return rightRotate(root);

	// Right Right Case 
	if (balance < -1 && data > root->right->data)
		return leftRotate(root);

	// Left Right Case 
	if (balance > 1 && data > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case 
	if (balance < -1 && data < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	/* return the (unchanged) node pointer */
	return root;
}

AVLNode* remove(AVLNode* root, int data) {
	if (root == NULL)
		return root;

	// Key < root => left
	if (data < root->data)
		root->left = remove(root->left, data);

	// Key > root => right 
	else if (data > root->data)
		root->right = remove(root->right, data);

	// Delete root  
	else
	{
		// node with only one child or no child  
		if ((root->left == NULL) ||
			(root->right == NULL))
		{
			AVLNode* temp;
			if (root->left != NULL)
				temp = root->left;
			else
				temp = root->right;
			// No child case  
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case  
				*root = *temp; // Copy the contents of  
							   // the non-empty child  
			free(temp);
		}
		else
		{
			AVLNode* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = remove(root->right,
				temp->data);
		}
	}
	// If the tree had only one node 
	if (root == NULL)
		return root;
	// Update new height of this ancestor
	root->height = 1 + max(height(root->left), height(root->right));

	// Get balance factor and rotate if necessary
	int balance = getBalance(root);
	//cout << bFactor << endl; 

	// Left Left Case  
	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case  
	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case  
	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case  
	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void printBFS(AVLNode* root) {
	queue<AVLNode*> q;
	AVLNode* traverse;
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
void printLNR(AVLNode* root) {
	if (root == NULL)
		return;

	printLNR(root->left);
	cout << root->data << " ";
	printLNR(root->right);
}
void printNLR(AVLNode* root) {
	if (root == NULL)
		return;
	cout << root->data << ' ';
	printNLR(root->left);
	printNLR(root->right);
}

// -- Helper -- //

AVLNode* newNode(int key)
{
	AVLNode* node = new AVLNode();
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially 
					  // added at leaf  
	return(node);
}

AVLNode* rightRotate(AVLNode* y)
{
	AVLNode* x = y->left;
	AVLNode* T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	// Return new root  
	return x;
}
AVLNode* leftRotate(AVLNode* x)
{
	AVLNode* y = x->right;
	AVLNode* T2 = y->left;

	// Perform rotation  
	y->left = x;
	x->right = T2;

	// Update heights  
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	// Return new root  
	return y;
}
int getBalance(AVLNode* node) {
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

int height(AVLNode* node) {
	if (node == NULL)
		return 0;
	return node->height;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

AVLNode* minValueNode(AVLNode* node)
{
	AVLNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}


int main() {
	int arr[8] = {10, 20, 30, 40, 50, 25};
	AVLNode* root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	cout << "NLR Print: ";
	printNLR(root);
	cout << endl;
	cout << "LNR Print: ";
	printLNR(root);
	cout << endl;
	root = remove(root, 30);
	cout << "Remove 30: ";
	printBFS(root);
	cout << endl;
	return 0;
}