#include "Tetrahedron.h"

// Конструктор
Tetrahedron::Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d)
    : a(a), b(b), c(c), d(d) {}

// Расчёт объёма тетраэдра
double Tetrahedron::volume() const {
    // Векторы AB, AC, AD
    Point ab = b - a;
    Point ac = c - a;
    Point ad = d - a;

    // Векторное произведение AC × AD
    double cross_x = ac.getY() * ad.getZ() - ac.getZ() * ad.getY();
    double cross_y = ac.getZ() * ad.getX() - ac.getX() * ad.getZ();
    double cross_z = ac.getX() * ad.getY() - ac.getY() * ad.getX();

    // Скалярное произведение AB · (AC × AD)
    double dot = ab.getX() * cross_x + ab.getY() * cross_y + ab.getZ() * cross_z;

    // Объём = 1/6 * |скалярное произведение|
    return std::abs(dot) / 6.0;
}