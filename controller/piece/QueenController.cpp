#include "QueenController.h"

#include "BishopController.h"
#include "TowerController.h"

std::vector<Position> QueenController::possibleMoves(const Position & origin) {
    std::vector<Position> moves;
    std::vector<Position> bishopMoves = BishopController().possibleMoves(origin);
    moves.insert(moves.end(), bishopMoves.begin(), bishopMoves.end());
    std::vector<Position> towerMoves = TowerController().possibleMoves(origin);
    moves.insert(moves.end(), towerMoves.begin(), towerMoves.end());
    return moves;
}
