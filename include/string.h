//string.h

#ifndef __STRING__
#define __STRING__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include <iostream>
using namespace std;


class String
{
    private:
        char* string;

    public:
        // ctor
        String();
        String(const char* data);
        // dtor
        ~String();
        //cpy ctor
        String(const String& rhs);

        //methods
        void append(const char* data);
        char* data();
        int find(char c);
        void print();
        void clear();
        
};

#endif