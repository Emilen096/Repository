#include <iostream>
#include "Point.h"
#include "Tetrahedron.h"

int main() {
    try {
        double x, y, z;
        std::cout << "Enter coordinates for point A (x y z): ";
        std::cin >> x >> y >> z;
        Point A(x, y, z);
        
        std::cout << "Enter coordinates for point B (x y z): ";
        std::cin >> x >> y >> z;
        Point B(x, y, z);
        
        std::cout << "Enter coordinates for point C (x y z): ";
        std::cin >> x >> y >> z;
        Point C(x, y, z);
        
        std::cout << "Enter coordinates for point D (x y z): ";
        std::cin >> x >> y >> z;
        Point D(x, y, z);

        // Создаём тетраэдр (автоматически проверяем валидность)
        Tetrahedron tetra(A, B, C, D);

        // Выводим объём
        std::cout.precision(6);
        std::cout << "Volume: " << tetra.volume() << std::endl;
        
    } catch (const std::invalid_argument& e) {
        // Обрабатываем ошибку невалидного тетраэдра
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
