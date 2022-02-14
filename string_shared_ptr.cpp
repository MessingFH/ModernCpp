//string_shared_ptr.cpp
#include "include/string_shared_ptr.h"
#include <iostream> //currently only for debug outputs
#include "include/string.h"

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String_shared_ptr is a class to represent shared Pointers pointing to Strings

/**
 * @brief Construct a new String_shared_ptr::String_shared_ptr object
 * 
 */
String_shared_ptr::String_shared_ptr() : address (nullptr), refcount(new int(1))
{}

/**
 * @brief Construct a new overloaded String_shared_ptr::String_shared_ptr object
 * 
 * @param data 
 */
String_shared_ptr::String_shared_ptr(String* data) : address(data), refcount(new int(1))
{}

/**
 * @brief Destroy the String_shared_ptr::String_shared_ptr object
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

/**
 * @brief Copy-Construct a new String_shared_ptr::String_shared_ptr object
 * 
 * @param rhs 
 */
String_shared_ptr::String_shared_ptr(const String_shared_ptr& rhs) 
         : address{ rhs.address }, refcount{ rhs.refcount } 
{
        *rhs.refcount += 1;

        std::cout << "User defined shared copy constructor invoked." << std::endl; //Used as Debug
}

/**
 * @brief Function to reset the shared_ptr while checking for Refcount
 * 
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