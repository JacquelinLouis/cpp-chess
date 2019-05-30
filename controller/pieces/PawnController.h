#ifndef CONTROLLER_PAWN_CONTROLLER_H_
#define CONTROLLER_PAWN_CONTROLLER_H_

#include "../PieceController.h"
#include "../../model/PieceModel.h"
#include "../../model/BoardModel.h"

class PawnController : public PieceController {
    public:
        PieceModel * take(BoardModel & board,
                          const int posOrigin[2],
                          const int posDestination[2]) override;
        bool move(BoardModel & board,
                  const int posOrigin[2],
                  const int posDestination[2]) override;
        virtual std::vector<Position> possibleMove(BoardModel & board, const Position origin) override;
};

#endif // CONTROLLER_PAWN_CONTROLLER_H_
