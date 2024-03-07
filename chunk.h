#pragma once
#include <memory>

#include "my_deque.h"

template<typename T>
class my_deque<T>::chunk {
public:
    chunk(size_t size = 10, const std::shared_ptr<chunk>& previous = nullptr, const std::shared_ptr<chunk>& next = nullptr);
    ~chunk();
    void add(T value);
    void remove();
    bool isFull() const;
    bool empty() const;
    T& operator[](size_t index);
    void show_chunk() const;

    size_t size;
    std::unique_ptr<T[]> values;
    size_t count;
    std::shared_ptr<chunk> previous;
    std::shared_ptr<chunk> next;
};
