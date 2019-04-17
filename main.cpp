#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "MyString.h"
#include <iostream>

using namespace std;

void DisplayIntro();

void DisplayInstructions();

void ToLowerCase(MyString *str);

bool ValidateInput(MyString input1, MyString input2);

Position ConvertChessNotation(MyString move);

Board board;


int main() {

   MyString  input1, input2;
    COLOR turnColor = board.getTurnColor();
    bool moveSucceed = false;
    Position moveFrom;
    Position moveTo;
    DisplayIntro();

    while (input1 != "quit") {


        board.Draw();

        if(board.endGame())
        {
            COLOR curPlayer=board.getTurnColor();
            string s = curPlayer == Black ? "White" : "Black";

            cout<<s<<" Wins!"<<endl;
            return 0;
        }

        if(board.checkMate())
        {

            return 0;
        }
        do {

            if (board.getTurnColor() == White) {
                cout << endl << "White's turn" << endl;
            } else {
                cout << endl << "Blacks's turn" << endl;
            }

            do {



                cout << "Please enter where to move from: ";

                cin >> input1;
                ToLowerCase(&input1);
                if (input1 == "quit") {
                    return 0;

                } else if (input1 == "help") {

                    DisplayInstructions();

                } else if(input1=="remi") {
                    board.nextTurn();

                    if (board.getTurnColor() == White) {
                        cout << endl << "White's turn" << endl;
                    } else {
                        cout << endl << "Blacks's turn" << endl;
                    }
                    cout << "Please enter if you are agree whit remi!!!(Yes/No)" << endl;
                    cin >> input1;
                    if (input1 == "Yes") {
                        cout << "Game ended whit remi";
                        return 0;
                    } else if (input1 == "No") {
                        cout << "Game continue";
                        board.nextTurn();
                        if (board.getTurnColor() == White) {
                            cout << endl << "White's turn" << endl;
                        } else {
                            cout << endl << "Blacks's turn" << endl;
                        }
                        cout << "Please enter where to move from: ";

                        cin >> input1;
                        ToLowerCase(&input1);
                        cout << "Please enter where to move to: ";
                        cin >> input2;
                        ToLowerCase(&input2);



                        moveFrom = ConvertChessNotation(input1);
                        moveTo = ConvertChessNotation(input2);
                    }

                }
                else
                    {
//

                    cout << "Please enter where to move to: ";
                    cin >> input2;
                    ToLowerCase(&input2);



                    moveFrom = ConvertChessNotation(input1);
                    moveTo = ConvertChessNotation(input2);


                }

            } while (input1 == "help" || !ValidateInput(input1, input2));


            moveFrom = ConvertChessNotation(input1);
            moveTo = ConvertChessNotation(input2);

            if (board.GetPiece(moveFrom)->GetColor() != board.getTurnColor()) {

                cout << "Move Invalid: Wrong color pawn selected" << endl;
                moveSucceed = false;

            } else {


                moveSucceed = board.MovePiece(moveFrom, moveTo);

                if (!moveSucceed) {
                    cout << "Move Invalid" << endl;
                } else {
                    cout << "Move Completed" << endl;
                }
            }
              if(board.checkMate())
              {
                  return 0;
              }

        } while (!moveSucceed );
        board.nextTurn();

    }

    return 0;
}


void DisplayIntro() {

    cout << "\n\n\t\t CHESS  " << endl;

    DisplayInstructions();
    cout << "\n\n\t\t\tPress enter to start game" << endl;
    cin.ignore();
}

void DisplayInstructions() {

    cout << "\nInstructions:" << endl
         << "To move chess pieces, use standard chess algebriac notation(letter(a-h)followed by number (1-8))." << endl
         << "The board is labeled around the edges with the algebriac notation." << endl
         << "It consists of a letter (column), followed by a number (row)." << endl
         << "Pieces are designated by w or b for color, followed by the piece's first char. Note* N = Knight" << endl
         << "At any time you can enter 'Quit' to exit the program ,'Help' to receive these instructions again or 'rmei' <<endl"
            <<  "to end the game with a  draw ." << endl << endl;
}

void ToLowerCase(MyString *str) {
    for (size_t i = 0; i < str->size(); ++i) {
        (*str)[i] = tolower((*str)[i]);
    }
}


bool ValidateInput(MyString input1, MyString input2) {

    if (input1.size() != 2 || input2.size() != 2) {

        cout << "Incorrect input size. Please check that the input is only a letter followed by number" << endl;
    } else {

        Position moveFrom = ConvertChessNotation(input1);
        Position moveTo = ConvertChessNotation(input2);

        if (moveFrom.getRow()< 0 || moveFrom.getRow() > 7 || moveFrom.getCol() < 0 || moveFrom.getCol() > 7) {
            cout << "Currant location out of bounds" << endl;
        } else if (moveTo.getRow() < 0 || moveTo.getRow() > 7 || moveTo.getCol() < 0 || moveTo.getCol() > 7) {
            cout << "Destination location out of bounds" << endl;
        } else {
            return true;
        }
    }

    return false;
}

Position ConvertChessNotation(MyString moveInputStr) {

    Position movePosition;
    movePosition.setCol((int) moveInputStr[0] - 97)  ;
    movePosition.setRow(atoi(&moveInputStr[1]) - 1);
    return movePosition;
}