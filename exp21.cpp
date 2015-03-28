#include <iostream>
#include <fstream>
using namespace std;

int
main(int argc,char *argv[]) {
	ifstream i(argv[1]);
	ofstream o(argv[2],ios::app);
	char c;
	while (i.good()) { //Checks for eof , fail ,bad => good()
    		c = i.get();      
		if (i.good())
			o.put(c);	      		
  	}

	
}

