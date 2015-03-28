#include <iostream>
#include "stack.h"
using namespace std;
using namespace lib;


class EXPRESSION{
	private:
		string infix;
		string postfix;
		bool isop(char);
		int prior(char);
		bool error;
	public:
		void get_exp();
		void infix_postfix();
		void put_post_exp();
};

bool 
EXPRESSION :: isop(char ch){
	if(prior(ch) == -1)
		return false;
	else 
		return true;
}

int 
EXPRESSION :: prior(char n){
	switch(n){
		case '+':case '-': 
			return 1;
			
		case '*':case '/': 
			return 2;
 		case '(':
			return 0;
		default:
			return -1;
	}
}
void 
EXPRESSION :: get_exp(){
	cout<<"Enter expression : ";
	cin>>infix;
}

void 
EXPRESSION :: infix_postfix(){
	STACK<char> op;
	char temp,top;
	int i;
	for(i=0;i<infix.length();i++){
		if(infix[i] == '('){               //Char is (

			op.push(infix[i]);

		}else if(infix[i] == ')'){        //Char is  )
				op.pop(top);
				while(!op.isEmpty() && top!='('){
					postfix+=top;
					op.pop(top);
				}

		}else{//Char is operator or operand 

			if(isop(infix[i])){     //Char is operator
				top=op.get_top();
				while(!op.isEmpty() && prior(infix[i])<=prior(top)){
					op.pop(top);
					postfix+=top;
				}
				op.push(infix[i]);
			}else{			//Char is operand
				postfix+=infix[i];
			}
		}

	}
	for(i=0;op.get_count()>0;i++){ //Empty stack 
		op.pop(temp);
		postfix+=temp;
	}		
}
void 
EXPRESSION :: put_post_exp(){
		cout<<"\nInfix expression is : "<<infix<<endl;
		cout<<"Postfix expression is : "<<postfix<<endl;
}


int
main(){
	EXPRESSION exp1;
	exp1.get_exp();
	exp1.infix_postfix();
	exp1.put_post_exp();
	return 0;	
}
