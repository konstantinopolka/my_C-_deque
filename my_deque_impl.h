#pragma once
#include "my_deque.h"
using namespace std;

using std::shared_ptr;

template<typename T>
my_deque<T>::my_deque() : head(nullptr), tail(nullptr), size_(0), node_count(0) {}

template<typename T>
my_deque<T>::my_deque(size_t n, const T& value) {
    while (n--)
        push_back(value);
}


template<typename T>
my_deque<T>::my_deque(size_t n) : my_deque(n, T())
{}

template<typename T>
my_deque<T>::my_deque(const my_deque<T>& other) {
    size_t i = 0;
    shared_ptr<my_deque<T>::ñhunk> current = other.head;
    while (current != nullptr) {
        for (size_t j = 0; j < node_size && i < other.size_; j++, i++) {
            auto temp = current->operator[](j);
            push_back(temp);
        }
        current = current->next;
    }
}

template<typename T>
my_deque<T>::~my_deque() {
    clear();
}

template<typename T>
void my_deque<T>::clear() {
    while (size_)
        pop_back();
}

template<typename T>
void my_deque<T>::push_back(const T& value) {
    if (tail == nullptr) {
        tail = std::make_shared<chunk>(node_size);
        head = tail;
        node_count++;
    }

    if (tail->isFull()) {
        auto newTail = std::make_shared<chunk>(node_size, tail);
        tail->next = newTail;
        tail = newTail;
        node_count++;
    }

    tail->add(value);
    size_++;
}

template<typename T>
void my_deque<T>::pop_back() {
    if (tail == nullptr)
        return;

    tail->remove();
    if (tail->empty()) {
        if (head != tail) {
            auto toDelete = tail;
            tail = tail->previous;
            tail->next = nullptr;
            toDelete = nullptr;
        }
        node_count--;
    }
    size_--;
}

template<typename T>
T& my_deque<T>::front() const {
    if (head == nullptr) {
        throw out_of_range("Front called on empty deque");
    }
    return head->operator[](0);
}

template<typename T>
T& my_deque<T>::back() const {
    if (tail == nullptr) {
        throw out_of_range("Back called on empty deque");
    }
    return tail->operator[](tail->count - 1);
}

template<typename T>
size_t my_deque<T>::size() const {
    return size_;

}

template<typename T>
bool my_deque<T>::empty() const {
    return size_ == 0;

}

template<typename T>
T my_deque<T>::operator[](const size_t index) const {
    if (index >= size) {
        throw out_of_range("Index was more than size of deque");
    }
    size_t i = 0;
   auto current = head;
    while (current != nullptr) {
        for (size_t j = 0; j < node_size && i < size_; j++, i++) {
            if (index == i)
                return current->operator[](j);
        }
        current = current->next;
    }
    return T();
}

template<typename T>
T& my_deque<T>::operator[](const size_t index) {
    if (index >= size_) {
        throw out_of_range("Index was more than size of deque");
    }
    size_t i = 0;
    auto current = head;
    while (current != nullptr) {
        for (size_t j = 0; j < node_size && i < size_; j++, i++) {
            if (index == i)
                return current->operator[](j);
        }
        current = current->next;
    }
}

template<typename T>
bool my_deque<T>::operator==(const my_deque<T>& other) const {
    if (other.size_ != this->size_)
        return false;

    size_t i = 0;
    auto current_this = this->head;
    auto current_other = other.head;

    while (current_this != nullptr && current_other != nullptr) {
        for (size_t j = 0; j < node_size && i < size_; j++, i++) {
            if (current_this->operator[](j) != current_other->operator[](j))
                return false;
        }
        current_this = current_this->next;
        current_other = current_other->next;
    }
    return true;
}

template<typename T>
bool my_deque<T>::operator!=(const my_deque<T>& other) const {
    return !operator==(other);
}

template<typename T>
void my_deque<T>::resize(size_t n) {
    resize(n, T());
}

template<typename T>
void my_deque<T>::resize(size_t n, const T& value) {
    if (n > size_)
        while (n != size_)
            push_back(value);
    else
        while (n != size_)
            pop_back();
}

template<typename T>
void my_deque<T>::push_front(T value) {
    push_back(T());

    for (size_t i = size_-1; i > 0; i--) {
        operator[](i) = operator[](i-1);
    }
    head->operator[](0) = value;
}

template<typename T>
void my_deque<T>::pop_front() {
    for (size_t i = 0; i < size_-1; i++) {
        operator[](i) = operator[](i + 1);
    }
    pop_back();
}


template<typename T>
void my_deque<T>::insert(size_t n, size_t pos, const T& value);

template<typename T>
void my_deque<T>::insert(size_t n, const T& value);

template<typename T>
void my_deque<T>::insert(size_t n, T* begin, T* end);

template<typename T>
void my_deque<T>::erase(int index);

template<typename T>
void my_deque<T>::erase(int begin, int end);

template<typename T>
void my_deque<T>::show_list() {
    size_t i = 0;
    auto current_chunk = head;
    while (current_chunk != nullptr) {
        for (size_t j = 0; j < node_size && i < size_; j++, i++) {
            cout << current_chunk->operator[](j) << " ";
        }
        current_chunk = current_chunk->next;
    }
    cout << "\n";
}



// Define other member functions...
