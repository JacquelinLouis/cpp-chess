#include "BoardController.h"

PieceModel * BoardController::move(const Position & origin,
                                   const Position & destination) const {

    if (!m_boardModel.inBoard(origin) || !m_boardModel.inBoard(destination))
        return nullptr;
    PieceModel * lastDestinationPiece = m_boardModel.get(destination);
    m_boardModel.set(m_boardModel.get(origin), destination);
    m_boardModel.set(nullptr, origin);
    return lastDestinationPiece;
}
