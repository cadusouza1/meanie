CC=gcc
TEST_FILE=test.txt
BIN=bin/meanie

LIBS=-lm
CFLAGS=-ansi -pedantic

SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c, obj/%.o, $(SRCS))

build: $(BIN)

run: $(build)
	./$<

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

test: $(BIN)
	./$< < $(TEST_FILE)

obj/%.o: src/%.c
	$(CC) -c $^ $(CFLAGS) -o $@

e: $(OBJS)
	echo $^

clean:
	rm obj/* $(BIN)
