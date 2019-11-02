#include "BishopController.h"

int pow(int a, int b) {
    if (b < 1) {
        return 1;
    }
    return a * pow(a, b - 1);
}

std::vector<Position> BishopController::possibleMoves(const Position & origin) {
    std::vector<Position> moves;
    for (int i = 1; i < BOARD_SIZE; ++i) {
        for (int j = 1; j < 5; ++j) {
            int x = origin[X] + (i * pow(-1, j % 2));
            int y = origin[Y] + (i * pow(-1, j % 3));
            Position move(x, y);
            if (BoardModel::inBoard(move))
                    moves.push_back(move);
        }
    }
    return moves;
}