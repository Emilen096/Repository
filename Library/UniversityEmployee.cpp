#include "Library\UniversityEmployee.h"
#include <iostream>
#include <algorithm>
#include <string>

UniversityEmployee::UniversityEmployee(
    const FullName& fullName, Gender gender, const Date& birthDate,
    const Department& department, const Position& position,
    int experience, Category category)
    : Person(fullName, gender, birthDate),
      department(department), position(position),
      experience(experience), category(category) {}

std::string UniversityEmployee::ToString() const {
    return fullName.ToString() + " | " +
           department.ToString() + " | " +
           position.ToString() + " | " +
           std::to_string(experience) + " years | " +
           (category == Category::High ? "High" :
            category == Category::Middle ? "Middle" : "Low");
}

void UniversityEmployee::PrintSortedBySurname(const std::vector<UniversityEmployee>& employees) {
    std::vector<UniversityEmployee> sorted = employees;
    std::sort(sorted.begin(), sorted.end(), [](const UniversityEmployee& a, const UniversityEmployee& b) {
        return a.fullName.ToString() < b.fullName.ToString();
    });
    for (const auto& emp : sorted)
        std::cout << emp.ToString() << std::endl;
}

void UniversityEmployee::PrintSortedByPosition(const std::vector<UniversityEmployee>& employees) {
    std::vector<UniversityEmployee> sorted = employees;
    std::sort(sorted.begin(), sorted.end(), [](const UniversityEmployee& a, const UniversityEmployee& b) {
        return static_cast<int>(a.position.getPositionType()) < static_cast<int>(b.position.getPositionType());
    });
    for (const auto& emp : sorted)
        std::cout << emp.ToString() << std::endl;
}