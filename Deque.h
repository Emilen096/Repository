#pragma once
#include <cstddef>
#include <string>
#include <initializer_list>
#include <ostream>
#include <istream>

class Deque {
public:
    Deque();
    Deque(std::initializer_list<int> init);
    Deque(const Deque& other);
    Deque(Deque&& other) noexcept;
    ~Deque();

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

private:
    int*         data;      // Указатель на динамически выделенный массив элементов
    std::size_t  capacity;  // Максимально допустимое количество элементов
    std::size_t  count;     // Текущее количество элементов в деке
    std::size_t  head;      // Индекс в массиве, где находится первый (front) элемент
    std::size_t  tail;      // Индекс “за” последним (back) элементом; invariant: tail = (head + count) % capacity

    void resizeBuffer();

};
