CC := g++
CFLAGS := -std=c++17 -I. -Wall -Wextra
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

.PHONY: all build debug test clean

all: build

build: jogo

jogo: main.cpp screens.cpp button.cpp
	$(CC) $(CFLAGS) main.cpp screens.cpp button.cpp -o jogo $(LDFLAGS)

# Debug build with compile-time DEBUG
debug: CFLAGS += -DDEBUG
debug: clean jogo

# Unit tests (no raylib)
test: CFLAGS += -DUNIT_TEST
test: clean_test test_runner
	./test_runner

test_runner: tests/test_screens.cpp screens.cpp
	$(CC) $(CFLAGS) tests/test_screens.cpp screens.cpp -o test_runner

clean:
	rm -f jogo

clean_test:
	rm -f test_runner
