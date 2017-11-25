#include <iostream>
#include <cstdio>
#include <climits> // for INT_MIN

using namespace std;

#define MAX_SIZE 10 // we can change it, maybe make it smaller/bigger so that we can
                    //show that the circular queue actually works
                    
class Queue {
public:
	int arr[MAX_SIZE];
	int front, rear; // deletion at front, insertion at rear
	Queue() {
		front = rear = -1;
	}
	bool isFull();
	bool isEmpty();
	void enqueue(int);
	void dequeue();
	void print();
};                

bool Queue::isEmpty() {
	return (front==-1);
}

bool Queue::isFull() {
	return ((front == rear+1) || ((front == 0) && (rear == MAX_SIZE-1)));
}


void Queue::enqueue(int x) {
	if(isEmpty()) {
		arr[++front] = arr[++rear] = x;
	}
	else if(isFull()) printf("Queue is full\n");
	
	else {
		if(rear == MAX_SIZE-1) {
			rear = 0;
			arr[rear] = x;
		}
		else arr[++rear] = x;
	}	
}

void Queue::dequeue() {
	if(isEmpty()) {
		printf("Queue is empty\n");
	}
	else {
		cout<<arr[front];
		if(front==rear) front = rear = -1;
		else if(front==MAX_SIZE-1) front = 0;
		else front++;
	}
	
}

void Queue::print() {
	// print from front to rear
	if(isEmpty()) printf("Queue is empty\n");
	else {
		if(front>rear) {
			for(int i=front; i<=MAX_SIZE-1; i++) cout<<arr[i]<<' ';
			for(int i=0; i<=rear; i++) cout<<arr[i]<<' ';
			cout<<endl;
		}
		else {
			for(int i=front; i<=rear; i++) cout<<arr[i]<<' ';
			cout<<endl;
		}
	}
}



int main() {
	int n;
	cout<<"Enter no. of values: ";
	cin>>n;
	Queue queue;
	int ele;
	for(int i=0; i<n; i++) {
		cin>>ele;
		queue.enqueue(ele);
	}
	cout<<"Dequeueing"<<endl;
	for(int i=0; i<4; i++) { 
		queue.dequeue();
		cout<<" ";
	}
	cout<<endl;
	queue.enqueue(32);
	queue.enqueue(44);
	queue.enqueue(56);
	queue.enqueue(49);
	queue.enqueue(89);
	queue.print();
	return 0;
}








