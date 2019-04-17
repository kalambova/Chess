//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H


#include "Piece.h"

class Square {
public:

    Square();
    virtual ~Square();
    Piece* GetPiece();
    void SetPiece(Piece *piece);
    void Clear();

private:
    Piece *chessPiece;
};



#endif //CHESS_SQUARE_H
