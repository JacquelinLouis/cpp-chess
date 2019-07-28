#include "TowerControllerTest.h"

#include "../../model/BoardModel.h"
#include "../../controller/pieces/TowerController.h"

TEST(testPossibleMoves,
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
    expectEquals(possibleMoves, expectedMoves);
)

TEST(testingTest,
    // Do nothing
    std::cout << "tested" << std::endl;
)

void TowerControllerTest::runAll() {
    testPossibleMoves();
    testingTest();
}