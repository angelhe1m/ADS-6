// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
 T* arr;
 int startQueue;
 int first, last, k;
 public:
  TPQueue():startQueue(size), first(0), last(0), k(0) {
   arr = new T[startQueue + 1];
  }
  
  ~TPQueue() {
    delete[] arr;
  }
  bool isFull() const {
    return k == startQueue;
  }
  bool isEmpty() const {
    return k == 0;
  }
  char get() {
    assert(k > 0);
    return arr[first].ch;
  }
  void push(const T& value) {
    assert(k < startQueue);
    if (k == 0) {
      arr[last++] = value;
      k++;
    } else {
      int i = last - 1;
      bool flag = 0;
      while (i >= first && value.prior > arr[i].prior) {
        flag = 1;
        arr[i + 1] = arr[i];
        arr[i] = value;
        i--;
      }
      if (flag == 0) {
        arr[last] = value;
      }
      last++;
      k++;
    }
    if (last > startQueue) {
      last -= startQueue;
    }
  }
  const T& pop() {
    assert(k > 0);
    k--;
    if (first > startQueue) {
      first -= startQueue;
    }
    return arr[first++];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
