CC     = g++
CFLAGS = -Wall -ansi -pedantic -g -fpermissive
LFLAGS = -lm 
LEX    = flex
LEXFLAGS =
YAC    = bison 
YACFLAGS = -v -d

EXEC   = pochodna
OBJS   = $(EXEC).tab.o $(EXEC).yy.o \
expression.o expr/function.o expr/const.o expr/econst.o expr/var.o \
expr/add.o expr/sub.o expr/neg.o expr/mul.o expr/div.o expr/pow.o expr/sqrt.o\
expr/cos.o expr/sin.o expr/tg.cc expr/ctg.cc expr/arcsin.cc expr/arccos.cc expr/arctg.cc expr/arcctg.cc expr/sinh.cc expr/cosh.cc expr/tgh.cc expr/ctgh.cc \
expr/ln.o expr/log.cc

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) $+ -o $@
	echo $@ zbudowane!

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%.yy.o: %.yy.c
	$(CC) -c $(CFLAGS) $<

%.yy.c: %.lex
	$(LEX) $(LEXFLAGS) -o$(<:.lex=.yy.c) $<

%.tab.o: %.tab.c
	$(CC) -c $(CFLAGS) $<

%.tab.c: %.y
	$(YAC) $(YACFLAGS) -o $(<:.y=.tab.c) $<

clean:
	rm -f *~ *.bak
	rm -f $(EXEC) $(OBJS) *.tab.? *.yy.?

.PHONY: clean install dist doc
