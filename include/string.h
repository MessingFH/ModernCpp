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
    //friend class shared_string_ptr;

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
        //move ctor
        String(String&& other);

        //methods
        void append(const char* data);
        char* data();
        const char* data() const;
        int find(char c) const;
        void print() const;
        void clear();
        String operator+(String other);
    	char &operator[](int i) const;
        char at(int i) const;
};

#endif