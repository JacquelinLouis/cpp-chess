#include "BishopControllerTest.h"

#include "../../model/BoardModel.h"
#include "../../controller/piece/BishopController.h"

std::vector<Position> getPossibleMoves(const Position & position, int xDirection, int yDirection) {
    std::vector<Position> possiblePositions;
    int i = 1;
    Position expectedMove(position[X] + (i * xDirection), position[Y] + (i * yDirection));
    while (BoardModel::inBoard(expectedMove)) {
        possiblePositions.push_back(expectedMove);
        i += 1;
        expectedMove = Position(position[X] + (i * xDirection), position[Y] + (i * yDirection));
    }
    return possiblePositions;
}

TEST(testPossibleMoves,
    Position origin(5, 3);
    std::vector<Position> expectedMoves = getPossibleMoves(origin, 1, 1);
    std::vector<Position> expectedPossibleMoves = getPossibleMoves(origin, -1, 1);
    expectedMoves.insert(expectedMoves.end(), expectedPossibleMoves.begin(), expectedPossibleMoves.end());
    expectedPossibleMoves = getPossibleMoves(origin, 1, -1);
    expectedMoves.insert(expectedMoves.end(), expectedPossibleMoves.begin(), expectedPossibleMoves.end());
    expectedPossibleMoves = getPossibleMoves(origin, -1, -1);
    expectedMoves.insert(expectedMoves.end(), expectedPossibleMoves.begin(), expectedPossibleMoves.end());
    BishopController bishopController;
    std::vector<Position> possibleMoves = bishopController.possibleMoves(origin);
    expectUnorderedEquals(expectedMoves, possibleMoves);
)

void BishopControllerTest::runAll() {
    testPossibleMoves();
}