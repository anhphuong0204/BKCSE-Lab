#include <iostream>
#include <fstream>
using namespace std;

class Queue {
public:
	virtual void EnQueue(const int) = 0;
	virtual void DeQueue() = 0;
	virtual void Clear() = 0;
	virtual void Create(int) = 0;
	virtual int QueueFront() = 0;
	virtual int QueueRear() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual	int Size() = 0;
	virtual void PrintQueue() = 0;
};

class ArrayQueue : public Queue
{
private:
	int size, front, rear;
	int capacity;
	int* array;
public:

	void Create(int cap) {
		array = new int[cap];
		capacity = cap;
		size = 0;
	}

	void EnQueue(const int newE) {
		if (isFull() == 1) {
			return;
		}
		else {
			if (isEmpty() == 1) {
				array[0] = newE;
				front = 0;
				rear = 0;
			}
			else {
				rear++;
				array[rear] = newE;
			}
			size++;
		}
	}

	void DeQueue() {
		if (size == 0)
			return;
		else {
			if (size == 1) {
				front = -1;
				rear = -1;
				size == 0;
			}
			else {
				for (int i = 0; i < size - 1; i++) {
					array[i] = array[i + 1];
				}
				rear--;
				size--;
			}
		}
	}

	void Clear() {
		if (isEmpty())
			return;
		delete array;
		size = 0;
		front = -1;
		rear = -1;
	}

	int QueueFront() {
		if (isEmpty())
			return INT8_MIN;
		return array[front];
	}

	int QueueRear() {
		if (isEmpty())
			return INT8_MIN;
		return array[rear];
	}

	bool isFull() {
		if (size == capacity)
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
		if (size == 0) {
			cout << endl;
			return;
		}
		if (rear >= front) {
			for (int i = front; i <= rear; i++)
				cout << array[i] << " ";
		}
		else {
			for (int i = front; i < capacity; i++)
				cout << array[i] << " ";
			for (int i = 0; i <= rear; i++)
				cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char* argv[]) {
	ArrayQueue* list = NULL;
	ifstream ifs;
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
			case 'e': //enqueue a item to queue
				ifs >> val;
				list->EnQueue(val);
				break;
			case 'd': //dequeue a item from queue
				list->DeQueue();
				break;
			case 'c': //create an object of ArrayQueue
				if (list != NULL) delete list;
				ifs >> val;
				list = new ArrayQueue();
				list->Create(val);
				break;
			case 'l': //clear the queue
				list->Clear();
				break;
			case 'f': //return a front item from a queue
				temp = list->QueueFront();
				cout << "Front: " << temp << endl;
				break;
			case 'r': //return a rear item from a queue
				temp = list->QueueRear();
				cout << "Rear: " << temp << endl;
				break;
			case 'm': //check if stack is empty or not
				temp = list->isEmpty();
				if (temp) {
					cout << "Queue is empty" << endl;
				}
				else {
					cout << "Queue isn't empty" << endl;
				}
				break;
			case 'n': //check if stack is full or not, if stack is linkedstack return false why?
				temp = list->isFull();
				if (temp) {
					cout << "Queue is full" << endl;
				}
				else {
					cout << "Queue isn't full" << endl;
				}
				break;
			case 's': //return the size (number of elements) of queue
				temp = list->Size();
				cout << "Size: " << temp << endl;
				break;
			case 'p': //print out the queue
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