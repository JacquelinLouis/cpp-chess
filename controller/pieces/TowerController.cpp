#include "TowerController.h"

std::vector<Position> TowerController::possibleMoves(BoardModel & board, const Position & origin) {
    std::vector<Position> moves;
    Position move(origin);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        move[X] = i;
        if (board.inBoard(move) && move != origin)
            moves.emplace_back(move);
    }
    move[X] = origin[X];
    for (int j = 0; j < BOARD_SIZE; ++j) {
        move[Y] = j;
        if (board.inBoard(move)  && move != origin)
            moves.emplace_back(move);
    }
    return moves;
}
