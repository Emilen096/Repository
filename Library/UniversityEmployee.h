#pragma once
#include "Library\Person.h"
#include "Library\Department.h"
#include "Library\Position.h"
#include "Library\Category.h"
#include <string>
#include <vector>

class UniversityEmployee : public Person {
private:
    Department department;
    Position position;
    int experience;
    Category category;

public:
    UniversityEmployee(
        const FullName& fullName, Gender gender, const Date& birthDate,
        const Department& department, const Position& position,
        int experience, Category category);

    std::string ToString() const override;
    static void PrintSortedBySurname(const std::vector<UniversityEmployee>& employees);
    static void PrintSortedByPosition(const std::vector<UniversityEmployee>& employees);
};