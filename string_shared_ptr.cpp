//string_shared_ptr.cpp
#include "include/string_shared_ptr.h"
#include <iostream> //currently only for debug outputs
#include "include/string.h"

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String_shared_ptr is a class to represent shared Pointers pointing to Strings

/* Constructor
 * 
 */
String_shared_ptr::String_shared_ptr() : address (nullptr), refcount(new int(1))
{}

/* Overloaded Constructor
 * 
 */
String_shared_ptr::String_shared_ptr(String* data) : address(data), refcount(new int(1))
{}

/* Destructor
 * 
 */
String_shared_ptr::~String_shared_ptr()
{
        std::cout << "User defined shared destructor invoked."<< *refcount << std::endl; //Used as Debug
        if(*refcount <= 1)
        {
                delete refcount;
                (*address).clear();
                refcount = nullptr;
                address = nullptr;
        }
        else
        {
                *refcount--;
                address = nullptr;
                //only delete this pointer
        }
}

/* Copy Constructor
 * 
 */
String_shared_ptr::String_shared_ptr(const String_shared_ptr& rhs) 
         : address{ rhs.address }, refcount{ rhs.refcount } 
{
        *rhs.refcount += 1;

        std::cout << "User defined shared copy constructor invoked." << std::endl; //Used as Debug
}

/* Function to reset the shared_ptr
 * while checking for Refcount
 */
void String_shared_ptr::reset()
{
        if(*refcount <= 1)
        {       
                delete[] address;
                address = nullptr;
        }
        else
        {
                *refcount--;
                address = nullptr;
        }
}