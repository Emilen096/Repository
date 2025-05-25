#pragma once
#include <vector>
#include <string>
#include <initializer_list>

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
    size_t size() const;
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Deque& deque);
    friend std::istream& operator>>(std::istream& is, Deque& deque);

private:
    std::vector<int> data;
};