#include "Library\Position.h"
#include <string>
#include <stdexcept>
#include <map>

static const std::map<std::string, PositionType> positionMap = {
    {"Professor", PositionType::Professor},
    {"AssociateProfessor", PositionType::AssociateProfessor},
    {"SeniorLecturer", PositionType::SeniorLecturer},
    {"Assistant", PositionType::Assistant}
};

Position::Position(const std::string& name) {
    auto it = positionMap.find(name);
    if (it == positionMap.end())
        throw std::runtime_error("Invalid position");
    type = it->second;
}

std::string Position::ToString() const {
    switch (type) {
        case PositionType::Professor: return "Professor";
        case PositionType::AssociateProfessor: return "AssociateProfessor";
        case PositionType::SeniorLecturer: return "SeniorLecturer";
        case PositionType::Assistant: return "Assistant";
        default: return "Unknown";
    }
}

PositionType Position::getPositionType() const {
    return type;
}