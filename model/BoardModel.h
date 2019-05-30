#ifndef MODEL_BOARD_MODEL_H_
#define MODEL_BOARD_MODEL_H_

#include "PieceModel.h"
#include "../mvc/Notifier.h"

#define BOARD_SIZE 8

#define X 0
#define Y 1
typedef int Position[2];

class PieceModel;

class BoardModel : public Notifier {
    public:
        BoardModel();
        PieceModel * get(const Position & position) const;
        bool set(const PieceModel * piece, const Position & position);
        PieceModel * move(const Position & origin, const Position & destination);

        bool inBoard(const Position & position) const;

    private:
        PieceModel * m_board[BOARD_SIZE * BOARD_SIZE]{};

        void initialize();
        void initialize_white();
        void initialize_black();
};

#endif // MODEL_BOARDMODEL_H_
