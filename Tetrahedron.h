#pragma once
#include "Point.h"

class Tetrahedron {
private:
    Point a, b, c, d;

public:
    // Конструктор
    Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d);

    // Метод для расчёта объёма
    double volume() const;
};