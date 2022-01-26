//string_weak_ptr.cpp

#include <iostream>
#include "include/string.h"
#include "include/string_weak_ptr.h"

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
}
/* Overloaded Constructor
 * 
 */
String_weak_ptr::String_weak_ptr(const String_shared_ptr& data)
{

}

/* Destructor
 * 
 */
String_weak_ptr::~String_weak_ptr()
{
        delete[] adress;
}
/* Copy Constructor
 * 
 */
String_weak_ptr::String_weak_ptr(const String_weak_ptr& rhs) 
         : adress{ rhs.adress } 
{
        std::cout << "User defined weak copy constructor invoked."; //Used as Debug for 2 c)
}

/* Function to append further chars to the string
 * 
 */
String_shared_ptr String_weak_ptr::lock()
{

}


