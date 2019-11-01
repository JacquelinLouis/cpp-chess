#ifndef CONTROLLER_PAWN_CONTROLLER_H_
#define CONTROLLER_PAWN_CONTROLLER_H_

#include "../PieceController.h"

class PawnController : public PieceController {
    public:
        enum Direction {
            Positive = 1,
            Negative = -1
        };

        PawnController(Direction direction);
        std::vector<Position> possibleMoves(const Position & origin) override;

    private:
        Direction m_direction;
};

#endif // CONTROLLER_PAWN_CONTROLLER_H_
