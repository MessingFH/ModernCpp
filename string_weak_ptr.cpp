//string_weak_ptr.cpp
#include "include/string_weak_ptr.h"
#include <iostream> //currently only for debug outputs
#include "include/string.h"
#include "include/string_shared_ptr.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String_weak_ptr is a class to represent weak Pointers, pointing to Strings

/**
 * @brief Construct a new String_weak_ptr::String_weak_ptr object
 * 
 */
String_weak_ptr::String_weak_ptr(): address (nullptr), refcount(new int(0)), weakcount(new int(1))
{}

/**
 * @brief Construct a new overloaded String_weak_ptr::String_weak_ptr object
 * 
 * @param data 
 */
String_weak_ptr::String_weak_ptr(const String_shared_ptr& data) : 
address (data.address), refcount (data.refcount), weakcount(new int(1))
{}

/**
 * @brief Destroy the String_weak_ptr::String_weak_ptr object
 * 
 */
String_weak_ptr::~String_weak_ptr()
{
        *weakcount--;
        if(*weakcount <= 1)
        {
                delete weakcount;
                address = nullptr;
                weakcount = nullptr;
        }
        else
        {
                address = nullptr;
        }
        std::cout << "Weak_ptr destructor called" << std::endl;        //Used as Debug
}

/**
 * @brief Copy-Construct a new String_weak_ptr::String_weak_ptr object
 * 
 * @param rhs 
 */
String_weak_ptr::String_weak_ptr(const String_weak_ptr& rhs) 
         : address{ rhs.address } 
{
        *rhs.weakcount += 1;

        std::cout << "User defined weak copy constructor invoked."; //Used as Debug
}

/**
 * @brief Function to check the status of the weak_ptr
 * 
 * @return true 
 * @return false 
 */
bool String_weak_ptr::expired() const
{
        if(address == nullptr || *refcount == 0)
        {
                return true;
        }
        return false;
}

/**
 * @brief Function to lock the weak_ptr, by returning a shared_ptr depending on the state of expired()
 * 
 * @return String_shared_ptr 
 */
String_shared_ptr String_weak_ptr::lock() const
{
        if(expired() == false)
        {
                String_shared_ptr x(address, refcount);
                return x;
        }
        else
        {
                String_shared_ptr x;
                return x;
        }
}