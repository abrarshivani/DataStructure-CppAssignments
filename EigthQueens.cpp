#include <iostream>
#include "stack.h"

using namespace lib;
using namespace std;
#define unvisited '*'
class ChessBoard {
	public:
	ChessBoard(int x=0) {
		size=x;
	}
	bool makeboard(unsigned);
	bool adjustQueen(int,int);
	bool printboard();
	bool clear();
	char **board;
	private:
	bool add_queen(int,int);
	bool del_queen(int,int);
	int size;
	
};


bool
ChessBoard :: makeboard(unsigned size) {

	int i,j;
	board = new char *[size];
	for(i=0;i<size;i++)
		board[i]=new char[size];
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			board[i][j]=unvisited;
	this->size=size;
}

bool
ChessBoard :: add_queen(int row,int col) {
	int i,j;
	//Mark in line
	for(i=row+1;i<size;i++) {
		if(board[i][col]==unvisited)
			board[i][col]=char(row+48);
	}

	for(i=row+1,j=col+1;i<size && j<size;i++,j++){
			if(board[i][j]==unvisited)
				board[i][j]=char(row+48);
	}
	
	for(i=row+1,j=col-1;i<size && j>=0;i++,j--){
			if(board[i][j]==unvisited)
				board[i][j]=char(row+48);
	}
}

bool
ChessBoard :: del_queen(int row,int col) {
	int i,j;
	//Mark in line
	for(i=row+1;i<size;i++) {
		if(board[i][col]==char(row+48))
			board[i][col]=unvisited;
	}

	for(i=row+1,j=col+1;i<size && j<size;i++,j++){
			if(board[i][j]==char(row+48))
				board[i][j]=unvisited;
	}
	
	for(i=row+1,j=col-1;i<size && j>=0;i++,j--){
			if(board[i][j]==char(row+48))
				board[i][j]=unvisited;
	}
}


bool
ChessBoard :: adjustQueen(int row=0,int col=0) {
	int precol;
	precol=col;
	STACK<int> stack;

	for(;row<size && row >=0;row++) {
		for(col=precol;col<size;col++){
			if(board[row][col] == unvisited) {
				board[row][col]='Q';
				add_queen(row,col);
				break;	
			}
		}

		if(col < size) {  //putting queen done
			precol = 0;
			stack.push(col);
		}else {
			stack.pop(precol);
			--row;
			if(row>=0) {
				board[row][precol] = unvisited;
				del_queen(row,precol);
			
				--row;
				precol++;
			}else return false;	
		}
	}	
}

bool
ChessBoard :: clear() {
	int i,j;
	i=j=0;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			board[i][j]=unvisited;
}

bool
ChessBoard :: printboard() {
	int i,j;
	cout<<endl;
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			if(board[i][j]  == 'Q' || board[i][j] == unvisited)
				cout<<board[i][j]<<" ";
			else
				cout<<unvisited<<" ";
		}
		cout<<"\n";
	}
	clear();
}

int
main() {
	int i;
	int boardsize=2;
	ChessBoard cb1;
	cout<<"\nEnter board size : ";
	cin>>boardsize;
	cb1.makeboard(boardsize);
	for(i=0;i<boardsize;i++) {
		if(cb1.adjustQueen(0,i))
			if(cb1.board[0][i] == 'Q')				//Violating abstraction of class !!!!
				cb1.printboard();
			else
				cb1.clear();
	}
	return 0;
}

