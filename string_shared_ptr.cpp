//string_shared_ptr.cpp

#include <iostream>

#include "include/string.h"
#include "include/string_shared_ptr.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String is a Class to represent an array of chars

/* Constructor
 * 
 */
String_shared_ptr::String_shared_ptr()
{
        adress = nullptr;    //pointer is initialized empty
        refcount = new int;
        *refcount = 1;
}
/* Overloaded Constructor
 * 
 */
String_shared_ptr::String_shared_ptr(String* data)
{
        adress = data;
        refcount = new int;
        *refcount = 1;
}

/* Destructor
 * 
 */
String_shared_ptr::~String_shared_ptr()
{
        std::cout << "User defined shared destructor invoked." << std::endl; //Used as Debug for 2 c)
        if(*refcount <= 1)
        {
                delete[] refcount;
                delete[] adress;
        }
        else
        {
                *refcount -= 1;
                //only delete this pointer
        }
}
/* Copy Constructor
 * 
 */
String_shared_ptr::String_shared_ptr(const String_shared_ptr& rhs) 
         : adress{ rhs.adress }, refcount{ rhs.refcount } 
{
        *rhs.refcount += 1;

        std::cout << "User defined shared copy constructor invoked." << std::endl; //Used as Debug for 2 c)
}

int String_shared_ptr::getRef()
{
        return *refcount;
}

/* Function to return the current string data as pointer
 * 
 */
void String_shared_ptr::reset()
{
        if(*refcount <= 1)
        {       
                delete[] refcount;
                delete[] adress;
                adress = nullptr;
        }
        else
        {
                *refcount -= 1;
                adress = nullptr;
        }
}


