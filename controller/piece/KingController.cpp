#include "KingController.h"

std::vector<Position> KingController::possibleMoves(const Position & origin) {
    std::vector<Position> moves;
    for (int j = -1; j < 2; ++j) {
        for (int i = -1; i < 2; ++i) {
            Position move = Position(origin).addX(i).addY(j);
            if (BoardModel::inBoard(move) && move != origin)
                moves.push_back(move);
        }
    }
    return moves;
}