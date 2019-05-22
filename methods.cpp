#include <iostream>
using namespace std;

template <typename R>
struct node 
{
	R key;
	unsigned char height;
	node* left;
	node* right;
	node(R k) { key = k; left = right = 0; height = 1; }
};

template <typename R>
unsigned char height(node<R>* p)
{
	return p?p->height:0;
}

template <typename R>
int bfactor(node<R>* p)
{
	return height(p->right)-height(p->left);
}

template <typename R>
void fixheight(node<R>* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

template <typename R>
node<R>* rotateright(node<R>* p) 
{
	node<R>* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

template <typename R>
node<R>* rotateleft(node<R>* q) 
{
	node<R>* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

template <typename R>
node<R>* balance(node<R>* p)
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; 
}

template <typename R>
node<R>* insert(node<R>* p, R k) 
{
	if( !p ) return new node<R>(k);
	if( k<p->key )
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}

template <typename R>
node<R>* findmin(node<R>* p) 
{
	return p->left?findmin(p->left):p;
}

template <typename R>
node<R>* removemin(node<R>* p) 
{
	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

template <typename R>
node<R>* remove(node<R>* p, R k) 
{
	if( !p ) return 0;
	if( k < p->key )
		p->left = remove(p->left,k);
	else if( k > p->key )
		p->right = remove(p->right,k);	
	else  
	{
		node<R>* q = p->left;
		node<R>* r = p->right;
		delete p;
		if( !r ) return q;
		node<R>* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

template <typename R>
void print_tree(node<R>* root)
{
	cout<<root->key<<' ';
	if(root->left!=NULL)
		print_tree(root->left);
	if(root->right!=NULL)
		print_tree(root->right);
}

template <typename R>
void deleteTree(node<R>* a)  
{  
    if (a == NULL) return;  
  
    deleteTree(a->left);  
    deleteTree(a->right);  
      
    cout << "\n Deleting node1: " << a->key;  
    delete(a);
}

