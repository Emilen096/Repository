#pragma once
#include <string>

enum class PositionType {
    Professor, AssociateProfessor, SeniorLecturer, Assistant
};

class Position {
private:
    PositionType type;

public:
    Position(const std::string& name);

    std::string ToString() const;
    PositionType getPositionType() const;
};