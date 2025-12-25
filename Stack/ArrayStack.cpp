#include <iostream>
#include <stdexcept>
using namespace std

template<typename T ,size_t MAX_SIZE = 100>
Class ArrayStack {
private:
    T data[MAX_SIZE];
    int topIndex;

public:
    ArrayStack() : topIndex(-1) {}

    void push(const T& value) {
        if(isFull()){
            throw overflow_error("Stack is full!");
        }
        data[++topIndex] = value;
    }

    T pop() {
        if(isEmpty()) {
            throw underflow_error("Stack is empty!");
        }
        return data[topIndex--];
    }

    T peek() const {
        if(isEmpty()) {
            throw underflow_error("Stack is empty!");
        }
        return data[topIndex];
    }

    bool isFull() const {
        return topIndex == MAX_SIZE - 1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    size_t size() const {
        return topIndex + 1;
    }

    void clear() {
        topIndex = -1;
    }

    void print() const {
        cout << "Stack (top to bottom):";
        for (int i = topIndex; i>=0; i--) {
            cout << data[i] <<" ";
        }

        cout << endl;
    }
}