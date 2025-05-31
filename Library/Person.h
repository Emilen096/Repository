#pragma once
#include "Library\FullName.h"
#include "Library\Date.h"
#include <string>

enum class Gender { Male, Female };

class Person {
protected:
    FullName fullName;
    Gender gender;
    Date birthDate;

public:
    Person(const FullName& fullName, Gender gender, const Date& birthDate);
    virtual std::string ToString() const = 0;
};