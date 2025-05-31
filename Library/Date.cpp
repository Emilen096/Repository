#include "Library\Date.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

bool Date::IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::DaysInMonth(Month month, int year) {
    switch (month) {
        case Month::February: return IsLeapYear(year) ? 29 : 28;
        case Month::April: case Month::June: case Month::September: case Month::November: return 30;
        default: return 31;
    }
}

Date::Date(int day, Month month, int year)
    : day(day), month(month), year(year) {
    if (day < 1 || day > DaysInMonth(month, year))
        throw std::invalid_argument("Invalid day for the given month and year.");
}

std::string Date::ToString() const {
    std::ostringstream oss;
    oss << day << " " << static_cast<int>(month) + 1 << " " << year;
    return oss.str();
}