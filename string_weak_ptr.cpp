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
        adress = nullptr;    //string is initialized empty
        refcount = new int(0);
        weakcount = new int(1);
}
/* Overloaded Constructor
 * 
 */
String_weak_ptr::String_weak_ptr(const String_shared_ptr& data)
{
        adress = data.getAdress();
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
                adress = nullptr;
                weakcount = nullptr;
        }
        else
        {
                *weakcount--;
                adress = nullptr;
        }
        std::cout << "Weak_ptr destructor called" << std::endl;        
}
/* Copy Constructor
 * 
 */
String_weak_ptr::String_weak_ptr(const String_weak_ptr& rhs) 
         : adress{ rhs.adress } 
{
        *rhs.weakcount += 1;

        std::cout << "User defined weak copy constructor invoked."; //Used as Debug for 2 c)
}

bool String_weak_ptr::expired() const
{
        if(adress == nullptr || *refcount == 0)
        {
                return true;
        }
        return false;
}

/* Function to append further chars to the string
 * 
 */
String_shared_ptr String_weak_ptr::lock()
{
        if(expired() == false)
        {
                String_shared_ptr x(adress);
                x.setRef(refcount);
                return x;
        }
        else
        {
                String_shared_ptr x;
                return x;
        }
}


