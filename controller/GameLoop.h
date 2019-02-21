#ifndef CONTROLLER_GAME_LOOPER_H_
#define CONTROLLER_GAME_LOOPER_H_

#include "../model/BoardModel.h"
#include "../model/ColorModel.h"

class GameLoop {
    public:
        GameLoop(BoardModel & boardModel);
        void start();
        void stop();

    private:
        BoardModel & m_boardModel;
        ColorModel m_playColor;
        bool m_stop;
        int m_loopNumber;

        void updatePlayerColor();
        ColorModel gameEnd();
};

#endif // CONTROLLER_GAME_LOOPER_H_