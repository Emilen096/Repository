#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>

class Deque {
public:
    // Конструкторы
    Deque() = default;
    Deque(std::initializer_list<int> init);
    Deque(const Deque& other) = default;
    Deque(Deque&& other) noexcept = default;
    
    // Операторы присваивания
    Deque& operator=(const Deque& other) = default;
    Deque& operator=(Deque&& other) noexcept = default;
    
    // Деструктор
    ~Deque() = default;

    // Основные операции
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();

    // Доступ к элементам
    int front() const;
    int back() const;

    // Состояние дека
    bool empty() const noexcept;
    size_t size() const noexcept;
    
    // Преобразование в строку
    std::string toString() const;

    // Операторы сдвига
    friend std::ostream& operator<<(std::ostream& os, const Deque& deque);
    friend std::istream& operator>>(std::istream& is, Deque& deque);

private:
    std::vector<int> data;
};
