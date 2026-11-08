CC ?= gcc
CFLAGS ?= -O2 -Wall -Wextra

build/recomp-hello: src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ $<

test: build/recomp-hello
	./build/recomp-hello

clean:
	rm -rf build
