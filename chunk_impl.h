#include "chunk.h"
#include <iostream>

template<typename T>
my_deque<T>::chunk::chunk(size_t size, const std::shared_ptr<chunk>& previous, const std::shared_ptr<chunk>& next)
    : size(size), values(std::make_unique<T[]>(size)), count(0), previous(previous), next(next) {
    for (size_t i = 0; i < size; i++)
        values[i] = T();
}

template<typename T>
my_deque<T>::chunk::~chunk() {
    //show_chunk();
}

template<typename T>
void my_deque<T>::chunk::add(T value) {
    if (!isFull()) {
        values[count++] = value;
    }
}

template<typename T>
void my_deque<T>::chunk::remove() {
    if (!empty()) {
        values[--count] = T();
    }
}

template<typename T>
bool my_deque<T>::chunk::isFull() const {
    return count >= size;
}

template<typename T>
bool my_deque<T>::chunk::empty() const {
    return count == 0;
}

template<typename T>
T& my_deque<T>::chunk::operator[](size_t index) {
    return values[index];
}

template<typename T>
void my_deque<T>::chunk::show_chunk() const {
    for (size_t i = 0; i < size; i++)
        std::cout << values[i] << " ";
    std::cout << "\n";
}

// Explicit instantiation of the template class for types used in your application
// For example, if you use my_deque<int>, my_deque<float>, etc.
