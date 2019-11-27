#include <iostream>
#include <math.h>
using namespace std;

//create binary search tree for question 2
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node() : data(0), left(NULL), right(NULL) {}
	Node(int d) : data(d), left(NULL), right(NULL) {}
};
class BSTree
{
private:
	Node* head;
	int size;
public:
	BSTree() { head = NULL; size = 0; }
	~BSTree() {}
	Node*& gethead() { return head; }
	int getsize() { return size; }
	void insert(int data)
	{
		insertNode(head, data);
		size++;
	}
	void remove(int data)
	{
		deleteNode(head, data);
		size--;
	}
	bool deleteNode(Node*& p, int d);
	bool insertNode(Node*& p, int d);
	void printLNR()
	{
		printLNR(head);
		cout << endl;
	}
	void printLNR(Node* p);
};
bool BSTree::insertNode(Node*& p, int d)
{
	if (p == NULL) {
		p = new Node(d);
		return true;
	}
	else if (d < p->data) return insertNode(p->left, d);
	else return insertNode(p->right, d);
}
bool BSTree::deleteNode(Node*& p, int d)
{
	if (p == NULL) return false;
	if (p->data == d) {
		if (p->left == NULL) {
			if (p->right == NULL) { delete p, p = NULL; }
			else { Node* pPre = p; p = p->right; delete pPre; }
		}
		else {
			if (p->right == NULL) {
				Node* pPre = p; p = p->left; delete pPre;
			}
			else {
				Node* pPre = p; pPre = pPre->right;
				while (pPre->left != NULL) { pPre = pPre->left; }
				p->data = pPre->data;
				return deleteNode(p->right, pPre->data);
				return true;
			}
		}
	}
	else if (p->data > d) return deleteNode(p->left, d);
	else return deleteNode(p->right, d);
}
void BSTree::printLNR(Node* p)
{
	if (p == NULL) return;
	if (p->left != NULL) {
		cout << "(";
		printLNR(p->left);
		cout << ")";
	}
	cout << p->data;
	if (p->right != NULL) {
		cout << "(";
		printLNR(p->right);
		cout << ")";
	}
}

//some function for print heap to tree
void print_(int size)
{
	for (int i = 1; i <= size; i++) cout << "---";
}
void printspace(int size)
{
	for (int i = 1; i <= size; i++) cout << "   ";
}
int getHeight(int size)
{
	return (int)log2(size) + 1;
}
void printArr(int* pD, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << pD[i] << " ";
	}
	cout << endl;
}

//heapup and heapdown for maxheap (buildmaxheap)
//Copy tu question 1
void HeapUp(int* pD, int N, int i)
{
	//TODO
	if (i > 0) {
		int parent = (i - 1) / 2;
		if (pD[parent] < pD[i]) {
			int temp = pD[parent];
			pD[parent] = pD[i];
			pD[i] = temp;
			HeapUp(pD, N, parent);
		}
	}
	return;
}
void HeapDown(int* pD, int pos, int lastPos)
{
	//TODO
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;
	if (left <= lastPos) {
		int largeChild;
		if (right <= lastPos && pD[right] < pD[left])
			largeChild = left;
		else
			largeChild = right;
		if (pD[largeChild] > pD[pos]) {
			int temp = pD[largeChild];
			pD[largeChild] = pD[pos];
			pD[pos] = temp;
			HeapDown(pD, largeChild, lastPos);
		}
	}
}
void buildHeap(int* pD, int size)
{
	//TODO
	int traveler = 1;
	while (traveler < size) {
		HeapUp(pD, size, traveler);
		traveler++;
	}
}

bool deleteHeap(int* arr, int last, int& data) {
	if (arr == NULL)
		return false;
	data = arr[0];
	arr[0] = arr[last];
	last--;
	HeapDown(arr, 0, last);
	return true;
}

void printNode(int i) {
	if (i >= 0 && i <= 9)
		cout << 0 << 0 << i;
	else if (i >= 10 && i <= 99)
		cout << 0 << i;
	else
		cout << i;
}


void printHeapTree(int* list, int size)
{
	//TODO
	int h = getHeight(size);
	int i = 0;
	int k = h - 1;
	while (i < h) {

		int a = (int)pow(2, i);
		int b = (int)pow(2, i + 1) - 1;
		if (b > size)
			b = size;

		int space_ = pow(2, k) - 1;
		int _ = space_ / 2;
		int space = space_ - _;

		for (a; a <= b; a++) {
			printspace(space);
			print_(_);
			printNode(list[a - 1]);
			print_(_);
			printspace(space + 1);

		}
		cout << endl;
		i++;
		k--;
	}
}


//question 2
void BSTtomheap(Node* root, int* arr) //co the thay doi protocol
{
	//TODO Vi du, co the tu thay doi theo tuy y ban than
	if (root == NULL)
		return;
	static int i = 0;
	arr[i] = root->data;
	i++;
	BSTtomheap(root->left, arr);
	BSTtomheap(root->right, arr);
}
int*& conBSTtoHeap(BSTree*& p)
{
	//TODO
	int size = p->getsize();
	int* arr = new int[size];
	BSTtomheap(p->gethead(), arr);
	printArr(arr, size);
	buildHeap(arr, size);
	printArr(arr, size);
	return arr;
}
int main()
{
	BSTree* bst = new BSTree();
	bst->insert(473);
	bst->insert(309);
	bst->insert(286);
	bst->insert(598);
	bst->insert(438);
	bst->insert(663);
	bst->insert(948);
	bst->insert(424);
	cout << endl;
	cout << endl;
	cout << "BSTree (left node right): ";
	bst->printLNR();
	int* Maxheap = conBSTtoHeap(bst);
	int Maxsize = bst->getsize();
	cout << "Maxheap converted from BST: " << endl;
	printHeapTree(Maxheap, Maxsize);
	int data;
	deleteHeap(Maxheap, Maxsize - 1, data);
	Maxsize--;
	printHeapTree(Maxheap, Maxsize);
	cout << data;

	system("pause");
	return 0;
}