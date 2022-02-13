//exception.h

#ifndef __INCLUDED_MODERNCPP_EXCEPTION_H__
#define __INCLUDED_MODERNCPP_EXCEPTION_H__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

#include <exception>
#include <string.h>

class Exception : virtual public std::exception {


    protected:

        int line_number;               //Line number
        String file_name;               //Error offset
        String error_message;      //Error message
    
    public:
    /** Constructor
         */
        //explicit 
        Exception(const String& msg, const String& file_na, const int line_num):
            line_number(line_num),
            file_name(file_na),
            error_message(msg)
            {}

        /** Destructor.
         *  
         */
        ~Exception() throw () {}
        
        const char* what() const throw () {
            return error_message.data();
        }

        /** Returns error number.
         *  @return #error_number
         */
        const int getLineNumber() const throw() {
            return line_number;
        }
        
        /**Returns error offset.
         * @return #error_offset
         */
        const char* getFile() const throw() {
            return file_name.data();
        }

};

#endif