.RECIPEPREFIX = >

CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra

LIFT = python3 lift.py
test: build/test_input
> ./build/test_input

build/test_input: test_input_main.c build/lifted_input.c build/lifted_misc.c build/lifted_jsr.c build/lifted_trans.c build/lifted_arith.c
> $(CC) $(CFLAGS) -I . -o build/test_input test_input_main.c

build/lifted_input.c: fixtures/input_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/input_snip.s build/lifted_input.c b7 LE914

build/lifted_misc.c: fixtures/misc_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/misc_snip.s build/lifted_misc.c b7 entry_E895,entry_E89F,entry_E996

clean:
> rm -rf build

build/lifted_jsr.c: fixtures/jsr_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/jsr_snip.s build/lifted_jsr.c b7 entry_E974,LE9A2

build/lifted_trans.c: fixtures/trans_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/trans_snip.s build/lifted_trans.c b7 LC7C7,entry_CA14

build/lifted_arith.c: fixtures/arith_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/arith_snip.s build/lifted_arith.c b7 entry_D136,entry_D151,entry_D161,entry_D02D
