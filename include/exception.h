//exception.h

#ifndef __INCLUDED_MODERNCPP_EXCEPTION_H__
#define __INCLUDED_MODERNCPP_EXCEPTION_H__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include <exception>
#include "string.h"

class Exception : virtual public std::exception {


    protected:

        int line_number;               //Line number
        String file_name;               //Error offset
        String error_message;      //Error message
    
    public:
        //explicit ctr
        Exception(const String& msg, const String& file_na, const int line_num);
        //dstr
        ~Exception() throw ();
        //methods
        const char* what() const throw ();
        const int getLineNumber() const throw();
        const char* getFile() const throw();

};

#endif