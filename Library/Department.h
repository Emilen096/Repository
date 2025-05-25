#pragma once
#include <string>
#include <vector>

class Department {
private:
    std::string name;

    static const std::vector<std::string>& GetValidDepartments();

public:
    Department(const std::string& name);
    std::string ToString() const;
};