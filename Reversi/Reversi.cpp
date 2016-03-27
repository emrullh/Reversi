#include <cstdlib>
#include "Reversi.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace myspace {
    //########################### Consructors ######################################
    //No parameter consructor

    Reversi::Reversi() : width(4), height(4) {
        width = 4;
        height = 4;
        capacity = width*height;
        used = 0;
        gameCells = new Cell[capacity]; //Memory allocate
    }

    Reversi::Reversi(int W) : width(W), height(4), used(4) {
        width = W;
        height = 4;
        capacity = width*height;
        gameCells = new Cell[capacity];
    }

    Reversi::Reversi(int W, int H) : width(W), height(H), used(0) {
        width = W;
        height = H;
        capacity = width*height;
        gameCells = new Cell[capacity];
    }
    //Copy consructor

    Reversi::Reversi(const Reversi& gameObject) : width(gameObject.getWidth()), height(gameObject.getHeight()), used(gameObject.getUsed()) {

        width = gameObject.getWidth();
        height = gameObject.getHeight();
        used = gameObject.getUsed();
        capacity = width*height;
        gameCells = new Cell[capacity]; //Memory allocate
        for (int i = 0; i < used; ++i)
            gameCells[i] = gameObject.gameCells[i];

    }
    //############################### Operator Overloads ##################################//

    //Increment operator prefix

    Reversi& Reversi::operator++() {
        playComputer();

        return *this;
    }
    //Increment operator posfix

    Reversi Reversi::operator++(int) {
        Reversi temp = *this; //copy object (i have  copy consructor)

        playComputer();

        return temp;
    }
    //Assignment operator overload

    Reversi& Reversi::operator=(const Reversi& rigthSide) {
        if (&rigthSide == this)
            return *this;
        else {
            used = rigthSide.getUsed();
            delete[] gameCells;
            gameCells = new Cell[used];
            height = rigthSide.getHeight();
            width = rigthSide.getWidth();
            for (int i = 0; i < used; ++i)
                gameCells[i] = rigthSide.gameCells[i];
        }
        return *this;

    }
    //Stream insertion operator

    ostream& operator<<(ostream& outStream, const Reversi& game) {
        int i = 0;
        outStream << "   ";
        for (i = 0; i < game.getWidth(); ++i)
            outStream << " " << game.convertToStr(i);
        outStream << " " << game.convertToStr(i);

        for (int i = 0; i < game.getWidth(); i++)
            outStream << "  ";
        outStream << endl;
        for (int j = 0; j < game.getHeight(); j++) {
            outStream << "  " << j + 1;
            if (j < 9 && j >= 0)
                outStream << " ";

            outStream << "|";
            for (int i = 0; i < game.getWidth(); i++) {
                if (game.isAlive(j, i) == 'O')
                    outStream << 'O';
                else if (game.isAlive(j, i) == 'X')
                    outStream << 'X';
                else if (game.isAlive(j, i) == '.')
                    outStream << '.';
                outStream << "|";
            }
            outStream << endl;
        }
        return outStream;
    }

    //############################# Reversi Class Functions ######################
    //Getters

    int Reversi::getWidth()const {
        return width;
    }

    int Reversi::getHeight()const {
        return height;
    }
    //Set function

    void Reversi::setSize(int numOfRow, int numOfColmn) {
        if (numOfRow > 3 && numOfColmn > 3) {
            height = numOfRow;
            width = numOfColmn;
            //capacity = height * width;
        } else
            cout << "Not existing sizes\n";


    }

    //Give first value for new game

    void Reversi::getNewCells() {
        Cell temp;
        string strTemp;

        //liveCells.resize(3);
        temp.setX(height / 2 - 1);
        temp.setY(convertToStr(width / 2));
        temp.setPlayer(pcStone);
        addElement(temp);

        temp.setX(height / 2);
        temp.setY(convertToStr(width / 2 - 1));
        temp.setPlayer(pcStone);
        addElement(temp);
        ///
        temp.setX(height / 2 - 1);
        temp.setY(convertToStr(width / 2 - 1));
        temp.setPlayer(userStone);
        addElement(temp);

        temp.setX(height / 2);
        temp.setY(convertToStr(width / 2));
        temp.setPlayer(userStone);
        addElement(temp);

        //numOfLiveCells = 4;
    }
    //Read game cells from file

    bool Reversi::getLivingCells(ifstream& instream) {
        char ch;
        int row = 0;
        char col = 0;
        int maxCol = 0;
        Cell temp;

        //liveCells.resize(3);
        instream.get(ch);
        if (instream.eof())
            return false;
        while (!instream.eof()) {

            if (ch == userStone) {
                temp.setX(row); // living cell's X coordinate
                temp.setY(convertToStr(col));
                temp.setPlayer(ch);
                addElement(temp); // add it to livingCells	
            } else if (ch == pcStone) {
                temp.setX(row); // living cell's X coordinate
                temp.setY(convertToStr(col));
                temp.setPlayer(ch);
                addElement(temp); // add it to livingCells
            } else if (ch == '\n') {
                col = -1; //   if character is \n, col and row
                row += 1; // reinitialized

            }
            col++;
            instream.get(ch);
            if (maxCol < col)
                maxCol = col;
        }

        setSize(row, maxCol); //Set size from file
        //numOfLiveCells += liveCells[0].size() + liveCells[1].size(); // static value is updated
        return true;

    }
    // Save game 

    void Reversi::saveLivingCells(ofstream& outstream) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (isAlive(i, j) == userStone)
                    outstream << userStone;
                else if (isAlive(i, j) == pcStone)
                    outstream << pcStone;
                else if (isAlive(i, j) == '.')
                    outstream << '.';
            }
            outstream << endl;
        }
    }
    //Print board on console

    void Reversi::displayBoard()const {
        int i = 0;
        cout << "   ";
        for (i = 0; i < width; ++i)
            cout << " " << convertToStr(i);
        cout << " " << convertToStr(i);

        for (int i = 0; i < width; i++)
            cout << "  ";
        cout << endl;
        for (int j = 0; j < height; j++) {
            cout << "  " << j + 1;
            if (j < 9 && j >= 0)
                cout << " ";

            cout << "|";
            for (int i = 0; i < width; i++) {
                if (isAlive(j, i) == userStone)
                    cout << userStone;
                else if (isAlive(j, i) == pcStone)
                    cout << pcStone;
                else if (isAlive(j, i) == '.')
                    cout << '.';
                cout << "|";
            }
            cout << endl;
        }
    }
    //

    int Reversi::playComputer() {
        int isValid = -1;
        if (checkMove(pcStone))
            isValid = makeMoveComputer(pcStone);
        else {
            cout << "Computer has no move\n";
            isValid = 0;
        }


        return isValid;
    }
    //

    int Reversi::playUser(int row, int col) {
        int isValid = -1;
        if (checkMove(userStone))
            isValid = makeMove(row, col, userStone);
        else {
            cout << "You haven't move\n";
            isValid = 0;
        }

        return isValid;
    }
    //

    bool Reversi::gameEnd() {
        if (checkMove(userStone) || checkMove(pcStone))
            return true;
        else
            return false;

    }
    //Playing game in here

    void Reversi::playGame() {

        int isValid = -1;
        char resize = 'O';
        cout << "\nIf you want to resize the board,Enter 'n' or 'N'\n ";
        cin >> resize;
        if (resize == 'N' || resize == 'n') { //Give new board size
            Resize(); //Start new game
            getNewCells();
        }
        displayBoard();
        if (gameEnd()) {
            int row = 0;
            string colmn = "";
            while (isValid == -1) {
                cout << "Enter your coordinate (5 A)" << endl;
                cin >> row >> colmn;
                row -= 1;

                isValid = playUser(row, convertToInt(colmn) - 1);
                if (isValid == 0)
                    break;
                else if (isValid == -1)
                    cout << "There is no move for your coordinates, again...\n";
            }
            if (playComputer() == 0)
                cout << "Your Turn !!!\n";
        } else
            cout << "Final Board\n";
        displayBoard();

        getScore();

    }
    //Make move for computer

    int Reversi::makeMoveComputer(char player) {
        int x = 0;
        int y = 0;
        int Valid = -1;

        char opponent = (player == 'O') ? pcStone : 'O';
        for (int i = 0; i < getHeight(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (isAlive(i, j) == player) {
                    for (int rowX = -1; rowX <= 1; rowX++) //search down-up & rigth-left &
                        for (int colY = -1; colY <= 1; colY++) {
                            if (!(rowX == 0 && colY == 0)) {
                                x = i + rowX;
                                y = j + colY;
                                if (isAlive(x, y) == opponent) {
                                    while (isAlive(x, y) == opponent) {
                                        x += rowX;
                                        y += colY;
                                    }
                                    if (isAlive(x, y) == '.' && checkCoordinate(x, y)/*check size*/) {
                                        cout << "Computer played X: " << x + 1 << " -- Y: " << convertToStr(y + 1) << endl;
                                        Valid = makeMove(x, y, pcStone);
                                        return Valid;
                                    }
                                }
                            }
                        }
                }
            }
        }
        return Valid;
    }
    //Controle for move both 

    int Reversi::checkMove(char player) {
        int x = 0;
        int y = 0;
        int Valid = 0;
        char opponent = (player == 'O') ? pcStone : 'O';
        for (int i = 0; i < getHeight(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (isAlive(i, j) == player) {
                    for (int rowX = -1; rowX <= 1; rowX++)
                        for (int colY = -1; colY <= 1; colY++) {
                            if (!(rowX == 0 && colY == 0)) {
                                x = i + rowX;
                                y = j + colY;
                                if (isAlive(x, y) == opponent) {
                                    while (isAlive(x, y) == opponent) {
                                        x += rowX;
                                        y += colY;
                                    }
                                    if (isAlive(x, y) == '.' && checkCoordinate(x, y))
                                        Valid = 1;
                                }
                            }
                        }
                }
            }
        }

        return Valid;
    }
    //Make move for computer & user

    int Reversi::makeMove(int row, int col, char player) {
        int x = 0, y = 0;
        int Valid = -1;
        int code = 0;
        char opponent = (player == 'O') ? pcStone : 'O';
        Cell temp;
        if (isAlive(row, col) == '.') {
            for (int rowX = -1; rowX <= 1; rowX++)
                for (int colY = -1; colY <= 1; colY++) {
                    if (!(rowX == 0 && colY == 0)) {
                        x = row + rowX;
                        y = col + colY;
                        code = 0;
                        while (isAlive(x, y) == opponent) {
                            x += rowX;
                            y += colY;
                            code = 1;
                        }
                        if (isAlive(x, y) == player && code) {
                            x -= rowX;
                            y -= colY;
                            while (isAlive(x, y) == opponent) {

                                //changeMove(x, y, player); //Change stones 
                                for (int i = 0; i < used; ++i)
                                    if (gameCells[i].getX() == x && gameCells[i].getY() == convertToStr(y)) //Change move 
                                        gameCells[i].setPlayer(player);
                                x -= rowX;
                                y -= colY;
                                //temp.set(x, convertToStr(y));
                            }
                            temp.set(x, convertToStr(y));
                            temp.setPlayer(player);
                            addElement(temp);
                            Valid = 1;

                            //return Valid;
                        }


                    }

                }
        }
        //if (Valid != -1)
        //numOfLiveCells++;
        return Valid;
    }
    // Checking a cell is live or dead

    char Reversi::isAlive(const int rowX, const int colY)const {

        for (int i = 0; i < used; ++i) {
            if ((rowX == gameCells[i].getX()) && (colY == convertToInt(gameCells[i].getY()))) {
                if (gameCells[i].getPlayer() == pcStone)
                    return pcStone;
                else if (gameCells[i].getPlayer() == userStone)
                    return userStone;
            }

        }
        return '.';
    }
    //

    bool Reversi::checkCoordinate(int rowX, int colY) {
        // Checking coordinates valid or not 
        if (rowX < 0 || colY < 0)
            return false; // return false when coordinate is invalid
        else if (rowX >= height || colY >= width)
            return false;

        return true; // retrun true when it is valid

    }
    //

    bool Reversi::compareGames(const Reversi& other)const {
        int count = 0;
        int count1 = 0;
        for (int i = 0; i < used; ++i)
            if ((gameCells[i].getPlayer() == pcStone)) //Count computer's moves
                count++;
        for (int i = 0; i < other.getUsed(); ++i)
            if (gameCells[i].getPlayer() == userStone) //Count user's moves
                count1++;
        if (count > count1)
            return true;
        else
            return false;

    }
    //

    void Reversi::getScore() {
        int count = 0;
        for (int i = 0; i < used; ++i)
            if (gameCells[i].getPlayer() == userStone)
                count++;

        cout << "\nScore => User: " << count;
        cout << " Computer: " << getUsed() - count << endl;
    }
    //Convert number

    int Reversi::convertToInt(const string strCol)const {
        int col = 0;
        for (int i = 0; i < (signed)strCol.length(); ++i)
            col = col * 26 + strCol[i] - 64;

        return col;
    }
    //Convert string

    string Reversi::convertToStr(int num)const {
        string strCol = "";
        while (num > 0) {
            strCol = (char) (65 + (num - 1) % 26) + strCol;
            num = (num - 1) / 26;
        }
        return strCol;
    }
    //

    void Reversi::Resize() {
        int numOfRow = 0;
        int numOfColmn = 0;
        do {
            cout << "Enter Board Height & Width at least (4 X 4)\n";
            cin >> numOfRow >> numOfColmn;
            setSize(numOfRow, numOfColmn); //resizes	

        } while (numOfRow < 4 || numOfColmn < 4);

    }

    //Add element	

    void Reversi::addElement(Cell cellElem) {
        if (used >= capacity) {
            capacity *= 2;
            Cell* temp = new Cell[capacity]; //Memory allocate
            for (int i = 0; i < used; ++i)
                temp[i] = gameCells[i];
            delete[] gameCells;
            gameCells = temp;

        }
        gameCells[used] = cellElem; //add element
        used++; //size +1
    }
    //Destructor

    Reversi::~Reversi() {

        delete [] gameCells; //Remove object
    }
}