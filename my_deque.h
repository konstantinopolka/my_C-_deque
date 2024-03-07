#pragma once
#include <memory>
#include <stdexcept>
#include <iostream>

template<typename T>
class my_deque {
public:
    my_deque(); // OK
    explicit my_deque(size_t n); // OK
    my_deque(size_t n, const T& value); // OK
    my_deque(const my_deque<T>& other); // OK
    ~my_deque(); // OK
    void clear(); // OK
    void push_back(const T& value); // OK
    void pop_back(); // OK
    T& front() const; // OK
    T& back() const; // OK
    size_t size() const; // OK
    bool empty() const; // OK
    T operator[](const size_t index) const; // OK
    T& operator[](const size_t index); // OK
    bool operator==(const my_deque<T>& other) const; // OK
    bool operator!=(const my_deque<T>& other) const; // OK
    void resize(size_t n); // OK
    void resize(size_t n, const T& value); // OK
    void push_front(T value);
    void pop_front();
    void insert(size_t n, size_t pos, const T& value);
    void insert(size_t n, const T& value);
    void insert(size_t n, T* begin, T* end);
    void erase(int index);
    void erase(int begin, int end);
    void show_list();
    static void swap(my_deque<T>& list1, my_deque<T>& list2) // OK
    { 
        using std::swap;
        swap(list1.size_, list2.size_);
        swap(list1.head, list2.head);
        swap(list1.tail, list2.tail);
        swap(list1.node_count, list2.node_count);
    }

private:
    class chunk;
    static const size_t node_size = 4;
    size_t node_count;
    size_t size_;
    std::shared_ptr<chunk> head;
    std::shared_ptr<chunk> tail;
};

#include "chunk.h"
#include "my_deque_impl.h"
