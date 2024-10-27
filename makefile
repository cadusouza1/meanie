CC=gcc

BIN_DIR=bin
BIN=$(BIN_DIR)/meanie

LIBS=-lm

CFLAGS=-std=c99 -pedantic

SRC_DIR=src
SRCS=$(wildcard $(SRC_DIR)/*.c)
HEADERS=$(wildcard $(SRC_DIR)/*.h)

OBJ_DIR=obj
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Exclude main.o from OBJS when building tests
OBJS_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

TEST_DIR=test
TEST_SRCS=$(wildcard $(TEST_DIR)/*.c)
TEST_BINS=$(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

build: $(BIN)

run: $(build)
	./$<

test: $(TESTS_BIN)

$(BIN): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $^ $(CFLAGS) -o $@

$(TEST_DIR)/bin/%: $(OBJS_NO_MAIN) $(TEST_DIR)/%.c | $(TEST_DIR)/bin
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) -lcriterion

test: $(TEST_DIR)/bin $(TEST_BINS)
	for test in $(TEST_BINS); do ./$$test; done

clean:
	rm obj/* $(BIN) $(TEST_BINS)

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

$(TEST_DIR)/bin:
	mkdir -p $@
