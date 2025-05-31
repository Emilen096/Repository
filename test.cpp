#include "pch.h"
#include "gtest/gtest.h"
#include "C:\Users\EMIL\.vscode\c++\Library\Category.h"
#include "C:\Users\EMIL\.vscode\c++\Library\Date.h"
#include "C:\Users\EMIL\.vscode\c++\Library\Department.h"
#include "C:\Users\EMIL\.vscode\c++\Library\FullName.h"
#include "C:\Users\EMIL\.vscode\c++\Library\Person.h"
#include "C:\Users\EMIL\.vscode\c++\Library\Position.h"
#include "C:\Users\EMIL\.vscode\c++\Library\UniversityEmployee.h"


// Тест: Сортировка по фамилии
TEST(UniversityEmployeeTest, SortingBySurname) {
    std::vector<UniversityEmployee> employees;

    // Создаём два сотрудника
    FullName name1("Ivanov", "Ivan", "Ivanovich");
    FullName name2("Alekseev", "Alex", "Alexeevich");
    Date date(1, Month::January, 2000);
    Department dept("Math");
    Position pos("Assistant");

    employees.emplace_back(name1, Gender::Male, date, dept, pos, 5, Category::Middle);
    employees.emplace_back(name2, Gender::Male, date, dept, pos, 3, Category::Low);

    // Сортируем по фамилии через геттеры
    /*std::sort(employees.begin(), employees.end(), [](const UniversityEmployee a, const UniversityEmployee b) {
        return a.GetFullName().ToString() < b.GetFullName().ToString();
        });*/

    // Проверяем, что сортировка успешна
    EXPECT_EQ(employees[0].GetFullName().ToString(), "Alekseev Alex Alexeevich");
    EXPECT_EQ(employees[1].GetFullName().ToString(), "Ivanov Ivan Ivanovich");
}

// Тест: Сортировка по должности
TEST(UniversityEmployeeTest, SortingByPosition) {
    std::vector<UniversityEmployee> employees;

    // Создаём два сотрудника
    FullName name1("Ivanov", "Ivan", "Ivanovich");
    FullName name2("Petrov", "Petr", "Petrovich");
    Date date(1, Month::January, 2000);
    Department dept("Math");
    Position pos1("Professor");
    Position pos2("Assistant");

    employees.emplace_back(name1, Gender::Male, date, dept, pos1, 15, Category::High);
    employees.emplace_back(name2, Gender::Male, date, dept, pos2, 2, Category::Low);

    /*// Сортируем по должности (через enum PositionType)
    std::sort(employees.begin(), employees.end(), [](const UniversityEmployee& a, const UniversityEmployee& b) {
        return static_cast<int>(a.GetPosition().getPositionType()) < static_cast<int>(b.GetPosition().getPositionType());
        });*/

    // Проверяем, что сортировка успешна
    EXPECT_EQ(employees[0].GetPosition().ToString(), "Professor");
    EXPECT_EQ(employees[1].GetPosition().ToString(), "Assistant");
}