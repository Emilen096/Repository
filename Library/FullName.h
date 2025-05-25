#pragma once
#include <string>

class FullName {
private:
    std::string lastName;
    std::string firstName;
    std::string patronymic;

public:
    FullName(const std::string& lastName, const std::string& firstName, const std::string& patronymic);
    std::string ToString() const;
};