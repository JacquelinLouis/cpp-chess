#include "TowerControllerTest.h"

#include "../../model/BoardModel.h"
#include "../../controller/pieces/TowerController.h"

void testPossibleMoves() {
    BoardModel boardModel;
    Position origin(5, 3);
    std::vector<Position> expectedMoves;
    Position expectedMove(0, origin[Y]);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (expectedMove != origin)
            expectedMoves.push_back(expectedMove);
        expectedMove.addX(1);
    }
    expectedMove = Position(origin[X], 0);
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (expectedMove != origin)
            expectedMoves.push_back(expectedMove);
        expectedMove.addY(1);
    }
    TowerController towerController;
    std::vector<Position> possibleMoves = towerController.possibleMoves(boardModel, origin);
    Test::expectEquals(possibleMoves, expectedMoves);
}

void TowerControllerTest::runAll() {
    testPossibleMoves();
}