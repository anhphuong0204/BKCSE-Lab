#include <iostream>
#include <fstream>
using namespace std;

struct LlItem {
	int data;
	LlItem* next;
	LlItem() : next(NULL) {}
	LlItem(int a, LlItem* p) : data(a), next(p) {}
};

class Stack {

public:
	virtual void Create() = 0;
	virtual void Push(const int& item) = 0;
	virtual void Pop() = 0;
	virtual int Top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void Clear() = 0;
	virtual int Size() = 0;
};

class LinkedStack : public Stack {

private:
	int size;
	LlItem* sTop;
public:
	void Create() {
		size = 0;
		sTop = NULL;
	}
	void Clear() {
		while (sTop) {
			LlItem* prePtr = sTop->next;
			free(sTop);
			sTop = prePtr;
		}
		size = 0;
	}
	void Push(const int& newE) {
		if (isFull())
			return;
		else {
			if (isEmpty()) {
				sTop = new LlItem();
				sTop->data = newE;
				size++;
			}
			else {
				LlItem* newTop = new LlItem();
				newTop->data = newE;
				newTop->next = sTop;
				sTop = newTop;
				size++;
			}
		}		
	}
	void Pop() {
		if (sTop == NULL)
			return;
		LlItem* temp = new LlItem();
		sTop = sTop->next;
		temp->next = NULL;
		free(temp);
	}
	int Top() {
		if (sTop == NULL)
			return INT8_MIN;
		return sTop->data;
	}
	bool isEmpty() {
		if (sTop == NULL)
			return 1;
		return 0;
	}
	bool isFull() {
		struct LlItem* temp;
		temp = new LlItem();
		if (!temp)
			return 1;
		return 0;
	}
	int Size() {
		return size;
	}
	void PrintStack() {
		cout << "Print: ";
		LlItem* temp;
		temp = sTop;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main(int argc, char* argv[]) {
	LinkedStack* list = NULL;
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
			case 'l': //create an object of LinkedStack
				if (list != NULL) delete list;
				list = new LinkedStack();
				list->Create();
				break;
			case 'p': //push an element to the top of the stack
				ifs >> val;
				list->Push(val);
				cout << "Push " << val << endl;
				break;
			case 'r': //pop an element from the top of the stack
				list->Pop();
				cout << "Pop" << endl;
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
	if (list != NULL) delete list;
	ifs.close();
	return 0;
}