#include "node.h"

/** 
 * @file 
 * @brief Implementation of the constructors of the Node.
 */

/***********************************************************************/

/** 
 * @brief Initializes the Node with a value and sets the pointer to the next Node.
 *
 * @param data The value to be stored in the Node.
 * @param nextNode The memory address of the next Node.
 */

template <typename T>
Node<T>::Node(T data, Node<T>* nextNode)
{
    value = data;
    next = nextNode;
}

/***********************************************************************/

/** 
 * @brief Initializes the Node with a value and sets its pointer to nullptr.
 *
 * @param data The value to be stored in the Node.
 */

template <typename T>
Node<T>::Node(T data)
{
    value = data;
    next = nullptr;
}

/***********************************************************************/

/** 
 * @brief Initializes the Node empty (no value nor reference stored).
 * Default Node constructor.
 */

template <typename T>
Node<T>::Node()
{
    value = T();
    next = nullptr;
}

/***********************************************************************/

/** 
 * @brief Inserts a value into the Node.
 * 
 * @param data The value to be stored.
 */

template <typename T>
void Node<T>::insertValue(T data)
{
    value = data;
}

/***********************************************************************/

/** 
 * @brief Sets the pointer to the next Node.
 * 
 * @param nextNode The memory address of the next Node.
 */

template <typename T>
void Node<T>::insertNext(Node<T>* nextNode)
{
    next = nextNode;
}

/***********************************************************************/

/** 
 * @brief Returns the value stored in the Node.
 *
 * @return The value stored in the Node.
 */ 

template <typename T>
T Node<T>::getValue() const
{
    return value;
}

/***********************************************************************/

/** 
 * @brief Returns the memory address to the next Node.
 *
 * @return Memory address of the next Node.
 */

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return next;
}