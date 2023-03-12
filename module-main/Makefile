CC = clang
LAB_OPTS = -I./src src/lib.c
C_OPTS = $(MAC_OPTS) -std=gnu11 -g -lm -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
DOCG = doxygen
DOC = Doxyfile

clean:
	rm -rf dist

clean1:
	rm -rf ./dist/html
	rm -rf ./dist/latex 
prep:
	mkdir dist
compile: main.bin 

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main.bin
check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
all: clean prep compile check

Doxygen:
	$(DOCG) $(DOC)
	
all1: clean1 Doxygen

compile_2: test.bin

test.bin:  test/test.c
	 $(CC) $(C_OPTS) $< -fprofile-instr-generate -fcoverage-mapping  -o ./dist/$@ -lcheck 
test: prep compile_2
		LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
		llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
		llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
		llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html
