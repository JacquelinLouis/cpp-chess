#ifndef KING_H_
#define KING_H_

#include "PieceModel.h"
#include "ColorModel.h"
#include "BoardModel.h"

class KingModel : public PieceModel {
    public:
        KingModel(const enum ColorModel color);
};

#endif // KING_H_
