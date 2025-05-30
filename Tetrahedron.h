#pragma once
#include "Point.h"
#include <cmath>
#include <stdexcept>

class Tetrahedron {
private:
    Point a, b, c, d;

public:
    // Конструктор с проверкой
    Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d);
    
    // Проверка валидности тетраэдра
    bool isValid(double tolerance = 1e-9) const;
    
    // Метод для расчёта объёма
    double volume() const;
};
