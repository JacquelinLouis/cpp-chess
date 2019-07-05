#ifndef CONTROLLER_TOWER_CONTROLLER_H_
#define CONTROLLER_TOWER_CONTROLLER_H_

#include "../PieceController.h"

class TowerController : public PieceController {
    public:
        std::vector<Position> possibleMoves(BoardModel & board, const Position & origin) override;
};

#endif // CONTROLLER_TOWER_CONTROLLER_H_
