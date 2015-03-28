#include <iostream>

using namespace std;

class student {
	protected:
		int roll;
	public:
		void getroll();
		void putroll();
};

class test:virtual public student {
	protected:
		int marks;
	public:
		void getmarks();
		void putmarks();
};

class sports:virtual public student {

	protected :
		int score;
	public:
		void getscore();
		void putscore();
};

class result:public test,public sports {
	private:
		int total;
	public:
		
		void puttotal();
};

void 
student :: getroll() {
	cout<<"\nEnter roll : ";
	cin>>roll;
}

void 
test :: getmarks() {
	cout<<"\nEnter marks : ";
	cin>>marks;
}

void 
sports :: getscore() {
	cout<<"\nEnter score : ";
	cin>>score;
}

void 
student :: putroll() {
	cout<<"\nRoll: "<<roll;
}

void 
test :: putmarks() {
	cout<<"\nMarks : "<<marks;
}

void 
sports :: putscore() {
	cout<<"\nScore : "<<score;
}

void 
result :: puttotal() {
		putroll();
		putmarks();
		putscore();
	
		total=score+marks;
		cout<<"\nTotal is : "<<total;
}

int
main() {
	result obj;
	obj.getroll();
	obj.getmarks();
	obj.getscore();
	obj.puttotal();
}
