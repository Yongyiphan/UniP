
#makefile for exmaple.out
# the # symbol means the rest of the line is a comment

# this is definition of macro GCC_OPTIONS
GCC_OPTIONS = -std=c11 -pedantic-errors -Wstrict-prototypes -Wall -Wextra -Werror

OBJS = qdriver.o q.o

q.out: $(OBJS) 
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm

qdriver.o : qdriver.c
	gcc $(GCC_OPTIONS) -c qdriver.c -o qdriver.o

q.o : q.c q.h
	gcc $(GCC_OPTIONS) -c q.c -o q.o -lm

output:
	./q.out > your-output.txt

test:
	./q.out > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt output.txt

# clean is a target with no prerequisites:
# typing the command in the shell
# make clean
# will only exeute the command which is to delete the object files
clean :
	rm $(OBJS)