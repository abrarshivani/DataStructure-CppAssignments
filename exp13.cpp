#include <iostream>

using namespace std;


class complex{
	float x;
	float y;

	public:
		complex(){
			x=y=0;
		}
		complex(float a,float b){
			x=a;
			y=b;
		}
		void getdata();
		complex  operator +(complex &);
		void putdata();
	
};
complex complex::operator +(complex &t){
	complex temp;
	temp.x=t.x+x;
	temp.y=t.y+y;	
	return temp;
};

void complex::getdata(){
	cout<<"\nEnter x and y : ";
	cin>>x>>y;
}

void complex::putdata(){
	cout<<"\nValue is : "<<x<<" + "<<y<<endl;
}

int
main(){
	complex a(10,20),b,c;
	b.getdata();
	c=a+b;
	c.putdata();
	return 0;
}
