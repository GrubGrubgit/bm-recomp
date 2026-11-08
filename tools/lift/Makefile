.RECIPEPREFIX = >

CC ?= gcc
CFLAGS ?= -O2 -Wall -Wextra

LIFT = python3 lift.py
FIX = fixtures/input_snip.s
GEN = build/lifted_input.c
BIN = build/test_input

test: $(BIN)
> ./$(BIN)

$(GEN): $(FIX) lift.py runtime.h
> mkdir -p build
> $(LIFT) $(FIX) $(GEN) b7 LE914

$(BIN): test_input_main.c $(GEN)
> $(CC) $(CFLAGS) -I . -o $(BIN) test_input_main.c

clean:
> rm -rf build
