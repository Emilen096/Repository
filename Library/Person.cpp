#include "Library\Person.h"

Person::Person(const FullName& fullName, Gender gender, const Date& birthDate)
    : fullName(fullName), gender(gender), birthDate(birthDate) {}