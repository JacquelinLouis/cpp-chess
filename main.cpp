#include <iostream>

#include "mvc/Notifier.h"
#include "model/BoardModel.h"
#include "controller/GameLoop.h"
#include "view/BoardView.h"

#include "test/MvcTests.h"
#include "test/BoardModelTest.h"
#include "test/controller/TowerControllerTest.h"
#include "test/controller/PawnControllerTest.h"
#include "test/controller/BishopControllerTest.h"

void runGame() {
    BoardModel boardModel;
    GameLoop gameLoop(boardModel);
    gameLoop.start();
}

void runTests() {
    MvcTests().runAll();
    BoardModelTest().runAll();
    TowerControllerTest().runAll();
    PawnControllerTest().runAll();
    BishopControllerTest().runAll();
}

int main(int argc, char **argv) {
    std::cout << "start" << std::endl;
    #if BUILD_TESTS
        runTests();
    #else
        runGame();
    #endif
    std::cout << "end" << std::endl;
    return 0;
}
