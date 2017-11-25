#include <iostream>
#include <cstdio>
using namespace std;

class Node {
public:
	Node(int);
	int val;
	Node *left, *right;
	
};

Node::Node(int data) {
	val = data;
	left = right = NULL;
}

class Tree {
public:
	Node *root;
	Tree();
	~Tree();
	void destroy_tree(Node*);
	void insert(Node*, int&);
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);
	int height(Node*);

};

Tree::Tree() {
	root = NULL;
}

Tree::~Tree() {
	destroy_tree(root);
}

void Tree::destroy_tree(Node *node) {
	if(node!=NULL) {
		destroy_tree(node->left);
		destroy_tree(node->right);
		delete node;
	}
}

void Tree::insert(Node *node,int &ele) {
	if(root!=NULL) {
		if(ele<=node->val) {
			if((node->left)!=NULL) insert(node->left, ele);
			else node->left = new Node(ele);
		}
		else {
			if((node->right)!=NULL) insert(node->right, ele);
			else node->right = new Node(ele);
		}
		
	}
	else root = new Node(ele);
	
}

int Tree::height(Node *node) {
	if(node!=NULL)
		return max(height(node->left), height(node->right))+1;
	return 0;
}

void Tree::postorder(Node *node) {
	if(node!=NULL) {
		postorder(node->left);
		postorder(node->right);
		cout<<node->val<<" ";
	}
}

void Tree::inorder(Node *node) {
	if(node!=NULL) {
		inorder(node->left);
		cout<<node->val<<" ";
		inorder(node->right);
	}
}

void Tree::preorder(Node *node) {
	if(node!=NULL) {
		cout<<node->val<<" ";
		preorder(node->left);
		preorder(node->right);
	}
}


int main() {
	Tree tree;
	int n, ele;
	cout<<"Enter no. of elements: ";
	cin>>n;
	cout<<"Enter the "<<n<<" elements"<<endl;
	for(int i=0; i<n; i++) {
		cin>>ele;
		tree.insert(tree.root, ele);
	}
	if(tree.root!=NULL) {
	cout<<"Postorder: ";
	tree.postorder(tree.root);
	cout<<endl; 
	cout<<"Inorder: ";
	tree.inorder(tree.root);
	cout<<endl;
	cout<<"Preorder: ";
	tree.preorder(tree.root);
	cout<<endl;
	cout<<"Height of the tree: "<<tree.height(tree.root)-1<<endl;
	}
	else cout<<"Empty tree"<<endl;
	return 0;
}