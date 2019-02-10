#include "PieceController.h"

PieceModel * PieceController::move(BoardModel & boardModel,
                                   const int posOrigin[2],
                                   const int posDestination[2]) {
    PieceModel * piece = nullptr;
    if (posOrigin[X] < BOARD_SIZE && posOrigin[Y] < BOARD_SIZE
        && posDestination[X] < BOARD_SIZE && posDestination[Y] < BOARD_SIZE)
        piece = boardModel.get(posDestination[X], posDestination[Y]);
    return piece;
}