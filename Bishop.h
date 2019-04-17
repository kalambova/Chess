//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Piece.h"
#include "Board.h"
extern Board board;

class Bishop : public Piece {

public:

    Bishop(COLOR color,const  Position& pos);
    virtual ~Bishop();

    virtual  bool ValidateMove(const Position& moveToPosition);
private:



};



#endif //CHESS_BISHOP_H
