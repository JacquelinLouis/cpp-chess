#ifndef MODEL_BOARD_MODEL_H_
#define MODEL_BOARD_MODEL_H_

#include "PieceModel.h"
#include "../mvc/Notifier.h"

#define BOARD_SIZE 8

class PieceModel;

class BoardModel : public Notifier {
    public:
        BoardModel();
        PieceModel * get(const int & x, const int & y) const;
        bool set(PieceModel * piece, const int & x, const int & y);
        PieceModel * move(const int & xOrigin, const int & yOrigin,
                  const int & xDestination, const int & yDestination);

    private:
        PieceModel * m_board[BOARD_SIZE * BOARD_SIZE] = { };

        void initialize();
        void initialize_white();
        void initialize_black();
};

#endif // MODEL_BOARDMODEL_H_
