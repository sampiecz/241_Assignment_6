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
 Size method 

 Use: Returns Queue's size data member. 

 Parameters: No parameters. 

 Returns: qSize
***************************************************************/

template <class T>
size_t Queue<T>::size() const
{
    return qSize;
}

/***************************************************************
 Capacity method 

 Use: Returns Queue object's capacity. 

 Parameters: No parameters. 

 Returns: qCapacity
***************************************************************/

template <class T>
size_t Queue<T>::capacity()
{
    return qCapacity;
}

/***************************************************************
 Empty method 

 Use: Says wether or not the object is empty. 

 Parameters: No parameters. 

 Returns: A bool stating wether or not the object is empty.
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
 Clear method 

 Use: Resets the Queue object back to it's default created state.
 In other words it clears the object.... 

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
 Front method 

 Use: Returns the front object in the qArray. If the object is
 empty it throws an error. 

 Parameters: No parameters. 

 Returns: qArray[qFront] so the front object in the array.
***************************************************************/

template <class T>
const T& Queue<T>::front() const 
{
    if (empty())
    {
        throw underflow_error("Underflow_Error from front()");
    }

    return qArray[qFront];
}

/***************************************************************
 Back method 

 Use: Returns the back item in the array. If it doesn't exist
 it throws an error.  

 Parameters: No parameters. 

 Returns: qArray[qBack] the back item of the array.
***************************************************************/

template <class T>
const T& Queue<T>::back() const
{
    if (empty())
    {
        throw underflow_error("Underflow_Error from back()");
    }
    return qArray[qBack];
}

/***************************************************************
 Push method 

 Use: Pushes a new item to the Queue object. 

 Parameters: Reference to a constant template called val. 

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
 Pop method 

 Use: If empty thow underflow error. Otherwise pop the next
 object off the Queue ADT. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
void Queue<T>::pop()
{
    if (empty())
    {
        // You left off here
        throw underflow_error("Underflow_Error on empty().");
    }

    qFront = (qFront + 1) % qCapacity;
    --qSize;
}

/***************************************************************
 Alternate Queue Constructor 

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
 Queue Destructor 

 Use: Deletes the Queue object. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/

template <class T>
Queue<T>::~Queue()
{
    delete[] qArray;
}

/***************************************************************
 Reserve method 

 Use: Make array larger when it's needed.  

 Parameters: size_t n 

 Returns: If the size_t object is less that qSize or n is equal
 to the qCapacity the it will return itself.
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
 Overloaded Output Operator 

 Use: Overloads the output operator. Makes it possible to cout
 Queue object.  

 Parameters: Reference to an osteam object, lhs, and a reference
 to a constant Queue template object called rhs. 

 Returns: lhs
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
 Queue assignment operator 

 Use: Assigns Queue objects to another.  

 Parameters: Reference to a constant Queue Template object
 called other. 

 Returns: This object.
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
