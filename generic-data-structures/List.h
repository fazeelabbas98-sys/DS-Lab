#pragma once

template <typename Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int capacity = 10)
        : arr(nullptr), maxSize(capacity > 0 ? capacity : 10), currentSize(0) {
        arr = new Type[maxSize]{};
    }

    List(const List<Type>& other)
        : arr(new Type[other.maxSize]{}),
        maxSize(other.maxSize),
        currentSize(other.currentSize) {
        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    virtual void addElementAtFirstIndex(Type value) = 0;
    virtual void addElementAtLastIndex(Type value) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List() {
        delete[] arr;
    }
};
