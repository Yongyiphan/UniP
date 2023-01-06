
#makefile for exmaple.out
# the # symbol means the rest of the line is a comment

# this is definition of macro GCC_OPTIONS
GCC_OPTIONS = -std=c11 -pedantic-errors -Wstrict-prototypes -Wall -Wextra -Werror

OBJS = qdriver.o q.o

q.out: $(OBJS) 
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm

test0: test0.c q.c
	gcc $(GCC_OPTIONS) -o test0 test0.c q.c

test0Out:
	./test0 < input-test0-0.txt > actual-output-test0-0.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test0-0.txt expected-output-test0-0.txt
	./test0 < input-test0-1.txt > actual-output-test0-1.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test0-1.txt expected-output-test0-1.txt
	./test0 < input-test0-2.txt > actual-output-test0-2.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test0-2.txt expected-output-test0-2.txt
	./test0 < input-test0-3.txt > actual-output-test0-3.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test0-3.txt expected-output-test0-3.txt

test1: test1.c q.c
	gcc $(GCC_OPTIONS) -o test1 test1.c q.c

test1Out:
	./test1 < input-test1-4.txt > actual-output-test1-4.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test1-4.txt expected-output-test1-4.txt
	./test1 < input-test1-5.txt > actual-output-test1-5.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test1-5.txt expected-output-test1-5.txt


test2: test2.c q.c
	gcc $(GCC_OPTIONS) -o test2 test2.c q.c

test2Out:
	./test2 < input-test2-6.txt > actual-output-test2-6.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test2-6.txt expected-output-test2-6.txt
	./test2 < input-test2-7.txt > actual-output-test2-7.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test2-7.txt expected-output-test2-7.txt

test3: test3.c q.c
	gcc $(GCC_OPTIONS) -o test3 test3.c q.c

test3Out:
	./test3 < input-test3-8.txt > actual-output-test3-8.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test3-8.txt expected-output-test3-8.txt
	./test3 < input-test3-9.txt > actual-output-test3-9.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test3-9.txt expected-output-test3-9.txt
	./test3 < input-test3-10.txt > actual-output-test3-10.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test3-10.txt expected-output-test3-10.txt
	./test3 < input-test3-11.txt > actual-output-test3-11.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test3-11.txt expected-output-test3-11.txt

test4: test4.c q.c
	gcc $(GCC_OPTIONS) -o test4 test4.c q.c

test4Out:
	./test4 < input-test4-12.txt > actual-output-test4-12.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test4-12.txt expected-output-test4-12.txt
	./test4 < input-test4-13.txt > actual-output-test4-13.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test4-13.txt expected-output-test4-13.txt
	./test4 < input-test4-14.txt > actual-output-test4-14.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test4-14.txt expected-output-test4-14.txt
	./test4 < input-test4-15.txt > actual-output-test4-15.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test4-15.txt expected-output-test4-15.txt
	./test4 < input-test4-16.txt > actual-output-test4-16.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test4-16.txt expected-output-test4-16.txt
	./test4 < input-test4-17.txt > actual-output-test4-17.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-test4-17.txt expected-output-test4-17.txt

qout: qdriver.c q.c
	gcc $(GCC_OPTIONS) -o q.out qdriver.c q.c

qtest:
	./q.out < input-third_largest-18.txt > actual-output-third_largest-18.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-third_largest-18.txt expected-output-third_largest-18.txt
	./q.out < input-third_largest-19.txt > actual-output-third_largest-19.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-third_largest-19.txt expected-output-third_largest-19.txt
	./q.out < input-third_largest-20.txt > actual-output-third_largest-20.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-third_largest-20.txt expected-output-third_largest-20.txt
	./q.out < input-third_largest-21.txt > actual-output-third_largest-21.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-third_largest-21.txt expected-output-third_largest-21.txt
	./q.out < input-third_largest-22.txt > actual-output-third_largest-22.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-third_largest-22.txt expected-output-third_largest-22.txt
	./q.out < input-third_largest-23.txt > actual-output-third_largest-23.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output-third_largest-23.txt expected-output-third_largest-23.txt


# clean is a target with no prerequisites:
# typing the command in the shell
# make clean
# will only exeute the command which is to delete the object files
clean :
	rm $(OBJS)