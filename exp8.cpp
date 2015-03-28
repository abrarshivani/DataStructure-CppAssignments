#include <iostream>
using namespace std;

class EMPLOYEE {
	private:
		string name;
		int number;
		float salary;
	public:
		EMPLOYEE () {
			name="";
			number=0;
			salary=0;
		}
		void getdata();
		void putdata();
};

void 
EMPLOYEE :: getdata() {
		cout<<"\n Enter name : ";
		cin>>name;
		cout<<"\n Enter number : ";
		cin>>number;
		cout<<"\n Enter salary : ";
		cin>>salary;
}

void 
EMPLOYEE :: putdata() {
		cout<<"\n Name : "<<name;
		cout<<"\n Number : "<<number;
		cout<<"\n Salary : "<<salary<<endl;
}


int
main() {
	EMPLOYEE e1;
	e1.getdata();
	e1.putdata();
	return 0;
}
