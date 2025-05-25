#pragma once
#include <cmath> 

class Point {
private:
    double x, y, z;

public:
    // Конструктор
    Point(double x, double y, double z);

    // Геттеры
    double getX() const;
    double getY() const;
    double getZ() const;

    // Перегрузка оператора вычитания (вектор AB = B - A)
    Point operator-(const Point& other) const;
};