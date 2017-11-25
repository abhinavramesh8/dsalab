#include<iostream>
#include<cstdio>
 
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val) {
    	data = val;
    	height = 1;
    	left = NULL;
    	right = NULL;
    }
};
 

int height(Node *N)
{
    if (N != NULL) return N->height;
    return 0;
}
 
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}
 
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}
 
int getBalance(Node *N)
{
    if (N != NULL) return height(N->left) - height(N->right);
    return 0;
    
}
 
Node *insert(Node *node, int val)
{
    if (node == NULL)
        return new Node(val);
 
    if (val < node->data)
        node->left  = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    else 
        return node;
 
   
    node->height = 1 + max(height(node->left), height(node->right));
 
    int balance = getBalance(node);
 
    // left-left
    if (balance > 1 && val < node ->left->data)
        return rightRotate(node);
 
    // right right
    if (balance < -1 && val > node->right->data)
        return leftRotate(node);
 
   	// left-right
    if (balance > 1 && val > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // right-left
    if (balance < -1 && val < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    
    return node;
}
 
void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) {
	if(root!=NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void inOrder(Node *root) {
	if(root!=NULL) {
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
 

int main()
{
	Node *root = NULL;
 /*	int n, ele;
	cout<<"Enter no. of elements: ";
	cin>>n;
	cout<<"Enter the "<<n<<" elements"<<endl;
	for(int i=0; i<n; i++) {
		cin>>ele;
		root = insert(root, ele);
	} */
  	root = insert(root, 10);
  	root = insert(root, 20);
  	root = insert(root, 30);
  	root = insert(root, 40);
  	root = insert(root, 50);
  	root = insert(root, 60);
 
  	printf("Preorder traversal of the AVL tree is \n");
  	preOrder(root);
  	cout<<endl;
  	printf("Inorder traversal of the AVL tree is \n");
  	inOrder(root);
  	cout<<endl;
  	printf("Postorder traversal of the AVL tree is \n");
  	postOrder(root);
  	cout<<endl;
  	return 0;
}