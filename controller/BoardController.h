#ifndef CONTROLLER_BOARD_CONTROLLER_H_
#define CONTROLLER_BOARD_CONTROLLER_H_

#include "../model/BoardModel.h"
#include "PieceController.h"

class BoardController {
    public:
        BoardController(BoardController & boardController)
            : m_boardController(boardController)
        {}

        /**
         * @brief Move the piece at posOrigin to posDestination
         * 
         * @param board 
         * @param posOrigin 
         * @param posDestination 
         * @return PieceModel* the piece that as been moved.
         * nullptr if piece could not be moved.
         */
        PieceModel * move(BoardModel & board,
                          const Position & origin,
                          const Position & destination) const;

    private:
        BoardController & m_boardController;
};

#endif // CONTROLLER_BOARD_CONTROLLER_H_