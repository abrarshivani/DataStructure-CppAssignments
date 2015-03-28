#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int		//RECTANGLE 
AREA(int l ,int b) {
	return l*b;	
}

int 
AREA(int side) { //SQUARE
	return side*side;	
}

float 
AREA(float r) { //CIRCLE
	return 3.14*r*r;	
}

float 
AREA(int a,int b,int c) { //TRIANGLE USING HERONS FORMULA
	float s;
	s=0.5*(a+b+c);
	return sqrt(s*(s-a)*(s-b)*(s-c));
		
}

enum Menu {
	CIRCLE=1,
	RECT,
	SQ,
	Tr,
	END	
};

inline void clear();
inline void wait();

int
main() {
	int a,b,c,i;
	float r;
	Menu item;
	const char * menu[]={	"Circle",
                        	"Rectangle",
                        	"Square",
                        	"Triangle",
				"Exit"};

	int size_menu=sizeof(menu)/sizeof(char *);
	
	while(1) {
		clear();
		for(i=0;i<size_menu;i++)
			cout<<endl<<i+1<<". "<<menu[i];

		cout<<"\n\nEnter your choice : ";
		cin>>c;

		item = (Menu) c;

		switch(item) {

			case CIRCLE:
				cout<<"\nEnter radius : ";
				cin>>r;
				cout<<"\nArea is : "<<AREA(r)<<endl;
				wait();		
				break;

			case RECT:
				cout<<"\nEnter sides : ";
				cin>>a>>b;
				cout<<"\nArea is : "<<AREA(a,b)<<endl;
				wait();		
				break;


			case SQ:
				cout<<"\nEnter side : ";
				cin>>a;
				cout<<"\nArea is : "<<AREA(a)<<endl;
				wait();		
				break;
			
			case Tr:
				cout<<"\nEnter sides : ";
				cin>>a>>b>>c;
				cout<<"\nArea is : "<<AREA(a,b,c)<<endl;
				wait();		
				break;

			case END:
				exit(0);
		}
	}
	

	return 0;
}

inline void 
clear() {
	system("clear");
}

inline void 
wait() {
	cin.get();
	cin.get();
} 
