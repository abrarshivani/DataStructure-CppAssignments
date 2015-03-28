#include <iostream>
#include <string.h>

class string {
	private:
		char *str;
	public:
		string() {
			str=NULL;		
		}

		string(const char *s) {
			int len=strlen(s);
			strcpy(str,s);		
		}
		
		string(string &a) {
			strcpy(str,a.str);					
		}
		
		void getdata();
		void putdata();
};

void 
string :: getdata() {

}

void 
string :: putdata() {
		
}


int
main() {
	string e1("Hello");
	e1.getdata();
	e1.putdata();
	return 0;
}
