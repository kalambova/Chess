//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Piece.h"
#include "Board.h"
extern Board board;

class Queen : public Piece {

public:

    Queen(COLOR color, const Position& pos);
    virtual ~Queen();

    virtual bool ValidateMove(const Position& moveToPosition);
private:

};


#endif //CHESS_QUEEN_H
