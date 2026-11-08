.RECIPEPREFIX = >

CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra

LIFT = python3 lift.py
test: build/test_input build/test_vec
> ./build/test_input
> ./build/test_vec

build/test_input: test_input_main.c build/lifted_input.c build/lifted_misc.c build/lifted_jsr.c build/lifted_trans.c build/lifted_arith.c build/lifted_g3.c
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

build/lifted_g3.c: fixtures/g3_snip.s lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/g3_snip.s build/lifted_g3.c b7 entry_D7C0,entry_D7CF,entry_D804,entry_D81C,LE2AB

build/test_vec: test_vec_main.c build/lifted_vec.c build/lifted_xbank.c
> $(CC) $(CFLAGS) -I . -o build/test_vec test_vec_main.c

build/lifted_vec.c: fixtures/vec_snip.s fixtures/vec007A_mini.txt lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/vec_snip.s build/lifted_vec.c b7 entry_C9A4,LC9AE,LC9D3,LC900 entry_EA3A,entry_EB51 VEC:fixtures/vec007A_mini.txt

build/lifted_xbank.c: fixtures/xbank_snip.s fixtures/xbank_mini.txt lift.py runtime.h
> mkdir -p build
> $(LIFT) fixtures/xbank_snip.s build/lifted_xbank.c b7 entry_DEC2,entry_XBPB entry_DF05,entry_DF0A XBANK:fixtures/xbank_mini.txt
