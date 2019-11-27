#include <iostream>
#include <math.h>
using namespace std;

//question1
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
}
void HeapDown(int* pD, int N, int i)
{
	//TODO
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

int main()
{
	int size;
	cout << "Input the number of elements in array: "; cin >> size;
	int* maxHeap = new int[size];
	for (int i = 0; i < size; i++)
	{
		maxHeap[i] = i;
	}
	cout << "The heaptree before build: " << endl;
	printArr(maxHeap, size);
	printHeapTree(maxHeap, size);
	cout << "The heaptree after build: " << endl;
	buildHeap(maxHeap, size);
	printArr(maxHeap, size);
	printHeapTree(maxHeap, size);

	system("pause");
	return 0;
}