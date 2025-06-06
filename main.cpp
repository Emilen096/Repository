#include <iostream>
#include "Deque.h"

int main() {
    Deque d1{1, 2, 3, 4};
    std::cout << "Initial deque: " << d1.toString() << "\n";

    d1.push_back(5);
    std::cout << "After push_back(5): " << d1.toString() << "\n";

    d1.push_front(0);
    std::cout << "After push_front(0): " << d1.toString() << "\n";

    d1.pop_front();
    std::cout << "After pop_front(): " << d1.toString() << "\n";

    d1.pop_back();
    std::cout << "After pop_back(): " << d1.toString() << "\n";

    std::cout << "Front element: " << d1.front() << "\n";
    std::cout << "Back element: " << d1.back() << "\n";

    std::cout << "Size: " << d1.size() << ", ";
    std::cout << "Empty? " << (d1.empty() ? "Yes" : "No") << "\n";

    // Demonstrate copy and move
    Deque d2 = d1;  // copy
    d2.push_back(99);
    std::cout << "Copied and modified deque: " << d2.toString() << "\n";

    Deque d3 = std::move(d2); // move
    std::cout << "Moved deque: " << d3.toString() << "\n";
    std::cout << "Original after move (should be empty): " << d2.toString() << "\n";

    return 0;
}
