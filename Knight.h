//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Piece.h"
#include "Board.h"
extern Board board;

class Knight : public Piece {

public:
    Knight(COLOR color, const Position& pos);
    virtual ~Knight();

    virtual bool ValidateMove(const Position& moveToPosition);
private:

};


#endif //CHESS_KNIGHT_H
