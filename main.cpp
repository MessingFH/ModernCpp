//main.cpp
#include <iostream>
#include "string.cpp"

// Autor(en): Daniel Mollenhauer, Bjarne Messing, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm


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
