#include "BoardModel.h"

BoardModel::BoardModel() {
    initialize();
}

void BoardModel::initialize() {
    initialize_white();
    initialize_black();
    notify();
}

PieceModel * BoardModel::get(const int & x, const int & y) const{
    if (-1 < x && x < BOARD_SIZE && -1 < y && y < BOARD_SIZE)
        return m_board[x + y * BOARD_SIZE];
    return nullptr;
}

bool BoardModel::set(PieceModel * pieceModel, const int & x, const int & y) {
    if (BOARD_SIZE -1 < x || x < 0 || BOARD_SIZE - 1 < y || y < 0) {
        return false;
    }
    m_board[x + y * BOARD_SIZE] = pieceModel;
    notify();
    return true;
}

PieceModel * BoardModel::move(const int & xOrigin, const int & yOrigin,
                      const int & xDestination, const int & yDestination) {
    if (BOARD_SIZE - 1 < xOrigin || xOrigin < 0
        || BOARD_SIZE - 1 < yOrigin || yOrigin < 0
        || BOARD_SIZE - 1 < xDestination || xDestination < 0
        || BOARD_SIZE - 1 < yDestination || yDestination < 0) {
        return nullptr;
    }
    PieceModel * lastDestinationPiece = m_board[xDestination + yDestination * BOARD_SIZE];
    m_board[xDestination + yDestination * BOARD_SIZE] = m_board[xOrigin + yOrigin * BOARD_SIZE];
    m_board[xOrigin + yOrigin * BOARD_SIZE] = nullptr;
    notify();
    return lastDestinationPiece;
}

void BoardModel::initialize_white() {
    m_board[0] = nullptr;
    m_board[1] = nullptr;
    m_board[2] = nullptr;
    m_board[3] = nullptr;
    m_board[4] = nullptr;
    m_board[5] = nullptr;
    m_board[6] = nullptr;
    m_board[7] = nullptr;

    m_board[BOARD_SIZE] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 1] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 2] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 3] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 4] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 5] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 6] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
    m_board[BOARD_SIZE + 7] = new PieceModel(PieceModel::Type::PAWN, ColorModel::WHITE);
}

void BoardModel::initialize_black() {
    int lastPosition = BOARD_SIZE * BOARD_SIZE;
    m_board[lastPosition - 2 * BOARD_SIZE] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 1] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 2] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 3] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 4] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 5] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 6] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 7] = new PieceModel(PieceModel::Type::PAWN, ColorModel::BLACK);
    m_board[lastPosition - BOARD_SIZE] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 1] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 2] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 3] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 4] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 5] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 6] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 7] = nullptr;
}