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

  Set(const Set<type>& other)
  {
    size = other.size;
    capacity = other.capacity;

    data = new type[capacity];

    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }

  Set<type>& operator=(const Set<type>& other)
  {
    if (this == &other) {
      return *this;
    }

    delete[] data;

    size = other.size;
    capacity = other.capacity;

    data = new type[capacity];

    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }

    return *this;
  }

  bool contains(type item) const
  {
    for (int i = 0; i < size; i++) {
      if (data[i] = item) {
        return true;
      }
    }

    return false;
  }

  void add(type item)
  {
    if (contains(item)) {
      return;
    }

    if (size >= capacity) {
      grow();
    }

    data[size] = item;
    size++;
  }

  int getSize() const
  {
    return size;
  }

  void remove(type item)
  {
    for (int i = 0; i < size; i++) {
      if (data[i] == item) {
        for (int j = i; j < size - 1; j++) {
          data[j] = data[j + 1];
        }

        size--;
        return;
      }
    }
  }

  void clear()
  {
    size = 0;
  }

  type removeSmallert()
  {
    if (size == 0) {
      throw runtime_error("Empty set");
    }

    int smallestIndex = 0;

    for (int i = 1; i < size; i++) {
      if (data[i] < data[smallestIndex]) {
        smallestIndex = i;
      }
    }

    type smallest = data[smallestIndex];

    for (int i = smallestIndex; i < size - 1; i++) {
      data[i] = data[i + 1];
    }

    size--;

    return smallest;
  }

  bool operator==(const Set<type>& other) const
  {
    if (size != other.size) {
      return false;
    }

    for (int i = 0; i < size; i++) {
      if (!other.contains(data[i])) {
        return false;
      }
    }
    return true;
  }

  string toString() const
  {
    stringstream ss;

    ss << "{";

    for (int i = 0; i < size; i++) {
      ss << data[i];

      if (i < size - 1) {
        ss << ", ";
      }
    }

    ss << "}";

    return ss.str();
  }
}

#endif