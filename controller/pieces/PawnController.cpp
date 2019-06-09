#include "PawnController.h"

PawnController::PawnController(Direction direction) : m_direction(direction)
{};

PieceModel * PawnController::take(BoardModel & board, const Position & origin, const Position & destination) {
    PieceModel * pieceOrigin = board.get(origin);
    PieceModel * pieceDestination = board.get(destination);
    if (!pieceOrigin || !pieceDestination) {
        return nullptr;
    }
    board.set(pieceOrigin, destination);
    board.set(nullptr, destination);
    return pieceDestination;
}

bool PawnController::move(BoardModel & board, const Position & origin, const Position & destination) {
    PieceModel * pieceModel = board.get(origin);
    if (!pieceModel) {
        return false;
    }
    int direction = colorToDirection(pieceModel->color);
    if (origin[X] == destination[X]
        || (origin[Y] != destination[Y] + direction
            && origin[Y] != destination[Y] + 2 * direction)) {
        return false;
    }
    return PieceController::move(board, origin, destination);
}


std::vector<Position> PawnController::possibleMove(BoardModel & board, const Position & origin) {
    std::vector<Position> moves;
    // TODO: continue here
    origin[X] += m_direction;
    if (board.inBoard(origin))
    moves.emplace_back(origin[X] + m_direction, origin[Y]);
    moves.emplace_back(origin[X] + (2 * m_direction), origin[Y]);
    return moves;
}