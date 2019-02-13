#ifndef MODEL_PIECE_MODEL_H_
#define MODEL_PIECE_MODEL_H_

#include "ColorModel.h"
#include "BoardModel.h"

/**
 * PieceModel interface
 */
class PieceModel {
    public:
        enum Type { KING, QUEEN, ROOK, PAWN, KNIGHT, BISHOP };

        PieceModel(const enum Type t, const enum ColorModel c);
        /**
         *@brief Test if the piece is equal to an other
            *@return true if piece type and color are equals, false else
            */
        bool operator==(PieceModel & other) const {
            return other.type == type && other.color == color;
        }
        /**
         *@brief Test if the piece is equal to an other
         *@return true if the piece type and color are equals, false else
         */
        bool equals(const PieceModel * piece) const {
            return piece != nullptr && type == piece->type && color == piece->color;
        }

        const enum Type type;
        const ColorModel color;
};

#endif // MODEL_PIECE_MODEL_H_
