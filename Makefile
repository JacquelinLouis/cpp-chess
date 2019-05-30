CC=gcc
CFLAGS=-std=c++11 -Wall -Werror -g
LDFLAGS=-lstdc++
GAME_EXEC=chess
TEST_EXEC=tests
SRC=*.cpp \
	model/*.cpp \
	view/*.cpp \
	controller/*.cpp \
	controller/pieces/*.cpp \
	test/*.cpp \
	stateMachine/*.cpp \
	stateMachine/states/*.cpp

OBJ=$(SRC:.c=.o)
HDR=$(SRC:.c=.h)

all: game tests

game: $(OBJ)
	$(CC) $^ $(CFLAGS) $(LDFLAGS)

tests: $(OBJ)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -DBUILD_TESTS=1

main.o: $(HDR)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f a.out *.o
