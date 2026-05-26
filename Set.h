#ifndef SET_H
#define SET_H

#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

template<typename type>
class Set {
private:
  type* data;
  int size;
  int capacity;

  void grow()
  {
    capacity *= 2;
    type* temp = new type[capacity];

    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }

    delete[] data;
    data = temp;
  }

public:
  set()
  {
    capacity = 0;
    size = 0;
    data = new type[capacity];
  }

  ~Set()
  {
    delete[] data;
  }
}

#endif