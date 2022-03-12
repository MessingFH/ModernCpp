//string_set.cpp
#include "include/string_set.h"
#include "include/string_set_node.h"
#include "include/string.h"

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// String_set is a class to represent a set of strings

/**
 * @brief Construct a new String_set::String_set object
 * 
 */
String_set::String_set() : parent(nullptr)
{}


/**
 * @brief Destroy the String_set::String_set object
 * 
 */
String_set::~String_set()
{
        
}

/**
 * @brief Copy-Construct a new String_set::String_set object
 * 
 * @param rhs 
 */
String_set::String_set(const String_set& rhs) 
{

}

/**
 * @brief Construct a new String_set::String_set object
 * 
 * @param other 
 */
String_set::String_set(String_set&& other)
{

}

/**
 * @brief function to insert a string into a set
 * 
 * @param s 
 */
void String_set::insert(String s)
{
    if(parent == nullptr)
    {
        parent = new String_set_node(s);
    }
    else{
        parent->insert(s);
    }

}

/**
 * @brief overloaded function to insert a string_node into a set
 * 
 * @param s 
 */
void String_set::insert(String_set_node s)
{
    if(parent == nullptr)
    {
        parent= &s;
    }
    else{
        parent->insert(s);
    }

}

/**
 * @brief finds s, else returns nullptr
 * 
 * @param s 
 * @return String 
 */
String String_set::find(String s)
{
    if(parent == nullptr)
    {
        return nullptr;
    }
    return parent->find(s);
}

void String_set::insert_all(String_set set)
{
    String_set_node* nodePtr;
    nodePtr = set.parent;
    while(nodePtr != nullptr){
        insert(*nodePtr);
        nodePtr = nodePtr->left_child;
    }
    nodePtr = set.parent;
    while(nodePtr != nullptr){
        nodePtr = nodePtr->right_child;
        insert(*nodePtr);
    }
}