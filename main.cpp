//main.cpp
#include <iostream>
#include "string.cpp"   //unexcpected include, see below
//#include "include/string.h" <- excpected include, not working due to compiling error

// Autor(en): Daniel Mollenhauer, Bjarne Messing, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// main.cpp for debuging 2 c)


using namespace std;


void print_string(String s)
{
    s.print();
    s.append("234");
    s.print();
}

int main()
{
    String test("test");
    //print_string(test);
    test.clear();
    test.append("123");
    test.print();
}
