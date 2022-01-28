//main.cpp
#include <iostream>

#include "include/string.h"
#include "include/string_shared_ptr.h"
#include "include/string_weak_ptr.h"

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
