//
// Created by eleonora on 25.05.18.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Piece.h"
#include "Board.h"
extern Board board;

class Pawn: public Piece
{
    bool doubleJumpAvailable;


public:
    Pawn(COLOR color, const Position& pos):Piece(color,pos)
    {
        this->name="P";
        this->doubleJumpAvailable = true;
    }
    ~Pawn() {

    }

    virtual bool ValidateMove(const Position&  moveToPos)
    {
        bool validMove = false;
        int allowableMove1 = 1;
        int allowableMove2 = 2;

        if (color == Black) {
            allowableMove1 = -1;
            allowableMove2 = -2;
        }
        if (moveToPos.getRow() == pos.getRow() + allowableMove1 && moveToPos.getCol() == pos.getCol() && board.GetPiece(moveToPos) == NULL) {
            validMove = true;

           this-> doubleJumpAvailable = false;

        }

        else if((this->pos.getRow()==6&&this->color==Black)||(this->pos.getRow()==1&&this->color==White))
        {
            this->doubleJumpAvailable=true;
        }
        else this->doubleJumpAvailable=false;
            if (doubleJumpAvailable == true && moveToPos.getRow() == (pos.getRow() + allowableMove2) && moveToPos.getCol() == pos.getCol()
                 && board.GetPiece(moveToPos) == NULL)   {

            validMove = true;
        }

        else if (moveToPos.getRow() == pos.getRow() + allowableMove1 && (moveToPos.getCol() == pos.getCol() - 1 || moveToPos.getCol() == pos.getCol() + 1) ) {


            if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() != this->color) )  {
                validMove = true;
            }
        }


        return validMove;
    }



};


#endif //CHESS_PAWN_H
