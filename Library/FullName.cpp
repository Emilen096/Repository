#include "Library\FullName.h"

FullName::FullName(const std::string& lastName, const std::string& firstName, const std::string& patronymic)
    : lastName(lastName), firstName(firstName), patronymic(patronymic) {}

std::string FullName::ToString() const {
    return lastName + " " + firstName + " " + patronymic;
}