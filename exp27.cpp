#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;
using namespace lib;

class BSTNode {
	public:

	BSTNode(){
		left=right=0;
	}

	BSTNode(const int &el,BSTNode *left=0,BSTNode *right=0){
		info=el;
		this->left=left;
		this->right=right;
	}
	
	int info;
	BSTNode *left,*right;
	
};

class BIN_TREE {
	public:
		BIN_TREE() {
			root=0;
			nodes=0;
		}
		
		~BIN_TREE() {
			clear();
		}
		
		
		bool insert(const int &);
		bool clear();
		void inorder(); 
		void preorder();
		void postorder();
		void visit(const BSTNode *);
		void iterative_preorder();
		void iterative_inorder();
		void iterative_postorder();
			
	protected:
		int nodes;
		BSTNode *root;
		BSTNode * rightmost();
		BSTNode * leftmost();
		bool clear(BSTNode *);
		void inorder(BSTNode *);
		void preorder(BSTNode *);
		void postorder(BSTNode *);
};

bool
BIN_TREE :: insert(const int &el) { 
	BSTNode *tmp,*pre;
	
	tmp = root;

	while(tmp!=0) {
		pre = tmp;
		if(el < tmp->info)
			tmp = tmp->left;	
		else 
			tmp = tmp->right;
	}	
	
	if(root == 0) {
		root = new BSTNode(el);
	}else if(el < pre->info) {
		pre->left=new BSTNode(el);
	}else if(el > pre->info){
		pre->right=new BSTNode(el);
	}else{
		return false;
	}
	
	return true;
}



void
BIN_TREE :: inorder() {
	inorder(root);
}

void 
BIN_TREE :: inorder(BSTNode *p) {
	if(p==NULL)
		return;
	inorder(p->left);
	visit(p);
	inorder(p->right);
}

void
BIN_TREE :: preorder() {
	preorder(root);
}

void 
BIN_TREE :: preorder(BSTNode *p) {
	if(p==NULL)
		return;
	visit(p);
	preorder(p->left);
	preorder(p->right);
}

void
BIN_TREE :: postorder() {
	postorder(root);
}

void 
BIN_TREE :: postorder(BSTNode *p) {
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	visit(p);
}

void 
BIN_TREE :: iterative_preorder() {
	STACK<BSTNode *> stack;
	BSTNode *node;
	if(root) {
		stack.push(root);
		while(!stack.isEmpty()){
			stack.pop(node);
			visit(node);
			if(node -> right != NULL)
				stack.push(node->right);
			if(node -> left != NULL)
				stack.push(node->left);		
		}
	}
}

void
BIN_TREE :: iterative_postorder() {
	BSTNode *tmp=root,*pre=root;
	STACK <BSTNode *> stack;

	while(tmp!=NULL){

		for(;tmp->left!=NULL;tmp=tmp->left){
			stack.push(tmp);
		}

		while(tmp!=NULL && ((tmp->right) ==NULL || (tmp->right)==pre)){
			visit(tmp);
			pre=tmp;
			if(stack.isEmpty())
				return;
			stack.pop(tmp);
		}

		stack.push(tmp);
		tmp=tmp->right;
	}
}

void
BIN_TREE :: iterative_inorder() {
	BSTNode *tmp=root;
	STACK <BSTNode *> stack;

	while(tmp!=NULL){

		for(;tmp->left!=NULL;tmp=tmp->left){
			stack.push(tmp);
		}

		while(tmp!=NULL && (tmp->right) ==NULL){
			visit(tmp);
			if(stack.isEmpty())
				return;
			stack.pop(tmp);
		}

		visit(tmp);
		tmp=tmp->right;
	}
}

void
BIN_TREE :: visit(const BSTNode *p) {
	cout<<"\n"<<p->info;
}


bool
BIN_TREE :: clear() {
	bool result;

	result=clear(root);
	root=0;

	return result;
}

bool
BIN_TREE :: clear(BSTNode *tmp){ /*Same as postorder (because (LRV) first child nodes are visited 
				i.e parent nodes are deleted child nodes and then parent node) 
					instead of visit  delete the node*/ 
	if(tmp==NULL)
		return false;

	clear(tmp->left);
	clear(tmp->right);
	delete tmp;

	return true;
}
enum Menu{
	INSERT=1,
	R_IN,
	R_PRE,
	R_POST,
	I_IN,
	I_PRE,
	I_POST,
	DELETE_ALL,
	END	
};

inline void clear();
inline void wait();

int
main(int argc,char *argv[]){
	BIN_TREE t1;
	Menu item;
	int size_menu,i,choice,data;
	const char *menu[]={	"Insert",
				"Inorder transverse",
				"Preorder transverse",
				"Postorder transverse",
				"Iterative Inorder transverse",
				"Iterative Preorder transverse",
				"Iterative Postorder transverse",
				"Delete all the nodes",
				"Exit"};

	size_menu=sizeof(menu)/sizeof(char *);

	while(1) {
		clear();
		for(i=0;i<size_menu;i++)
			cout<<endl<<i+1<<". "<<menu[i];

		cout<<"\n\nEnter your choice : ";
		cin>>choice;

		item = (Menu) choice;

		switch(item) {

			case INSERT:
				cout<<"\nEnter data to be inserted : ";
				cin>>data;
				
				t1.insert(data);
				break;
			case R_IN:
				t1.inorder();
				wait();
				break;
			case R_PRE:
				t1.preorder();
				wait();
				break;
			case R_POST:
				t1.postorder();
				wait();
				break;
			case I_IN:
				t1.iterative_inorder();
				wait();
				break;
			case I_PRE:
				t1.iterative_preorder();
				wait();
				break;
			case I_POST:
				t1.iterative_postorder();
				wait();
				break;
			case DELETE_ALL:
				t1.clear();
				break;
			case END:
				exit(0);
		}
	}
	return 0;
}

inline void clear() {
	system("clear");
}

inline void wait() {
	cin.get();
	cin.get();
} 
