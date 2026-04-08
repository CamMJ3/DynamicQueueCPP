#pragma once
#include <string>

/** 
 * @file 
 * @brief Defines the structure of a Node.
 * Its structure consists of a type T "value", and a pointer "next".
 *
 * @details A node can store a value of type T in "value", whereas the pointer "next" that references
 * to the next Node in the list.
 * This file defines the constructors of the functions of a Node. 
 */

template <typename T>
class Node
{
    private:
        T value;
        Node<T>* next;

    public:
        Node(T data, Node<T>* nextNode); ///< Initializes the Node with a value and sets the pointer to the next Node.
        Node(T data); ///< Initializes the Node with a value and sets its pointer to nullptr.
        Node(); ///< Initializes the Node empty (no value nor reference stored).

        void insertValue(T data); ///< Inserts a value into the Node.
        void insertNext(Node<T>* nextNode); ///< Sets the pointer to the next Node.
        T getValue() const; ///< Returns the value stored in the Node.
        Node<T>* getNext() const; ///< Returns the memory address to the next Node.
};

#include "../src/node.cpp" 