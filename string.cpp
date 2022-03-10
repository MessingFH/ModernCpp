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
        stringptr[0] = '\0';
}

/**
 * @brief Construct a new overloaded String:: String object
 * Noexcept
 * @param data 
 */
String::String(const char* data) noexcept : length(0)
{
        std::cout << "User defined String-parameter constructor invoked." << std::endl; //Used as Debug
        if(data != NULL){
                while (data[length] != '\0') length++;          //calculate length of given data
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
        for(int i = 0; i < length; i++)
        {
                stringptr[i] = data[i];            //fill allocated memory
        }
        stringptr[length] = '\0';          //add stringptr termination
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
         : stringptr{ nullptr } 
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
        *stringptr = *rhs.stringptr;
        std::cout << "User defined String copy constructor invoked." << std::endl; //Used as Debug for 2 c)
}

/**
 * @brief Move-Construct a new String:: String object
 * 
 * @param other 
 */
String::String(String&& other) 
         : stringptr{ other.stringptr } 
{
        std::cout << "User defined String move constructor invoked."<< std::endl; //Used as Debug for 2 c)
        other.stringptr = nullptr;
}


/**
 * @brief Function to append further chars to the stringptr
 *        Basic Safety is guranteed -> undefined behaviour can occure f.e. regarding max_size at "stringptr[length+data_length] = \0"
 * @param data 
 */
void String::append(const char* data)
{
        size_t data_length = 0;
        if(data != NULL){
                while (data[data_length] != '\0') data_length++;      //calculate length of given data
        }
        try{
        size_t final_length = length + data_length;
        char *temp;
        temp = (char*) realloc(stringptr, final_length*sizeof(char));             //reallocate memory (in case of nullptr, behaves like malloc)
        if (temp == NULL){
                        throw (Exception("Realloc in String-Append failed", __FILE__, __LINE__));
                }
                stringptr = temp;
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        
        for(int i = 0; i < data_length; i++)
        {
                stringptr[length+i] = data[i];              //fill the reallocated memory
        }
        stringptr[length+data_length] = '\0';               //terminate stringptr
        length += data_length;
}

/**
 * @brief Function to return the current stringptr data as pointer
 * 
 * @return char* 
 */
char* String::data()
{
        return stringptr;
}

/* Function to return the current stringptr data as const pointer
 * 
 */
const char* String::data() const
{
        if(stringptr == nullptr)
        {
                throw std::invalid_argument("String-Memberfunction data returned Nullptr");
        }
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
void String::clear() 
{
        try{ 

               char *ptr, *new_ptr;
	ptr = (char*) malloc(3*sizeof(char));
	

	/* Initializing memory block */
	for (int i=0; i<2; i++)
	{
		ptr[i] = 't';
	}
        ptr[2]='\0';

	/* reallocating memory */
        char *temp = stringptr;
	new_ptr = (char*) realloc(temp, 1*sizeof(char));
	
	new_ptr[0] = '\0';

                stringptr = (char*)realloc (stringptr, 1*sizeof(char));
                
                if (stringptr == NULL){
                        throw (Exception("Malloc in String-Constructor failed", __FILE__, __LINE__));
                }
                
        }catch(const Exception& e){
                std::cout << "Error:" << e.what() 
                        << "\nLine: " << e.getLineNumber()
                        << "\nFile: " << e.getFile();
        }
        
        stringptr[0] = '\0';
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
 * Strong gurantee
 * @param i 
 * @return char& 
 */
char &String::operator[](int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator [] index out of bounds");
                return stringptr[0];       //return first element
        }
        return stringptr[i];
}

/**
 * @brief Function to use at() for indexing
 * Strong gurantee
 * @param i 
 * @return char 
 */
char String::at(int i) const
{
        if (i>length-2 || i<0 ){
                throw std::invalid_argument("String-Operator .at() index out of bounds");
                return stringptr[0];       //return first element
        }
        return stringptr[i];
}

