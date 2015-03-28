#include <iostream>
#include <cstdlib>

using namespace std;


class DLL_NODE{
	public:
	DLL_NODE() {
		prev=next=NULL;
	}
	int info;
	DLL_NODE *prev;
	DLL_NODE *next;
};

class DLL {
	public:
	DLL() {
		count=0;
		head=rear=NULL;
	}

	DLL_NODE * addtostart(int &);
	DLL_NODE * addtoend(int &);
	bool  add_n_node(int &,int &);

	bool delete_start();
	bool delete_end();
	bool delete_all();
	bool delete_n_node(int &);

	bool isEmpty();
	bool rev();

	void display();
	int get_count();

	protected:
		
		int count;
		DLL_NODE *head;
		DLL_NODE *rear;	
		DLL_NODE * get_node(int &);	
};

DLL_NODE * 
DLL :: addtostart(int &data) {
	DLL_NODE *current;
	
	current=new DLL_NODE;
	if(current!=NULL){
		current->info=data;
			if(head==NULL)
				rear=current;
			else{
				head->prev=current;
				current->next=head;
			}
			head=current;
			count++;
		
			return current;
		
	}
	return NULL;
}


DLL_NODE * 
DLL :: addtoend(int &data) {
	DLL_NODE *current;
		current=new DLL_NODE;
		
		if(current!=NULL){
			current->info=data;
		
			if(rear==NULL)
				head=current;
			else{
				current->prev=rear;
				rear->next=current;
			}
			rear=current;
			count++;
			return current;
		
	}
	return NULL;
}

bool 
DLL :: add_n_node(int &data ,int &node){
	
	DLL_NODE *current,*newnode;
	current=get_node(node);
	newnode = new DLL_NODE;
	if(current){	
	
		if(current==head){
			addtostart(data);
		}else{	
		
				newnode->info=data;
				newnode->next=current;
				newnode->prev=current->prev;
				current->prev=newnode;
				newnode->prev->next=newnode;
				count++;		
			}			
	}else if(node == count +1)
		addtoend(data);
	else
		return false;
	return true;		
}	


bool 
DLL :: delete_start() {
	DLL_NODE *current;
	if(isEmpty()==true)
			return false;
	else{
		current=head->next;
		delete head;
		if(current==NULL)
			rear=NULL;
		else
			current->prev=NULL;		
		head=current;
		count--;
		return true;
	}
	return false;
}
	
bool 
DLL :: delete_end() {
	DLL_NODE *current;
	current=NULL;
	if(!isEmpty()) {
		count--;
		current=rear->prev;
		free(rear);
		if(current==NULL) {
			head=rear=NULL;
			return true;
		}
		current->next=NULL;
		rear=current;
		return true;
	}
	return false;
}

bool 
DLL :: rev() {
	DLL_NODE *current,*temp;
	if(!isEmpty()){
		temp=current=rear;
		rear=head;
		head=current;
		while(temp!=NULL){
			temp=current->prev;
			current->prev=current->next;
			current->next=temp;
			current=temp;	
		}
		
		return true;
	}
	return false;
}

bool 
DLL :: delete_all() {
	DLL_NODE *next,*current;

	if(!isEmpty()){
			current=head;
			while(current!=NULL){
				next=current->next;
				free(current);
				current=next;		
			}
			head=rear=NULL;
			count=0;
			return true;
	}
	return false;
}

bool 
DLL :: delete_n_node(int &node){
	
	DLL_NODE *current;
	current=get_node(node);
	if(current){	
	
		if(current==head){
			delete_start();
		}else{
				if(rear==current)
					delete_end();		
				else{
					current->prev->next=current->next;
					current->next->prev=current->prev;
					free(current);
					(count)--;
				}
					
			}
			
			return true;
		}
	return false;		
}	



DLL_NODE * 
DLL :: get_node(int &node){
	DLL_NODE *current,*prev;
	int count;
	prev=NULL;
	if(!isEmpty() && node>0){
		count=(this->count);
		if(count>=node){
			current=head;
			if(node==1){
				return current;
			}else if(node==count)
				return rear;
			else{
				for(;node>1;node--){
					current=current->next;
				}
				return current;
			     }
				
		}
	}
	return NULL;		
}

bool 
DLL :: isEmpty(){
	return  count==0;
}	


void 
DLL :: display(){
	DLL_NODE *node;
	cout<<"\nData:\n";
	if(isEmpty()==false){
		for(node=head;node!=NULL;node=node->next)
			cout<<" "<<node->info<<endl;
		cout<<"\nCount is "<<count<<endl;
	}
}


inline int 
DLL :: get_count(){
	return count;
}


typedef enum {
	add_start=1,
	add_end,
	add_n,
	del_start,
	del_end,
	del_all,
	del_n,
	reverse,
	show,
	end,
}Menu;

void clear();
void wait();

int
main(int argc,char *argv[])
{
	DLL l1;
	int choice,data,i,size_menu,pos;
	Menu item;	
	const char *menu[]={	"Add to start",
				"Add to end",
				"Add nth node",
				"Delete at start",
				"Delete at end",
				"Delete all",
				"Delete nth node",
				"Reverse",
				"Display",
				"Exit"};
	

	size_menu=sizeof(menu)/sizeof(char *);

	while(1){
		clear();

		for(i=0;i<size_menu;i++)
			cout<<"\n"<<i+1<<". "<<menu[i];
	
		cout<<"\nEnter your choice  : ";
		cin>>choice;
		item=(Menu)choice;
		switch(item){
			case add_start:
				cout<<"\nEnter data : ";
				cin>>data;
				l1.addtostart(data);		
				break;
			case add_end:
				cout<<"\nEnter data : ";
				cin>>data;
				l1.addtoend(data);
				break;	
			case add_n:
				cout<<"\nEnter data : ";
				cin>>data;
				cout<<"\nEnter position : ";
				cin>>pos;
				l1.add_n_node(data,pos);
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
			case del_n:
				cout<<"\nEnter position : ";
				cin>>data;
				l1.delete_n_node(data);
				break;
			case reverse:
				l1.rev();
				break;
			case show:
				l1.display();
				wait();
				break;
			case end:
				l1.delete_all();
				exit(0);
			default:
				cout<<"\nPlease enter proper number";
		}
	}

	return 0;
}


void clear(){
	system("clear");
}

void wait(){
	cin.get();
	cin.get();
}

