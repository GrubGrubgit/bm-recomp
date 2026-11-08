.RECIPEPREFIX = >

CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra

LIFT = python3 lift.py
test: build/test_input
> ./build/test_input

build/test_input: test_input_main.c build/lifted_input.c build/lifted_misc.c
> $(CC) $(CFLAGS) -I . -o build/test_input test_input_main.c

build/lifted_input.c: fixtures/input_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/input_snip.s build/lifted_input.c b7 LE914

build/lifted_misc.c: fixtures/misc_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/misc_snip.s build/lifted_misc.c b7 entry_E895,entry_E89F,entry_E996

clean:
> rm -rf build
