#include <iostream>

#include "mvc/Notifier.h"
#include "model/BoardModel.h"
#include "controller/GameLoop.h"
#include "view/BoardView.h"

#include "test/MvcTests.h"
#include "test/BoardModelTest.h"

void runGame() {
    BoardModel boardModel;
    Listener boardModelListener(
        [&]() {
            // Update UI
            std::cout << "Board model updated" << std::endl;
            BoardView(boardModel).show();
        });
    boardModel.addListener(&boardModelListener);

    GameLoop gameLoop(boardModel);
    gameLoop.start();
    // Wait for end of game or quit key press
    if (false) { // Quit key press
        gameLoop.stop();
        boardModel.removeListener(&boardModelListener);
    }
}

void runTests() {
    MvcTests mvcTests;
    mvcTests.runAll();
    BoardModelTest boardModelTest;
    boardModelTest.runAll();
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
