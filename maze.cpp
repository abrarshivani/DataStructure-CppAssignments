#include <iostream>
#include "stack.h"
#include <cstdlib>

using namespace lib;
using namespace std;

#define passage '0'
#define visited '*'
#define start  's'
#define end    'e'

class Maze;

class Cell {
	public:
		Cell() {
			x=y=0;
		}

		Cell(int x,int y) {
			this->x=x;
			this->y=y;
		}
		
		bool operator==(Cell);
		bool operator!=(Cell);
	protected:
		friend class Maze;
		int x,y;
};

bool
Cell :: operator==(Cell tmp) {
	return x==tmp.x && y==tmp.y;
}

bool
Cell :: operator!=(Cell tmp) {
	return !(*this == tmp);
}

class Maze {
	public:

		bool getmaze();
		bool findroute();
		bool printmaze();

	protected:
		bool pushUnvisited(int,int);
		
		Cell entrycell,exitcell;
		STACK<Cell> stack;
		char **maze;
		int size;
};

bool
Maze :: getmaze() {

	int i,j;
	char tmp;

	cout<<"\nNote: Enter your maze in 1's and 0's form";
	cout<<"\nUse s for start point , e for end point , 1 for blocks and 0(zero) for passage";
	cout<<"\n\n\nEnter maze size: ";
	cin>>size;

	//Allocating for maze	
	maze = new char *[size+2];
	for(i=0;i<=size+1;i++) {
		maze[i] = new char[size+2];
	}

	//Setting frame
	for(i=0;i<=size+1;i++) {
		maze[0][i]='1';
		maze[i][0]='1';
		maze[i][size+1]='1';
		maze[size+1][i]='1';
	}

	//Now getting maze from user
	cout<<"\nEnter your design rowise\n";
	for(i=1;i<=size;i++) {
		for(j=1;j<=size;j++) {
			cin>>tmp;
			if(tmp != '\n' && tmp != ' ' && tmp != '\t' && tmp != '\b')
				maze[i][j] = tmp;
			if ( maze[i][j] == start) {
				entrycell.x = i;
				entrycell.y = j;
			}else if(maze[i][j] == end) {
				exitcell.x = i;
				exitcell.y = j;
				
			}
		}
	}

}

bool 
Maze :: pushUnvisited (int row,int col) {
//	if(row > 0  && col>0 &&  row<=size  && col <=size) {
		if(maze[row][col] == passage || maze[row][col] == end) {
			//cout<<"\npushing: "<<row<<col<<"\n\n";
			Cell tmp(row,col);
			stack.push(tmp);
			return true; 
		}
		return false;
//	}
}

bool
Maze :: findroute() {
	int row,col;
	Cell current;
	current = entrycell;
	STACK<char> direction;
	STACK<Cell> visit;
	char vertical = '|',horizontal = '-';
	while( current != exitcell ) {
		
		row = current.x;
		col = current.y;  

		if(current != entrycell) 
			maze[row][col] = visited;
	
		stack.push(current);
						//cout<<row<<col<<"\n\n";
		if(pushUnvisited(row-1,col)) direction.push(vertical); 		//push cell above 			
		else if(pushUnvisited(row+1,col))direction.push(vertical); 	//push cell below 			
		else if (pushUnvisited(row,col+1))direction.push(horizontal); 	//push cell right 			
		else if(pushUnvisited(row,col-1))direction.push(horizontal); 	//push cell left 			
		else {
			stack.pop(current);
			visit.push(current);
		}

		if (!stack.isEmpty())
			stack.pop(current);
		else
			return false;
	}
	cout<<"\nSuccess\n";
	if ( current == exitcell) {
			while(! stack.isEmpty()) {
				stack.pop(current);
				direction.pop(maze[current.x][current.y]);
			}
			while(! visit.isEmpty()) {
				visit.pop(current);
				maze[current.x][current.y]='0';
			}
			maze[entrycell.x][entrycell.y] = 's';
	}	
}

bool
Maze :: printmaze() {
	int i,j;
	cout<<"\n\n";
	for(i=1;i<=size;i++) {
		for(j=1;j<=size;j++) {
			cout<<maze[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int
main() {
	Maze m;
	m.getmaze();
	m.findroute();
	m.printmaze();
	return 0;
}
