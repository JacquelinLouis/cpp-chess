#include "PieceController.h"

int PieceController::colorToDirection(PieceModel::Color color) {
    switch (color)
    {
        case PieceModel::Color::BLACK:
            return -1;
        case PieceModel::Color::WHITE:
            return 1;
        default:
            return 0;
    }
}

PieceModel * take(BoardModel & board,
                  const Position origin,
                  const Position destination) {
    return nullptr;
}

bool PieceController::move(BoardModel & board,
                           const Position & origin,
                           const Position & destination) {
    PieceModel * pieceOrigin = board.get(origin);
    if (!pieceOrigin || board.get(destination)) {
        return false;
    }
    // TODO check for Pawn rights to move
    board.set(pieceOrigin, destination);
    board.set(nullptr, origin);
    return true;
}