
#ifndef CELL_H
#define	CELL_H
#include <cstdlib>
#include <iostream>
using namespace std;
class Cell {
public:
	Cell(int x, string y);
	Cell(int x);
	Cell() {}
	void set(int x, string y);
	void setX(int x);
	void setY(string y);
	void setPlayer(char player);
	int getX()const;
	string getY()const;
	char getPlayer()const;
	int convertToInt(const string strCol)const;
	string convertToStr(int num)const;
		
	bool operator< (const Cell other);
	bool operator> (const Cell other);
	bool operator<= (const Cell other);
	bool operator>= (const Cell other);
	bool operator== (const Cell other);
	bool operator!= (const Cell other);
	Cell operator++ ();				 // Prefix operator ++
	Cell operator++ (int);			// Postfix operator ++
	Cell operator-- ();				 // prefix operator --
	Cell operator-- (int);			 // postfix operator --

private:
	int X;
	string Y;
	char Player;
};



#endif	/* CELL_H */


