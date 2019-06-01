#ifndef CONTROLLER_PAWN_CONTROLLER_H_
#define CONTROLLER_PAWN_CONTROLLER_H_

#include "../PieceController.h"
#include "../../model/PieceModel.h"
#include "../../model/BoardModel.h"

class PawnController : public PieceController {
    public:
        PieceModel * take(BoardModel & board,
                          const Position & origin,
                          const Position & destination) override;
        bool move(BoardModel & board, const Position & origin, const Position & destination) override;
        virtual std::vector<Position> possibleMove(BoardModel & board, const Position origin) override;
};

#endif // CONTROLLER_PAWN_CONTROLLER_H_
