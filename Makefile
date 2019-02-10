CC=gcc
CFLAGS=-std=c++11 -Wall -Werror
LDFLAGS=-lstdc++
GAME_EXEC=chess
TEST_EXEC=tests
SRC=*.cpp \
	model/*.cpp \
	controller/*.cpp \
	test/*.cpp

OBJ=$(SRC:.c=.o)
HDR=$(SRC:.c=.h)

all: game tests

game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

tests: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -DBUILD_TESTS=1

main.o: $(HDR)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f game tests *.o
