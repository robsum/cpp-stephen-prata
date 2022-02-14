#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <array>
#include <iostream>

const int MAX_SIZE = 5;

template <class T>
class QueueTp {

    private:
        std::array<T, MAX_SIZE> elements;
        int current_size;
    public:
        QueueTp() {
            current_size = 0;
        }
        bool add(T& item) {
            if (current_size == MAX_SIZE) {
                return false;
            }
            elements[current_size++] = item;
            return true;
        }
        bool get(T& item) {
            if (current_size == 0) {
                return false;
            }
            T tempItem = elements[0];

            std::array<T, MAX_SIZE> new_elements;
            for (int i = 1; i <= current_size; ++i) {
                new_elements[i-1] = elements[i];
            }
            elements = new_elements;

            current_size--;
            item = tempItem;
            return true;
        }
};

#endif