#include "Deque.h"
#include <iostream>

int main() {
    Deque d1{1, 2, 3, 4};
    std::cout << "Initial deque: " << d1 << std::endl;
    
    d1.push_back(4);
    std::cout << "After push_back(4): " << d1 << std::endl;
    
    d1.push_front(0);
    std::cout << "After push_front(0): " << d1 << std::endl;
    
    d1.pop_front();
    std::cout << "After pop_front: " << d1 << std::endl;
    
    d1.pop_back();
    std::cout << "After pop_back: " << d1 << std::endl;
    
    std::cout << "Front element: " << d1.front() << std::endl;
    std::cout << "Back element: " << d1.back() << std::endl;
    
    std::cout << "Size: " << d1.size() << ", ";
    std::cout << "Empty? " << (d1.empty() ? "Yes" : "No") << std::endl;
    
    return 0;
}