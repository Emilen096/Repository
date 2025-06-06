#include "Deque.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

Deque::Deque()
    : count(0) {}

Deque::Deque(std::initializer_list<int> init)
    : count(init.size()) {
    if (count > capacity)
        throw std::length_error("Initializer list exceeds maximum capacity");
    std::copy(init.begin(), init.end(), data);
}

Deque::Deque(const Deque& other)
    : count(other.count) {
    std::copy(other.data, other.data + other.count, data);
}

Deque::Deque(Deque&& other) noexcept
    : count(other.count) {
    std::copy(other.data, other.data + other.count, data);
    other.count = 0;
}

Deque& Deque::operator=(const Deque& other) {
    if (this == &other) return *this;
    count = other.count;
    std::copy(other.data, other.data + other.count, data);
    return *this;
}

Deque& Deque::operator=(Deque&& other) noexcept {
    if (this == &other) return *this;
    count = other.count;
    std::copy(other.data, other.data + other.count, data);
    other.count = 0;
    return *this;
}

void Deque::push_back(int value) {
    if (count >= capacity)
        throw std::overflow_error("Deque is full");
    data[count++] = value;
}

void Deque::push_front(int value) {
    if (count >= capacity)
        throw std::overflow_error("Deque is full");
    for (std::size_t i = count; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    ++count;
}

void Deque::pop_back() {
    if (count == 0) return;
    --count;
}

void Deque::pop_front() {
    if (count == 0) return;
    for (std::size_t i = 0; i < count - 1; ++i) {
        data[i] = data[i + 1];
    }
    --count;
}

int Deque::front() const {
    if (count == 0)
        throw std::out_of_range("Deque is empty");
    return data[0];
}

int Deque::back() const {
    if (count == 0)
        throw std::out_of_range("Deque is empty");
    return data[count - 1];
}

bool Deque::empty() const {
    return count == 0;
}

std::size_t Deque::size() const {
    return count;
}

std::string Deque::toString() const {
    std::ostringstream oss;
    oss << "[ ";
    for (std::size_t i = 0; i < count; ++i) {
        oss << data[i] << " ";
    }
    oss << "]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Deque& deque) {
    os << deque.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Deque& deque) {
    int val;
    while (is >> val) {
        deque.push_back(val);
    }
    return is;
}
