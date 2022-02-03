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

int main () {
/*    
String test;
test.find('a');
test.print();
test.append("a");
String test2 = test; // must copy the string
test.clear();
test2.print(); // must print "a"
String test3(std::move(test2));
String result = (String() + "b" + "c");
result.print();
*/
String x("");
std::cout << x.at(1) << x[0]<<std::endl;


}