#include <iostream>
#define max 10

using namespace std;

class STACK{
	int top;
	int storage[max];
	public:
		STACK(){
			top=-1;
		}
		STACK & operator +(int); 
		void  operator -(); 
		int gettop(){
			return storage[top];
		}
};

STACK & STACK::operator+(int element){
	
	storage[++top]=element;
	
}

void  STACK::operator-(){
	if(top!=-1)
		top--;	
}

int
main(){
	STACK s1;
	int ele;	

	cout<<"\nEnter data : ";
	cin>>ele;
	
	s1 = s1 + ele;
	-s1;
	cout<<"\n Stack top element is : "<<s1.gettop();
	
	return 0;
}
