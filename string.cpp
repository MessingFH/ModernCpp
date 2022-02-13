//string.cpp

#include "include/string.h"
#include <iostream>
#include "include/exception.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String is a Class to represent an array of chars

/* Constructor
 * 
 */
String::String() : string((char*)malloc(1)), length(0)
{
        std::cout << "User defined String constructor invoked." << std::endl; //Used as Debug
        string[0] = '\0';
}

/* Overloaded Constructor
 * 
 */
String::String(const char* data) : length(0)
{
        std::cout << "User defined String-parameter constructor invoked." << std::endl; //Used as Debug
        if(data != NULL){
                while (data[length] != '\0') length++;          //calculate length of given data
        }
        try{ 
                string = (char*)malloc(length);         //allocate memory
                if (string == NULL){
                        throw (Exception("Malloc in String-Constructor failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
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
        std::cout << "User defined String destructor invoked." << std::endl; //Used as Debug
        if (string != nullptr)
        {
                clear();
        }
        string = nullptr;
}
/* Copy Constructor
 * 
 */
String::String(const String& rhs) 
         : string{ nullptr } 
{
        try{
        string = (char*)malloc(length);
        if (string == NULL){
                        throw (Exception("Malloc in String-Copy-Constructor failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        *string = *rhs.string;
        std::cout << "User defined String copy constructor invoked." << std::endl; //Used as Debug for 2 c)
}

/* Move Constructor
 * 
 */
String::String(String&& other) 
         : string{ other.string } 
{
        std::cout << "User defined String move constructor invoked."<< std::endl; //Used as Debug for 2 c)
        other.string = nullptr;
}


/* Function to append further chars to the string
 * 
 */
void String::append(const char* data)
{
        size_t data_length = 0;
        if(data != NULL){
                while (data[data_length] != '\0') data_length++;      //calculate length of given data
        }
        try{
        string = (char*)realloc(string, length+data_length);             //reallocate memory (in case of nullptr, behaves like malloc)
        if (string == NULL){
                        throw (Exception("Realloc in String-Append failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        for(int i = 0; i < data_length; i++)
        {
                string[length+i] = data[i];              //fill the reallocated memory
        }
        string[length+data_length] = '\0';               //terminate string
        length += data_length;
}

/* Function to return the current string data as pointer
 * 
 */
char* String::data()
{
        return string;
}

/* Function to return the current string data as const pointer
 * 
 */
const char* String::data() const
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
int String::find(char c) const
{
        for(int i = 0; i < length; i++)
        {
                if(string[i] == c) 
                {
                        return i;
                }
        }
        const int charNotFound = -1;      //-1 as feedback "not found"
        return charNotFound;
}

/* Function to print the current string
 * 
 */
void String::print() const
{
        std::cout << string << std::endl;
}

/* Function to clear the string and free memory
 * 
 */
void String::clear()
{
        string = (char*)realloc (string, 1);
        string[0] = '\0';
        length = 0;
}

/* Function to use operator + for concat
 * 
 */
String String::operator+ (String other) {
            String temp(data());
            temp.append(other.data());
            return temp;
        }

/* Function to use operator [] for indexing
 * 
 */
char &String::operator[](int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator [] index out of bounds");
                return string[0];       //return first element
        }
        return string[i];
}

/* Function to use at() for indexing
 * 
 */
char String::at(int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator .at() index out of bounds");
                return string[0];       //return first element
        }
        return string[i];
}

