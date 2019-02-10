#include <iostream>

#include "mvc/Listener.h"
#include "mvc/Notifier.h"
#include "model/BoardModel.h"
// #include "controller/GameLooper.h"

#include "test/MvcTests.h"

void runGame() {
    BoardModel boardModel;
    Listener<BoardModel> boardListener([&](const BoardModel boardModel) {
        // Update UI
    });
    boardModel.addListener(boardListener);
    
    /*
    GameLooper gameLooper(boardModel);
    gameLooper.start();
    // Wait for end of game or quit key press
    if (false) { // Quit key press
        gameLooper.end();
    }
    */
}

void runTests() {
    MvcTests mvcTests;
    mvcTests.runAll();
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
