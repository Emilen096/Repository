#include "Deque.h"
#include <sstream>
#include <stdexcept>

// Конструктор со списком инициализации
Deque::Deque(std::initializer_list<int> init) {
    for (int val : init) {
        data.push_back(val);
    }
}

// Добавление в конец
void Deque::push_back(int value) {
    data.push_back(value);
}

// Добавление в начало
void Deque::push_front(int value) {
    data.insert(data.begin(), value);
}

// Удаление с конца
void Deque::pop_back() {
    if (data.empty()) {
        throw std::out_of_range("Deque is empty");
    }
    data.pop_back();
}

// Удаление с начала
void Deque::pop_front() {
    if (data.empty()) {
        throw std::out_of_range("Deque is empty");
    }
    data.erase(data.begin());
}

// Первый элемент
int Deque::front() const {
    if (data.empty()) {
        throw std::out_of_range("Deque is empty");
    }
    return data.front();
}

// Последний элемент
int Deque::back() const {
    if (data.empty()) {
        throw std::out_of_range("Deque is empty");
    }
    return data.back();
}

// Проверка на пустоту
bool Deque::empty() const noexcept {
    return data.empty();
}

// Размер дека
size_t Deque::size() const noexcept {
    return data.size();
}

// Преобразование в строку
std::string Deque::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        oss << (i > 0 ? " " : "") << data[i];
    }
    oss << "]";
    return oss.str();
}

// Оператор вывода (сдвиг влево)
std::ostream& operator<<(std::ostream& os, const Deque& deque) {
    os << deque.toString();
    return os;
}

// Оператор ввода (сдвиг вправо)
std::istream& operator>>(std::istream& is, Deque& deque) {
    int value;
    while (is >> value) {
        deque.push_back(value);
        
        // Проверка следующего символа
        if (is.peek() == '\n' || is.peek() == EOF) {
            break;
        }
    }
    return is;
}
