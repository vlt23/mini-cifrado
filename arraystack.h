#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "myexception.h"

template<typename E, int N=100000>
class ArrayStack {
public:
    ArrayStack();
    ArrayStack(const ArrayStack<E,N>& stack);
    void push(E e);
    void pop();
    E top();
    bool isEmpty();
    ArrayStack<E,N>& operator=(const ArrayStack<E,N>& stack);
private:
    E storage[N];
    int lastIndex;
};

template<typename E, int N>
ArrayStack<E,N>::ArrayStack() {
    lastIndex = -1;
}

template<typename E, int N>
ArrayStack<E,N>::ArrayStack(const ArrayStack<E, N> &stack) {
    for (int i=0;i<stack.lastIndex;i++) {
        this->storage[i] = stack.storage[i];
    }
    this->lastIndex = stack.lastIndex;
}

template<typename E, int N>
void ArrayStack<E,N>::push(E e) {
    if (lastIndex == N-1) {
        throw MyException("The stack is complete");
    }
    lastIndex++;
    this->storage[lastIndex] = e;
}

template<typename E, int N>
void ArrayStack<E,N>::pop() {
    if (isEmpty()) {
        throw MyException("The stack is empty");
    }
    lastIndex--;
}

template<typename E, int N>
E ArrayStack<E,N>::top() {
    if (isEmpty()) {
        throw MyException("The stack is empty");
    }
    return storage[lastIndex];
}

template<typename E, int N>
bool ArrayStack<E,N>::isEmpty() {
    return lastIndex == -1;
}

template<typename E, int N>
ArrayStack<E,N>& ArrayStack<E,N>::operator=(const ArrayStack<E,N>& stack) {
    for (int i=0;i<stack.lastIndex;i++) {
        this->storage[i] = stack.storage[i];
    }
    this->lastIndex = stack.lastIndex;
    return *this;
}

#endif // ARRAYSTACK_H
