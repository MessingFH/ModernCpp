//string.cpp

#include "include/string.h"
#include <iostream>
#include "include/exception.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String is a Class to represent an array of chars

/**
 * @brief Construct a new String:: String object
 * 
 */
String::String() : string((char*)malloc(1)), length(0)
{
        std::cout << "User defined String constructor invoked." << std::endl; //Used as Debug
        string[0] = '\0';
}

/**
 * @brief Construct a new overloaded String:: String object
 * 
 * @param data 
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

/**
 * @brief Destroy the String:: String object
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
/**
 * @brief Copy-Construct a new String:: String object
 * 
 * @param rhs 
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

/**
 * @brief Move-Construct a new String:: String object
 * 
 * @param other 
 */
String::String(String&& other) 
         : string{ other.string } 
{
        std::cout << "User defined String move constructor invoked."<< std::endl; //Used as Debug for 2 c)
        other.string = nullptr;
}


/**
 * @brief Function to append further chars to the string
 * 
 * @param data 
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

/**
 * @brief Function to return the current string data as pointer
 * 
 * @return char* 
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

/**
 * @brief Function to find first instance of char c in string
 * 
 * @param c 
 * @return int 
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

/**
 * @brief Function to print the current string
 * 
 */
void String::print() const
{
        std::cout << string << std::endl;
}

/**
 * @brief Function to clear the string and reallocate memory
 * 
 */
void String::clear()
{
        try{ 
                string = (char*)realloc (string, 1);
                if (string == NULL){
                        throw (Exception("Malloc in String-Constructor failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        string[0] = '\0';
        length = 0;
}

/**
 * @brief Function to use operator + for concat
 * 
 * @param other 
 * @return String 
 */
String String::operator+ (String other) {
            String temp(data());
            temp.append(other.data());
            return temp;
        }

/**
 * @brief Function to use operator [] for indexing
 * 
 * @param i 
 * @return char& 
 */
char &String::operator[](int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator [] index out of bounds");
                return string[0];       //return first element
        }
        return string[i];
}

/**
 * @brief Function to use at() for indexing
 * 
 * @param i 
 * @return char 
 */
char String::at(int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator .at() index out of bounds");
                return string[0];       //return first element
        }
        return string[i];
}

