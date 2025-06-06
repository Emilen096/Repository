#pragma once
#include <cstddef>
#include <initializer_list>
#include <string>
#include <iostream>

class Deque {
private:
    static const std::size_t capacity = 100;  // Статическое максимальное значение
    int data[capacity];                       // Статический массив
    std::size_t count;                        // Количество элементов

public:
    Deque();
    Deque(std::initializer_list<int> init);
    Deque(const Deque& other);
    Deque(Deque&& other) noexcept;
    ~Deque() = default;

    Deque& operator=(const Deque& other);
    Deque& operator=(Deque&& other) noexcept;

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();

    int front() const;
    int back() const;
    bool empty() const;
    std::size_t size() const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Deque& deque);
    friend std::istream& operator>>(std::istream& is, Deque& deque);
};
