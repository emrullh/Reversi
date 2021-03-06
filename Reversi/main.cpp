/*
* File:   main.cpp
* Author: Emrullah gencoglu
*
* Created on November 10, 2015, 03:33 AM
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Reversi.h"
#include "Cell.h"
using namespace std;
using namespace myspace;

void testFiveGamesReference(Reversi& game1, Reversi& game2, Reversi& game3, Reversi& game4, Reversi& game5);
void testFiveGamesValue(Reversi game1, Reversi game2, Reversi game3, Reversi game4, Reversi game5);
void testSingleGameReference(Reversi& game1);

int main(int argc, char** argv) {

	Reversi game1, game2, game3, game4, game5;
	Cell c1(8, "AA"), c2(8, "C"), c3(4, "D"), c4(8, "AF"), c5, c6, c7, a1(3, "AA");

	//Cell class test overload operators

	/*	cout << "Test Of Cell Class Overload \n";
	if (c1 == c2)
	cout << "Esittir ! \n";
	if (c1 > c3)
	cout << "Buyuktur  ! \n";
	if (c3 < c2)
	cout << "Kucuktur  ! \n";
	if (c1 <= c4)
	cout << "Kucuk esit !\n";			// CELL CLASS OVERLOAD
	if (c1 >= c2)
	cout << "Buyuk Esit !\n";
	if (c1 != c3)
	cout << "Esit degil !\n";

	c5 = c1++;  //increment operator
	c6 = c3;    //assign operator
	c7 = c3--;  //decrement operator

	cout << "c1 => " << c1.getX() << "   " << c1.getY() << endl;
	cout << "c6 => " << c6.getX() << "   " << c6.getY() << endl;

	cout << "c5 => " << c5.getX() << "   " << c5.getY() << endl;
	cout << "c7 => " << c7.getX() << "   " << c7.getY() << endl;*/

	
	cout << "\n--------- MENU --------------------------------------- ";
	cout << "\nPlay Single Game: 1 (object:game1)\n";
	cout << "\nPlay Five Game: 2 (TestOfReference => objects:game1,game2,game3,game4,game5)\n";
	cout << "\nPlay Five Game: 3 (TestOfValue => objects:game1,game2,game3,game4,game5)\n";
	cout << "\nPlease enter your choose (number): ";
	int choose=0;
	cin >> choose;
	switch (choose) {
		case 1:
			testSingleGameReference(game1);
			break;
		case 2:		
			testFiveGamesReference(game1, game2, game3, game4, game5);
			break;
		case 3:	
			testFiveGamesValue(game1, game2, game3, game4, game5);
			break;	
	default:
		cout << "\nInvalid choose !!!\n";
	}
	cout << "\nTest of Copy constructor \n";
	Reversi game6(game1); // This is for test
	cout << game6;
	cout << "\nTest of Operator++ (posfix) \n";
	++game1;
	cout << game1;
	cout << "\nTest of Operator++ (prefix) \n";
	game1++;
	cout << game1;
	cout << "\nTest of Operator =  \n";
	game1 = game1;
	cout << game1;
	cout << "\nTest of Operator =  \n";
	game2 = game1;
	cout << game2;	
	cout << "\nTest of Compare Games \n";
	if (game1.compareGames(game6))
		cout << "First game better than second\n"; //Call compare function
	else
		cout << "Second game better than first\n";


	return 0;
}


// ################################# TEST_FUNCTIONS_ #####################################


void testSingleGameReference(Reversi& game) {
	ifstream instream1;
	ofstream outstream1;
	
	char newGame, state;
	//-------------------------------------------- GAME-Single --------------------------------------------//
	cout << "\n\t//---------------------- GAME-Single -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream1.open("singleFile.text");
		//instream.get(ch);
		if (!game.getLivingCells(instream1)) {
			cout << "File is empty !!\n You play new game..\n";
			game.Resize();
			game.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream1.close();
	}
	else {
		game.Resize();     //play new game
		game.getNewCells();
	}

	outstream1.open("singleFile.text");
	do {
		cout << "\n ------------ GameSingle's Board ------------- \n";
		game.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E' ).\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	game.saveLivingCells(outstream1);
	outstream1.close();

}

void testFiveGamesReference(Reversi& game1,Reversi& game2,Reversi& game3,Reversi& game4,Reversi& game5) {
	
	ifstream instream1,
		instream2,
		instream3,
		instream4,
		instream5;
	ofstream outstream1,
		outstream2,
		outstream3,
		outstream4,
		outstream5;
	char newGame, state;
	cout << "\n################# CALL BY REFERENCE #######################\n";
	//-------------------------------------------- GAME-1 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-1 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream1.open("file1.text");
		//instream.get(ch);
		if (!game1.getLivingCells(instream1)) {
			cout << "File is empty !!\n You play new game..\n";
			game1.Resize();
			game1.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream1.close();
	}
	else {
		game1.Resize();     //play new game
		game1.getNewCells();
	}

	outstream1.open("file1.text");
	do {
		cout << "\n ------------ Game1's Board ------------- \n";
		game1.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E' ).\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	game1.saveLivingCells(outstream1);
	outstream1.close();
	//-------------------------------------------- GAME-2 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-2 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream2.open("file2.text");
		//instream.get(ch);
		if (!game2.getLivingCells(instream2)) {
			cout << "File is empty !!\n You play new game..\n";
			game2.Resize();
			game2.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream2.close();
	}
	else {
		game2.Resize();     //play new game
		game2.getNewCells();
	}
	outstream2.open("file2.text");
	do {
		cout << "\n ------------ Game2's Board ------------- \n";
		game2.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game2.saveLivingCells(outstream2);
	outstream2.close();
	cout << "\nTest of compares Games Function\n";
	if (game1.compareGames(game2))
		cout << "The first game is better for the user\n";
	else
		cout << "The second game is better for the user\n";

	//-------------------------------------------- GAME-3 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-3 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream3.open("file3.text");
		//instream.get(ch);
		if (!game3.getLivingCells(instream3)) {
			cout << "File is empty !!\n You play new game..\n";
			game3.Resize();
			game3.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream3.close();
	}
	else {
		game3.Resize();     //play new game
		game3.getNewCells();
	}
	outstream3.open("file3.text");
	do {
		cout << "\n ------------ Game3's Board ------------- \n";
		game3.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game3.saveLivingCells(outstream3);
	outstream3.close();
	//-------------------------------------------- GAME-4 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-4 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream4.open("file4.text");
		//instream.get(ch);
		if (!game4.getLivingCells(instream4)) {
			cout << "File is empty !!\n You play new game..\n";
			game4.Resize();
			game4.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream4.close();
	}
	else {
		game4.Resize();     //play new game
		game4.getNewCells();
	}
	outstream4.open("file4.text");
	do {
		cout << "\n ------------ Game4's Board ------------- \n";
		game4.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game4.saveLivingCells(outstream4);
	outstream4.close();
	//-------------------------------------------- GAME-5 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-5 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream5.open("file5.text");
		//instream.get(ch);
		if (!game5.getLivingCells(instream5)) {
			cout << "File is empty !!\n You play new game..\n";
			game5.Resize();
			game5.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream5.close();
	}
	else {
		game5.Resize();     //play new game
		game5.getNewCells();
	}
	outstream5.open("file5.text");
	do {
		cout << "\n ------------ Game5's Board ------------- \n";
		game5.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game5.saveLivingCells(outstream5);
	outstream5.close();

}

void testFiveGamesValue(Reversi game1, Reversi game2, Reversi game3, Reversi game4, Reversi game5) {

	ifstream instream1,
		instream2,
		instream3,
		instream4,
		instream5;
	ofstream outstream1,
		outstream2,
		outstream3,
		outstream4,
		outstream5;
	char newGame, state;
	cout << "\n###################### CALL BY VALUE #######################\n";
	//-------------------------------------------- GAME-1 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-1 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream1.open("file1.text");
		//instream.get(ch);
		if (!game1.getLivingCells(instream1)) {
			cout << "File is empty !!\n You play new game..\n";
			game1.Resize();
			game1.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream1.close();
	}
	else {
		game1.Resize();     //play new game
		game1.getNewCells();
	}

	outstream1.open("file1.text");
	do {
		cout << "\n ------------ Game1's Board ------------- \n";
		game1.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E' ).\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	game1.saveLivingCells(outstream1);
	outstream1.close();
	//-------------------------------------------- GAME-2 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-2 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream2.open("file2.text");
		//instream.get(ch);
		if (!game2.getLivingCells(instream2)) {
			cout << "File is empty !!\n You play new game..\n";
			game2.Resize();
			game2.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream2.close();
	}
	else {
		game2.Resize();     //play new game
		game2.getNewCells();
	}
	outstream2.open("file2.text");
	do {
		cout << "\n ------------ Game2's Board ------------- \n";
		game2.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game2.saveLivingCells(outstream2);
	outstream2.close();
	cout << "\nTest of compares Games Function\n";
	if (game1.compareGames(game2))
		cout << "The first game is better for the user\n";
	else
		cout << "The second game is better for the user\n";

	//-------------------------------------------- GAME-3 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-3 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream3.open("file3.text");
		//instream.get(ch);
		if (!game3.getLivingCells(instream3)) {
			cout << "File is empty !!\n You play new game..\n";
			game3.Resize();
			game3.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream3.close();
	}
	else {
		game3.Resize();     //play new game
		game3.getNewCells();
	}
	outstream3.open("file3.text");
	do {
		cout << "\n ------------ Game3's Board ------------- \n";
		game3.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game3.saveLivingCells(outstream3);
	outstream3.close();
	//-------------------------------------------- GAME-4 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-4 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream4.open("file4.text");
		//instream.get(ch);
		if (!game4.getLivingCells(instream4)) {
			cout << "File is empty !!\n You play new game..\n";
			game4.Resize();
			game4.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream4.close();
	}
	else {
		game4.Resize();     //play new game
		game4.getNewCells();
	}
	outstream4.open("file4.text");
	do {
		cout << "\n ------------ Game4's Board ------------- \n";
		game4.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game4.saveLivingCells(outstream4);
	outstream4.close();
	//-------------------------------------------- GAME-5 --------------------------------------------//
	cout << "\n\t//---------------------- GAME-5 -----------------------------//\n";
	cout << "\nIf You want to begin save game,Enter ('s' or 'S')\n";
	cin >> newGame;
	if (newGame == 'S' || newGame == 's') {
		instream5.open("file5.text");
		//instream.get(ch);
		if (!game5.getLivingCells(instream5)) {
			cout << "File is empty !!\n You play new game..\n";
			game5.Resize();
			game5.getNewCells();
		}
		else
			cout << "Saved game is loaded.\n";

		instream5.close();
	}
	else {
		game5.Resize();     //play new game
		game5.getNewCells();
	}
	outstream5.open("file5.text");
	do {
		cout << "\n ------------ Game5's Board ------------- \n";
		game5.playGame();
		cout << "\nIf You want to continue,Enter ('e' or 'E') .\n";
		cin >> state;
	} while (state == 'E' || state == 'e');
	//cout<<"Your game was save"
	game5.saveLivingCells(outstream5);
	outstream5.close();

}
