#ifndef MODEL_PIECE_MODEL_H_
#define MODEL_PIECE_MODEL_H_

#include "BoardModel.h"

/**
 * PieceModel interface
 */
class PieceModel {
    public:
        /**
         * @brief Pieces types
         * 
         * NONE value is used to keep the 0 value as default, separate from real
         * pieces.
         */
        enum Type { NONE = 0, KING, QUEEN, ROOK, PAWN, KNIGHT, BISHOP };

        enum Color { WHITE, BLACK };

        PieceModel(const enum Type t, const enum Color c);
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
        const enum Color color;
};

#endif // MODEL_PIECE_MODEL_H_
