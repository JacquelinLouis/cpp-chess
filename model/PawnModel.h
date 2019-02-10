#ifndef MODEL_PAWN_MODEL_H_
#define MODEL_PAWN_MODEL_H_

#include "PieceModel.h"
#include "ColorModel.h"
#include "BoardModel.h"

class PawnModel : public PieceModel {
    public:
        PawnModel(const enum ColorModel color);
};

#endif // MODEL_PAWN_MODEL_H_
