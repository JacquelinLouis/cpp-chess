#include "BoardModelTest.h"

#include "../model/BoardModel.h"
#include "../model/PieceModel.h"

void BoardModelTest::testInitialize() {
    BoardModel boardModel;
    PieceModel * pieceModel = nullptr;
    for (int i; i < BOARD_SIZE && !pieceModel; ++i) {
        for (int j = 0; j < BOARD_SIZE && !pieceModel; ++j) {
            pieceModel = boardModel.get(i, j);
        }
    }
    Test::expectTrue(pieceModel);
}

void testPiece(PieceModel::Type type, PieceModel::Color color, int x, int y) {
    BoardModel boardModel;
    PieceModel * pieceModel = boardModel.get(x, y);
    Test::expectTrue(pieceModel);
    Test::expectEquals(static_cast<int>(pieceModel->type), static_cast<int>(type));
    Test::expectEquals(static_cast<int>(pieceModel->color), static_cast<int>(color));
}

void BoardModelTest::testKings() {
    testPiece(PieceModel::Type::KING, PieceModel::Color::WHITE, 0, BOARD_SIZE / 2);
    testPiece(PieceModel::Type::KING, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE / 2 + 1);
}

void BoardModelTest::testQueens() {
    testPiece(PieceModel::Type::QUEEN, PieceModel::Color::WHITE, 0, BOARD_SIZE / 2 + 1);
    testPiece(PieceModel::Type::QUEEN, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE / 2);
}

void BoardModelTest::testRooks() {
    testPiece(PieceModel::Type::ROOK, PieceModel::Color::WHITE, 0, 0);
    testPiece(PieceModel::Type::ROOK, PieceModel::Color::WHITE, 0, BOARD_SIZE - 1);
    testPiece(PieceModel::Type::ROOK, PieceModel::Color::BLACK, BOARD_SIZE - 1, 0);
    testPiece(PieceModel::Type::ROOK, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 1);
}

void BoardModelTest::testBishops() {
    testPiece(PieceModel::Type::BISHOP, PieceModel::Color::WHITE, 0, 1);
    testPiece(PieceModel::Type::BISHOP, PieceModel::Color::WHITE, 0, BOARD_SIZE - 2);
    testPiece(PieceModel::Type::BISHOP, PieceModel::Color::BLACK, BOARD_SIZE - 1, 1);
    testPiece(PieceModel::Type::BISHOP, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 2);
}

void BoardModelTest::testKnights() {
    testPiece(PieceModel::Type::KNIGHT, PieceModel::Color::WHITE, 0, 2);
    testPiece(PieceModel::Type::KNIGHT, PieceModel::Color::WHITE, 0, BOARD_SIZE - 3);
    testPiece(PieceModel::Type::KNIGHT, PieceModel::Color::BLACK, BOARD_SIZE - 1, 2);
    testPiece(PieceModel::Type::KNIGHT, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 3);
}

void BoardModelTest::testPawns() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        testPiece(PieceModel::Type::PAWN, PieceModel::Color::WHITE, 1, i);
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        testPiece(PieceModel::Type::PAWN, PieceModel::Color::BLACK, BOARD_SIZE - 2, i);
    }
}

void BoardModelTest::runAll() {
    testInitialize();
    testKings();
    testQueens();
    testRooks();
    testBishops();
    testKnights();
    testPawns();
}