#include <cstdio>
#include <iostream>
#define MAX 1010 

using namespace std;

class Stack
{
private:
	int arr[MAX];  
	int top;   
public:

	Stack()
	{
		top = -1; 
	}

	void push(int x) 
	{
	    if(top == MAX -1) { 
			printf("Stack overflow\n");
			return;
		}
		arr[++top] = x;
	}
 
	void pop() 
	{
		if(top == -1) { 
			printf("Stack empty\n");
			return;
		}
		top--;
	}
 
	int returnTop() 
	{
		return arr[top];
	}
 
	bool isEmpty()
	{
		if(top == -1) return true;
		return false;
	}

};

int main()
{ 
	Stack S;
	S.push(3);
	S.push(5);
	S.push(87);
	cout<<S.returnTop()<<endl;
	S.pop();
	S.pop();
	S.push(23);
	cout<<S.returnTop()<<endl;
}