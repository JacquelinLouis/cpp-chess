#include "BoardModel.h"

BoardModel::BoardModel() {
    initialize();
}

void BoardModel::initialize() {
    initialize_white();
    initialize_black();
    notify();
}

PieceModel * BoardModel::get(int x, int y) const {
    if (-1 < x && x < BOARD_SIZE && -1 < y && y < BOARD_SIZE)
        return m_board[x + y * BOARD_SIZE];
    return nullptr;
}

PieceModel * BoardModel::get(const Position & position) const {
    if (inBoard(position))
        return m_board[position[X] + position[Y] * BOARD_SIZE];
    return nullptr;
}

void BoardModel::set(PieceModel * pieceModel, const Position & position) {
    if (internalSet(pieceModel, position))
        notify();
}

bool BoardModel::internalSet(PieceModel * pieceModel, const Position & position) {
    if (!inBoard(position))
        return false;
    int newPosition = position[X] + position[Y] * BOARD_SIZE;
    m_board[newPosition] = pieceModel;
    return true;
}

PieceModel * BoardModel::move(const Position & origin,
                              const Position & destination) {
    if (!inBoard(origin) || !inBoard(destination))
        return nullptr;
    PieceModel * destPiece = get(destination);
    PieceModel * oriPiece = get(origin);
    set(oriPiece, destination);
    set(nullptr, origin);
    return destPiece;
}

bool BoardModel::inBoard(const Position & position) const {
    return -1 < position[X] && position[X] < BOARD_SIZE
        && -1 < position[Y] && position[Y] < BOARD_SIZE;
}

void BoardModel::initialize_white() {
    m_board[0] = new PieceModel(PieceModel::Type::ROOK, PieceModel::Color::WHITE);
    m_board[1] = new PieceModel(PieceModel::Type::KNIGHT, PieceModel::Color::WHITE);;
    m_board[2] = new PieceModel(PieceModel::Type::BISHOP, PieceModel::Color::WHITE);;
    m_board[3] = new PieceModel(PieceModel::Type::QUEEN, PieceModel::Color::WHITE);;
    m_board[4] = new PieceModel(PieceModel::Type::KING, PieceModel::Color::WHITE);;
    m_board[5] = new PieceModel(PieceModel::Type::BISHOP, PieceModel::Color::WHITE);;
    m_board[6] = new PieceModel(PieceModel::Type::KNIGHT, PieceModel::Color::WHITE);;
    m_board[7] = new PieceModel(PieceModel::Type::ROOK, PieceModel::Color::WHITE);;

    m_board[BOARD_SIZE] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 1] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 2] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 3] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 4] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 5] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 6] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
    m_board[BOARD_SIZE + 7] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::WHITE);
}

void BoardModel::initialize_black() {
    int lastPosition = BOARD_SIZE * (BOARD_SIZE - 2);
    m_board[lastPosition] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 1] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 2] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 3] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 4] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 5] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 6] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    m_board[lastPosition + 7] = new PieceModel(PieceModel::Type::PAWN, PieceModel::Color::BLACK);
    
    lastPosition = BOARD_SIZE * (BOARD_SIZE - 1);
    m_board[lastPosition] = new PieceModel(PieceModel::Type::ROOK, PieceModel::Color::BLACK);
    m_board[lastPosition + 1] = new PieceModel(PieceModel::Type::KNIGHT, PieceModel::Color::BLACK);
    m_board[lastPosition + 2] = new PieceModel(PieceModel::Type::BISHOP, PieceModel::Color::BLACK);
    m_board[lastPosition + 3] = new PieceModel(PieceModel::Type::KING, PieceModel::Color::BLACK);
    m_board[lastPosition + 4] = new PieceModel(PieceModel::Type::QUEEN, PieceModel::Color::BLACK);
    m_board[lastPosition + 5] = new PieceModel(PieceModel::Type::BISHOP, PieceModel::Color::BLACK);
    m_board[lastPosition + 6] = new PieceModel(PieceModel::Type::KNIGHT, PieceModel::Color::BLACK);
    m_board[lastPosition + 7] = new PieceModel(PieceModel::Type::ROOK, PieceModel::Color::BLACK);
}