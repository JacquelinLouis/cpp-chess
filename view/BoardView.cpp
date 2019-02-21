#include "BoardView.h"

#include <iostream>

int BoardView::mapCharKeyToInt(char charKey) {
    int intKey = -1;
    if ('A' <= charKey && charKey <= 'H')
        intKey = charKey - 'A';
    return intKey;
}

char BoardView::mapIntKeyToChar(int intKey) {
    char charKey = ' ';
    if (0 <= intKey && intKey <= 7) {
        charKey = 'A' + intKey;
    }
    return charKey;
}

BoardView::BoardView(BoardModel boardModel):
    m_boardModel(boardModel)
{}

void BoardView::show() {
    std::cout << "  ";
    for (int j = 0; j < BOARD_SIZE; ++j) {
        std::cout << j;
    }
    std::cout << std::endl << "  ";
    for (int j = 0; j < BOARD_SIZE; ++j) {
        std::cout << "-";
    }
    std::cout << "|X" << std::endl;
    for (int j = 0; j < BOARD_SIZE; ++j) {
        std::cout << mapIntKeyToChar(j) << '|';
        for (int i = 0; i < BOARD_SIZE; ++i) {
            PieceModel * piece = m_boardModel.get(i, j);
            if (piece)
                std::cout << piece->type;
            else
                std::cout << PieceModel::Type::NONE;
        }
        std::cout << std::endl;
    }
    std::cout << "--" << std::endl << 'Y' << std::endl;
}