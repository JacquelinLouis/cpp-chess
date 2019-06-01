#ifndef CONTROLLER_PIECE_CONTROLLER_H_
#define CONTROLLER_PIECE_CONTROLLER_H_

#include <vector>
#include "../model/PieceModel.h"
#include "../model/BoardModel.h"

/**
 * PieceController interface
 */
class PieceController {
    public:
        int colorToDirection(PieceModel::Color color);

        /**
         * @brief Take the piece at posDestination, by the piece at posOrigin.
         * 
         * @param board the game board to use.
         * @param posOrigin position of the piece which take the other.
         * @param posDestination position of the piece which be taken.
         * @return PieceModel* pointer to the piece taken, or nullptr if failed.
         */
        virtual PieceModel * take(BoardModel & board,
                                  const Position & origin,
                                  const Position & destination) = 0;
        /**
         * @brief Move the piece from posOrigin to posDestination.
         * Check if the piece at posOrigin is in board and if the destination is
         * too.
         * 
         * @param board the game board to use.
         * @param posOrigin position of the piece to move.
         * @param posDestination position where to move the piece.
         * @return true on success, false if something
         * (for instance : anoter piece or a move out of array bounds) happend
         */
        virtual bool move(BoardModel & board,
                          const Position & origin,
                          const Position & destination);

        virtual std::vector<Position> possibleMove(BoardModel & board, const Position origin) = 0;
};

#endif // CONTROLLER_PIECE_CONTROLLER_H_
