#include <cstdio>
#include <iostream>
using namespace std;


class Node {

public:
	Node() {
		next = prev = 0; // 0 means null
	}	
	Node(int &dat, Node *n=0, Node *p=0) {
		data = dat;
		next = n;
		prev = p;
	}
	static void print(Node *listTail) {
		while(listTail->data==0 && listTail->prev!=0) listTail = listTail->prev;
		while(listTail!=0) {
			printf("%d", listTail->data);
			listTail = listTail->prev;
		}
	}
	int data, exp;
	Node *next, *prev;
	
	
};


class DLList {

public:
	DLList() {
		head = tail = 0;
	}
	DLList(int len) {
		head = tail = new Node();
		int x = 0;
		int expo = 0;
		while(len--) {
			addToTail(x);
			tail->exp = expo;
			++expo;
		}
		head = head->next;
		head->prev = 0; 
	}
	
	DLList(int len,int value)
	{
	 head = tail = new Node();
	 addToTail(value);
	 tail->exp = 0;
	 head = head->next;
	 head->prev = 0;
	}
	int length();	
	void addToHead(int &);
	void addToTail(int &);
	void input();
	bool great(Node*, int&);
	Node* add(Node *, int);
	Node *head, *tail;
	Node* subtract(DLList, int);
	Node* multiply(Node*, int);
	Node* divide(DLList);
	DLList extract(int);
	void truncate();
};

void DLList::truncate()
{
while(tail->data==0 && tail->prev)
tail  = tail->prev;
tail->next = 0;
}
DLList DLList::extract(int len)
{	
	DLList newlist(len);
	
	Node* newhead = newlist.head;
	truncate();
	Node* list2head = tail;
	int i = 0;
	while(i<len-1)
	list2head = list2head->prev,i++;
	
	while(newhead)
	{
		newhead->data = list2head->data;
		newhead = newhead->next;
		list2head = list2head->next;
		i++;
	}
	//Node::print(newlist.tail);
	//cout<<endl;
return newlist;

}


void DLList::addToHead(int &ele) {
	if(head!=0) {
		head = new Node(ele, head, 0);
		head->next->prev = head;
	}
	else {
		head = tail = new Node(ele);
	}
}

void DLList::addToTail(int &ele) {
	if(tail!=0) {
		tail = new Node(ele, 0, tail);
		tail->prev->next = tail;
	}
	else {
		head = tail = new Node(ele);
	}
}

void DLList::input() {
	char c;
	int j;
	while((c=getchar())!='\n') {
		j = c-'0';
		addToHead(j);
	}
	int i=0;
	for(Node *p=head; p!=0; p=p->next) {
		p->exp = i;
		++i;
	}
	truncate();
}

int DLList::length() {
	return tail->exp+1;
	}

Node* DLList::add(Node *list2, int len2) {
	int len1 = length();
	int maxLen = len1>len2 ? len1 : len2;
	DLList newList(++maxLen); // can be optimized
	/*
	Over here, try to optimize
	Instead of finding maxLen and initializing the whole list, add nodes one by one 
	and fill in the data after addition and taking into account carry
	Do if possible
	*/
	Node *list1 = head;
	Node *list3 = newList.head;
	int carry = 0;
	int sum;
	while(list1!=0 && list2!=0) {
		sum = list1->data+list2->data+carry;
		list3->data = (sum%10);
		carry = sum/10;
		list1 = list1->next;
		list2 = list2->next;
		list3 = list3->next;
	}
	while(list1!=0) {
		sum = list1->data+carry;
		list3->data = (sum%10);
		carry = sum/10;
		list1 = list1->next;
		list3 = list3->next;
	}
	while(list2!=0) {
		sum = list2->data+carry;
		list3->data = (sum%10);
		carry = sum/10;
		list2 = list2->next;
		list3 = list3->next;
	}
	list3->data = carry;
	return list3; 
}

bool DLList::great(Node* list2, int &len2){
	Node* list1 = tail;
	int len1 = length();
	if (len1>len2)
	return true;
	else if(len1<len2)
		return false;
	else {
		while(list2!=0)
		{
			if(list2->data < list1->data)
				return true;
			else if(list2->data > list1->data)
				return false;
			else
			{
				list2 = list2->prev;
				list1 = list1->prev;
			}
		}
	}
	return true; // to prevent -0 from getting printed
}

Node* DLList::subtract(DLList list2, int len2)	{
	Node* a;Node *b;
	Node* list2tail = list2.tail;
	Node* list2head = list2.head;
	Node* list1head = head;
	bool toret1;
	if(great(list2tail, len2))
		a = list1head,b = list2head, toret1=true;
	else {
		a = list2head, b = list1head, toret1=false;
		printf("-");
	}
	while(a!=0)
	{
		if(b!=0)
		{	
			a->data = a->data-b->data;
			b = b->next;
		}
			if((a->data)<0)
			{
				a->data = a->data+10;
				 (a->next)->data -= 1;
		}
		a = a->next;

	}	
	truncate();
	list2.truncate();
	if(toret1) return tail;
	else return list2tail;
}

Node* DLList::multiply(Node* list2, int len2)
{	
	Node* list1 = head;
    int len1 = length();
	Node *a = list1, *b = list2;
	DLList newlist(len1+len2+1);
	int i = 0;
	for(; a!=0; a=a->next) {
		int j = 0;
		b = list2;
		for(; b!=0;b= b->next){
			int k = 0;
			Node* counter = newlist.head;
			while(k<i+j) { 
				counter = counter->next;
				k++;
			}
			counter->data = counter->data + a->data*b->data;
			j++;
		}
		i++;
	}
	int carry=0;
	Node *p=newlist.head;
	while(p!=0) {
		p->data += carry;
		carry = p->data/10;
		p->data %= 10;
		p = p->next;
	}
	
/*
	Node *check = newlist.tail;
		while(check)
	{
		cout<<check->exp<<" "<<check->data<<endl;
		check = check->prev;
	}
*/
	newlist.truncate();
	return newlist.tail;	
}

Node* DLList::divide(DLList a){
	truncate();
	a.truncate();
	int len1 = length();
	int len2 = a.length();
	int length = len1-len2+1;
	if(len1<len2)
	length = 1;
	DLList newlist(length);
	int value = 0;
	Node* list2tail = a.tail;
	while(list2tail->data==0)
	list2tail = list2tail->prev;
	
	while(great(a.tail,len2))
	{	
	
		len1 = tail->exp+1;
		Node* list1tail = tail;
		//Node::print(tail);
		//cout<<endl;
		int flag = 0;
		Node* point1 = list1tail;
		Node* point2 = list2tail;
		while(point2){
		if(point1->data>point2->data)
		{
		value = a.length(),flag = 1;
		break;
		}
		else
		if(point1->data<point2->data)
		{value = a.length()+1,flag = 1;
		break;
		}
		point2=point2->prev;
		point1 = point1->prev;
		}
		if(!flag)
		value = a.length();
//		cout<<flag<<endl;
//		cout<<value<<endl;	
	DLList portion = extract(value);
	Node* portion_tail = portion.tail;
	//some problem in portion.length() should be checked out
//	Node::print(portion.tail);
//	cout<<endl;
/*	Node* c = portion.tail;
		while(c)
		{
		cout<<c->exp<<" "<<c->data<<endl;
		c = c->prev;
		}
		*/
	Node* producttail;	
	int i;
	//	cout<<tail->exp+1<<" "<<len2<<endl;
	for(i = 9;i>=1;i--)
	{
		DLList newlist(1,i);
	//Node::print(newlist.tail);
	//	cout<<endl;
	
		producttail = a.multiply(newlist.head,newlist.length());
		while(producttail->data==0)
		producttail = producttail->prev;
		while(portion_tail->data==0)
		portion_tail = portion_tail->prev;
		if(value==a.length() && producttail->exp+1>portion_tail->exp+1)
		continue;
			int productlen = (producttail->exp)+1;
		//	cout<<productlen<<endl;
		//cout<<portion.great(producttail,productlen)<<endl;
		if(!portion.great(producttail,productlen))
		continue;
		else
		break;
	}
//	cout<<i<<endl;
		Node* chec = tail;
//	Node::print(chec);
//	cout<<endl;
//	Node::print(producttail);
//	cout<<endl;
	//Node* check = list1tail;
	if(value==a.length()+1  && producttail->exp+1 == a.length())
	list1tail = list1tail->prev;
	
	while(producttail->prev)
	{
	//	cout<<producttail->data<<" "<<list1tail->data<<endl;
	producttail = producttail->prev;
	list1tail = list1tail->prev;
}
//	cout<<producttail->data<<" "<<list1tail->data<<endl;
	//cout<<1<<endl;
	while(list1tail)
	{
		if(producttail)
		{
				//cout<<list1tail->data<<" "<<producttail->data<<endl;
			list1tail->data = list1tail->data-producttail->data;
			producttail = producttail->next;
	
		}
		if(list1tail->data<0)
		{
			
			list1tail->data = list1tail->data+10;
			list1tail->next->data -= 1;
		}
		list1tail = list1tail->next;
	}
	//cout<<1<<endl;
	truncate();
	int k = 0;
	Node* newhead = newlist.head;
	while(k<len1-value)
	{
	newhead = newhead->next,k++;
}
	//	cout<<newhead->exp<<endl;
	newhead->data = i;
	//Node* check = newlist.tail;
	//Node::print(newlist.tail);
	//cout<<endl;
	}
	cout<<"remainder is "<<endl;
	Node* check = tail;
	truncate();
	Node::print(check);
	cout<<endl;
	newlist.truncate();
	cout<<"quotient is" <<endl;
	return newlist.tail;
}





int main() {
	
	DLList a,b;
	printf("Enter first number for addition: ");
	a.input();
	printf("Enter second number for addition: ");
	b.input();
	Node::print(a.add(b.head, b.length()));
	printf("\n");

	DLList c,d;
	printf("Enter first number for subtraction: ");
	c.input();
	printf("Enter second number for subtraction: ");
	d.input();
	Node::print(c.subtract(d, d.length()));
	printf("\n");
	
	DLList e,f;
	printf("Enter first number for multiplication: ");
	e.input();
	printf("Enter second number for multiplication: ");
	f.input();

	Node::print(e.multiply(f.head,f.length()));
	printf("\n");	

	DLList g,h;
	printf("Enter first number for division: ");
	g.input();
	printf("Enter second number for division: ");
	h.input();
	g.truncate();
	h.truncate();
	Node::print(g.divide(h));
	printf("\n");
	return 0;
}





