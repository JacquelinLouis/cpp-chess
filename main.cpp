#include <iostream>

#include "mvc/Notifier.h"
#include "model/BoardModel.h"
#include "controller/GameLoop.h"
#include "view/BoardView.h"

#include "test/MvcTests.h"
#include "test/BoardModelTest.h"
#include "test/controller/TowerControllerTest.h"

void runGame() {
    BoardModel boardModel;
    GameLoop gameLoop(boardModel);
    gameLoop.start();
}

void runTests() {
    MvcTests mvcTests;
    mvcTests.runAll();
    BoardModelTest boardModelTest;
    boardModelTest.runAll();
    TowerControllerTest towerControllerTest;
    towerControllerTest.runAll();
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
