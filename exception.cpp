//exception.cpp

#include "include/exception.h"
#include "include/string.h"
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Exception is a class to represent a file and linespecific exception

/**
 * @brief Construct a new Exception:: Exception object
 * 
 * @param msg 
 * @param file_na 
 * @param line_num 
 */
Exception::Exception(const String& msg, const String& file_na, const int line_num):
    line_number(line_num),
    file_name(file_na),
    error_message(msg)
    {}

/**
 * @brief Destroy the Exception:: Exception object
 * 
 */
Exception::~Exception() throw () {}

/**
 * @brief Returns the error-message
 * 
 * @return const char* 
 */
const char* Exception::what() const throw () {
    return error_message.data();
}

/**
 * @brief Returns the error-line
 * 
 * @return const int 
 */
const int Exception::getLineNumber() const throw() {
    return line_number;
}

/**
 * @brief Returns the File
 * 
 * @return const char* 
 */
const char* Exception::getFile() const throw() {
            return file_name.data();
        }