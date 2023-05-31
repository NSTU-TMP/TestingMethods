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

all: shadow_calculator.a

rebuild: clean all

shadow_calculator.a: $(OBJECTS) segment.h
	ar rc $@ $(OBJECTS)
	ranlib -D $@

lib_cov.a: $(SOURCES) segment.h
	$(CC) $(CFLAGS) $(CFLAGS_GCOV) -c  $(SOURCES)
	ar rc lib_cov.a $(OBJECTS)
	ranlib lib_cov.a

test: clean $(TESTS_SOURSES) shadow_calculator.a
	@checkmk clean_mode=1 ./segment.h $(TESTS_SOURSES) > test.c
	$(CC) test.c $(CHECKFLAGS) -lm shadow_calculator.a -o test
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