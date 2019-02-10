#ifndef CONTROLLER_PAWN_CONTROLLER_H_
#define CONTROLLER_PAWN_CONTROLLER_H_

#include "PieceController.h"
#include "../model/PieceModel.h"
#include "../model/BoardModel.h"

class PawnController : public PieceController {
    public:
        PieceModel * move(BoardModel & board,
                          const int posOrigin[2],
                          const int posDestination[2]) override;
};

#endif // CONTROLLER_PAWN_CONTROLLER_H_
