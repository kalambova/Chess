//
// Created by eleonora on 26.05.18.
//

#include "Queen.h"

Queen::Queen(COLOR color,const Position &pos):Piece(color,pos) {
this->name="Q";
}

Queen::~Queen() {

}

 bool Queen::ValidateMove(const Position &moveToPos) {
     bool validMove=true;
     if(abs(moveToPos.getRow()-pos.getRow())==abs(moveToPos.getCol()-pos.getCol())) {

         for (int i = 1; i < moveToPos.getCol() - pos.getCol() && validMove; i++) {
             if (moveToPos.getRow() > pos.getRow()) {
                 Position poseRUp(pos.getRow() + i, pos.getCol() + i);
                 if (board.GetPiece(poseRUp) != NULL) {
                     validMove = false;
                 }
             }
             if (moveToPos.getRow() < pos.getRow()) {
                 Position poseRDown(pos.getRow() - i, pos.getCol() + i);
                 if (board.GetPiece(poseRDown) != NULL) {
                     validMove = false;
                 }
             }
         }

         if (board.GetPiece(moveToPos) != NULL &&
             board.GetPiece(pos)->GetColor() == board.GetPiece(moveToPos)->GetColor()) {
             validMove = false;
         } else {

             for (int i = 1; i < pos.getCol() - moveToPos.getCol() && validMove; i++) {

                 if (moveToPos.getRow() < pos.getRow()) {
                     Position poseLDown(pos.getRow() - i, pos.getCol() - i);
                     if (board.GetPiece(poseLDown) != NULL) {
                         validMove = false;
                     }
                 }
                 if (moveToPos.getRow() > pos.getRow()) {
                     Position poseLUp(pos.getRow() + i, pos.getCol() - i);
                     if (board.GetPiece(poseLUp) != NULL) {
                         validMove = false;
                     }
                 }

             }

             if (board.GetPiece(moveToPos) != NULL &&
                 board.GetPiece(pos)->GetColor() == board.GetPiece(moveToPos)->GetColor()) {
                 validMove = false;
             }
         }
     }
            else {if (this->pos.getCol() == moveToPos.getCol())
                 {
                     if (moveToPos.getRow() > pos.getRow())
                     {
                         for (int i = this->pos.getRow() + 1; i < moveToPos.getRow() && validMove; i++)
                         {
                             Position pose(i,moveToPos.getCol());

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
                         for (int i = this->pos.getRow() - 1; i > moveToPos.getRow() && validMove; i--) {
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
                                 Position pose( moveToPos.getRow(),i);

                                 if (board.GetPiece(pose) != NULL) {
                                     validMove = false;
                                 }


                             }

                             if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() == this->color)) {
                                 validMove = false;
                             }
                         } else {
                             for (int i = this->pos.getCol() - 1; i > moveToPos.getCol() && validMove; i--) {
                                 Position pose( moveToPos.getRow(),i);
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


             }








     return validMove;
}