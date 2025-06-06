#include "Deque.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Инициализация статической переменной
std::size_t Deque::capacity = 100;  // Максимальная ёмкость

// Конструктор по умолчанию
Deque::Deque()
    : data(nullptr), count(0)
{}

// Конструктор с инициализацией из списка
Deque::Deque(std::initializer_list<int> init)
    : data(nullptr), count(init.size())
{
    if (count > capacity) {
        throw std::out_of_range("Cannot initialize deque: exceeds maximum capacity");
    }
    
    data = new int[count];
    std::size_t i = 0;
    for (int v : init) {
        data[i++] = v;
    }
}

// Конструктор копирования
Deque::Deque(const Deque& other)
    : data(nullptr), count(other.count)
{
    if (count > capacity) {
        throw std::out_of_range("Cannot copy deque: exceeds maximum capacity");
    }

    if (count > 0) {
        data = new int[count];
        for (std::size_t i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }
}

// Конструктор перемещения
Deque::Deque(Deque&& other) noexcept
    : data(other.data), count(other.count)
{
    other.data = nullptr;
    other.count = 0;
}

// Деструктор
Deque::~Deque() {
    delete[] data;
}

// Оператор присваивания (копирование)
Deque& Deque::operator=(const Deque& other) {
    if (this == &other) return *this;

    delete[] data;
    
    count = other.count;
    if (count > capacity) {
        throw std::out_of_range("Cannot copy deque: exceeds maximum capacity");
    }

    if (count > 0) {
        data = new int[count];
        for (std::size_t i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }

    return *this;
}

// Оператор присваивания (перемещение)
Deque& Deque::operator=(Deque&& other) noexcept {
    if (this == &other) return *this;

    delete[] data;
    
    data = other.data;
    count = other.count;
    
    other.data = nullptr;
    other.count = 0;

    return *this;
}

// Добавление элемента в конец
void Deque::push_back(int value) {
    if (count >= capacity) {
        throw std::overflow_error("Deque is full, cannot push_back");
    }
    
    int* newData = new int[count + 1];
    std::copy(data, data + count, newData);
    newData[count] = value;
    
    delete[] data;
    data = newData;
    ++count;

    // Проверка на превышение ёмкости
    if (count > capacity) {
        count = capacity;  // Обрезаем до максимальной ёмкости
    }
}

// Добавление элемента в начало
void Deque::push_front(int value) {
    if (count >= capacity) {
        throw std::overflow_error("Deque is full, cannot push_front");
    }

    int* newData = new int[count + 1];
    std::copy(data, data + count, newData + 1);
    newData[0] = value;
    
    delete[] data;
    data = newData;
    ++count;

    // Проверка на превышение ёмкости
    if (count > capacity) {
        count = capacity;  // Обрезаем до максимальной ёмкости
    }
}

// Удаление элемента с конца
void Deque::pop_back() {
    if (count == 0) return;
    
    int* newData = new int[count - 1];
    std::copy(data, data + count - 1, newData);
    
    delete[] data;
    data = newData;
    --count;
}

// Удаление элемента с начала
void Deque::pop_front() {
    if (count == 0) return;

    int* newData = new int[count - 1];
    std::copy(data + 1, data + count, newData);

    delete[] data;
    data = newData;
    --count;
}

// Получить первый элемент
int Deque::front() const {
    if (count == 0) throw std::out_of_range("Deque is empty");
    return data[0];
}

// Получить последний элемент
int Deque::back() const {
    if (count == 0) throw std::out_of_range("Deque is empty");
    return data[count - 1];
}

// Проверка на пустоту
bool Deque::empty() const noexcept {
    return (count == 0);
}

// Получить размер очереди
std::size_t Deque::size() const noexcept {
    return count;
}

// Преобразовать очередь в строку
std::string Deque::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (std::size_t i = 0; i < count; ++i) {
        oss << (i > 0 ? " " : "") << data[i];
    }
    oss << "]";
    return oss.str();
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Deque& deque) {
    os << deque.toString();
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Deque& deque) {
    int value;
    while (is >> value) {
        deque.push_back(value);
        
        // Проверка на конец строки
        if (is.peek() == '\n' || is.peek() == EOF) {
            break;
        }
    }
    return is;
}
