
/*
 * File:   main.cpp
 * Author: Emrullah gencoglu
 *
 * Created on November 24, 2015, 10:53 PM
 */

#ifndef REVERSI_H
#define	REVERSI_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "Cell.h"
using namespace std;

namespace myspace {

    class Reversi {
    public:

        Reversi(); //No parameter  constructor
        Reversi(int W);
        Reversi(int W, int H);
        Reversi(const Reversi& gameObject); //Copy constructor
        void setSize(int numOfRow, int numOfColmn);

        inline void setUsed(int need) {
            used = need;
        }

        inline Cell getCell()const {
            return Cell();
        }

        inline int getUsed()const {
            return used;
        }
        void displayBoard()const;
        int getWidth()const;
        int getHeight()const;
        void playGame();
        char isAlive(const int rowX, const int colY)const; //Check Cell is living		
        bool getLivingCells(ifstream& instream); //Get Cells From file
        void saveLivingCells(ofstream& outstream); //Save Cells To file
        void getNewCells(); //Get Cells For New Game
        bool compareGames(const Reversi& other)const;

        int convertToInt(const string strCol)const;
        string convertToStr(int num)const;
        void Resize();
        void addElement(Cell cellElem); //NEW 
        Reversi& operator++();
        Reversi operator++(int);
        Reversi& operator=(const Reversi& rigthSide);
        
        friend ostream& operator<<(ostream& outStream, const Reversi& game);
        ~Reversi(); //Destructor U must use
    private:

        Cell *gameCells;
        int width;
        int height;
        int used; // Number of Element of Array
        int capacity;
        const static char userStone = 'O';
        const static char pcStone = 'X';

        int playComputer();
        int playUser(int row, int col);
        int checkMove(char player);
        int makeMove(int row, int col, char player);
        int makeMoveComputer(char player);
        void getScore();
        bool checkCoordinate(int rowX, int colY); // DONE	
        bool gameEnd();
    };

}

#endif	/* REVERSI_H */

