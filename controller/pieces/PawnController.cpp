#include "PawnController.h"

PieceModel * PawnController::take(BoardModel & board,
                  const int posOrigin[2],
                  const int posDestination[2]) {
    PieceModel * pieceOrigin = board.get(posOrigin[0], posOrigin[1]);
    PieceModel * pieceDestination = board.get(posDestination[0], posDestination[1]);
    if (!pieceOrigin || !posDestination) {
        return nullptr;
    }
    board.set(pieceOrigin, posDestination[0], posDestination[1]);
    board.set(nullptr, posOrigin[0], posOrigin[1]);
    return pieceDestination;
}

bool PawnController::move(BoardModel & board, 
                          const int posOrigin[2],
                          const int posDestination[2]) {
    PieceModel * pieceModel = board.get(posOrigin[0], posOrigin[1]);
    if (!pieceModel) {
        return false;
    }
    int direction = colorToDirection(pieceModel->color);
    if (posOrigin[0] == posDestination[0]
        || (posOrigin[1] != posDestination[1] + direction
            && posOrigin[1] != posDestination[1] + 2 * direction)) {
        return false;
    }
    return PieceController::move(board, posOrigin, posDestination);
}


std::vector<Position> PawnController::possibleMove(BoardModel & board, const Position origin) {
    std::vector<Position> moves;
    
    return moves
}