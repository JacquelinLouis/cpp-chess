#include "BoardController.h"

PieceModel * BoardController::move(BoardModel & board,
                                   const Position & origin,
                                   const Position & destination) const {

    if (!board.inBoard(origin) || !board.inBoard(destination))
        return nullptr;
    PieceModel * lastDestinationPiece = board.get(destination);
    board.set(board.get(origin), destination);
    board.set(nullptr, origin);
    return lastDestinationPiece;
}
