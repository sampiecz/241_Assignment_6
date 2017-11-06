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
        Queue(const T& other);
        size_t size();
        size_t capacity();
        bool empty();
        void clear();
        void front(); // void to run make file
        void back();  // void to run make file
        void push();  // void to run make file
        void pop();
        void reserve(size_t n);
};

template <class T>
Queue<T>::Queue()
{
    qCapacity = 0;
    qSize = 0;
    qArray = nullptr;
    qFront = 0;                     // First element of qArray
    qBack = qCapacity - 1;          // Last element of qArray
}
/*

template <class T>
Queue<T>::size()
{
    return qSize;
}

template <class T>
Queue<T>::capacity()
{
    return qCapacity;
}

template <class T>
Queue<T>::empty()
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

template <class T>
Queue<T>::clear()
{
    qSize = 0;
    qFront = 0;
    qBack = qCapacity - 1;
}

template <class T>
Queue<T>::front()
{
    if (empty())
        throw underflow exception

    return qArray[qFront];
}

template <class T>
Queue<T>::back()
{
    if (empty())
        throw underflow exception

    return qArray[qBack];
}

template <class T>
Queue<T>::push()
{
    if (qSize == qCapacity)
    {
        if (qCapacity == 0)
            reserve(1);
        else
            reserve(qCapacity * 2);
    }

    qBack = (qBack + 1) % qCapacity;
    qArray[qBack] = val;
    ++qSize;
}

template <class T>
Queue<T>::pop()
{
    if (empty())
        throw underflow exception

    qFront = (qFront + 1) % qCapacity;
    --qSize;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
    qCapacity = other.qCapacity;
    qSize = other.qSize;
    qArray = new int[qCapacity];

    for (size_t i = 0; i < qCapacity; ++i)
        qArray[i] = other.qArray[i];

    qFront = other.qFront;
    qBack = other.qBack;
}  

template <class T>
Queue<T>::~Queue()
{
    delete[] qArray;
}

template <class T>
void Queue<T>::reserve(size_t n)
{
    if (n < qSize || n == qCapacity)
        return;

    int* tempArray = new int[n];

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

*/
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
    for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
    {
        // Print queue element at subscript i
        lhs << rhs.qArray[current] << ' ';
        // Increment i, wrapping around to front of queue array if necessary     
        current = (current + 1) % rhs.qCapacity;
    }

 
}

#endif
