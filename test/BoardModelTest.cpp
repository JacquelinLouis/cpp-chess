#include "BoardModelTest.h"

#include "../model/BoardModel.h"
#include "../model/PieceModel.h"

void testPiece(Test * test, PieceModel::Type type, PieceModel::Color color, int x, int y) {
    BoardModel boardModel;
    PieceModel * pieceModel = boardModel.get(x, y);
    test->assertTrue(pieceModel);
    test->expectEquals(type, pieceModel->type);
    test->expectEquals(color, pieceModel->color);
}

TEST(testKingWhite,
    testPiece(this, PieceModel::Type::KING, PieceModel::Color::WHITE, BOARD_SIZE / 2, 0);
)

TEST(testKingBlack,
    testPiece(this, PieceModel::Type::KING, PieceModel::Color::BLACK, BOARD_SIZE / 2 - 1, BOARD_SIZE - 1);
)

TEST(testWhiteQueen,
    testPiece(this, PieceModel::Type::QUEEN, PieceModel::Color::WHITE, BOARD_SIZE / 2 - 1, 0);
)

TEST(testBlackQueen,
    testPiece(this, PieceModel::Type::QUEEN, PieceModel::Color::BLACK, BOARD_SIZE / 2, BOARD_SIZE - 1);
)

TEST(testLeftWhiteRook,
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::WHITE, 0, 0);
)

TEST(testRightWhiteRook,
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::WHITE, BOARD_SIZE - 1, 0);
)

TEST(testLeftBlackRook,
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::BLACK, 0, BOARD_SIZE - 1);
)

TEST(testRightBlackRook,
    testPiece(this, PieceModel::Type::ROOK, PieceModel::Color::BLACK, BOARD_SIZE - 1, BOARD_SIZE - 1);
)

TEST(testRightWhiteBishop,
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::WHITE, 2, 0);
)

TEST(testLeftWhiteBishop,
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::WHITE, BOARD_SIZE - 3, 0);
)

TEST(testRightBlackBishop,
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::BLACK,  2, BOARD_SIZE - 1);
)

TEST(testLeftBlackBishop,
    testPiece(this, PieceModel::Type::BISHOP, PieceModel::Color::BLACK, BOARD_SIZE - 3, BOARD_SIZE - 1);
)

TEST(testRightWhiteKnight,
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::WHITE, 1, 0);
)

TEST(testLeftWhiteKnight,
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::WHITE, BOARD_SIZE - 2, 0);
)

TEST(testRightBlackKnight,
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::BLACK, 1, BOARD_SIZE - 1);
)

TEST(testLeftBlackKnight,
    testPiece(this, PieceModel::Type::KNIGHT, PieceModel::Color::BLACK, BOARD_SIZE - 2, BOARD_SIZE - 1);
)

TEST(testWhitePawns,
    for (int i = 0; i < BOARD_SIZE; ++i) {
        testPiece(this, PieceModel::Type::PAWN, PieceModel::Color::WHITE, i, 1);
    }
)

TEST(testBlackPawns,
    for (int i = 0; i < BOARD_SIZE; ++i) {
        testPiece(this, PieceModel::Type::PAWN, PieceModel::Color::BLACK, i, BOARD_SIZE - 2);
    }
)

TEST(testSetRaiseNotification,
    Position position;
    position[X] = 0;
    position[Y] = 1;
    BoardModel boardModel;
    expectCall();
    Listener listener([&](){
        raiseCall();
    });
    boardModel.addListener(&listener);
    boardModel.set(nullptr, position);
    runExpectation();
)

void BoardModelTest::runAll() {
    testKingWhite();
    testKingBlack();
    testWhiteQueen();
    testBlackQueen();
    testLeftWhiteRook();
    testRightWhiteRook();
    testLeftBlackRook();
    testRightBlackRook();
    testRightWhiteBishop();
    testLeftWhiteBishop();
    testRightBlackBishop();
    testLeftBlackBishop();
    testRightWhiteKnight();
    testLeftWhiteKnight();
    testRightBlackKnight();
    testRightBlackKnight();
    testWhitePawns();
    testBlackPawns();
    testSetRaiseNotification();
}