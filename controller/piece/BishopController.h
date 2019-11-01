#ifndef CONTROLLER_BISHOP_CONTROLLER_H_
#define CONTROLLER_BISHOP_CONTROLLER_H_

#include "../PieceController.h"

class BishopController : PieceController
{
private:
    /* data */
public:
    std::vector<Position> possibleMoves(const Position & origin) override;
};

#endif // CONTROLLER_BISHOP_CONTROLLER_H_