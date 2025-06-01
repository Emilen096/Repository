#include "Deque.h"
#include <sstream>
#include <stdexcept>

// Увеличить буфер: удвоить capacity (или сделать 1, если capacity == 0), скопировать элементы
void Deque::resizeBuffer() {
    std::size_t newCapacity = (capacity == 0 ? 1 : capacity * 2);
    int* newData = new int[newCapacity];

    // Копируем в порядке FIFO
    for (std::size_t i = 0; i < count; ++i) {
        std::size_t oldIndex = (head + i) % capacity;
        newData[i] = data[oldIndex];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    head = 0;
    tail = count % capacity;
}

Deque::Deque()
    : data(nullptr), capacity(0), count(0), head(0), tail(0)
{}

Deque::Deque(std::initializer_list<int> init)
    : data(nullptr),
      capacity(init.size() == 0 ? 1 : init.size() * 2),
      count(init.size()),
      head(0),
      tail(init.size() % (init.size() == 0 ? 1 : init.size() * 2))
{
    data = new int[capacity];
    std::size_t i = 0;
    for (int v : init) {
        data[i++] = v;
    }
}

Deque::Deque(const Deque& other)
    : data(nullptr),
      capacity(other.capacity),
      count(other.count),
      head(0),
      tail(other.count % other.capacity)
{
    if (capacity > 0) {
        data = new int[capacity];
        for (std::size_t i = 0; i < count; ++i) {
            std::size_t idx = (other.head + i) % other.capacity;
            data[i] = other.data[idx];
        }
    }
}

Deque::Deque(Deque&& other) noexcept
    : data(other.data),
      capacity(other.capacity),
      count(other.count),
      head(other.head),
      tail(other.tail)
{
    other.data = nullptr;
    other.capacity = 0;
    other.count = 0;
    other.head = other.tail = 0;
}

Deque::~Deque() {
    delete[] data;
}

Deque& Deque::operator=(const Deque& other) {
    if (this == &other) return *this;

    int* newData = nullptr;
    if (other.capacity > 0) {
        newData = new int[other.capacity];
        for (std::size_t i = 0; i < other.count; ++i) {
            std::size_t idx = (other.head + i) % other.capacity;
            newData[i] = other.data[idx];
        }
    }
    delete[] data;

    data = newData;
    capacity = other.capacity;
    count = other.count;
    head = 0;
    tail = count % capacity;
    return *this;
}

Deque& Deque::operator=(Deque&& other) noexcept {
    if (this == &other) return *this;

    delete[] data;
    data = other.data;
    capacity = other.capacity;
    count = other.count;
    head = other.head;
    tail = other.tail;

    other.data = nullptr;
    other.capacity = 0;
    other.count = 0;
    other.head = other.tail = 0;
    return *this;
}

void Deque::push_back(int value) {
    if (count == capacity) {
        resizeBuffer();
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    ++count;
}

void Deque::push_front(int value) {
    if (count == capacity) {
        resizeBuffer();
    }
    head = (head + capacity - 1) % capacity;
    data[head] = value;
    ++count;
}

void Deque::pop_back() {
    if (count == 0) return;
    tail = (tail + capacity - 1) % capacity;
    --count;
}

void Deque::pop_front() {
    if (count == 0) return;
    head = (head + 1) % capacity;
    --count;
}

int Deque::front() const {
    if (count == 0) throw std::out_of_range("Deque is empty");
    return data[head];
}

int Deque::back() const {
    if (count == 0) throw std::out_of_range("Deque is empty");
    std::size_t idx = (head + count - 1) % capacity;
    return data[idx];
}

bool Deque::empty() const {
    return (count == 0);
}

std::size_t Deque::size() const {
    return count;
}

std::string Deque::toString() const {
    std::ostringstream oss;
    oss << "[ ";
    for (std::size_t i = 0; i < count; ++i) {
        std::size_t idx = (head + i) % capacity;
        oss << data[idx] << " ";
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
