#include "BoardView.h"

#include <iostream>

BoardView::BoardView(BoardModel boardModel):
    m_boardModel(boardModel)
{}

void BoardView::show() {
    for (int j = 0; j < BOARD_SIZE; ++j) {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            std::cout << m_boardModel.get(i, j)->type;
        }
        std::cout << std::endl;
    }
}
