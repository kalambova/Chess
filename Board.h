//
// Created by eleonora on 26.05.18.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H



#include "Square.h"

class Board {
public:

    Board();
    virtual ~Board();

    void Draw();
    bool MovePiece(const Position& fromPos, const Position& toPos);
    Piece* GetPiece(const Position &piecePos);
    bool checkMate();
    void nextTurn();
    bool isPlayerInTurnPiece(const Position & piecePos);
    const COLOR getTurnColor()const ;
    void inturn();
    bool endGame();
private:

    Square board[8][8];
    Piece* king() ;
    void InitializePieces();
    bool IsWithinBoard(const Position& pos);
    COLOR turnColor=White;
    const Position tryToMove( Piece * x);

    Piece* isInCheck(Piece* king);
};



#endif //CHESS_BOARD_H
