#include "Position.h"

Position::Position(int x, int y) {
    m_position[X] = x;
    m_position[Y] = y;
}

Position::Position(const Position & position) {
    m_position[X] = position.m_position[X];
    m_position[Y] = position.m_position[Y];
}

int & Position::operator[](int i) {
    return (i == X || i == Y) ? m_position[i] : m_position[X];
}

int Position::operator[](int i) const {
    return (i == X || i == Y) ? m_position[i] : m_position[X];
}

bool Position::operator==(const Position & position) const {
    return position.m_position[X] == m_position[X]
        && position.m_position[Y] == m_position[Y];
}

bool Position::operator!=(const Position & position) const {
    return !(*this == position);
}

std::ostream& operator<< (std::ostream & stream, const Position & position) {
    stream << "[" << position[X] << ";" << position[Y] << "]";
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const std::vector<Position> & positions) {
    for (const Position & position : positions) {
        if (position != positions.front())
            stream << ",";
        stream << position;
    }
    return stream;
}

Position & Position::addX(int value) {
    m_position[X] += value;
    return *this;
}

Position & Position::addY(int value) {
    m_position[Y] += value;
    return *this;
}