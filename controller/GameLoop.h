#ifndef CONTROLLER_GAME_LOOPER_H_
#define CONTROLLER_GAME_LOOPER_H_

#include "../model/BoardModel.h"
#include "../model/PieceModel.h"

class GameLoop {
    public:
        GameLoop(BoardModel & boardModel);
        void start();
        void stop();

    private:
        BoardModel & m_boardModel;
        PieceModel::Color m_playingColor;
        bool m_stop;
        int m_loopNumber;

        void updatePlayerColor();
};

#endif // CONTROLLER_GAME_LOOPER_H_