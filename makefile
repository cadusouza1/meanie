TEST_FILE=test.txt
BIN=meanie

LIBS=-lm

SRCS=$(wildcard *.c)

$(BIN): $(SRCS)
	gcc $(SRCS) $(LIBS) -o meanie

run: $(BIN)
	./$<

test: $(BIN)
	./$< < $(TEST_FILE)
