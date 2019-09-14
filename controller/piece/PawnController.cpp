#include "PawnController.h"

PawnController::PawnController(Direction direction) : m_direction(direction)
{};

std::vector<Position> PawnController::possibleMoves(BoardModel & board, const Position & origin) {
    std::vector<Position> moves;
    for (int i = 1; i < 3; ++i) {
        int destinationX = origin[X] + i * m_direction;
        if (board.inBoard(origin))
            moves.emplace_back(destinationX, origin[Y]);
    }
    return moves;
}