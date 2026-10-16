#pragma once
#include <iostream>
#include <algorithm>
#include "MyList.h"

template <typename Type>
class CustomList : public MyList<Type> {
private:
    bool isPrime(Type value) const {
        if (value < 2) {
            return false;
        }

        for (Type i = 2; i <= value / i; i++) {
            if (value % i == 0) {
                return false;
            }
        }

        return true;
    }

    void rotateRight(int start, int length, int times) {
        if (length <= 1) {
            return;
        }

        times %= length;
        if (times < 0) {
            times += length;
        }

        std::reverse(this->arr + start, this->arr + start + length);
        std::reverse(this->arr + start, this->arr + start + times);
        std::reverse(this->arr + start + times, this->arr + start + length);
    }

    void rotateLeft(int start, int length, int times) {
        if (length <= 1) {
            return;
        }

        times %= length;
        if (times < 0) {
            times += length;
        }

        rotateRight(start, length, length - times);
    }

public:
    CustomList(int capacity = 10) : MyList<Type>(capacity) {}

    CustomList(const CustomList<Type>& other) : MyList<Type>(other) {}

    Type sum_ofPrime() const {
        Type total = 0;

        for (int i = 0; i < this->currentSize; i++) {
            if (isPrime(this->arr[i])) {
                total += this->arr[i];
            }
        }

        return total;
    }

    Type secondMaxEven() const {
        bool foundMax = false;
        bool foundSecond = false;
        Type maximum{};
        Type second{};

        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];

            if (value % 2 != 0) {
                continue;
            }

            if (!foundMax || value > maximum) {
                if (foundMax) {
                    second = maximum;
                    foundSecond = true;
                }

                maximum = value;
                foundMax = true;
            }
            else if (value < maximum && (!foundSecond || value > second)) {
                second = value;
                foundSecond = true;
            }
        }

        if (!foundSecond) {
            throw std::runtime_error("There are not two distinct even values.");
        }

        return second;
    }

    Type secondMinOdd() const {
        bool foundMin = false;
        bool foundSecond = false;
        Type minimum{};
        Type second{};

        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];

            if (value % 2 == 0) {
                continue;
            }

            if (!foundMin || value < minimum) {
                if (foundMin) {
                    second = minimum;
                    foundSecond = true;
                }

                minimum = value;
                foundMin = true;
            }
            else if (value > minimum && (!foundSecond || value < second)) {
                second = value;
                foundSecond = true;
            }
        }

        if (!foundSecond) {
            throw std::runtime_error("There are not two distinct odd values.");
        }

        return second;
    }

    void printDuplicates() const {
        bool anyDuplicate = false;

        for (int i = 0; i < this->currentSize; i++) {
            bool appearedEarlier = false;

            for (int k = 0; k < i; k++) {
                if (this->arr[k] == this->arr[i]) {
                    appearedEarlier = true;
                    break;
                }
            }

            if (appearedEarlier) {
                continue;
            }

            for (int j = i + 1; j < this->currentSize; j++) {
                if (this->arr[i] == this->arr[j]) {
                    std::cout << this->arr[i] << " ";
                    anyDuplicate = true;
                    break;
                }
            }
        }

        if (!anyDuplicate) {
            std::cout << "No duplicates";
        }

        std::cout << '\n';
    }

    void rotateClockwaise(int r) {
        int firstHalf = this->currentSize / 2;
        int secondHalf = this->currentSize - firstHalf;

        rotateRight(0, firstHalf, r);
        rotateRight(firstHalf, secondHalf, r);
    }

    void rotateanitclockwaise(int rt) {
        int firstHalf = this->currentSize / 2;
        int secondHalf = this->currentSize - firstHalf;

        rotateLeft(0, firstHalf, rt);
        rotateLeft(firstHalf, secondHalf, rt);
    }

    ~CustomList() override = default;
};
