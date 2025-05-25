#include "Deque.h"
#include <sstream>

Deque::Deque() = default;

Deque::Deque(std::initializer_list<int> init) {
    for (int val : init) {
        data.push_back(val);
    }
}

Deque::Deque(const Deque& other) : data(other.data) {}

Deque::Deque(Deque&& other) noexcept : data(std::move(other.data)) {}

Deque::~Deque() = default;

Deque& Deque::operator=(const Deque& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

Deque& Deque::operator=(Deque&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
    }
    return *this;
}

void Deque::push_back(int value) {
    data.push_back(value);
}

void Deque::push_front(int value) {
    data.insert(data.begin(), value);
}

void Deque::pop_back() {
    if (!data.empty()) {
        data.pop_back();
    }
}

void Deque::pop_front() {
    if (!data.empty()) {
        data.erase(data.begin());
    }
}

int Deque::front() const {
    if (data.empty()) throw std::out_of_range("Deque is empty");
    return data.front();
}

int Deque::back() const {
    if (data.empty()) throw std::out_of_range("Deque is empty");
    return data.back();
}

bool Deque::empty() const {
    return data.empty();
}

size_t Deque::size() const {
    return data.size();
}

std::string Deque::toString() const {
    std::ostringstream oss;
    oss << "[ ";
    for (int val : data) {
        oss << val << " ";
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