#ifndef MODEL_BOARD_MODEL_H_
#define MODEL_BOARD_MODEL_H_

#include "Position.h"
#include "PieceModel.h"
#include "../mvc/Notifier.h"

#define BOARD_SIZE 8

class PieceModel;

class BoardModel : public Notifier {
    public:
        BoardModel();
        PieceModel * get(int x, int y) const;
        PieceModel * get(const Position & position) const;
        void set(PieceModel * piece, const Position & position);

        /**
         * @brief Move the piece at origin to destination.
         *
         * @param origin piece's to move position.
         * @param destination position where to move the piece.
         * @return PieceModel * pointer to the position which was previously at
         * destination, or nullptr if there was none or if the move fail.
         */
        PieceModel * move(const Position & origin, const Position & destination);

        static bool inBoard(const Position & position);

    private:
        PieceModel * m_board[BOARD_SIZE * BOARD_SIZE]{};

        void initialize();
        void initialize_white();
        void initialize_black();
        /**
         * @brief Set the piece pointer at given position
         *
         * @param piece the PieceModel pointer to set at the position.
         * @param position the position to use to set the PieceModel pointer.
         * @return true if the piece has been set, false else.
         */
        bool internalSet(PieceModel * piece, const Position & position);
};

#endif // MODEL_BOARDMODEL_H_
