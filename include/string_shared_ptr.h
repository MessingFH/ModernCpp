//string_shared_ptr.h

#ifndef __STRING_SHARED_PTR__
#define __STRING_SHARED_PTR__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include <iostream>
using namespace std;


class String_shared_ptr
{
    private:
        String* adress;

    public:
        // ctor
        String_shared_ptr();
        String_shared_ptr(const String* data);
        // dtor
        ~String_shared_ptr();
        //cpy ctor
        String_shared_ptr(const String_shared_ptr& rhs);

        //methods
        void reset();
        /* Funtion to associate the -> operator with
        * 
        * Return: 
        */
        String operator -> () const {
            return *adress;
        }
        
};


#endif