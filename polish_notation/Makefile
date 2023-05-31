CC = gcc
CFLAGS = -Wall -Werror -Wextra 

GKOVFLAGS = -lgcov --coverage
CHECKFLAGS = -lcheck

OS = $(shell uname)
ifeq ($(OS), Linux)
CHECKFLAGS += -lm -lpthread -lsubunit -lrt
endif
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TESTS_SOURSES = $(wildcard ./tests/*.check)
CFLAGS_GCOV =-fprofile-arcs --coverage

all: polish_notation.a

rebuild: clean all

polish_notation.a: $(OBJECTS) polish_notation.h parsing.h stack.h
	ar rc $@ $(OBJECTS)
	ranlib -D $@

lib_cov.a: $(SOURCES) polish_notation.h parsing.h stack.h
	$(CC) $(CFLAGS) $(CFLAGS_GCOV) -c  $(SOURCES)
	ar rc lib_cov.a $(OBJECTS)
	ranlib lib_cov.a

test: clean $(TESTS_SOURSES) polish_notation.a
	@checkmk clean_mode=1 ./polish_notation.h $(TESTS_SOURSES) > test.c
	$(CC) test.c $(CHECKFLAGS) -lm polish_notation.a -o test
	./test

gcov_report: clean $(TESTS_SOURSES) lib_cov.a
	checkmk clean_mode=1 $(TESTS_SOURSES) > test.c
	$(CC)  test.c -c
	$(CC)  test.o -g $(CHECKFLAGS) lib_cov.a -o test $(GKOVFLAGS)
	./test > /dev/null
	lcov -t "t" -o test.info -c -d . 
	genhtml -o report test.info 
	open ./report/index.html
	rm -f test.c

clean:
	rm -rf *.a *.o *.test *test.c .test.c *.gcda *.gcno *.info test.c report *.out test report