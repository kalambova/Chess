//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Piece.h"
#include "Board.h"
extern Board board;

class King : public Piece {

public:

    King(COLOR color, const Position &pos);
    virtual ~King();


    virtual bool ValidateMove(const Position& moveToPosition);
    bool checkMate();

private:


};


#endif //CHESS_KING_H
