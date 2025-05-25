#include <iostream>
#include "Point.h"
#include "Tetrahedron.h"

int main() {
    // Создаём точки
    Point A(0.0, 0.0, 0.0);
    Point B(2.0, 0.0, 0.0);
    Point C(0.0, 3.0, 0.0);
    Point D(0.0, 0.0, 4.0);

    // Создаём тетраэдр
    Tetrahedron tetra(A, B, C, D);

    // Выводим объём
    std::cout.precision(6);
    std::cout << "V: " << tetra.volume() << std::endl;

    return 0;
}