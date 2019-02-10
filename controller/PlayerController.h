#ifndef CONTROLLER_PLAYER_CONTROLLER_H_
#define CONTROLLER_PLAYER_CONTROLLER_H_

#include "../model/BoardModel.h"
#include "../model/ColorModel.h"

/**
 * PlayerController interface
 */
class PlayerController {
    public:
        virtual void move(const BoardModel & board,
          const int posOrigin[2],
          const int posDestination[2]);

    private:
        ColorModel m_color;
};

#endif // CONTROLLER_PLAYER_CONTROLLER_H_