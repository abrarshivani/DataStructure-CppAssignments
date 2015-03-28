#include <iostream>

#ifndef QUEUE_H
#define QUEUE_H

namespace lib{
	using namespace std;

	template <class T>

	class QNode{
		public:
			T info;
			QNode<T> *next;
	
		QNode(T info=0,QNode *next=NULL){
			this->info=(T)info;
			this->next=next;
		}
	};

	template <class T>
	
	class QUEUE{
		public:
		QUEUE(){
			count=0;
			head=NULL;
			rear=NULL;
		}

		~QUEUE(){
			clear();
		}	
		bool enqueue(T&);
		bool dequeue(T&);
		bool clear();
		inline bool isempty();
		void display();
		protected:
			int count;
			QNode<T> * head;
			QNode<T> * rear;
	};

	template <class T> 
	bool 
	QUEUE<T>:: enqueue(T &data) { // insert @ end

		QNode<T> *temp;

		temp = new QNode<T>;
	
		if(temp){   
			temp->info=data;

			if(head==NULL){
				head=rear=temp;
			}else{
				rear->next=temp;
				rear=temp;
			}
				count++;
			return true;
		}
		return false;
	}	

	template <class T>
	bool 
	QUEUE<T> :: dequeue(T &data) {  // delete  @ start
		
		QNode<T> *temp;
	
		if(head){

			temp=head->next;
			data=head->info;

			if(head->next == NULL)
				rear=NULL;

			delete head;
			head = temp;
			count--;

			return true;
		}
		return false;
	}

	template <class T>
	bool QUEUE<T>::clear(){
        	QNode<T> *next,*current;
        	if(isempty()==false){
        	        for(current=head;next!=NULL;current=next){
        	                next=current->next;
        	                delete current;
        	        }
        	     	head=rear=NULL;
        	        count=0;
        	        return true;
        	}
        	return false;
	}

	template <class T>
	inline bool 
	QUEUE<T> :: isempty() {
		return count==0;
	}

	template <class T>
	void
	QUEUE<T> :: display() {

		for(QNode<T> *temp=head;temp!=NULL;temp=temp->next){
			std::cout<<"\n "<<temp->info;
		}
	}

}
#endif

