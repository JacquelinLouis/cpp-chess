#include "GameLoop.h"
#include <iostream>
#include "../view/BoardView.h"

GameLoop::GameLoop(BoardModel & boardModel) :
    m_boardModel(boardModel),
    m_stop(true),
    m_loopNumber(0)
{}

void GameLoop::start() {
    Position posOrigin;
    char posOriginY = ' ';
    Position posDestination;
    char posDestinationY = ' ';

    m_stop = false;

    // Test first display
    m_boardModel.notify();
    
    while(!m_stop) {
        std::cout << "Loop number[" << m_loopNumber << ']' << std::endl;
        std::cout << "Player " << static_cast<int>(m_playingColor) << " turn" << std::endl;

        std::cout << "Enter the piece to move coordinates : ";
        std::cin >> posOrigin[0] >> posOriginY;
        posOrigin[1] = BoardView::mapCharKeyToInt(posOriginY);
        std::cout << "Enter the destination coordinates : ";
        std::cin >> posDestination[0] >> posDestinationY;
        posDestination[1] = BoardView::mapCharKeyToInt(posDestinationY);

        std::cout << "Move piece at[" << posOrigin[0] << ',' << posOrigin[1]
                  <<  "] to [" << posDestination[0] << ',' << posDestination[1]
                  << ']' << std::endl;

        // m_boardModel.move(posOrigin, posDestination);

        m_loopNumber += 1;
    }
}

void GameLoop::stop() {
    m_stop = true;
}