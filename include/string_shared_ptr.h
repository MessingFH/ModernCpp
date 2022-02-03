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

class String; //für Aufgabe 2 c)

class String_shared_ptr
{
    friend class String_weak_ptr;
    private:
        String* address;
        int* refcount;

    public:
        // ctor
        String_shared_ptr();
        String_shared_ptr(String* data);
        // dtor
        ~String_shared_ptr();
        //cpy ctor
        String_shared_ptr(const String_shared_ptr& rhs);

        //methods

        void reset();
        
        /* Funtion to associate the -> operator with the dedicated String
        * 
        * Return: 
        */
        String* operator -> () const {
            return address;
        }
        
};

#endif