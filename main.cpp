//main.cpp
#include <iostream>


#include "include/string.h"
#include "include/string_shared_ptr.h"
#include "include/string_weak_ptr.h"
#include "include/exception.h"
#include "include/string_set.h"
#include "include/string_set_node.h"

// Autor(en): Daniel Mollenhauer, Bjarne Messing, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// main.cpp

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

String test;
String a("a");
String b("b");
String c("c");
String_set s;
String d("d");
s.insert(b);
s.insert(a);
s.insert(c);
}

