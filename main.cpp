//main.cpp
#include <iostream>


#include "include/string.h"
#include "include/string_shared_ptr.h"
#include "include/string_weak_ptr.h"

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
test.append("te");
test.clear();
float *ptr, *new_ptr;
	ptr = (float*) malloc(5*sizeof(float));
	if(ptr==NULL)
	{
		cout << "Memory Allocation Failed";
		exit(1);
	}

	/* Initializing memory block */
	for (int i=0; i<5; i++)
	{
		ptr[i] = i*1.5;
	}

	/* reallocating memory */
	new_ptr = (float*) realloc(ptr, 10*sizeof(float));
	if(new_ptr==NULL)
	{
		cout << "Memory Re-allocation Failed";
		exit(1);
	}
	
	/* Initializing re-allocated memory block */
	for (int i=5; i<10; i++)
	{
		new_ptr[i] = i*2.5;
	}
	cout << "Printing Values" << endl;
	
	for (int i=0; i<10; i++)
	{
		cout << new_ptr[i] << endl;
	}
	free(new_ptr);
	
	return 0;

}
