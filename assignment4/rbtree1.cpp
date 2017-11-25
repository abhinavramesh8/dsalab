#include <cstdio>
#include<iostream>
using namespace std;
 
enum Color {RED, BLACK};
 
struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
 
    Node(int data)
    {
       this->data = data;
       left = right = parent = NULL;
    }
};
 
class RBTree
{
public:
    Node *root;
    void leftrotate(Node *&, Node *&);
    void rightrotate(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void preorder();
    void postorder();
};
 
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;
 
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}

void preorderHelper(Node *root)
{
	 if (root == NULL)
        return;
	
	cout<<root->data<<" "; 
    preorderHelper(root->left);
    preorderHelper(root->right);
}

void postorderHelper(Node* root)
{
	if (root == NULL)
        return;
	
    postorderHelper(root->left);
    postorderHelper(root->right);
	cout<<root->data<<" "; 
}
 
Node* BSTInsert(Node* root, Node *ele)
{
    if (root == NULL)
       return ele;
 
    if (ele->data < root->data)
    {
        root->left  = BSTInsert(root->left, ele);
        root->left->parent = root;
    }
    else if (ele->data > root->data)
    {
        root->right = BSTInsert(root->right, ele);
        root->right->parent = root;
    }
 
    return root;
}
 
 
void RBTree::leftrotate(Node *&root, Node *&ele)
{
    Node *noderight = ele->right;
 
    ele->right = noderight->left;
 
    if (ele->right != NULL)
        ele->right->parent = ele;
 
    noderight->parent = ele->parent;
 
    if (ele->parent == NULL)
        root = noderight;
 
    else if (ele == ele->parent->left)
        ele->parent->left = noderight;
 
    else
        ele->parent->right = noderight;
 
    noderight->left = ele;
    ele->parent = noderight;
}
 
void RBTree::rightrotate(Node *&root, Node *&ele)
{
    Node *nodeleft = ele->left;
 
    ele->left = nodeleft->right;
 
    if (ele->left != NULL)
        ele->left->parent = ele;
 
    nodeleft->parent = ele->parent;
 
    if (ele->parent == NULL)
        root = nodeleft;
 
    else if (ele == ele->parent->left)
        ele->parent->left = nodeleft;
 
    else
        ele->parent->right = nodeleft;
 
    nodeleft->right = ele;
    ele->parent = nodeleft;
}
 
void RBTree::fixViolation(Node *&root, Node *&ele)
{
    Node *parentnode = NULL;
    Node *grand_parentnode = NULL;
 
    while ((ele != root) && (ele->color != BLACK) &&
           (ele->parent->color == RED))
    {
 
        parentnode = ele->parent;
        grand_parentnode = ele->parent->parent;
 
        if (parentnode == grand_parentnode->left)
        {
 
            Node *unclenode = grand_parentnode->right;
 
            if (unclenode != NULL && unclenode->color == RED)
            {
                grand_parentnode->color = RED;
                parentnode->color = BLACK;
                unclenode->color = BLACK;
                ele = grand_parentnode;
            }
 
            else
            {
                if (ele == parentnode->right)
                {
                    leftrotate(root, parentnode);
                    ele = parentnode;
                    parentnode = ele->parent;
                }
 
                rightrotate(root, grand_parentnode);
                swap(parentnode->color, grand_parentnode->color);
                ele = parentnode;
            }
        }
 
        else
        {
            Node *unclenode = grand_parentnode->left;
 
            if ((unclenode != NULL) && (unclenode->color == RED))
            {
                grand_parentnode->color = RED;
                parentnode->color = BLACK;
                unclenode->color = BLACK;
                ele = grand_parentnode;
            }
            else
            {
                if (ele == parentnode->left)
                {
                    rightrotate(root, parentnode);
                    ele = parentnode;
                    parentnode = ele->parent;
                }
 
                leftrotate(root, grand_parentnode);
                swap(parentnode->color, grand_parentnode->color);
                ele = parentnode;
            }
        }
    }
 
    root->color = BLACK;
}
 
void RBTree::insert(const int &data)
{
    Node *ele = new Node(data);
 
    root = BSTInsert(root, ele);
 
    fixViolation(root, ele);
}
 
void RBTree::inorder()     {  inorderHelper(root);}
void RBTree::preorder() {preorderHelper(root);}
void RBTree::postorder() {postorderHelper(root);}

int main()
{
    RBTree tree;
 
   // tree.insert(10);
    //tree.insert(20);
   // tree.insert(30);
   // tree.insert(40);
   // tree.insert(50);
    //tree.insert(60);
 
	int n;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	
	cout<<"Enter the elements "<<endl;
	for(int i = 0;i<n;i++)
	{
		int x;
		cin>>x;
		tree.insert(x);	
	}
 
 
    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();
    cout<<endl;
    cout<<"Preorder Traversal of Created Tree\n";
	tree.preorder();
	cout<<endl;
	cout<<"Postorder Traversal of Created Tree\n";
	tree.postorder(); 
	cout<<endl;
 
    return 0;
}
