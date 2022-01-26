//string_weak_ptr.h

#ifndef __STRING_WEAK_PTR__
#define __STRING_WEAK_PTR__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include <iostream>

using namespace std;


class String_weak_ptr
{
    private:
        String* adress;

    public:
        // ctor
        String_weak_ptr();
        String_weak_ptr(const String_shared_ptr& data);
        // dtor
        ~String_weak_ptr();
        //cpy ctor


        //methods
        String_shared_ptr lock();                
};


#endif