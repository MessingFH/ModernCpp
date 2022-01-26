//string_shared_ptr.cpp

#include <iostream>

#include "include/string.h"
#include "include/string_shared_ptr.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String is a Class to represent an array of chars

/* Constructor
 * 
 */
String::String()
{
        string = "";    //string is initialized empty
}
/* Overloaded Constructor
 * 
 */
String::String(const char* data)
{
        size_t length = 0;
        if(data != NULL){
                while (data[length] != '\0') length++;          //calculate length of given data
        } 
        string = (char*)malloc(length);         //allocate memory

        for(int i = 0; i < length; i++)
        {
                string[i] = data[i];            //fill allocated memory
        }
        string[length] = '\0';          //add string termination
}

/* Destructor
 * 
 */
String::~String()
{
        clear();
        delete[] string;
}
/* Copy Constructor
 * 
 */
String::String(const String& rhs) 
         : string{ rhs.string } 
{
        std::cout << "User defined copy constructor invoked."; //Used as Debug for 2 c)
}

/* Function to append further chars to the string
 * 
 */
void String::append(const char* data)
{
        size_t this_length = 0;
        if(string != NULL)
        {
                while (string[this_length] != '\0') this_length++;      //calculate length of current string
        }
        
        size_t data_length = 0;
        if(data != NULL){
                while (data[data_length] != '\0') data_length++;      //calculate length of given data
        }

        realloc(string, this_length+data_length);             //reallocate memory (in case of nullptr, behaves like malloc)
        
        for(int i = 0; i < data_length; i++)
        {
                string[this_length+i] = data[i];              //fill the reallocated memory
        }
        string[this_length+data_length] = '\0';               //terminate string
        
}

/* Function to return the current string data as pointer
 * 
 */
char* String::data()
{
        if(string == nullptr)
        {
                throw std::invalid_argument("String-Memberfunction data returned Nullptr");
        }
        return string;
}

/* Function to find first instance of char c in string
 * 
 */
int String::find(char c)
{
        size_t this_length = 0;
        while (string[this_length] != '\0') this_length++;

        for(int i = 0; i < this_length; i++)
        {
                if(string[i] == c) 
                {
                        return i;
                }
        }
        return -1;      //-1 as feedback "not found"
}

/* Function to print the current string
 * 
 */
void String::print()
{
        std::cout << string << std::endl;
}

/* Function to clear the string and free memory
 * 
 */
void String::clear()
{
        string[0] = '\0';
        free(string);
}


