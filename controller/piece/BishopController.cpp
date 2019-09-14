#include "BishopController.h"

std::vector<Position> BishopController::possibleMoves(BoardModel & board, const Position & origin) {
    std::vector<Position> moves;
    for (int j = 0; j < 4; ++j) {
        int deltaX = (-1 + 2 * (j % 2));
        int deltaY = (-1 + 2 * (j % 3));
        for (int i = 0; i < BOARD_SIZE; ++i) {
            Position move = Position(origin).addX(deltaX * i).addY(deltaY * i);
            if (board.inBoard(move))
                moves.push_back(move);
        }
    }
    return moves;
}