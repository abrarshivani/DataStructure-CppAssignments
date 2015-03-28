#include <iostream>
#include <cstdlib>
using namespace std;

typedef enum {
	add_start=1,
	add_end,
	del_start,
	del_end,
	del_all,
	rev,
	show,
	end,
}Menu;

void clear();
void wait();
template <class T>
class Node{
public:
	T info;
	Node *next;
	Node() {
		info=0;
		next=NULL;
	}	
};

template <class T>
class SLL{
public:
	SLL(){
		count=0;
		head=NULL;
	}
	void addtostart(T&);
	void addtoend(T&);
	bool delete_start();
	bool delete_end();
	bool delete_all();
	void display();
	bool reverse();
	inline bool isEmpty();
	~SLL(){
		delete_all();
	}
protected:
	int count;
	Node<T> *head;

	};

template <class T>
void SLL<T>::addtostart(T & info){
	Node<T> *new_node;
	new_node=new Node<T>;
	new_node->info=info;
	new_node->next=head;
	head=new_node;
	count++;
}

template <class T>
void SLL<T>::addtoend(T & info){
	Node<T> *new_node,*temp;
	new_node=new Node<T>;
	new_node->info=info;
	if(head==NULL)
		head=new_node;
	else{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=new_node;
	}
	count++;
}

template <class T>
bool SLL<T>::delete_start(){
	Node<T> *temp;
	if(isEmpty()==false){
		temp=head->next;
		delete head;
		head=temp;
		count--;
		return true;
	}
	return false;
}

template <class T>
bool SLL<T>::delete_end(){
	Node<T> *temp;
	if(isEmpty())
		return false;
	else if(head->next==NULL){
		delete head;
		head = NULL;
		return true;
	}else{
		for(temp=head;temp->next->next!=NULL;temp=temp->next);
		delete temp->next;		
		temp->next=NULL;
		return true;
	}
	count--;
}

template <class T>
bool SLL<T>::delete_all(){
	Node<T> *next,*current;
	if(isEmpty()==false){
		for(current=head;next!=NULL;current=next){
			next=current->next;			
			delete current;			
		}
		head=NULL;
		count=0;
		return true;
	}
	return false;
}

template <class T>
bool SLL<T>::reverse(){
	Node<T> *pre,*next,*temp;
	pre=NULL;
	if(isEmpty()==false){
		next=head;
		while(next!=NULL){
			temp=next->next;	
			next->next=pre;
			pre=next;
			next=temp;
		}
		head =pre;
		return true;
	}
	return false;
}

template <class T>
inline bool SLL<T>::isEmpty(){
	return head==NULL;
}

template <class T>
void SLL<T>::display(){
	Node<T> *trans;
	cout<<endl<<"Data : "<<endl;
	for(trans=head;trans!=NULL;trans=trans->next)
		cout<<trans->info<<endl;
}
int
main(){
	SLL<int> l1;
	Menu item;	
	int choice;
	int el;
	const char * menu[]={"Add to start",
			"Add to end",
			"Delete at start",
			"Delete at end",
			"Delete all",
			"Reverse",
			"Display",
			"Exit"};
	
	int size_menu=sizeof(menu)/sizeof(char *);
	while(1){
		clear();
		for(int i=0;i<size_menu;i++)
			cout<<endl<<i+1<<". "<<menu[i];
		cout<<"\nEnter ur choice : ";
		cin>>choice;
		item=(Menu)choice;
		switch(item){
			case add_start:
				cout<<"Enter data : ";
				cin>>el;
				l1.addtostart(el);
				break;
			case add_end:
				cout<<"Enter data : ";
				cin>>el;
				l1.addtoend(el);
				break;
			case del_start:
				l1.delete_start();
				break;
			
			case del_end:
				l1.delete_end();
				break;

			case del_all:
				l1.delete_all();
				break;			

			case rev:
				l1.reverse();
				break;	
	
			case show:
				l1.display();
				wait();
				break;
			case end:
				l1.delete_all();
				exit(0);
		}
	}	
	return(0);
}

inline void clear(){
	system("clear");
}
inline void wait(){
	cin.get();
	cin.get();
}
