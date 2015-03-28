#include <iostream>
using namespace std;
class Publication {
	protected:
		string title;
		float price;
		void getdata();
		void putdata();
};

void 
Publication :: getdata() {
		cout<<"\n Enter title : ";
		cin>>title;
		cout<<"\n Enter price : ";
		cin>>price;
}

void 
Publication :: putdata() {
		cout<<"\n Title : "<<title;
		cout<<"\n Price : "<<price;
}

class 
book : private Publication {
	int pages;
	public:
		void getdata();
		void putdata();
};

void 
book :: getdata() {
	Publication :: getdata();
	cout<<"\n Enter no of pages : ";
	cin>>pages;
}
	
void 
book :: putdata() {
	Publication :: putdata();
	cout<<"\n Pages : "<<pages;
}
	
class 
tape : private Publication {
	float time;
	public:
		void getdata();
		void putdata();
};

void 
tape :: getdata() {
	Publication :: getdata();
	cout<<"\n Enter playing time : ";
	cin>>time;
}
	
void 
tape :: putdata() {
	Publication :: putdata();
	cout<<"\n Playing time : "<<time<<endl;
}
	
int
main() {
	book b;
	tape t;
	cout<<"\nEnter details of book : \n"; 
	b.getdata();
	cout<<"\nEnter details of tape : \n"; 
	t.getdata();
	cout<<"\nDetails of book : "<<endl;
	b.putdata();
	cout<<"\n\nDetails of tape : "<<endl;
	t.putdata();
	return 0;
}
