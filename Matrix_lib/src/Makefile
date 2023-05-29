SRC_DIR := ./
TEST_SRC_DIR := ./test/

DATE=date

LIB_SRC = $(shell find $(SRC_DIR) -maxdepth 1 -name 's21*.c')

LIB_OBJ := $(LIB_SRC:.c=.o)

TEST_SRC = $(shell find $(TEST_SRC_DIR) -maxdepth 1 -name 's21*.c')

TEST_OBJ := $(TEST_SRC:.c=.o)
OS := $(shell uname -s)

CFLAGS := -c

GCOV_CFLAGS := -fprofile-arcs -ftest-coverage -fPIC

ifeq ($(OS), Linux)
    LFLAGS := -lcheck -lpthread -lrt -lm -lsubunit
else
    LFLAGS =  -lcheck $(shell pkg-config --libs check)
endif

GCOV_LFLAGS := --coverage

TEST_CFLAGS += $(GCOV_CFLAGS)
TEST_CFLAGS += $(CFLAGS)

TEST_LFLAGS += $(GCOV_LFLAGS)
TEST_LFLAGS += $(LFLAGS)

LIB_CFLAGS += $(CFLAGS)

LIB_LFLAGS += $(LFLAGS)

CC := gcc
COV := gcovr

all: s21_matrix.a clean test

$(LIB_OBJ): %.o: %.c
	$(CC) $(TEST_CFLAGS) -g $< -o $@

$(TEST_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -g $< -o $@

test: $(TEST_OBJ) main.o $(LIB_OBJ)
	$(CC) $(TEST_OBJ) main.o $(LIB_OBJ) $(TEST_LFLAGS) -o s21_matrix

s21_matrix.a:
	$(CC) $(LIB_CFLAGS) $(LIB_SRC)
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

main.o: main.c
	$(CC) $(CFLAGS) -g $< -o $@

gcov_report:
	-@mkdir ./html_report
	$(COV) -r . --html --html-details -o ./html_report/coverage_report.html

open:
	open ./html_report/coverage_report.html

check: check_clang check_leaks

check_clang:
	@cp ../materials/linters/.clang-format ./.clang-format
	@clang-format -i *.c *.h
	@clang-format -i $(TEST_DIR)*.c $(TEST_DIR)*.h
	@clang-format -n *.c *.h
	@clang-format -n $(TEST_DIR)*.c $(TEST_DIR)*.h
	@rm .clang-format

check_leaks:
ifeq ($(OS), Linux)
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./s21_matrix
else
	leaks -atExit -- ./s21_matrix | grep LEAK:
endif

push:
	git add .
	git commit -m "project done"
	git push origin develop

clean:
	rm -rf *.o a.out \
	./html_report/   \
	./**/*.gcno      \
	./**/*.gcda 	 \
	*.gcno           \
	*.gcda           \
	./**/*.a         \
	./**/*.o         \
	./test/*.gcda    \
	./test/*.gcno    \
	./log.txt        \
	s21_matrix.a     \
	s21_matrix

.PHONY: all           \
		clean         \
		test          \
		s21_matrix.a  \
		gcov_report

