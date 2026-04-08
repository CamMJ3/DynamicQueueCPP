#pragma once
#include <string>
#include "node.h"

/** 
 * @file
 * @brief Defines the structure of the Queue.
 * Its structure consists of two pointers called "head" and "tail", respectively.
 *
 * @details A queue is a linear data structure that follows the FIFO (First-in, First-out) method, thus 
 * making the core of its functions the first (front) and last (back) elements, or in this case Nodes,
 * added to the queue.
 * This file defines the constructors of the functions of the queue.
 */

template <typename T>
class Queue
{
    private:
    
        Node<T>* head; ///< Points to the Node at the front, or head, of the queue.
        Node<T>* tail;  ///< Points to the Node at the back, or tail, of the queue.
    
    public:
    
        Queue(); ///< Initializes an empty queue.
        ~Queue(); ///< Clears the queue and releases all dynamically allocated resources.

        bool emptyQueue() const; ///< Returns true if the queue has no Nodes, and false otherwise.
        int getSize() const; ///< Returns the number of Nodes in the queue by traversing the list.

        void enqueue(Node<T>* data); ///< Adds a new Node, with a value, to the back of the queue.
        T dequeue(); ///< Deletes the Node at the front of the queue.

        T peek() const; ///< Returns the value of the Node at the front, or head, of the queue.
        void display() const; ///< Prints all Nodes in the queue, highlighting the value at the front and back of the queue.

};

#include "../src/queue.cpp" 