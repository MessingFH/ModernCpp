//string_set.cpp
#include "include/string_set.h"
#include<algorithm>
#include<vector>
#include<exception>
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
String_set::~String_set() noexcept
{
        
}

/**
 * @brief Copy-Construct a new String_set::String_set object
 * 
 * @param rhs 
 */
String_set::String_set(const String_set& rhs) : parent(rhs.parent)
{

}

/**
 * @brief Construct a new String_set::String_set object
 * 
 * @param other 
 */
String_set::String_set(String_set&& other)
{
    std::swap(parent, other.parent);
}

/**
 * @brief function to insert a string into a set
 * strong exception safety, while s is correct
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
 * strong exception safety, while s is correct
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
 * strong exception safety, provided s is a correct string
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

/**
 * @brief insert a whole set
 * basic exception safety, elements might be inserted partly during exceptions
 * @param set 
 */
void String_set::insert_all(String_set set)
{
    std::vector<String> temp;
    try{
    traverse(set.parent, &temp);    //might throw, might have undefinded behavior
    }catch(const std::exception& e){

        }
    for(int i = temp.size(); i>0; i--){
        
        insert(temp.at(i));         //might throw
        
        temp.pop_back();
    }
    //destroy set set
}

/**
 * @brief helper-function to traverse nodes and fill vector temp
 * basic exception safety, no parameter of the current set gets manipulated
 * @param nodePtr 
 * @param temp 
 */
void String_set::traverse(String_set_node* nodePtr, std::vector<String>* temp)
{
    temp->push_back(nodePtr->nodesString);
    if(nodePtr->left_child != nullptr){
        traverse (nodePtr->left_child, temp);
    }
    if(nodePtr->right_child != nullptr){
        traverse(nodePtr->right_child, temp);
    }
}