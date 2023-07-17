CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror -g

all: clean s21_cat test check

s21_cat: s21_cat.o 
	@$(CC)  s21_cat.o -o s21_cat

s21_cat.o: s21_cat.c s21_cat.h
	@$(CC) $(CFLAGS) s21_cat.c s21_cat.h 

clean:
	@rm -rf *.out *.o *.gch  log.txt logTest.txt s21_cat

test: 
	@chmod 777 s21_cat
	@chmod 777 s21_cat_test.sh
	@sh s21_cat_test.sh


OS = $(shell uname)
ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
	CC += -D OS_LINUX -g
	CHECK_LEAKS=valgrind --leak-check=full --log-file=log.txt
else
	LINUX_LIBS=
	CC += -D OS_MAC
	CHECK_LEAKS=CK_FORK=no leaks --atExit --
	OPEN_GCOV=open coverage/index.html
endif

check:
	@cppcheck s21_cat.c s21_cat.h 
	@cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../../materials/linters/cpplint.py --extension=c s21_cat.c s21_cat.h 
	@$(CC) s21_cat.c -lcheck $(LINUX_LIBS) -o ./Test
	@$(CHECK_LEAKS) ./Test
	@rm CPPLINT.cfg Test
