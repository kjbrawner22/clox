IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib
TESTDIR=../tests

LIBS=-lreadline

_TESTS = arithmetic.lox bool.lox
TESTS  = $(patsubst %,$(TESTDIR)/%,$(_TESTS))

_DEPS = chunk.h common.h compiler.h debug.h object.h memory.h scanner.h value.h vm.h
DEPS  = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = chunk.o compiler.o object.o main.o debug.o memory.o scanner.o value.o vm.o
OBJ  = $(patsubst %,$(ODIR)/%,$(_OBJ))



$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clox: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(TESTDIR)/%.lox: clox FORCE
	@echo "========== START TEST " $@ " =========="
	./clox $@
	@echo "========== END TEST " $@ " =========="

FORCE:

tests: $(TESTS)
	@echo "---------- TESTS DONE ----------"

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ clox