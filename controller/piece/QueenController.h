#ifndef CONTROLLER_QUEEN_CONTROLLER_H_
#define CONTROLLER_QUEEN_CONTROLLER_H_

#include "../PieceController.h"

class QueenController : public PieceController
{
public:
    std::vector<Position> possibleMoves(const Position & origin) override;
};

#endif // CONTROLLER_QUEEN_CONTROLLER_H_