#include "Tetrahedron.h"
#include <stdexcept>
#include <cmath>

// Конструктор с проверкой на вырожденность
Tetrahedron::Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d)
    : a(a), b(b), c(c), d(d) {
    
    const double tolerance = 1e-9;
    if (!isValid(tolerance)) {
        throw std::invalid_argument("Points do not form a valid tetrahedron");
    }
}

// Расчёт объёма тетраэдра
static double calculateMixedProduct(const Point& a, const Point& b, 
                                   const Point& c, const Point& d) {
    // Создание векторов из вершины A к другим вершинам

    // Вектор AB = B - A
    const double ABx = b.getX() - a.getX();
    const double ABy = b.getY() - a.getY();
    const double ABz = b.getZ() - a.getZ();
    
    // Вектор AC = C - A
    const double ACx = c.getX() - a.getX();
    const double ACy = c.getY() - a.getY();
    const double ACz = c.getZ() - a.getZ();
    
    // Вектор AD = D - A
    const double ADx = d.getX() - a.getX();
    const double ADy = d.getY() - a.getY();
    const double ADz = d.getZ() - a.getZ();

    // Векторное произведение AC × AD
    const double cross_x = ACy * ADz - ACz * ADy;
    const double cross_y = ACz * ADx - ACx * ADz;
    const double cross_z = ACx * ADy - ACy * ADx;

    // Объём = 1/6 * |скалярное произведение|
    return ABx * cross_x + ABy * cross_y + ABz * cross_z;
}

// Проверка валидности тетраэдра
bool Tetrahedron::isValid(double tolerance) const {
    const double mixedProduct = calculateMixedProduct(a, b, c, d);
    return std::abs(mixedProduct) > tolerance;
}

// Расчёт объёма тетраэдра
double Tetrahedron::volume() const {
    const double mixedProduct = calculateMixedProduct(a, b, c, d);
    return std::abs(mixedProduct) / 6.0;
}
