#include <iostream>
#include <math.h>

using namespace std;
class coord {
	protected:
		float x,y;
	public:
		coord() {
			x=y=0;
		}
		void getcoord();
		void display();	
};

class calc : public coord {
	protected:
		float dist;
	public:
		void cal_distance();
		void putdistance();
};

void
coord :: getcoord() {
	cout<<"\nEnter x and y co-ordinates : ";
	cin>>x>>y;
}

void
coord :: display() {
	cout<<"\n X = "<<x<<" Y = "<<y<<endl; 
}

void
calc :: cal_distance() {
	dist=sqrt(x*x+y*y);	
}

void
calc :: putdistance() {
	cout<<"\nDistance from origin is : "<<dist<<endl;
} 

int
main() {
	calc d1;
	d1.getcoord();
	d1.cal_distance();
	d1.display();
	d1.putdistance();
	return 0;
}
