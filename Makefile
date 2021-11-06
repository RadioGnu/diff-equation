CFLAGS = -Wall -pedantic
MATH = -lm

diffeq: diff.c quadratic.c quadratic.h
	gcc $(CFLAGS) -o bin/diffeq diff.c quadratic.c $(MATH)

