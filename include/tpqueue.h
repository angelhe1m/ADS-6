// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int last, first, count;

 public:
    TPQueue() :first(0), last(0), count(0) { arr = new T[size]; }
    bool isEmpty() const {
        return 0 == count;
    }
    bool isFull() const {
        return count == size;
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty");
        } else {
            count--;
            return arr[first++ % size];
        }
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            int x = last;
            arr[last % size] = value;
            T temp = arr[x % size];
            while (arr[x % size].prior > \
                arr[(x - 1) % size].prior && x > first) {
                temp = arr[x % size];
                arr[x % size] = arr[(x - 1) % size];
                arr[(x - 1) % size] = temp;
                x--;
            }
            count++;
            last++;
        }
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
