#ifndef CONTROLLER_GAME_LOOPER_H_
#define CONTROLLER_GAME_LOOPER_H_

#include "../model/BoardModel.h"
#include "../model/ColorModel.h"

class GameLoop {
    public:
        GameLoop(BoardModel boardModel);
        void start();
        void stop();

    private:
        BoardModel & m_boardModel;
        bool m_stop;
        int m_loopNumber;

        ColorModel gameEnd();
};

#endif // CONTROLLER_GAME_LOOPER_H_