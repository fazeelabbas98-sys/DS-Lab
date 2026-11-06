#pragma once
#include <iostream>
#include "List.h"

template <typename Type>
class MyList : public List<Type> {
public:
    MyList(int capacity = 10) : List<Type>(capacity) {}

    MyList(const MyList<Type>& other) : List<Type>(other) {}

    bool empty() const {
        return this->currentSize == 0;
    }

    bool full() const {
        return this->currentSize == this->maxSize;
    }

    int size() const {
        return this->currentSize;
    }

    void addElementAtFirstIndex(Type value) override {
        if (full()) {
            throw std::overflow_error("List is full.");
        }

        for (int i = this->currentSize; i > 0; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value) override {
        if (full()) {
            throw std::overflow_error("List is full.");
        }

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd() override {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }

        Type value = this->arr[this->currentSize - 1];
        this->currentSize--;
        return value;
    }

    void removeElementFromStart() override {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }

        for (int i = 0; i < this->currentSize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->currentSize--;
    }

    bool insertAt(int index, Type value) {
        if (index < 0 || index > this->currentSize || full()) {
            return false;
        }

        for (int i = this->currentSize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    Type last() const {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value) const {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == value) {
                return true;
            }
        }

        return false;
    }

    void display() const {
        if (empty()) {
            std::cout << "List is empty.\n";
            return;
        }

        for (int i = 0; i < this->currentSize; i++) {
            std::cout << this->arr[i] << " ";
        }

        std::cout << '\n';
    }

    ~MyList() override = default;
};
