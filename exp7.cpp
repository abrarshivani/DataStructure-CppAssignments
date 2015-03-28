#include <iostream>
using namespace std;

class circle{
	private:
		float radius,area;
	public:
		circle () {
			radius=0;
			area=0;
		}
		void getdata();
		void caldata();
		void putdata();
		~circle() {
			cout<<"\n\t\tCalled destructor\n\n\n";
		}
};

void 
circle :: getdata() {
		cout<<"\n Enter radius : ";
		cin>>radius;
}

void
circle :: caldata() {
	area=3.14*radius*radius;
}
void 
circle :: putdata() {
		cout<<"\n radius : "<<radius;
		cout<<"\n Area : "<<area<<endl;
}


int
main() {
	circle e1;
	e1.getdata();
	e1.caldata();
	e1.putdata();
	return 0;
}
