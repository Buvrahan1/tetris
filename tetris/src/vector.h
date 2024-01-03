#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class T>
class vectorClass {
    T* arr;
    int capacity;
    int current;

public:
    vectorClass() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    ~vectorClass() {
        //delete[] arr;
    }

    void push(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void push(T data, int index) {
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }

    T get(int index) {
        if (index < current)
            return arr[index];
        return arr[0];
    }

    void pop() {
        if (current > 0) 
            current--;
    }

    int size() {
        return current;
    }

    int getcapacity() {
        return capacity;
    }

    bool empty() {
        return current == 0;
    }

    void erase(T data) {
        int index = -1;
        for (int i = 0; i < current; i++) {
            if (arr[i] == data) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < current - 1; i++) {
                arr[i] = arr[i + 1];
            }
            current--;
        }
    }

    T* begin() {
        return arr;
    }
};

#endif // VECTOR_H