//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H


#include "Piece.h"
#include "Board.h"
extern Board board;

class Rook : public Piece {



public:
    Rook(COLOR color, const Position& pos):Piece(color,pos) {
this->name="R";
    }
    ~Rook() {

    }
    virtual bool ValidateMove(const Position & moveToPos)
    {
        bool validMove = true;
        if (this->pos.getCol() == moveToPos.getCol())
        {
            if (moveToPos.getRow() > pos.getRow())
            {
                for (int i = this->pos.getRow() + 1; i < moveToPos.getRow() && validMove; i++)
                {
                    Position pose(i, moveToPos.getCol());

                    if (board.GetPiece(pose) != NULL)
                    {
                        validMove = false;
                    }


                }

                if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() == this->color))
                {
                    validMove = false;
                }
            } else
                {
                for (int i = this->pos.getCol() - 1; i > moveToPos.getCol() && validMove; i--) {
                    Position pose(i, moveToPos.getCol());
                    if (board.GetPiece(pose) != NULL) {
                        validMove = false;
                    }

                }
                if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() == this->color)) {
                    validMove = false;
                }
            }

        } else {
            if (this->pos.getRow() == moveToPos.getRow())
            {

                if (moveToPos.getCol() > pos.getCol()) {
                    for (int i = this->pos.getCol() + 1; i < moveToPos.getCol() && validMove; i++) {
                        Position pose( moveToPos.getRow(),i );

                        if (board.GetPiece(pose) != NULL) {
                            validMove = false;
                        }


                    }

                    if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() == this->color)) {
                        validMove = false;
                    }
                } else {
                    for (int i = this->pos.getCol() - 1; i > moveToPos.getCol() && validMove; i--) {
                        Position pose( moveToPos.getRow(),i );
                        if (board.GetPiece(pose) != NULL) {
                            validMove = false;
                        }

                    }
                    if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() == this->color)) {
                        validMove = false;

                    }
                }

            }else validMove = false;
            }


        return validMove;
    }

};


#endif //CHESS_ROOK_H
