#include "Deque.h"
#include <iostream>

int main() {
    try {
        // Создание очереди с использованием списка
        Deque d1{1, 2, 3, 4};
        std::cout << "Initial deque: " << d1 << std::endl;
        
        // Добавление элементов
        d1.push_back(5);
        std::cout << "After push_back(5): " << d1 << std::endl;
        
        d1.push_front(0);
        std::cout << "After push_front(0): " << d1 << std::endl;
        
        // Удаление элементов
        d1.pop_front();
        std::cout << "After pop_front(): " << d1 << std::endl;
        
        d1.pop_back();
        std::cout << "After pop_back(): " << d1 << std::endl;
        
        // Доступ к элементам
        std::cout << "Front element: " << d1.front() << std::endl;
        std::cout << "Back element: " << d1.back() << std::endl;
        
        // Состояние очереди
        std::cout << "Size: " << d1.size() << ", ";
        std::cout << "Empty? " << (d1.empty() ? "Yes" : "No") << std::endl;
        
        // Тестирование оператора ввода
        Deque d2;
        std::cout << "\nEnter deque elements (space separated, finish with Enter): ";
        std::cin >> d2;
        std::cout << "You entered: " << d2 << std::endl;
        
        // Тестирование копирования
        Deque d3 = d2;
        d3.push_back(100);
        std::cout << "Copied deque + push_back(100): " << d3 << std::endl;
        std::cout << "Original deque: " << d2 << std::endl;
        
        // Тестирование перемещения
        Deque d4 = std::move(d3);
        std::cout << "After move: " << d4 << std::endl;
        std::cout << "Moved deque (should be empty): " << d3 << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
