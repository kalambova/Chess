//
// Created by eleonora on 25.05.18.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <string>
#include "Position.h"
#include "MyString.h"

using namespace std;
enum COLOR{Default,White,Black};
class Piece {
protected:
    MyString name;
    COLOR color;
    Position pos;

public:
    Piece()
    {
        this->name=".";
        this->color=Default;
        this->pos=Position();
    }
    Piece(const Piece&other)
    {
        this->name=other.name;
        this->color=other.color;
        this->pos=other.pos;
    }
    Piece& operator=(const Piece& other)
    {
        if(this!=&other)
        {
            this->name=other.name;
            this->color=other.color;
            this->pos=other.pos;
        }
        return *this;
    }
    bool operator==(const Piece& other)
    {
        return (name==other.name&&color==other.color&&pos==other.pos);
    }
    ~Piece()
    {

    }
    Piece(COLOR color,const Position& pos)
    {
        this->color=color;
        this->pos=pos;
    }
    void Draw() {


        if (color == Black) {
            if(name=="P")
            {
                cout<<"♟";
            }
            if(name=="K")
            {
                cout<<"♚";
            }
            if(name=="Q")
            {
                cout<<"♛";
            }
            if(name=="N")
            {
                cout<<"♞";
            }
            if(name=="R")
            {
                cout<<"♜";
            }
            if(name=="B")
            {
                cout<<"♝";
            }


        }
        else { if(name=="P")
            {
                cout<<"♙";
            }
            if(name=="K")
            {
                cout<<"♔";
            }
            if(name=="Q")
            {
                cout<<"♕";
            }
            if(name=="N")
            {
                cout<<"♘";
            }
            if(name=="R")
            {
                cout<<"♖";
            }
            if(name=="B")
            {
                cout<<"♗";
            }


        }



    }
    const COLOR GetColor()const
    {
        return this->color;
    }
    void SetPosition(const Position& pos) {

        this->pos = pos;

    }
    const Position getPos()const
    {
         return pos;
    }
    const MyString  getName()const
    {
        return name;
    }
    virtual bool ValidateMove(const Position & pos)=0;




};


#endif //CHESS_PIECE_H
