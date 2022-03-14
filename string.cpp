//stringptr.cpp

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
String::String() noexcept : length(0)
{
        try{ 
                stringptr = (char*)malloc(length);         //allocate memory
                if (stringptr == NULL){
                        throw (Exception("Malloc in String-Constructor failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }

        std::cout << "User defined String constructor invoked." << std::endl; //Used as Debug
       
        try{
                stringptr[0] = '\0';    //-> might throw
        }catch(const std::exception& e){
                std::cout << "Error at Assignment in String-Constructor" << std::endl;
        }
}

/**
 * @brief Construct a new overloaded String:: String object
 * Basic Safety is guranteed -> undefined behaviour can occure f.e. regarding max_size at "stringptr[length+data_length] = \0"
 * when data has a guranteed string termination
 * a
 * @param data 
 */
String::String(const char* data) noexcept : length(0)
{
        std::cout << "User defined String-parameter constructor invoked." << std::endl; //Used as Debug
        if(data != NULL){
                while (data[length] != '\0') length++;          //calculate length of given data -> migh
        }
        try{ 
                stringptr = (char*)malloc(length);         //allocate memory
                if (stringptr == NULL){
                        throw (Exception("Malloc in String-Constructor failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        try{
                for(int i = 0; i < length; i++)
                {
                        stringptr[i] = data[i];            //fill allocated memory -> might throw
                }
                stringptr[length] = '\0';          //add stringptr termination -> might throw
        }catch(const std::exception& e){
                std::cout << "Error at Assignment in String-Constructor" << std::endl;
        }
}

/**
 * @brief Destroy the String:: String object
 * 
 */
String::~String()
{
        std::cout << "User defined String destructor invoked." << std::endl; //Used as Debug
        if (stringptr != nullptr)
        {
                clear();
        }
        stringptr = nullptr;
}
/**
 * @brief Copy-Construct a new String:: String object
 * 
 * @param rhs 
 */
String::String(const String& rhs) 
         : stringptr(nullptr), length(rhs.length) 
{
        try{
        stringptr = (char*)malloc(length);
        if (stringptr == NULL){
                        throw (Exception("Malloc in String-Copy-Constructor failed", __FILE__, __LINE__));
                }
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }

        for(int i = 0; i < length; i++)
        {
                stringptr[i] = rhs.stringptr[i];            //fill allocated memory might throw
        }
        stringptr[length] = '\0';
        std::cout << "User defined String copy constructor invoked." << std::endl; //Used as Debug for 2 c)
}

/**
 * @brief Move-Construct a new String:: String object
 * 
 * @param other 
 */
String::String(String&& other) 
         : stringptr(other.stringptr ), length(other.length) 
{
        other.clear();
        std::cout << "User defined String move constructor invoked."<< std::endl; //Used as Debug for 2 c)
}


/**
 * @brief Function to append further chars to the stringptr
 *        Basic Safety is guranteed -> undefined behaviour can occure f.e. regarding max_size at "stringptr[length+data_length] = \0"
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
        size_t final_length = length + data_length+1;
        stringptr = (char*) realloc(stringptr, final_length*sizeof(char));             //reallocate memory (in case of nullptr, behaves like malloc)
        if (stringptr == NULL){
                        throw (Exception("Realloc in String-Append failed", __FILE__, __LINE__));
                }

        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        try{
                for(int i = 0; i < data_length; i++)
                {
                        stringptr[length+i] = data[i];              //fill the reallocated memory -> might throw
                }
                
                stringptr[length+data_length] = '\0';               //terminate stringptr - might throw
        }catch(const std::exception& e){
                std::cout << "Error at Assignment in String-clear" << std::endl;
        }
        length += data_length;

}

/**
 * @brief Function to return the current stringptr data as pointer
 * noexcept, while string is correctly initialized
 * @return char* 
 */
char* String::data()
{
        return stringptr;
}

/* Function to return the current stringptr data as const pointer
 * noexcept, while string is correctly initialized
 */
const char* String::data() const
{
        return stringptr;
}

/**
 * @brief Function to find first instance of char c in stringptr
 *        Noexcept/Nothrow
 * @param c 
 * @return int 
 */
int String::find(char c) const
{
        for(int i = 0; i < length; i++)
        {
                if(stringptr[i] == c) 
                {
                        return i;
                }
        }
        const int charNotFound = -1;      //-1 as feedback "not found"
        return charNotFound;
}

/**
 * @brief Function to print the current stringptr
 * 
 */
void String::print() const
{
        std::cout << stringptr << std::endl;
}

/**
 * @brief Function to clear the stringptr and reallocate memory
 * 
 */
void String::clear() noexcept
{
        try{ 
                stringptr = (char*)realloc (stringptr, sizeof(char));
                if (stringptr == NULL){
                        throw (Exception("Malloc in String-Clear failed", __FILE__, __LINE__));
                }
                
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        try{
        stringptr[0] = '\0';    //both might throw
        length = 0;
        }catch(const std::exception& e){
                std::cout << "Error at Assignment in String-clear" << std::endl;
        }
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
 * If i is less or equal to the string length, the function never throws exceptions (no-throw guarantee).
Otherwise, it causes undefined behavior.
 * @param i 
 * @return char& 
 */
char& String::operator[](int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator [] index out of bounds");
                return stringptr[0];       //return first element
        }
        return stringptr[i];
}

/**
 * @brief 
 * If i is less or equal to the string length, the function never throws exceptions (no-throw guarantee).
Otherwise, it causes undefined behavior.
 * @param i 
 * @return const char& 
 */
const char& String::operator[](int i) 
{
        return stringptr[i];
}

/**
 * @brief Function to use at() for indexing
 * Strong gurantee
 * @param i 
 * @return char 
 */
char& String::at(int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator .at() index out of bounds");
                return stringptr[0];       //return first element
        }
        return stringptr[i];
}

/**
 * @brief 
 * 
 * @param i 
 * @return const char 
 */
const char& String::at(int i)
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator .at() index out of bounds");
                return stringptr[0];       //return first element
        }
        return stringptr[i];
}
