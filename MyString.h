//
// Created by eleonora on 11.06.18.
//

#ifndef CHESS_MYSTRING_H
#define CHESS_MYSTRING_H


#include <cstring>
#include <iostream>
const int  BUFFER=256;
using namespace std;
class MyString {
    char * string;
public:
    MyString()
    {
        this->string= nullptr;
    }
    MyString(const MyString& other)
    {
        this->string=new char [strlen(other.string)+1];
        strcpy(this->string,other.string);
    }
    MyString& operator =(const MyString& other)
    {
        if(this!=&other)
        {
            delete[]this->string;
            this->string=new char [strlen(other.string)+1];
            strcpy(this->string,other.string);
        }
        return *this;

    }
    bool operator==(const MyString& other)
    {
        return !strcmp(this->string, other.string);
    }
    bool operator !=(const MyString& other)
    {
        return !(this->string==other.string);
    }
    MyString(const char* string)
    {
        this->string=new char[strlen(string)+1];
        strcpy(this->string,string);
    }
    ~MyString()
    {
        delete[]string;
    }
    friend ostream& operator<<(ostream & out, const MyString& mystr)
    {
        out<<mystr.string;
        return out;
    }
    friend istream&operator>>(istream & in,MyString& mystr)
    {
        char* str=new char [BUFFER];
        in.getline(str,BUFFER);
        mystr.string=new char [strlen(str)+1];
        strcpy(mystr.string,str);
        delete[] str;
        return in;

    }
    bool operator==(const char* str)
    {
        return !(strcmp(this->string,str));
    }
    friend bool operator==(const MyString & mystr,const char* str)
    {
        return !(strcmp(mystr.string,str));
    }
     const char* getString()const
    {
        return this->string;
    }
    const char& operator [](int index)const
    {
        return this->string[index];
    }
    char& operator[](int index)
    {
        return this->string[index];
    }
    const int size()const
    {
        return strlen(string);
    }

};


#endif //CHESS_MYSTRING_H
