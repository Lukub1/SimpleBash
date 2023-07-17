CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -g -Wall -Wextra -Werror

all: clean s21_grep test check

s21_grep: s21_grep.o 
	@$(CC)  s21_grep.o -o s21_grep

s21_grep.o: s21_grep.c s21_grep.h
	@$(CC) $(CFLAGS) s21_grep.c s21_grep.h 

clean:
	@rm -rf *.out *.o *.gch log.txt logTest.txt s21_grep

test: 
	@chmod 777 s21_grep
	@chmod 777 s21_grep_test.sh
	@sh s21_grep_test.sh 


OS = $(shell uname)
ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
	CC += -D OS_LINUX -g
	CHECK_LEAKS=valgrind --leak-check=full --track-origins=yes --log-file=log.txt
else
	LINUX_LIBS=
	CC += -D OS_MAC
	CHECK_LEAKS=CK_FORK=no leaks --atExit --
	OPEN_GCOV=open coverage/index.html
endif

check:
	@cppcheck s21_grep.c s21_grep.h 
	@cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../../materials/linters/cpplint.py --extension=c s21_grep.c s21_grep.h 
	@$(CC) s21_grep.c -lcheck $(LINUX_LIBS) -o ./Test
	@$(CHECK_LEAKS) ./Test
	@rm CPPLINT.cfg  Test 
