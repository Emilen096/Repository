#include "Library\UniversityEmployee.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    try {
        std::vector<UniversityEmployee> employees;

        for (int i = 0; i < 2; ++i) {
            std::string ln, fn, pt;
            std::cout << "Enter Full Name (lastName firstName patronymic): ";
            std::cin >> ln >> fn >> pt;
            FullName name(ln, fn, pt);

            int gender;
            std::cout << "Enter Gender (0 - Male, 1 - Female): ";
            std::cin >> gender;

            int day, month, year;
            std::cout << "Enter Birth Date (day month year): ";
            std::cin >> day >> month >> year;
            Date birthDate(day, static_cast<Month>(month - 1), year);

            std::string deptName;
            std::cout << "Enter Department (Math, Physics, CS, Biology, Chemistry): ";
            std::cin >> deptName;
            Department dept(deptName);

            std::string posName;
            std::cout << "Enter Position (Professor, AssociateProfessor, SeniorLecturer, Assistant): ";
            std::cin >> posName;
            Position pos(posName);

            int experience;
            std::cout << "Enter Experience (years): ";
            std::cin >> experience;

            int category;
            std::cout << "Enter Category (0 - High, 1 - Middle, 2 - Low): ";
            std::cin >> category;

            employees.emplace_back(
                name, static_cast<Gender>(gender), birthDate,
                dept, pos, experience, static_cast<Category>(category)
            );
        }

        std::cout << "\nSorted by Surname:\n";
        UniversityEmployee::PrintSortedBySurname(employees);

        std::cout << "\nSorted by Position:\n";
        UniversityEmployee::PrintSortedByPosition(employees);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}