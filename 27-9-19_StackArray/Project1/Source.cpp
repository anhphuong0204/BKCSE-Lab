#include <iostream>
#include <fstream>
using namespace std;

class Stack
{
public:
	virtual void Create(int cap) = 0;
	virtual void Push(const int& item) = 0;
	virtual void Pop() = 0;
	virtual int Top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void Clear() = 0;
	virtual int Size() = 0;
};

class ArrayStack : public Stack {
private:
	int size, capacity;
	int* array;
public:
	void Create(int cap) {
		capacity = cap;
		size = 0;
		array = new int[capacity];
	}
	void Push(const int& item) {
		if (size == capacity)
			return;
		array[size] = item;
		size++;
	}
	void Pop() {
		if (size == 0)
			return;
		size--;
	}
	int Top() {
		if (size == 0)
			return INT8_MIN;
		return array[size - 1];
	}
	bool isEmpty() {
		if (size == 0)
			return 1;
		return 0;
	}
	bool isFull() {
		if (size == capacity)
			return 1;
		return 0;
	}
	void Clear() {
		delete array;
		size = 0;
		array = new int[capacity];
	}
	int Size() {
		return size;
	}
	void PrintStack() {
		cout << "Print: ";
		for (int i = size - 1; i >= 0; i--)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char* argv[]) {
	ArrayStack* list = NULL;
	ifstream ifs;
	//ifs.open(argv[1]);
	ifs.open("in.txt");
	if (!ifs) {
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}
	char command;
	int val, temp;
	try {
		while (ifs >> command) {
			switch (command) {
			case 'l': //create an object of ArrayStack
				if (list != NULL) delete list;
				ifs >> val;
				list = new ArrayStack();
				list->Create(val);
				break;
			case 'p': //push an element to the top of the stack
				ifs >> val;
				list->Push(val);
				break;
			case 'r': //pop an element from the top of the stack
				list->Pop();
				break;
			case 't': //return top element of stack
				temp = list->Top();
				cout << "Top: " << temp << endl;
				break;
			case 'e': //check if stack is empty or not
				temp = list->isEmpty();
				if (temp) {
					cout << "Stack is empty" << endl;
				}
				else {
					cout << "Stack is not empty" << endl;
				}
				break;
			case 'f': //check if stack is full or not, if stack is linkedstack return false
				temp = list->isFull();
				if (temp) {
					cout << "Stack is full" << endl;
				}
				else {
					cout << "Stack is not full" << endl;
				}
				break;
			case 'c': //clear the stack
				list->Clear();
				break;
			case 's': //return the size (number of elements) of stack
				temp = list->Size();
				cout << "Size: " << temp << endl;
				break;
			case 'z':
				list->PrintStack();
				break;
			}
		}
	}
	catch (char const* s) {
		printf("An exception occurred. Exception type: %s\n", s);
	}
	cout << endl;
	if (list != NULL) delete list;
	ifs.close();
	return 0;
}