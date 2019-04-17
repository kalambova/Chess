cmake_minimum_required(VERSION 3.10)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess main.cpp Piece.h Position.h Pawn.h Square.cpp Square.h Board.cpp Board.h Rook.h Bishop.cpp Bishop.h King.cpp King.h Knight.cpp Knight.h Queen.cpp Queen.h MyString.h)