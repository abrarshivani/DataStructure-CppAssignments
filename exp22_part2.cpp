#include <iostream>
#include <cstdlib>
#include "queue.h"
using namespace std;
using namespace lib;
typedef enum {
        EnQ=1,
        DQ,
        show,
        end,
}Menu;

inline void clear();
inline void wait();

int
main(){
        QUEUE<int> Q;
	QUEUE<double> Qd;
        Menu item;
        int choice,choice2;
        int el,tmp=10;
	double d;
        const char * menu[]={	"Enqueue",
                        	"Dequeue",
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
	
                if(item==end)
                	exit(0);
		
		cout<<"\n1. Integer";
		cout<<"\n2. Double";
		cout<<"\nEnter ur choice : ";
    		cin>>choice2;
                	
		switch(item){		
                        case EnQ:
                                cout<<"Enter data : ";                                
                                if(choice2==1){
					cin>>el;
					Q.enqueue(el);
				}else if(choice2 == 2){
					cin>>d;
					Qd.enqueue(d);
				}else
					cout<<"\nPlease enter proper choice";
                                break;

                        case DQ:                                
                                if(choice2==1)
					if(Q.dequeue(el))
						cout<<"Element "<<el<<" is deleted";
                                else if(choice2 == 2)
					if(Qd.dequeue(d))
						cout<<"Element "<<d<<" is deleted";
                                else
					cout<<"\nPlease enter proper choice";
                                
                                break;

                        case show:
				if(choice2==1)
					Q.display();
                                else if(choice2 == 2)
					Qd.display();
                                else
					cout<<"\nPlease enter proper choice";
                                
                                wait();
                                break;
                       
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

