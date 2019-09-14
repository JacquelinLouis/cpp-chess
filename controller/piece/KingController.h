#ifndef CONTROLLER_KING_CONTROLLER_H_
#define CONTROLLER_KING_CONTROLLER_H_

#include "../PieceController.h"

class KingController : public PieceController
{
public:
    std::vector<Position> possibleMoves(BoardModel & board, const Position & origin) override;
};

#endif // CONTROLLER_KING_CONTROLLER_H_