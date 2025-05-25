#include "Library\Department.h"
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>

const std::vector<std::string>& Department::GetValidDepartments() {
    static const std::vector<std::string> departments = {
        "Math", "Physics", "CS", "Biology", "Chemistry"
    };
    return departments;
}

Department::Department(const std::string& name) : name(name) {
    const auto& valid = GetValidDepartments();
    if (std::find(valid.begin(), valid.end(), name) == valid.end())
        throw std::invalid_argument("Invalid department name.");
}

std::string Department::ToString() const {
    return name;
}