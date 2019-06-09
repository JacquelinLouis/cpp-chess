#include "GameLoop.h"
#include <iostream>
#include "BoardController.h"
#include "../view/BoardView.h"

GameLoop::GameLoop(BoardModel & boardModel) :
    m_boardModel(boardModel),
    m_stop(true),
    m_loopNumber(0)
{}

void GameLoop::start() {
    Position origin;
    char originY = ' ';
    Position destination;
    char destinationY = ' ';
    m_stop = false;

    Listener boardModelListener(
        [&]() {
            // Update UI
            std::cout << "Board model updated" << std::endl;
            BoardView(m_boardModel).show();
        });

    m_boardModel.addListener(&boardModelListener);

    BoardController boardController(m_boardModel);

    // Test first display
    m_boardModel.notify();
    
    while(!m_stop) {
        std::cout << "Loop number[" << m_loopNumber << ']' << std::endl;
        std::cout << "Player " << static_cast<int>(m_playingColor) << " turn" << std::endl;

        std::cout << "Enter the piece's coordinates to move it : ";
        std::cin >> origin[X] >> originY;
        origin[Y] = BoardView::mapCharKeyToInt(origin[Y]);
        std::cout << "Enter the destination : ";
        std::cin >> destination[X] >> destinationY;
        destination[Y] = BoardView::mapCharKeyToInt(destinationY);

        std::cout << "Move piece at[" << origin[X] << ',' << origin[Y]
                  <<  "] to [" << destination[X] << ',' << destination[Y]
                  << ']' << std::endl;

        boardController.move(origin, destination);

        m_loopNumber += 1;

        // TODO: remove after debug
        m_stop = true;
    }
    m_boardModel.removeListener(&boardModelListener);
}

void GameLoop::stop() {
    m_stop = true;
}