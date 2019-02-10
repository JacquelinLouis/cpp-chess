#ifndef CONTROLLER_GAME_LOOPER_H_
#define CONTROLLER_GAME_LOOPER_H_

#include "../model/BoardModel.h"

class GameLooper {
    public:
        GameLooper(BoardModel boardModel);
        void initialize();
        void start();
        void stop();

    private:
        BoardModel & m_boardModel;
        bool m_stop;
};

#endif // CONTROLLER_GAME_LOOPER_H_