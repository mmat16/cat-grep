CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11 -Wpedantic

all: s21_cat s21_grep

s21_cat:
	$(CC) $(FLAGS) -c cat/s21_cat.c cat/functions.c cat/helper.c
	$(CC) *.o -o cat/s21_cat
	rm -f *.o

s21_grep:
	$(CC) $(FLAGS) -c grep/s21_grep.c grep/functions.c grep/helper.c
	$(CC) *.o -o grep/s21_grep
	rm -f *.o

clean:
	rm -f grep/s21_grep cat/s21_cat

rebuild:
	make clean
	make
