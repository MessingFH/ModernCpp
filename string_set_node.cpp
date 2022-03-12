//string_set_node.cpp
#include <cstring>
#include "include/string_set_node.h"
#include "include/string.h"


// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String_set_node is a class to represent a string-node in a set

/**
 * @brief Construct a new String_set_node::String_set_node object
 * 
 */
String_set_node::String_set_node() : left_child(nullptr),right_child(nullptr)
{}



String_set_node::String_set_node(String s) : nodesString(s), left_child(nullptr),right_child(nullptr)
{}

/**
 * @brief Destroy the String_set_node::String_set_node object
 * 
 */
String_set_node::~String_set_node()
{
        
}

/**
 * @brief Construct a new String_set_node::String_set_node object
 * 
 * @param rhs 
 */
String_set_node::String_set_node(const String_set_node& rhs) 
{

}




/**
 * @brief Construct a new String_set_node::String_set_node object
 * 
 * @param other 
 */
String_set_node::String_set_node(String_set_node&& other)
{

}

/**
 * @brief function to insert String into the node or call the next node to insert it
 * 
 * @param s 
 */
void String_set_node::insert(String s)
{
    if(strcmp(s.data(),nodesString.data())< 0)
    {
        if(left_child == nullptr)
        {
            left_child = new String_set_node(s);
        }
        else{left_child->insert(s);}
    }
    else
    {
        if(right_child == nullptr)
        {
            right_child = new String_set_node(s);
        }
        else{right_child->insert(s);}
    }
}

/**
 * @brief overloaded function to insert String_node into the node or call the next node to insert it
 * 
 * @param s 
 */
void String_set_node::insert(String_set_node s)
{
    if(strcmp(s.nodesString.data(),nodesString.data())< 0)
    {
        if(left_child == nullptr)
        {
            left_child = &s;
        }
        else{left_child->insert(s);}
    }
    else
    {
        if(right_child == nullptr)
        {
            right_child = &s;
        }
        else{right_child->insert(s);}
    }
}

/**
 * @brief checks node for s, else checks child and returns child->find(s) or nullptr if no child
 * 
 * @param s 
 * @return String 
 */
String String_set_node::find(String s)
{
    if (s.data() == nodesString.data())
    {
        return s.data();
    }
    if(strcmp(s.data(),nodesString.data())< 0)
    {
        if(left_child == nullptr)
        {
            return nullptr;
        }
        else{return left_child->find(s);}
    }
    else
    {
        if(right_child == nullptr)
        {
            return nullptr;
        }
        else{return right_child->find(s);}
    }
}

