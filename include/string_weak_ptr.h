//string_weak_ptr.h

#ifndef __INCLUDED_MODERNCPP_STRING_WEAK_PTR_H__
#define __INCLUDED_MODERNCPP_STRING_WEAK_PTR_H__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include "string.h"
#include "string_shared_ptr.h"


class String_weak_ptr
{
    
    private:
        String* address;
        int* refcount;
        int* weakcount;

    public:
        // ctor
        String_weak_ptr();
        String_weak_ptr(const String_shared_ptr& data);
        // dtor
        ~String_weak_ptr();
        //cpy ctor
        String_weak_ptr(const String_weak_ptr& rhs);

        //methods
        bool expired() const;
        String_shared_ptr lock() const;                
};

#endif