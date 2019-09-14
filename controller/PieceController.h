#ifndef CONTROLLER_PIECE_CONTROLLER_H_
#define CONTROLLER_PIECE_CONTROLLER_H_

#include <vector>
#include "../model/PieceModel.h"
#include "../model/BoardModel.h"

/**
 * PieceController interface.
 * Basically, a piece can do two thing : move to an other {@link Position},
 * or take another piece.
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
        PieceModel * take(BoardModel & board,
                          const Position & origin,
                          const Position & destination);
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
        bool move(BoardModel & board,
                  const Position & origin,
                  const Position & destination);

        /**
         * @brief Return a vector of all accessible {@link Position} from the current one.
         *
         * @param board the game board to use.
         * @param the position of the piece to get possible position from.
         *
         * @return vector of {@link Position} typedef representing possible moves.
         */
        virtual std::vector<Position> possibleMoves(BoardModel & board, const Position & origin) = 0;

    protected:
        /**
         * @brief Check if a move is possible for this piece.
         * 
         * @param board the game board to use.
         * @param origin position to move the piece from.
         * @param destination position to move the piece to.
         * @return true if the piece can move from origin to destination
         *         (destination is in board, destination is in list of possible moves, ...).
         * @return false if the piece can't access to destination.
         */
        bool isPossibleMove(BoardModel & board, const Position & origin, const Position & destination);
};

#endif // CONTROLLER_PIECE_CONTROLLER_H_
