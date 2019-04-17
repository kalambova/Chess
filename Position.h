//
// Created by eleonora on 25.05.18.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

#include <iostream>
using namespace std;

class Position {
int  curcolum;
int currow;

public:
    Position()
    {
        this->curcolum=-1;
        this->currow=-1;

    }
    Position(const Position& other)
    {
        this->curcolum=other.curcolum;
        this->currow=other.currow;

    }
    Position& operator=(const Position& other)
    {
        if(this!=&other)
        {
            this->curcolum=other.curcolum;
            this->currow=other.currow;
        }
        return *this;
    }
    bool operator ==(const Position& other) const
    {
        return curcolum==other.curcolum&&currow==other.currow;
    }
    ~Position()
    {

    }
    Position(int row,int col)
    {
        this->currow=row;
        this->curcolum=col;
    }
    friend istream& operator>>(istream& in,Position& pos)
    {
        cout<<"Enter colum A-H";
        in>>pos.curcolum;
        cout<<"Enter row 1-8";
        in>>pos.currow;
        return in;
    }
    const int getCol()const
    {
        return this->curcolum;

    }
    const int getRow()const
    {
        return this->currow;
    }
    void setCol(int  col)
    {
        this->curcolum=col;
    }
    void setRow(int row)
    {
        this->currow=row;
    }


};


#endif //CHESS_POSITION_H
