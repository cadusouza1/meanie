CC=gcc

BIN_DIR=bin
BIN=$(BIN_DIR)/meanie

LIBS=-lm
CFLAGS=-ansi -pedantic

SRC_DIR=src
SRCS=$(wildcard $(SRC_DIR)/*.c)

OBJ_DIR=obj
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

build: $(BIN)

run: $(build)
	./$<

$(BIN): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

test: $(BIN)
	./$< < $(TEST_FILE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $^ $(CFLAGS) -o $@

e: $(OBJS)
	echo $^

clean:
	rm obj/* $(BIN)

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@
