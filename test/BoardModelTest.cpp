#include "BoardModelTest.h"

#include "../model/BoardModel.h"
#include "../model/PieceModel.h"

TEST(testInitialize,
    BoardModel boardModel;
    PieceModel * pieceModel = nullptr;
    for (int i; i < BOARD_SIZE && !pieceModel; ++i) {
        for (int j = 0; j < BOARD_SIZE && !pieceModel; ++j) {
            pieceModel = boardModel.get(i, j);
        }
    }
    expectTrue(pieceModel);
)

void testPiece(Test * test, PieceModel::Type type, PieceModel::Color color, int x, int y) {
    BoardModel boardModel;
    PieceModel * pieceModel = boardModel.get(x, y);
    test->assertTrue(pieceModel);
    test->expectEquals(pieceModel->type, type);
    test->expectEquals(pieceModel->color, color);
}

TEST(testKings,
    testPiece(this, PieceModel::Type::KING, PieceModel::Color::WHITE, 0, BOARD_SIZE / 2);
    testPiece(this, PieceModel::Type::KING, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE / 2 + 1);
)

TEST(testQueens,
    testPiece(this, PieceModel::Type::QUEEN, PieceModel::Color::WHITE, 0, BOARD_SIZE / 2 + 1);
    testPiece(this, PieceModel::Type::QUEEN, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE / 2);
)

TEST(testRooks,
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::WHITE, 0, 0);
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::WHITE, 0, BOARD_SIZE - 1);
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::BLACK, BOARD_SIZE - 1, 0);
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 1);
)

TEST(testBishops,
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::WHITE, 0, 1);
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::WHITE, 0, BOARD_SIZE - 2);
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::BLACK, BOARD_SIZE - 1, 1);
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 2);
)

TEST(testKnights,
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::WHITE, 0, 2);
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::WHITE, 0, BOARD_SIZE - 3);
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::BLACK, BOARD_SIZE - 1, 2);
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 3);
)

TEST(testPawns,
    for (int i = 0; i < BOARD_SIZE; ++i) {
        testPiece(this, PieceModel::Type::PAWN, PieceModel::Color::WHITE, 1, i);
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        testPiece(this, PieceModel::Type::PAWN, PieceModel::Color::BLACK, BOARD_SIZE - 2, i);
    }
)

TEST(testSetRaiseNotification,
    expectCall();
    Position position;
    position[X] = 0;
    position[Y] = 1;
    BoardModel boardModel;
    Listener listener([&](){
        raiseCall();
    });
    boardModel.addListener(&listener);
    boardModel.set(nullptr, position);
    runExpectation();
)

void BoardModelTest::runAll() {
    testInitialize();
    testKings();
    testQueens();
    testRooks();
    testBishops();
    testKnights();
    testPawns();
    testSetRaiseNotification();
}