#include <iostream>
#include<vector>

#define SIZE 100

using namespace std;

class node{
 public: 
  int data;
  node* next;	
};

class stacklist{
 public:
  stacklist()
   {
     top = NULL;
   }	
   
   	void push(int d);
   	void pop();
   	void print();
    node *top;
    int isEmpty();
    int count; //head
    int size;
    int stackData;
};

void stacklist :: push(int d)
 {
        node *newTop = new node;
        if(top == NULL)
        {       
            newTop->data = d;
            newTop->next = NULL;
            top = newTop;
        }
        else
        {
            newTop->data = d;
            newTop->next = top;
            top = newTop;
        }
}

void stacklist :: pop()
{
        node * old = top;
        top = top->next;
        count--;
        delete(old);
}

void stacklist :: print()
{
    node *temp;
    temp = top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int stacklist :: isEmpty()
{
  if(top==NULL) return 1;
  else return 0;	
}

class stack{
   public:	
   int arr[100];
   int size;
   
   public:
   
   stack()
    {
      size = 0;	
    } 	
    
    int top();
    int isEmpty();
    void push(int d);
    void pop();
};

int stack :: top()
   {
   	 if(size<=0) 
   	  {
		//cout << "Empty Stack" << endl;
		return -1;
      }
   	 else return arr[size-1];
   }
   
void stack :: push(int d)
   {
   	if(size<SIZE) arr[size++] = d;
   }
   
int stack :: isEmpty()
    {
     if(size==0) return 1;
     return 0;
    }
   
void stack :: pop()
    {
     size--;	
	}   

int main()
{
  stack example;
  
  char c;
  char temp;
  int flag = 1;
	while(true)
    {
    	temp = getchar();
    	if(temp=='\n')
    	break;
      if(temp == '(') example.push(temp);
      else if(temp == ')') 
      {
      	if(example.size<=0)
      	{
		  flag = 0;
		  string str;
		  getline(cin,str);
      	  break;
		  }
		example.pop();
	  }
	}
  if(example.isEmpty()&&flag) cout << "Matched!" << endl;
  else cout << "Unmatched!" << endl;
 // cout<< "Now stack list:" << endl;
  stacklist example2;
  flag = 1;
   while(true)
    {
    	temp = getchar();
    	if(temp=='\n')
    	break;
      if(temp == '(') example2.push(temp);
      else if(temp == ')') 
	  {
	  	if(example2.top==NULL)
	  	{
		  flag = 0;
		  string str;
		  getline(cin,str);
		  break;
		  
		  }
	  example2.pop();
		}
	} 	
  
  if(example2.isEmpty()&&flag) cout << "Matched!" << endl;
  else cout << "Unmatched!" << endl;	
}
