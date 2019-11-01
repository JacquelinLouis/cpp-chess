#include "PieceController.h"

#include <algorithm>

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


PieceModel * PieceController::take(BoardModel & board,
                                   const Position & origin,
                                   const Position & destination) {
    PieceModel * pieceOrigin = board.get(origin);
    PieceModel * pieceDestination = board.get(destination);
    if (!pieceOrigin || !pieceDestination) {
        return nullptr;
    }
    if (!isPossibleMove(origin, destination))
        return nullptr;
    board.set(pieceOrigin, destination);
    board.set(nullptr, destination);
    return pieceDestination;
}

bool PieceController::move(BoardModel & board,
                           const Position & origin,
                           const Position & destination) {
    PieceModel * pieceOrigin = board.get(origin);
    if (!pieceOrigin || board.get(destination)) {
        return false;
    }
    if (!isPossibleMove(origin, destination))
        return false;
    // TODO check for Pawn rights to move
    board.set(pieceOrigin, destination);
    board.set(nullptr, origin);
    return true;
}

bool PieceController::isPossibleMove(const Position & origin, const Position & destination) {
    std::vector<Position> pMoves = possibleMoves(origin);
    auto itMove = std::find_if(pMoves.begin(), pMoves.end(), [&](const Position & position) {
        return position == destination;
    });
    return itMove != pMoves.end();
}