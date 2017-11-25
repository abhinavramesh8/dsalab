template <class T>
class Node{
public: 
	T data;
	Node<T>* next;	
	Node(T);
};

template <class T>
Node<T>::Node(T c) {
	data = c;
	next = NULL;
}

template <class T>
class Stack{
public:
	Stack()
	{
    	top = NULL;
	}	
	void push(T);
   	T pop();
    Node<T> *top;
    bool isEmpty();
};

template <class T>
void Stack<T>::push(T d)
 {
	if(isEmpty()) top = new Node<T>(d);
	else {
		Node<T> *newNode = new Node<T>(d);
		newNode->next = top;
		top = newNode;
	}
	
}

template <class T>
T Stack<T>::pop()
{
	T c = top->data;
	Node<T> *newTop = top->next;
	delete(top);
	top = newTop;
    return c;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return (top==NULL);
}
