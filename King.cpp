//
// Created by eleonora on 26.05.18.
//

#include "King.h"
#include "Pawn.h"

King::King(COLOR color, const Position& pos):Piece(color,pos) {
this->name="K";

}

King::~King() {

}

 bool King::ValidateMove(const Position &moveToPos) {
    bool validMove=false;
    if(this->pos.getCol()==moveToPos.getCol())
    {
        if(moveToPos.getRow()==(this->pos.getRow()-1)||moveToPos.getRow()==(this->pos.getRow()+1)) {
            if (board.GetPiece(moveToPos) == NULL) {
                validMove = true;
            } else {
                if (board.GetPiece(pos)->GetColor() != board.GetPiece(moveToPos)->GetColor()) {
                    validMove = true;
                }
            }

        }

    }
    else {
        if (this->pos.getRow() == moveToPos.getRow()) {
            if (moveToPos.getCol() == (this->pos.getCol() - 1) || moveToPos.getCol() == (this->pos.getCol() + 1)) {
                if (board.GetPiece(moveToPos) == NULL) {
                    validMove = true;
                } else {
                    if (board.GetPiece(pos)->GetColor() != board.GetPiece(moveToPos)->GetColor()) {
                        validMove = true;
                    }
                }


            }

        } else {
            if (moveToPos.getRow() == (this->pos.getRow() + 1) || moveToPos.getRow() == (this->pos.getRow() - 1)) {
                if (moveToPos.getCol() == (this->pos.getCol() + 1) || moveToPos.getCol() == (this->pos.getCol() - 1)) {
                    if (board.GetPiece(moveToPos) == NULL) {
                        validMove = true;
                    } else {
                        if (board.GetPiece(pos)->GetColor() != board.GetPiece(moveToPos)->GetColor()) {
                            validMove = true;
                        }
                    }

                }

            }
        }
    }


    return validMove;
}


/*bool King::checkMate() {
    Position pose(pos.getRow()+1,pos.getCol());
    if(board.GetPiece(pose)==)
}*/