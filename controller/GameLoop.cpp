#include "GameLoop.h"
#include <iostream>
#include "../view/BoardView.h"

GameLoop::GameLoop(BoardModel & boardModel) :
    m_boardModel(boardModel),
    m_playColor(ColorModel::WHITE),
    m_stop(true),
    m_loopNumber(0)
{}

void GameLoop::start() {
    int posOrigin[2];
    char posOriginY = ' ';
    int posDestination[2];
    char posDestinationY = ' ';

    m_stop = false;

    // Test first display
    m_boardModel.initialize();
    
    while(!m_stop && gameEnd() == ColorModel::NONE) {
        std::cout << "Loop number[" << m_loopNumber << ']' << std::endl;
        std::cout << "Player " << static_cast<int>(m_playColor) << " turn" << std::endl;

        std::cout << "Enter the piece to move coordinates : ";
        std::cin >> posOrigin[0] >> posOriginY;
        posOrigin[1] = BoardView::mapCharKeyToInt(posOriginY);
        std::cout << "Enter the destination coordinates : ";
        std::cin >> posDestination[0] >> posDestinationY;
        posDestination[1] = BoardView::mapCharKeyToInt(posDestinationY);

        std::cout << "Move piece at[" << posOrigin[0] << ',' << posOrigin[1]
                  <<  "] to [" << posDestination[0] << ',' << posDestination[1]
                  << ']' << std::endl;

        m_boardModel.move(posOrigin[0], posOrigin[1],
                          posDestination[0], posDestination[1]);

        m_loopNumber += 1;
        updatePlayerColor();
        m_stop = true;
    }
}

void GameLoop::stop() {
    m_stop = true;
}

void GameLoop::updatePlayerColor() {
    if (m_playColor == ColorModel::NONE || m_playColor == ColorModel::BLACK) {
        m_playColor = ColorModel::WHITE;
    } else {
        m_playColor = ColorModel::BLACK;
    }
}

ColorModel GameLoop::gameEnd() {
    // Return the color that won
    return ColorModel::NONE;
}