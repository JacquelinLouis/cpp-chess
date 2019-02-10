#ifndef CONTROLLER_PIECE_CONTROLLER_H_
#define CONTROLLER_PIECE_CONTROLLER_H_

#define X 0
#define Y 1

#include "../model/ColorModel.h"
#include "../model/BoardModel.h"

/**
 * PieceController interface
 */
class PieceController {
    public:
        virtual PieceModel * move(BoardModel & board,
                                  const int posOrigin[2],
                                  const int posDestination[2]);
};

#endif // CONTROLLER_PIECE_CONTROLLER_H_
