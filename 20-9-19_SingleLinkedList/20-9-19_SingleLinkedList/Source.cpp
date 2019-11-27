#include <iostream>
using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;
		node = node->next;
		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

void segregateEvenOdd(SinglyLinkedList* head_ref) {
	// even -> 2
	// odd -> 1
	SinglyLinkedList* head_even = new SinglyLinkedList();
	SinglyLinkedList* head_odd = new SinglyLinkedList();
	SinglyLinkedListNode* temp = head_ref->head;
	while (temp) {
		if (temp->data % 2 == 0)
			head_even->insert_node(temp->data);
		else
			head_odd->insert_node(temp->data);
		temp = temp->next;
	}
	free_singly_linked_list(head_ref->head);
	head_ref->head = head_even->head;
	head_even->tail->next = head_odd->head;
}

int count(SinglyLinkedList* root, int search_for) {
	int c = 0;
	SinglyLinkedListNode* temp = root->head;
	while (temp) {
		if (temp->data == search_for)
			c++;
		temp = temp->next;
	}
	return c;
}


int main() {
	// creat new list 8->12->10->5->4->1->6
	SinglyLinkedList* llist = new SinglyLinkedList();
	llist->insert_node(8);
	llist->insert_node(12);
	llist->insert_node(4);
	llist->insert_node(5);
	llist->insert_node(4);
	llist->insert_node(1);
	llist->insert_node(6);


	cout << count(llist, 4);
	return 0;
}