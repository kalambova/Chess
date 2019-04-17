//
// Created by eleonora on 26.05.18.
//

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
#include <iostream>

using namespace std;

Board::Board() {
    InitializePieces();
}
Board::~Board() {
}

void Board::Draw() {
    for (int row = 7; row >= 0; row--) {

        cout << "   ";
        for (int col = 0; col < 8; col++) {
            cout << "----";
        }
        cout << "-" << endl;

        cout << row + 1 << "  ";
        for (int col = 0; col < 8; col++) {
            cout << "| ";
            Piece *currPiece = board[row][col].GetPiece();
            if (currPiece != NULL) {
                currPiece->Draw();
            } else {
                cout << " ";
            }
            cout << " ";
        }


        cout << "|" << endl;

    }

    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "----";
    }
    cout << "-" << endl;

    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout <<"  "<< (char) (col + 97) <<" ";
    }
    cout << endl << endl;

}


void Board::InitializePieces() {


    // Pawns
    for (int col = 0; col < 8; col++) {
        Position blackPawnPos = {6,col};
        board[blackPawnPos.getRow()][blackPawnPos.getCol()].SetPiece(new Pawn(Black, blackPawnPos));

        Position whitePawnPos = {1,col};
        board[whitePawnPos.getRow()][blackPawnPos.getCol()].SetPiece(new Pawn(White, whitePawnPos));
    }


    // Rooks
    Position whiteRookPos = {0,0};
    board[whiteRookPos.getRow()][whiteRookPos.getCol()].SetPiece(new Rook(White, whiteRookPos));

    Position whiteRookPos2 = {0,7};
    board[whiteRookPos2.getRow()][whiteRookPos2.getCol()].SetPiece(new Rook(White, whiteRookPos2));

    Position blackRookPos = {7,0};
    board[blackRookPos.getRow()][blackRookPos.getCol()].SetPiece(new Rook(Black, blackRookPos));

    Position blackRookPos2 = {7,7};
    board[blackRookPos2.getRow()][blackRookPos2.getCol()].SetPiece(new Rook(Black, blackRookPos2));


    // Knights
    Position whiteKnightPos = {0,1};
    board[whiteKnightPos.getRow()][whiteKnightPos.getCol()].SetPiece(new Knight(White, whiteKnightPos));

    Position whiteKnightPos2 = {0,6};
    board[whiteKnightPos2.getRow()][whiteKnightPos2.getCol()].SetPiece(new Knight(White, whiteKnightPos2));

    Position blackKnightPos = {7,1};
    board[blackKnightPos.getRow()][blackKnightPos.getCol()].SetPiece(new Knight(Black, blackKnightPos));

    Position blackKnightPos2 = {7,6};
    board[blackKnightPos2.getRow()][blackKnightPos2.getCol()].SetPiece(new Knight(Black, blackKnightPos2));


    // Bishops
    Position whiteBishopPos = {0,2};
    board[whiteBishopPos.getRow()][whiteBishopPos.getCol()].SetPiece(new Bishop(White, whiteBishopPos));

    Position whiteBishopPos2 = {0,5};
    board[whiteBishopPos2.getRow()][whiteBishopPos2.getCol()].SetPiece(new Bishop(White, whiteBishopPos2));

    Position blackBishopPos = {7,2};
    board[blackBishopPos.getRow()][blackBishopPos.getCol()].SetPiece(new Bishop(Black, blackBishopPos));

    Position blackBishopPos2 = {7,5};
    board[blackBishopPos2.getRow()][blackBishopPos2.getCol()].SetPiece(new Bishop(Black, blackBishopPos2));


    // King
    Position whiteKingPos = {0,4};
    board[whiteKingPos.getRow()][whiteKingPos.getCol()].SetPiece(new King(White, whiteKingPos));

    Position blackKingPos = {7,4};
    board[blackKingPos.getRow()][blackKingPos.getCol()].SetPiece(new King(Black, blackKingPos));


    // Queens
    Position blackQueenPos = {7,3};
    board[blackQueenPos.getRow()][blackQueenPos.getCol()].SetPiece(new Queen(Black, blackQueenPos));

    Position whiteQueenPos2 = {0,3};
    board[whiteQueenPos2.getRow()][whiteQueenPos2.getCol()].SetPiece(new Queen(White, whiteQueenPos2));




}


bool Board::MovePiece(const Position& fromPos,const  Position &toPos) {


    bool moveCompleted = false;

    Piece *origPiece = board[fromPos.getRow()][fromPos.getCol()].GetPiece();

    if (origPiece != NULL && origPiece->ValidateMove(toPos) && IsWithinBoard(toPos)) {
        origPiece->SetPosition(toPos);
        board[toPos.getRow()][toPos.getCol()].SetPiece(origPiece);
        board[fromPos.getRow()][fromPos.getCol()].Clear();

        moveCompleted = true;
    }

    return moveCompleted;
}


Piece* Board::GetPiece(const Position &piecePos) {
    return board[piecePos.getRow()][piecePos.getCol()].GetPiece();
}


bool Board::IsWithinBoard(const Position& pos) {
    if ((0 <= pos.getRow() && pos.getRow() <= 7) && (0 <= pos.getCol() && pos.getCol()<= 7)) {
        return true;
    }

    return false;
}
Piece* Board::king()
{

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {

            Position pos(i,j);
            Piece* piece = GetPiece(pos);
            if(piece==NULL)
            {
                continue;
            }
            if(piece->getName() =="K" && piece->GetColor() == turnColor)
            {
                return piece;

            }
        }
    }
    return NULL;
}
bool Board::endGame()
{
    return king()==NULL;
}
bool Board ::checkMate()
{

    ///find KING
    Piece* kingg = king();
    COLOR kingColor=kingg->GetColor();
    MyString king(kingColor== Black ? "Black" : "White")  ;
    MyString winerKing(kingColor== Black ? "White" : "Black");
    Piece* checkpiece=isInCheck(kingg);

    if (checkpiece!=NULL)
    {
        cout<<king<<" King is in check\n";
        for (int i = 0; i <8; i++) {
            for (int j = 0; j < 8; j++) {
                Position pos(i,j);
                Piece *piece = GetPiece(pos);
                if (piece != NULL && piece->GetColor() == turnColor) {
                    // try to move
                    const Position newpos=tryToMove(piece);
                    //cout<<newpos.getRow()<<","<<newpos.getCol()<<endl;
                    bool canMove= !(newpos == Position());
                    if (canMove ){
                        bool b = MovePiece(pos,newpos);
                        if (b) {
                            if(!isInCheck(kingg) ) {
                                MovePiece(newpos,pos);
                                return false;
                            } else {
                                MovePiece(newpos,pos);
                                cout<<king<<" King is in checkmate"<<endl;
                                cout<<winerKing<<" Wins!"<<endl;
                                return true;
                            }
                        } else { cout<<"ne moje"; }
                    }
                }
            }
        }
    } else {
        return false;
    }

    return true;
}
 Piece * Board::isInCheck(Piece* king)
{


    for(int i=0;i<8;i++) {
        for (int j = 0; j < 8; j++) {
            Position pos(i,j);
            Piece *piece = GetPiece(pos);
            if(piece==NULL)
            {
                continue;
            }
            if (piece->getName() == "P" && piece->GetColor() != turnColor &&
                piece->ValidateMove(king->getPos()) == true) {
               return piece;
            }

            if (piece->getName() == "B" && piece->GetColor() != turnColor &&
                piece->ValidateMove(king->getPos()) == true) {
                return piece;
            }

            if (piece->getName() == "K" && piece->GetColor() != turnColor &&
                piece->ValidateMove(king->getPos()) == true) {
                return piece;
            }

            if (piece->getName() == "N" && piece->GetColor() != turnColor &&
                piece->ValidateMove(king->getPos()) == true) {
                return piece;
            }

            if (piece->getName() == "Q" && piece->GetColor() != turnColor &&
                piece->ValidateMove(king->getPos()) == true) {
                return piece;
            }

            if (piece->getName() == "R" && piece->GetColor() != turnColor &&
                piece->ValidateMove(king->getPos()) == true) {
                return piece;
            }
        }
    }
    return  NULL;
}

const Position Board::tryToMove( Piece *x) {
    Piece* kingg=king();
    Piece* checkpiece=isInCheck(kingg);

    if(abs(checkpiece->getPos().getRow()-kingg->getPos().getRow())==abs(checkpiece->getPos().getCol()-kingg->getPos().getCol())) {
        if (checkpiece->getPos().getCol() > kingg->getPos().getCol()) {
            for (int i = 1; i < checkpiece->getPos().getCol() - kingg->getPos().getCol(); i++) {
                if (checkpiece->getPos().getRow() > kingg->getPos().getRow()) {
                    Position poseRUp(kingg->getPos().getRow() + i, kingg->getPos().getCol() + i);
                    if (x!=kingg&&x->ValidateMove(poseRUp) == true) {

                    }
                }
                if (checkpiece->getPos().getRow() < kingg->getPos().getRow()) {
                    Position poseRDown(kingg->getPos().getRow() - i, kingg->getPos().getCol() + i);
                    if (x!=kingg&&x->ValidateMove(poseRDown) == true) {
                        return poseRDown;
                    }
                }
            }
        }
    }
        else {
            for (int i = 1; i < kingg->getPos().getCol() - checkpiece->getPos().getCol(); i++) {

                if (checkpiece->getPos().getRow() < kingg->getPos().getRow()) {
                    Position poseLDown(kingg->getPos().getRow() - i, kingg->getPos().getCol() - i);
                    if (x!=kingg&&x->ValidateMove(poseLDown) ==true) {
                        return poseLDown;
                    }
                }
                if (checkpiece->getPos().getRow() > kingg->getPos().getRow()) {
                    Position poseLUp(kingg->getPos().getRow() + i, kingg->getPos().getCol() - i);
                    if (x!=kingg&&x->ValidateMove(poseLUp) ==true) {
                        return poseLUp;
                    }
                }

            }
        }

    if (kingg->getPos().getCol() == checkpiece->getPos().getCol()) {
        if (checkpiece->getPos().getRow() > kingg->getPos().getRow()) {
            for (int i = kingg->getPos().getRow() + 1; i < checkpiece->getPos().getRow() ; i++) {
                Position poseUp(i, checkpiece->getPos().getCol());
                if(x==kingg)
                {
                    for(int i=0;i<8;i++)
                    {
                        for(int j=0;j<8;j++)
                        {
                            Position pose(i,j);
                            if(kingg->ValidateMove(pose)==true&&!(pose==poseUp))
                            {
                                return pose;
                            }
                        }
                    }
                }
                if(x!=kingg&&x->ValidateMove(poseUp)==true)
                {
                                return poseUp;


                }

            }
        }
        else {
            for (int i = kingg->getPos().getRow() - 1; i > checkpiece->getPos().getRow(); i--) {
                Position pose(i, checkpiece->getPos().getCol());
                if (x!=kingg&&x->ValidateMove(pose)== true) {
                 return pose;
                }

            }
        }
    }
    if (kingg->getPos().getRow() == checkpiece->getPos().getRow()) {

        if (checkpiece->getPos().getCol() > kingg->getPos().getCol()) {
            for (int i = kingg->getPos().getCol() + 1; i < checkpiece->getPos().getCol(); i++) {
                Position pose(checkpiece->getPos().getRow(), i);

                if (x!=kingg&&x->ValidateMove(pose) == true) {
                    return pose;
                }


            }
        } else {
            for (int i = kingg->getPos().getCol() - 1; i > checkpiece->getPos().getCol(); i--) {
                Position pose(checkpiece->getPos().getRow(), i);
                if (x!=kingg&&x->ValidateMove(pose)== true) {
                    return pose;
                }
            }
        }
    }
    if(x->ValidateMove(checkpiece->getPos())==true)
    {
        return checkpiece->getPos();
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            Position pose(i,j);
            if(kingg->ValidateMove(pose)==true)
            {
                return pose;
            }
        }
    }


    return Position();
}

void Board::nextTurn() {


    if (turnColor == White) {
        turnColor = Black;
    } else if (turnColor == Black) {
        turnColor = White;
    }

}
bool Board::isPlayerInTurnPiece(const Position &piecePos) {
    return GetPiece(piecePos)->GetColor()==turnColor;
}
const COLOR Board:: getTurnColor()const
{
    return turnColor;
}
void Board::inturn()
{
    if (turnColor == White) {
        cout << endl << "White's turn" << endl;
    } else {
        cout << endl << "Blacks's turn" << endl;
    }
}