//string_set_node.h
#include "string.h"

#ifndef __INCLUDED_MODERNCPP_STRING_SET_NODE_H__
#define __INCLUDED_MODERNCPP_STRING_SET_NODE_H__

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 


class String_set_node
{
    friend class String_set;
    private:
        String nodesString;
        String_set_node* left_child;
        String_set_node* right_child;

    public:
        // ctor
        String_set_node();
        String_set_node(String s);
        // dtor
        ~String_set_node();
        //cpy ctor
        String_set_node(const String_set_node& rhs);
        //move ctor
        String_set_node(String_set_node&& other);
        //methods
        void insert(String s);
        void insert(String_set_node s);
        String find (String s);
        
};

#endif