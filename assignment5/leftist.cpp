#include<iostream>
#include<cstdio>

using namespace std;


class Node
{
    int element;
    Node *left;
    Node *right;
    int npl;
    Node(int ele, Node *lt=NULL, Node *rt=NULL, int np) {
    	element = ele;
    	left = lt;
    	right = rt;
    	npl = np;
    }
    
};
    

class leftistheap
{
public:
    leftistheap();
    leftistheap (const leftistheap &rhs);
    ~leftistheap();
    bool isempthy()const ;
    bool isfull() const;
    const comparable &findmin() const;
    void insert(const comparable &x);
    void deletemin();
    void deletemin(comparable &minitem);
    void makeempthy();
    void merge(leftistheap &rhs);

    const leftistheap & operator=(const leftistheap &rhs);
private:
    leftistnode<comparable>*root;
    leftistnode<comparable>*merge(leftistnode<comparable>*h1,leftistnode<comparable>*h2)const;
     leftistnode<comparable> * merge1( leftistnode<comparable> *h1,
                                              leftistnode<comparable> *h2 ) const;
            void swapchildren( leftistnode<comparable> * t ) const;
            void reclaimmemory( leftistnode<comparable> * t ) const;
            leftistnode<comparable> * clone( leftistnode<comparable> *t ) const;
        };