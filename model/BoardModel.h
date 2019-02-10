#ifndef MODEL_BOARD_MODEL_H_
#define MODEL_BOARD_MODEL_H_

#include "PieceModel.h"
#include "../mvc/Notifier.h"

#define BOARD_SIZE 8

class PieceModel;

class BoardModel : public Notifier<BoardModel> {
    public:
        BoardModel();
        PieceModel * get(const int & x, const int & y) const;
        bool set(PieceModel * piece, const int & x, const int & y);

    private:
        PieceModel * m_board[BOARD_SIZE * BOARD_SIZE] = { };

        void init_black();
        void init_white();
};

#endif // MODEL_BOARDMODEL_H_
