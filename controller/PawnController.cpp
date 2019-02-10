#include "PawnController.h"

PieceModel * PawnController::move(BoardModel & board, 
                                       const int posOrigin[2],
                                       const int posDestination[2]) {
    PieceModel * pieceOrigin = PieceController::move(board, posOrigin, posDestination);
    PieceModel * pieceDestination = nullptr;
    if (!pieceOrigin) {
        return pieceOrigin;
    }
    pieceDestination = board.get(posOrigin[X] - 1, posOrigin[Y]);
    if (pieceOrigin && pieceOrigin->equals(pieceDestination)) {
        board.set(pieceOrigin, posDestination[X], posDestination[Y]);
        board.set(nullptr, posOrigin[X] - 1, posOrigin[Y]);
        return pieceOrigin;
    }
    pieceDestination = board.get(posOrigin[X] - 2, posOrigin[Y]);
    if (pieceOrigin && pieceOrigin->equals(pieceDestination)) {
        board.set(pieceOrigin, posDestination[X], posDestination[Y]);
        board.set(nullptr, posOrigin[X] - 2, posOrigin[Y]);
        return pieceOrigin;    
    }
    return nullptr;
}