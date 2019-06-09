#include "BoardController.h"

PieceModel * BoardController::move(const Position & origin,
                                   const Position & destination) const {
    return m_boardModel.move(origin, destination);
}
