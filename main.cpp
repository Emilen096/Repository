#include <iostream>
#include "Point.h"
#include "Tetrahedron.h"

int main() {
    try {
        // Создаём точки
        Point A(0.0, 0.0, 0.0);
        Point B(2.0, 0.0, 0.0);
        Point C(0.0, 3.0, 0.0);
        Point D(1.0, 1.0, 0.0);

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
