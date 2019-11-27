#include <iostream>
#include <fstream>
using namespace std;

struct LlItem {
	int data;
	LlItem* next;
	LlItem() : next(NULL) {}
	LlItem(int a, LlItem* p) : data(a), next(p) {}
};

class Queue {
public:
	virtual void EnQueue(const int&) = 0;
	virtual void DeQueue() = 0;
	virtual void Clear() = 0;
	virtual void Create() = 0;
	virtual int QueueFront() = 0;
	virtual int QueueRear() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual	int Size() = 0;
};

class LinkedQueue : public Queue
{
private:
	int size;
	LlItem* qFront, * qRear;
public:
	void EnQueue(const int& newE) {
		if (isFull())
			return;
		if (size == 0) {
			LlItem* newItem = new LlItem();
			newItem->data = newE;
			qFront = newItem;
			qRear = newItem;
		}
		else {
			if (size == 1) {
				LlItem* newItem = new LlItem();
				newItem->data = newE;
				qFront->next = newItem;
				qRear = newItem;
			}
			else {
				LlItem* newItem = new LlItem();
				newItem->data = newE;
				qRear->next = newItem;
				qRear = newItem;
			}
		}
		size++;
	}
	void DeQueue() {
		if (isEmpty())
			return;
		else {
			if (size == 1) {
				LlItem* newItem;
				newItem = qFront;
				qFront = NULL;
				qRear = NULL;
				free(newItem);
			}
			else {
				LlItem* newItem;
				newItem = qFront;
				qFront = qFront->next;
				newItem->next = NULL;
				free(newItem);
			}
		}
		size--;
	}
	void Clear() {
		while (qFront) {
			LlItem* prePtr = qFront->next;
			free(qFront);
			qFront = prePtr;
		}
		qRear = NULL;
		size = 0;
	}
	void Create() {
		size = 0;
		qFront = NULL;
		qRear = NULL;
	}
	int QueueFront() {
		if (isEmpty())
			return INT8_MIN;
		return qFront->data;
	}
	int QueueRear() {
		if (isEmpty())
			return INT8_MIN;
		return qRear->data;
	}
	bool isFull() {
		struct LlItem* temp;
		temp = new LlItem();
		if (!temp)
			return 1;
		return 0;
	}
	bool isEmpty() {
		if (size == 0)
			return 1;
		return 0;
	}
	int Size() {
		return size;
	}
	void PrintQueue() {
		cout << "Print: ";
		LlItem* temp = qFront;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main(int argc, char* argv[]) {
	ifstream ifs;
	ifs.open("in.txt");
	if (!ifs) {
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}
	LinkedQueue* list = NULL;
	char command;
	int val, temp;
	try {
		while (ifs >> command) {
			switch (command) {
			case 'e': //enqueue a item to queue
				ifs >> val;
				list->EnQueue(val);
				break;
			case 'd': //dequeue a item from queue
				list->DeQueue();
				break;
			case 'c': //create an object of LinkedQueue
				if (list != NULL) delete list;
				list = new LinkedQueue();
				list->Create();
				break;
			case 'l': //clear the queue
				list->Clear();
				break;
			case 'f': //return a front item from a queue
				temp = list->QueueFront();
				cout << temp << endl;
				break;
			case 'r': //return a rear item from a queue
				temp = list->QueueRear();
				cout << temp << endl;
				break;
			case 'm': //check if stack is empty or not
				temp = list->isEmpty();
				if (temp) {
					cout << "1" << endl;
				}
				else {
					cout << "0" << endl;
				}
				break;
			case 'n': //check if stack is full or not, if stack is linkedstack return false
				temp = list->isFull();
				if (temp) {
					cout << "1" << endl;
				}
				else {
					cout << "0" << endl;
				}
				break;
			case 's': //return the size (number of elements) of queue
				temp = list->Size();
				cout << temp << endl;
				break;
			case 'p': //print the queue
				list->PrintQueue();
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