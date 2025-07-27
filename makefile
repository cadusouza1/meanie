# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -pedantic
LIBS = -lm
TEST_LIBS = $(LIBS) -lcriterion
TEST_FLAGS = $(CFLAGS) -D_POSIX_C_SOURCE=200809L

# Directory structure
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test
TEST_BIN_DIR = $(TEST_DIR)/bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
HEADERS = $(wildcard $(SRC_DIR)/*.h)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

# Test files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TEST_SRCS))

# Main binary
BIN = $(BIN_DIR)/meanie

# Ensure directories exist
DIRS = $(BIN_DIR) $(OBJ_DIR) $(TEST_BIN_DIR)

default: build

$(DIRS):
	mkdir -p $@

# Main targets
.PHONY: all clean test build
all: $(BIN)

build: $(BIN)

# Compilation rules
$(BIN): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Test compilation and execution
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJS_NO_MAIN) | $(TEST_BIN_DIR)
	$(CC) $(TEST_FLAGS) $^ -o $@ $(TEST_LIBS)

test: $(TEST_BINS)
	@for test in $(TEST_BINS); do ./$$test;  done

# Cleanup
clean:
	rm -rf $(DIRS)
