//string_weak_ptr.h

#ifndef __STRING_WEAK_PTR__
#define __STRING_WEAK_PTR__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include <iostream>
#include "string_shared_ptr.h"

using namespace std;


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
        String_shared_ptr lock();                
};

/*
Wir habens fast geschafft produktiv anzufangen zu arbeiten
und Jonas so 
"alter daniel was geht eigentlcih mit dem fußball ab?"
-Bochum
-Karlsruhe
-Pauli 
-Gladbach
-Saarbrücken (sad)
-Holstein Kiel
-Sportdirektor
-Hannover
~Dörtmund
-Hamburg
-Läbpzsch
-Freiburch
*/
#endif