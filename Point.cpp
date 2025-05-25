#include "Point.h"

// Конструктор
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

// Геттеры
double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

// Перегрузка оператора вычитания
Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y, z - other.z);
}