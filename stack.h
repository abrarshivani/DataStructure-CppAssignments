#include <iostream>
#ifndef STACKLIB
#define STACKLIB

namespace lib{

	template <class T>
	
	class Node{
		public:
	        	T info;
	        	Node *next;
        	Node() {
        	        next=NULL;
        	}
	};


	template <class T>
	class STACK{
		public:
		        STACK(){
		                count=0;
		                top=NULL;
		        }

		        void push(T&);
				        
			bool pop(T&);
		        bool delete_all();
			bool reverse();
		        
			void display();		       
			inline T get_top();
			inline int get_count();
		        inline bool isEmpty();
		        ~STACK(){
	                	delete_all();
        		}
		protected:
       		 	int count;
       	 		Node<T> *top;
		
	};

	template <class T>
	void STACK<T>::push(T & info){    //insert @ start
		Node<T> *new_node;
		new_node=new Node<T>;
		new_node->info=info;
		new_node->next=top;
		top=new_node;
		count++;
	}


	template <class T>
	bool STACK<T>::pop(T& data){   //delete @ start
		Node<T> *temp;
		if(isEmpty()==false){
			temp=top->next;
			data = top->info;
			delete top;
			top=temp;
			count--;
			return true;
		}
		return false;
	}

	template <class T>
	bool STACK<T>::delete_all(){
        	Node<T> *next,*current;
        	if(isEmpty()==false){
        	        for(current=top;next!=NULL;current=next){
        	                next=current->next;
        	                delete current;
        	        }
        	        top=NULL;
        	        count=0;
        	        return true;
        	}
        	return false;
	}

	template <class T>
	bool STACK<T>::reverse(){
		Node<T> *pre,*next,*temp;
		pre=NULL;
		if(isEmpty()==false){
			next=top;
			while(next!=NULL){
				temp=next->next;	
				next->next=pre;
				pre=next;
				next=temp;
			}
			top=pre;
			return true;
		}
		return false;
	}

	template <class T>
	inline bool STACK<T>::isEmpty(){
		return top==NULL;
	}

	template <class T> 
	inline int STACK<T>::get_count(){
		return count;
	}
	
	template <class T> 
	inline T STACK<T>::get_top(){
		if(get_count())
			return  top->info;
		return 0;
	}
		
	template <class T>
	void STACK<T>::display(){
		Node<T> *temp;
		temp=NULL;
		if(isEmpty()==false){
			for(temp=top;temp!=NULL;temp=temp->next)
				std::cout<<temp->info;		
		}
	
	}
}
#endif
