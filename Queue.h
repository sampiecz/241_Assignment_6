//*********************************************************************
//// FILE:        Queue.h
//// AUTHOR:      Samuel Piecz
//// LOGON ID:    Z1732715
//// DUE DATE:    11/09/17
////
//// PURPOSE:     Declaration for the Queue class. ADTs 4 life. 
////********************************************************************
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Queue<T>&);

template <class T>
class Queue
{
    // Friend functions
    friend ostream& operator<< <>(ostream& lhs, const Queue<T>& rhs); 
    private:
        T* qArray; 
        size_t qCapacity; 
        size_t qSize;
        int qFront;
        int qBack;
    public:
        Queue();
        Queue(const Queue<T>& other);
        Queue<T>& operator=(const Queue& other);
        ~Queue();
        size_t size() const;
        size_t capacity();
        bool empty() const;
        void clear();
        const T& front() const; 
        const T& back() const;  
        void push(const T&);  
        void pop();
        void reserve(size_t n);
};

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
Queue<T>::Queue()
{
    qCapacity = 0;
    qSize = 0;
    qArray = nullptr;
    qFront = 0;                     // First element of qArray
    qBack = qCapacity - 1;          // Last element of qArray
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
size_t Queue<T>::size() const
{
    return qSize;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
size_t Queue<T>::capacity()
{
    return qCapacity;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
bool Queue<T>::empty() const
{
    if (qSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
void Queue<T>::clear()
{
    qSize = 0;
    qFront = 0;
    qBack = qCapacity - 1;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
const T& Queue<T>::front() const 
{
    if (empty())
    {
        throw underflow_error("The heck. Underflow_Error from front()");
    }

    return qArray[qFront];
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
const T& Queue<T>::back() const
{
    if (empty())
    {
        throw underflow_error("The heck. Underflow_Error from back()");
    }
    return qArray[qBack];
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
void Queue<T>::push(const T& val)
{
    if (qSize == qCapacity)
    {
        if (qCapacity == 0)
        {
            reserve(1);
        }
        else
        {
            reserve(qCapacity * 2);
        }
    }

    qBack = (qBack + 1) % qCapacity;
    qArray[qBack] = val; 
    ++qSize;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
void Queue<T>::pop()
{
    if (empty())
    {
        // You left off here
        throw underflow_error("The heck.  Underflow_Error on empty().");
    }

    qFront = (qFront + 1) % qCapacity;
    --qSize;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
    qCapacity = other.qCapacity;
    qSize = other.qSize;
    qArray = new T[qCapacity];

    for (size_t i = 0; i < qCapacity; ++i)
        qArray[i] = other.qArray[i];

    qFront = other.qFront;
    qBack = other.qBack;
} 

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
Queue<T>::~Queue()
{
    delete[] qArray;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
void Queue<T>::reserve(size_t n)
{
    if (n < qSize || n == qCapacity)
        return;

    T* tempArray = new T[n];

    int current = qFront;
    for (size_t i = 0; i < qSize; i++)
    {
        tempArray[i] = qArray[current];
        current = (current + 1) % qCapacity;
    }

    qCapacity = n;
    qFront = 0;
    qBack = qSize - 1;
    delete[] qArray;
    qArray = tempArray;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
    size_t current, i;

    for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
    {
        // Print queue element at subscript i
        lhs << rhs.qArray[current] << ' ';
        // Increment i, wrapping around to front of queue array if necessary     
        current = (current + 1) % rhs.qCapacity;
    }

    return lhs;
}

/***************************************************************
 Queue Constructor 

 Use: Instantiates Queue object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other)
    {
        delete[] qArray;
        qCapacity = other.qCapacity;
        qSize = other.qSize;
                
        if (qCapacity == 0)
        {
            qArray = nullptr;
        }
        else
        {
            qArray = new T[qCapacity];
        }

        for (size_t i = 0; i < qSize; ++i)
        {
            qArray[i] = other.qArray[i];
        }
    }
    
    return *this;

}

#endif
