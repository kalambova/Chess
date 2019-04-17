//
// Created by eleonora on 26.05.18.
//

#include "Knight.h"

Knight::Knight(COLOR color, const Position& pos):Piece(color,pos) {
this->name="N";
}


Knight::~Knight() {

}


 bool Knight::ValidateMove(const Position& moveToPos) {
    bool validMove=false;
    if(moveToPos.getRow()==pos.getRow()+2||moveToPos.getRow()==pos.getRow()-2)
    {
        if(moveToPos.getCol()==pos.getCol()-1||moveToPos.getCol()==pos.getCol()+1)
        {
            if(board.GetPiece(moveToPos)==NULL)
            {
                validMove=true;
            }
            else
            {
                if(board.GetPiece(moveToPos)->GetColor()!=board.GetPiece(pos)->GetColor())
                {
                    validMove=true;
                }
            }
        }
    }
    else
        {
        if(moveToPos.getCol()==pos.getCol()+2||moveToPos.getCol()==pos.getCol()-2)
        {
            if(moveToPos.getRow()==pos.getRow()-1||moveToPos.getRow()==pos.getRow()+1)
            {
                if(board.GetPiece(moveToPos)==NULL)
                {
                    validMove=true;
                }
                else {
                    if(board.GetPiece(moveToPos)->GetColor()!=board.GetPiece(pos)->GetColor())
                    {
                        validMove=true;
                    }
                }
            }
        }

        }

    return validMove;
}