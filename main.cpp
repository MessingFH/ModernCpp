//main.cpp
#include <iostream>
#include "string.cpp"   //unexcpected include, see below
//#include "include/string.h" <- excpected include, not working due to compiling error

#include "string_shared_ptr.cpp" 
#include "string_weak_ptr.cpp" 


// Autor(en): Daniel Mollenhauer, Bjarne Messing, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// main.cpp for debuging 2 c)


using namespace std;

void doSomething (const String_shared_ptr& t)
{
    
}


int main()
{
    String test("test");
    String_shared_ptr sharedPtr(&test);
    doSomething (sharedPtr);
}
