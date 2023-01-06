




test1:
	gcc -DUSE_STRING -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o q.out qdriver.c q.c
	./q.out > actual-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines actual-output.txt expected-output.txt


2:
	gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o q.out qdriver.c q.c my_string.c
	./q.out > actual-output.txt

test2:
	diff -y --strip-trailing-cr --suppress-common-lines actual-output.txt expected-output.txt
