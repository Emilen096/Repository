#pragma once
#include <string>

enum class Month {
    January, February, March, April, May, June,
    July, August, September, October, November, December
};

class Date {
private:
    int day;
    Month month;
    int year;

    static bool IsLeapYear(int year);
    static int DaysInMonth(Month month, int year);

public:
    Date(int day, Month month, int year);
    std::string ToString() const;
};