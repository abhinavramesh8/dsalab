#include <iostream>
#include <cstdio>

using namespace std;

/*
Useful for implementation of queue. We don’t need to maintain two pointers for 
front and rear if we use circular linked list. 
We can maintain a pointer to the last inserted node and 
front can always be obtained as next of last.
*/

class Node {
public:
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}

};

class CircList {
public:
	Node *head;
	void insertAtBeg(int);
	void enqueue(int);
	void dequeue();
	void deleteEnd();
	void print();
	CircList() {
		head = NULL;
	}
};

void CircList::insertAtBeg(int x) {
	Node *newNode = new Node(x);
	if(head == NULL) {
		head = newNode;
		newNode -> next = head;
	}
	else {
		Node *temp = head;
		while(temp -> next != head) temp = temp -> next;
		newNode -> next = head;
		head = newNode;
		temp -> next = head;
	}
}

void CircList::enqueue(int x) {
	Node *newNode = new Node(x);
	if(head == NULL) {
		head = newNode;
		newNode -> next = head;
	}
	else {
	    Node *temp = head;
		while(temp -> next != head) temp = temp -> next;
		temp -> next = newNode;
		newNode -> next = head;
	}
}

void CircList::dequeue() {
	if(head==NULL) printf("List is empty\n");
	else {
		Node *temp = head;
		if(temp -> next == head) {
			cout<<head->data<<endl;
			delete(head);
			head = NULL;
		}
		else {
			while(temp->next!=head) temp = temp->next;
			temp -> next = head -> next;
			cout<<head->data<<endl;
			delete(head);
			head = head -> next;
		}
	}
}

void CircList::deleteEnd() {
	if(head==NULL) printf("List is empty\n");
	else {
		Node *temp = head;
		Node *temp2;
		if(temp -> next == head) {
			head = NULL;
		}
		else {
			while(temp -> next != head) {
				temp2 = temp;
				temp = temp -> next;
			}
			temp2 -> next = head;
		}
	}
}

void CircList::print() {
	if(head==NULL) printf("List is empty\n");
	else {
		Node *temp = head;
		while(temp -> next != head) {
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<temp->data<<"->"<<head->data;
	}
}


int main() {
	CircList list;
	int n;
	cout<<"Enter no. of values: ";
	cin>>n;
	int ele;
	for(int i=0; i<n; i++) {
		cin>>ele;
		list.enqueue(ele);
	}
	cout<<"Inserting at the end"<<endl;
	list.print();
	cout<<endl;
	cout<<"Dequeueing one element"<<endl;
	list.dequeue();
	list.print();
	cout<<endl;
	return 0;
}