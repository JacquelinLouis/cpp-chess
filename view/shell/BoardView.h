#ifndef VIEW_BOARD_VIEW_H_
#define VIEW_BOARD_VIEW_H_

#include "../../model/BoardModel.h"

#define PIECE ' '
#define KING 'K'
#define QUEEN 'Q'
#define ROOK 'R'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'

class BoardView {
    public:
        static Position getNextPosition(); 
        static int mapCharKeyToInt(char charKey);
        static char mapIntKeyToChar(int intKey);

        BoardView(BoardModel boardModel);
        void show();

    private:
        BoardModel m_boardModel;
};

#endif // VIEW_BOARD_VIEW_H_