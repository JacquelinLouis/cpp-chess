CC=gcc
CFLAGS=-std=c++11 -Wall -Werror -g
LDFLAGS=-lstdc++
GAME_EXEC=chess.out
TEST_EXEC=test.out
SRC=*.cpp \
	model/*.cpp \
	view/*.cpp \
	controller/*.cpp \
	controller/piece/*.cpp \
	test/*.cpp \
	test/controller/*.cpp \
	stateMachine/*.cpp \
	stateMachine/states/*.cpp

OBJ=$(SRC:.c=.o)
HDR=$(SRC:.c=.h)

all: game.out test.out

game.out: $(OBJ)
	$(CC) -o ${GAME_EXEC} $^ $(CFLAGS) $(LDFLAGS)

test.out: $(OBJ)
	$(CC) -o ${TEST_EXEC} $^ $(CFLAGS) $(LDFLAGS) -DBUILD_TESTS=1

main.o: $(HDR)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f ${GAME_EXEC} ${TEST_EXEC} *.o
