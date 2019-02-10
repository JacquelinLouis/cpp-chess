#include "BoardModel.h"
#include "PawnModel.h"

BoardModel::BoardModel() {
    init_black();
    init_white();
}

PieceModel * BoardModel::get(const int & x, const int & y) const{
    return m_board[x + y * BOARD_SIZE];
}

bool BoardModel::set(PieceModel * pieceModel, const int & x, const int & y) {
    if (m_board[x + y * BOARD_SIZE] != nullptr)
        return false;
    m_board[x + y * BOARD_SIZE] = pieceModel;
    // notify(*this);
    return true;
}

void BoardModel::init_black() {
    int lastPosition = (BOARD_SIZE -1) * (BOARD_SIZE -1);
    m_board[lastPosition - 2 * BOARD_SIZE] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 1] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 2] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 3] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 4] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 5] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 6] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - 2 * BOARD_SIZE + 7] = new PawnModel(ColorModel::BLACK);
    m_board[lastPosition - BOARD_SIZE] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 1] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 2] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 3] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 4] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 5] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 6] = nullptr;
    m_board[lastPosition - BOARD_SIZE + 7] = nullptr;
}

void BoardModel::init_white() {
    m_board[0] = new PawnModel(ColorModel::WHITE);
    m_board[1] = new PawnModel(ColorModel::WHITE);
    m_board[2] = new PawnModel(ColorModel::WHITE);
    m_board[3] = new PawnModel(ColorModel::WHITE);
    m_board[4] = new PawnModel(ColorModel::WHITE);
    m_board[5] = new PawnModel(ColorModel::WHITE);
    m_board[6] = new PawnModel(ColorModel::WHITE);
    m_board[7] = new PawnModel(ColorModel::WHITE);
    m_board[BOARD_SIZE] = nullptr;
    m_board[BOARD_SIZE + 1] = nullptr;
    m_board[BOARD_SIZE + 2] = nullptr;
    m_board[BOARD_SIZE + 3] = nullptr;
    m_board[BOARD_SIZE + 4] = nullptr;
    m_board[BOARD_SIZE + 5] = nullptr;
    m_board[BOARD_SIZE + 6] = nullptr;
    m_board[BOARD_SIZE + 7] = nullptr;
}
