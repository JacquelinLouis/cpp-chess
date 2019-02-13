#include "GameLoop.h"
#include <iostream>

GameLoop::GameLoop(BoardModel boardModel) :
    m_boardModel(boardModel),
    m_stop(true),
    m_loopNumber(0)
{}

void GameLoop::start() {
    m_stop = false;
    
    while(!m_stop && gameEnd() == ColorModel::NONE) {
        // Game loop
        std::cout << "Loop number[" << m_loopNumber << ']' << std::endl;
        // Test first display
        m_boardModel.initialize();
        
        m_loopNumber += 1;
        m_stop = true;
    }
}

void GameLoop::stop() {
    m_stop = true;
}

ColorModel GameLoop::gameEnd() {
    // Return the color that won
    return ColorModel::NONE;
}