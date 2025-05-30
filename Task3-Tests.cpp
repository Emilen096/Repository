#include "Library\UniversityEmployee.h"
#include <iostream>
#include <vector>

int main() {
    try {
        std::vector<UniversityEmployee> employees;

        // Тестовые данные для первого сотрудника
        FullName name1("Ivanov", "Ivan", "Ivanovich");
        Date birthDate1(15, Month::January, 1980);
        Department dept1("CS");
        Position pos1("Professor");
        employees.emplace_back(name1, Gender::Male, birthDate1, dept1, pos1, 15, Category::High);

        // Тестовые данные для второго сотрудника
        FullName name2("Petrova", "Maria", "Sergeevna");
        Date birthDate2(22, Month::June, 1990);
        Department dept2("Physics");
        Position pos2("Assistant");
        employees.emplace_back(name2, Gender::Female, birthDate2, dept2, pos2, 3, Category::Low);

        // Тестовые данные для третьего сотрудника
        FullName name3("Sidorov", "Alexey", "Olegovich");
        Date birthDate3(10, Month::March, 1985);
        Department dept3("Math");
        Position pos3("AssociateProfessor");
        employees.emplace_back(name3, Gender::Male, birthDate3, dept3, pos3, 8, Category::Middle);

        std::cout << "=== Sorted by Surname ===\n";
        UniversityEmployee::PrintSortedBySurname(employees);

        std::cout << "\n=== Sorted by Position ===\n";
        UniversityEmployee::PrintSortedByPosition(employees);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}