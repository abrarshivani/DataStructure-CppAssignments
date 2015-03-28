#include <iostream>
using namespace std;

class serial {
	private:
		char title[20];
		int serialcode,noofepisodes;
		float duration;
	public:
		serial () {
			noofepisodes=10;
			duration=30;
		}
		void Newserial();
		void Otherentries(int,float);
		void Dispdata();
};

void 
serial :: Newserial() {
		cout<<"\n Enter serialcode : ";
		cin>>serialcode;

		cout<<"\n Enter title : ";
		cin>>title;
}

void 
serial :: Otherentries(int noof ,float time) {
		noofepisodes=noof;
		duration=time;
}


void 
serial :: Dispdata() {
		cout<<"\n Title : "<<title;
		cout<<"\n Serial Code : "<<serialcode;
		cout<<"\n Noofepisodes : "<<noofepisodes;
		cout<<"\n Duration : "<<duration<<endl;
}


int
main() {
	int noof;
	float duration;
	serial e1;
	e1.Newserial();
	cout<<"\n Enter Noopepisodes & Duration : ";
	cin>>noof>>duration;
	e1.Otherentries(noof,duration);
	e1.Dispdata();
	return 0;
}
