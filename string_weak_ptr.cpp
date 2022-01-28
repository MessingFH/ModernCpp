//string_weak_ptr.cpp

#include <iostream>
#include "include/string.h"
#include "include/string_weak_ptr.h"
#include "include/string_shared_ptr.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String is a Class to represent an array of chars

/* Constructor
 * 
 */
String_weak_ptr::String_weak_ptr()
{
        address = nullptr;    //Pointer is initialized empty
        refcount = new int(0);
        weakcount = new int(1);
}

/* Overloaded Constructor
 * 
 */
String_weak_ptr::String_weak_ptr(const String_shared_ptr& data)
{
        address = data.getaddress();
        refcount = data.getRef();
        weakcount = new int(1);
}

/* Destructor
 * 
 */
String_weak_ptr::~String_weak_ptr()
{
        if(*weakcount <= 1)
        {
                delete [] weakcount;
                address = nullptr;
                weakcount = nullptr;
        }
        else
        {
                *weakcount--;
                address = nullptr;
        }
        std::cout << "Weak_ptr destructor called" << std::endl;        //Used as Debug
}

/* Copy Constructor
 * 
 */
String_weak_ptr::String_weak_ptr(const String_weak_ptr& rhs) 
         : address{ rhs.address } 
{
        *rhs.weakcount += 1;

        std::cout << "User defined weak copy constructor invoked."; //Used as Debug
}

/* Function to check the status of the weak_ptr
 * 
 */
bool String_weak_ptr::expired() const
{
        if(address == nullptr || *refcount == 0)
        {
                return true;
        }
        return false;
}

/* Function to lock the weak_ptr, by returning a shared_ptr
 * depending on the state of expired()
 */
String_shared_ptr String_weak_ptr::lock()
{
        if(expired() == false)
        {
                String_shared_ptr x(address);
                x.setRef(refcount);
                return x;
        }
        else
        {
                String_shared_ptr x;
                return x;
        }
}