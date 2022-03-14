//string.h

#ifndef __INCLUDED_MODERNCPP_STRING_H__
#define __INCLUDED_MODERNCPP_STRING_H__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 
#include <stddef.h> //included for the size_t type

class String
{
    //friend class shared_string_ptr;

    private:
        char* stringptr;
        size_t length;

    public:
        // ctor
        String()noexcept;
        String(const char* data) noexcept;
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
        void clear() noexcept;
        String operator+(String other);
    	char& operator[](int i) const;
        const char& operator[](int i);
        char& at(int i) const;
        const char& at(int i);
        String& operator=(String& other);

};

#endif