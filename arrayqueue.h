#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "myexception.h"

template<typename E, int N=1000000>
class ArrayQueue
{
public:
    ArrayQueue();
    ArrayQueue(ArrayQueue<E,N>& q);
    void push_back(E e);
    void pop_front();
    bool isEmpty();
    E front();
    ArrayQueue<E,N>& operator=(ArrayQueue<E,N>& q);


private:
    E storage[N];
    int lastIndex;
};

template<typename E, int N>
ArrayQueue<E,N>::ArrayQueue() {
    this->lastIndex = -1;
}

template<typename E, int N>
ArrayQueue<E,N>::ArrayQueue(ArrayQueue<E,N>& q) {
    for (int i=0;i<=q.lastIndex;i++) {
        this->storage[i] = q.storage[i];
    }
    this->lastIndex = q.lastIndex;
}



template<typename E, int N>
void ArrayQueue<E,N>::push_back(E e) {
    if (lastIndex == N-1) {
        throw MyException("The queue is complete");
    }
    lastIndex++;
    storage[lastIndex] = e;
}



template<typename E, int N>
void ArrayQueue<E,N>::pop_front() {
    if (isEmpty()) {
        throw MyException("The queue is empty");
    }
    for (int j=0; j<lastIndex; j++) {
        storage[j] = storage[j+1];
    }
    lastIndex--;
}

template<typename E, int N>
bool ArrayQueue<E,N>::isEmpty() {
    return (lastIndex == -1);
}

template<typename E, int N>
E ArrayQueue<E,N>::front() {
    if (isEmpty()) {
        throw MyException("The queue is empty");
    }
    return storage[0];
}


template<typename E, int N>
ArrayQueue<E,N>& ArrayQueue<E,N>::operator=(ArrayQueue<E,N>& q) {
    for (int i=0;i<=q.lastIndex;i++) {
        storage[i] = q.storage[i];
    }
    lastIndex = q.lastIndex;
    return *this;
}

#endif // ARRAYQUEUE_H
