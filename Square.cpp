//
// Created by eleonora on 26.05.18.
//

#include "Square.h"
#include "Piece.h"
Square::Square() {
    chessPiece = NULL;
}

Square::~Square() {
}

Piece* Square::GetPiece() {
    return chessPiece;
}

void Square::SetPiece(Piece *piece) {
    this->chessPiece = piece;
}

void Square::Clear() {
    this->chessPiece = NULL;
}