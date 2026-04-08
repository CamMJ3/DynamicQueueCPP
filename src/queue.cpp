#include <iostream>
#include "queue.h"
#include "node.h"

/** 
 * @file 
 * @brief Implementation of the constructors of the queue.
 */

using namespace std;

/***********************************************************************/

/** 
 * @brief Initializes an empty queue.
 *
 * @details Head and tail are set to nullptr, allowing the queue to be empty.
 */

template <typename T>
Queue<T>::Queue()
{
    head = tail = nullptr;
}

/***********************************************************************/

/** 
 * @brief Clears the queue and releases all dynamically allocated resources.
 *
 * @details Deletes all the Nodes stored in the queue, thus releasing all allocated memory.
 */

template <typename T>
Queue<T>::~Queue()
{
    Node<T>* tmp = head;
        
    while (tmp != nullptr)
    {
        Node<T>* deleteNode = tmp;
        tmp = tmp->getNext();
        delete deleteNode;
    }
}

/***********************************************************************/

/** 
 * @brief Returns true if the queue has no Nodes, and false otherwise.
 * @return True if the queue has no Nodes. False if it has at least one Node.
 */

template <typename T>
bool Queue<T>::emptyQueue() const
{
    return head == nullptr; ///< If "head" is nullptr, so will "tail" be.
}

/***********************************************************************/

/** 
 * @brief Returns the number of Nodes in the queue by traversing the list.
 * @return The number of Nodes in the queue.
 */

template <typename T>
int Queue<T>::getSize() const
{
    int count = 0;
    Node<T>* tmp = head;

    while (tmp != nullptr)
    {
        count++;
        tmp = tmp->getNext();
    }

    return count;
}

/***********************************************************************/

/** 
 * @brief Adds a new Node, with a value, to the back of the queue.
 * 
 * @details If the queue is empty, the new Node becomes both the head and tail of the stack.
 * Otherwise, the pointer of the new Node is set to the memory address of "head", 
 * then the new Node becomes the back of the queue.
 * 
 * @param newNode Memory address of the new Node.
 */

template <typename T>
void Queue<T>::enqueue(Node<T>* newNode)
{
    if (emptyQueue())
    {
        head = tail = newNode;
    }
    else
    {
        tail->insertNext(newNode);
        tail = newNode;
    }
}

/***********************************************************************/

/** 
 * @brief Deletes the Node at the front of the queue.
 * 
 * @details If the queue is empty, then an error message is thrown.
 * Otherwise, a new pointer "deleteNode" that references to the front of the queue (pointer "head")
 * is initialized, while another variable stores the value stored in "head" to return it.
 * 
 * The front of the queue becomes the Node after the previous head. Finally, "deleteNode" is deleted.
 * 
 * @return The value stored in the deleted Node.
 */

template <typename T>
T Queue<T>::dequeue()
{
    if (emptyQueue())
    {
        throw runtime_error("The queue has no elements yet!");
    }
    else
    {
        Node<T>* deleteNode = head;
        T nodeValue = head->getValue();

        head = head->getNext();
        if (head == nullptr)
        {
            tail = nullptr; ///< If "head" is nullptr, so will "tail" be, meaning the queue is now empty.
        }

        delete deleteNode;
        return nodeValue;
    }
}

/***********************************************************************/

/** 
 * @brief Returns the value of the Node at the front, or head, of the queue.
 * 
 * @details If the queue is empty, then an error message is thrown.
 * Otherwise, it returns the value inside "head".
 * 
 * @return The value stored in the front of the stack.
 */

template <typename T>
T Queue<T>::peek() const
{
    if (emptyQueue())
    {
        throw runtime_error("The queue has no elements yet!");
    }
    else
    {
        return head->getValue();
    }
}


/***********************************************************************/

/** 
 * @brief Prints all Nodes in the queue, highlighting the value at the front and back of the queue.
 * 
 * @details If the queue is empty, then an error message is thrown.
 * Otherwise, a new pointer "tmp" that references to the front of the queue (pointer "head")
 * is initialized. By using a while loop, the function prints all the Nodes in the queue, then
 * provides the value of the Nodes stored at the front and back of the list.
 */

template <typename T>
void Queue<T>::display() const
{
    if (emptyQueue())
    {
        cout << "The queue has no elements yet!";
    }
    else
    {
        Node<T>* tmp = head;
        
        while (tmp != nullptr)
        {
            cout << tmp->getValue() << "|";
            tmp = tmp->getNext();
        }
    
        cout << "\nThe number of Nodes in the queue is: " << getSize();
        cout << "\n--> First value of the queue (head): " << head->getValue();
        cout << "\n--> Last value of the queue (tail): " << tail->getValue();
    }
}