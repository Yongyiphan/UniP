
#makefile for exmaple.out
# the # symbol means the rest of the line is a comment

# this is definition of macro GCC_OPTIONS
GCC_OPTIONS = -std=c11 -pedantic-errors -Wstrict-prototypes -Wall -Wextra -Werror

OBJS = qdriver.o q.o

testRun = 2

q.out: $(OBJS) 
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out

q.o: q.h q.c
	gcc $(GCC_OPTIONS) -c q.c

qdriver.o:
	gcc $(GCC_OPTIONS) -c qdriver.c

test:
	make q.out
	./q.out > actual.txt

# diff -y --strip-trailing-cr --suppress-common-lines actual.txt expected-output.txt

test1:
	make q.out
	./q.out ./input/input2.txt > actual.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual.txt ./output/output2.txt

# clean is a target with no prerequisites:
# typing the command in the shell
# make clean
# will only exeute the command which is to delete the object files
clean :
	rm $(OBJS)