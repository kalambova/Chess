//
// Created by eleonora on 26.05.18.
//

#include "Bishop.h"


Bishop::Bishop(COLOR color, const Position& pos):Piece(color,pos) {
this->name="B";
}


Bishop::~Bishop() {

}


 bool Bishop::ValidateMove(const Position &moveToPos)
 {
     bool validMove=true;
     if(abs(moveToPos.getRow()-pos.getRow())==abs(moveToPos.getCol()-pos.getCol()))
     {

     for(int i=1;i<moveToPos.getCol()-pos.getCol()&&validMove;i++) {
         if(moveToPos.getRow()>pos.getRow()) {
             Position poseRUp(pos.getRow() + i, pos.getCol() + i);
             if (board.GetPiece(poseRUp) != NULL) {
                 validMove = false;
             }
         }
         if(moveToPos.getRow()<pos.getRow()) {
             Position poseRDown(pos.getRow() - i, pos.getCol() + i);
             if (board.GetPiece(poseRDown) != NULL) {
                 validMove = false;
             }
         }
     }

     if (board.GetPiece(moveToPos) != NULL&&board.GetPiece(pos)->GetColor() == board.GetPiece(moveToPos)->GetColor())
             {
                 validMove =false;
             } else {

                 for(int i=1;i<pos.getCol()-moveToPos.getCol()&&validMove;i++) {

                        if(moveToPos.getRow()<pos.getRow())
                        {
                            Position poseLDown(pos.getRow() - i, pos.getCol() -i);
                            if (board.GetPiece(poseLDown) != NULL) {
                                validMove = false;
                            }
                        }
                        if(moveToPos.getRow()>pos.getRow())
                        {
                            Position poseLUp(pos.getRow() + i, pos.getCol() -i);
                            if (board.GetPiece(poseLUp) != NULL) {
                                validMove = false;
                            }
                        }

                 }

                 if (board.GetPiece(moveToPos) != NULL&&board.GetPiece(pos)->GetColor() == board.GetPiece(moveToPos)->GetColor())
                 {
                     validMove =false;
                 }


                 }
             }


     else validMove=false;



    return validMove;
}