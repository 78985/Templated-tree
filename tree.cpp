#include<iostream>
#include "container.cpp"
using namespace std;

template<typename R>
class tree: public Container<R>
{
	public:
		tree(R k) {
			node<R> a(k);
			this->root=&a;	
		}
		~tree() {
			cout<<endl;
			cout<<"DESTRUCTOR CALLED"<<endl;
			cout<<"=================="<<endl;
			//node<R>* b = this->root;
			//deleteTree(b); //для проверки работоспособности деструктора раскомментируйте эти две строчки. Если вдруг
			// будет вылет, значит, я всё же ошибся. 
		}
		void INSERT(R k) {
			node<R>* p=this->root;
			this->root=insert(p,k);
		}
		void REMOVE(R k) {
			node<R>* p=this->root;
			p=remove(p,k);
			this->root=p; 
		}
		void PRINT(){
			node<R>* p=this->root;
			print_tree(p);
		}
		void HEIGHT() {
			cout<<"HEIGHT: "<<(int)(this->root->height)<<endl;
		}
		void EXISTS(R k) {
			node<R>* cur=this->root;
			int f=0;
			while(f==0)
				{
					if(cur->key==k)
						{
							f=1;
							break;
						}
					if(k>cur->key && cur->right!=NULL)
							cur=cur->right;
					if(k>cur->key && cur->right==NULL)
							break;
					if(k<cur->key && cur->left!=NULL)
							cur=cur->left;
					if(k<cur->key && cur->left==NULL)
							break;
				}
			if(f==1)
				cout<<"ELEMENT"<<" "<<'"'<<k<<'"'<<" "<<"EXISTS IN THE TREE"<<endl;
			else
				cout<<"ELEMENT"<<" "<<'"'<<k<<'"'<<" "<<"DOES NOT EXIST IN THE TREE"<<endl;
		}
	protected:
		node<R>* root;
};
