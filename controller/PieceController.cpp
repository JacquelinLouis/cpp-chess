#include "PieceController.h"

bool PieceController::move(BoardModel & board,
                           const int posOrigin[2],
                           const int posDestination[2]) {
    PieceModel * pieceOrigin = board.get(posOrigin[0], posOrigin[1]);
    if (!pieceOrigin || board.get(posDestination[0], posDestination[1])) {
        return false;
    }
    // TODO check for Pawn rights to move
    board.set(pieceOrigin, posDestination[0], posDestination[1]);
    board.set(nullptr, posOrigin[0], posOrigin[1]);
    return true;

}