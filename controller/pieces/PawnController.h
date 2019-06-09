#ifndef CONTROLLER_PAWN_CONTROLLER_H_
#define CONTROLLER_PAWN_CONTROLLER_H_

#include "../PieceController.h"
#include "../../model/PieceModel.h"
#include "../../model/BoardModel.h"

class PawnController : public PieceController {
    public:
        enum Direction {
            Positive = -1,
            Negative = 1
        };

        PawnController(Direction direction);
        PieceModel * take(BoardModel & board, const Position & origin, const Position & destination) override;
        bool move(BoardModel & board, const Position & origin, const Position & destination) override;
        virtual std::vector<Position> possibleMove(BoardModel & board, const Position & origin) override;

    private:
        Direction m_direction;
};

#endif // CONTROLLER_PAWN_CONTROLLER_H_
