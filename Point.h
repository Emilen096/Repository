#pragma once

class Point {
private:
    double x, y, z;

public:
    Point(double x, double y, double z);
    
    // Геттеры
    double getX() const;
    double getY() const;
    double getZ() const;
};
