#ifndef MODEL_POSITION_H_
#define MODEL_POSITION_H_

#define X 0
#define Y 1

class Position {
    public:
        Position() : Position(0, 0) {};
        Position(int x, int y);
        Position(const Position & position);
        int & operator[](int i);
        int operator[](int i) const;
        bool operator==(const Position & position) const;
        Position & addX(int value);
        Position & addY(int value);
    private:
        int m_position[2];
};

#endif // MODEL_POSITION_H_