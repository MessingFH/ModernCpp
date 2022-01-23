#include <iostream>

#include "include/string.h"

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

String::String()
{
        string = "";
}

String::String(const char* data)
{
        size_t length = sizeof(data)/sizeof(char);
        string = (char*)malloc(length*sizeof(char)+1);

        for(int i = 0; i <= length; i++)
        {
                string[i] = data[i];
        }
        string[length+1] = '\0';
}     

String::~String()
{

}

void String::append(const char* data)
{
        size_t this_length = sizeof(this)/sizeof(char);
        size_t data_length = sizeof(data)/sizeof(char);
        realloc(this, sizeof(char)*(this_length+data_length));
        
        for(int i = 0; i < data_length; i++)
        {
                string[this_length+i] = data[i];
        }
        string[this_length+data_length] = '\0';
}

char* String::data()
{

}

int String::find(char c)
{

}

void String::print()
{
        std::cout << this << std::endl;
}

void String::clear()
{
        free(this);
        string = "";
}


