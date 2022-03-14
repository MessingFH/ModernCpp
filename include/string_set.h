//string_set.h

#ifndef __INCLUDED_MODERNCPP_STRING_SET_H__
#define __INCLUDED_MODERNCPP_STRING_SET_H__

#include <vector>
// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 
class String;
class String_set_node;

class String_set
{
    //friend class String_set_node;
    private:
        String_set_node* parent;

    public:
        // ctor
        String_set();
        // dtor
        ~String_set()noexcept;
        //cpy ctor
        String_set(const String_set& rhs);
        //move ctor
        String_set(String_set&& other);
        //methods

        void insert(String s);
        void insert(String_set_node s);
        String find(String s);
        void insert_all (String_set set);
        void traverse (String_set_node* nodePtr, std::vector<String>* temp);

        /* Funtion to associate the -> operator with the dedicated String
        * 
        * Return: 
        */
        String_set &operator=(const String_set &s) const;
        
};

#endif