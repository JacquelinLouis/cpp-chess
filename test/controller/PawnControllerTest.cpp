#include "PawnControllerTest.h"

#include "../../model/BoardModel.h"
#include "../../controller/piece/PawnController.h"

TEST(testPossibleMoves,
    Position origin(5, 3);
    std::vector<Position> expectedMoves;
    expectedMoves.push_back(Position(origin[X] + 1, origin[Y]));
    expectedMoves.push_back(Position(origin[X] + 2, origin[Y]));
    PawnController pawnController(PawnController::Direction::Positive);
    std::vector<Position> possibleMoves = pawnController.possibleMoves(origin);
    expectEquals(expectedMoves, possibleMoves);
)

void PawnControllerTest::runAll() {
    testPossibleMoves();
}