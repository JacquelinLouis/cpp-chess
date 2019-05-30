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
                           const Position posOrigin,
                           const Position posDestination) {
    PieceModel * pieceOrigin = board.get(posOrigin[X], posOrigin[Y]);
    if (!pieceOrigin || board.get(posDestination[X], posDestination[Y])) {
        return false;
    }
    // TODO check for Pawn rights to move
    board.set(pieceOrigin, posDestination[0], posDestination[1]);
    board.set(nullptr, posOrigin[0], posOrigin[1]);
    return true;
}