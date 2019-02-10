#include "GameLooper.h"

GameLooper::GameLooper(BoardModel boardModel) :
    m_boardModel(boardModel),
    m_stop(true)
{}

void GameLooper::initialize() {

}

void GameLooper::start() {
    m_stop = false;
    
    while(!m_stop) {
        // Game loop

    }
}

void GameLooper::stop() {
    m_stop = true;
}