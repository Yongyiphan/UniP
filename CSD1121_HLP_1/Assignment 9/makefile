GCC_OPTIONS = -std=c11 -pedantic-errors -Wstrict-prototypes -Wall -Wextra -Werror=vla
OBJS = qdriver.o q.o
EXEC = q.out

$(EXEC) : $(OBJS)
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm
	
qdriver.o : qdriver.c q.h
	gcc $(GCC_OPTIONS) -c qdriver.c -o qdriver.o
	
q.o : q.c q.h
	gcc $(GCC_OPTIONS) -c q.c -o q.o

test1:
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm
	./q.out ./data+files/tsunamis1.txt actual1.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./data+files/output1.txt actual1.txt

test:
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm
	./q.out ./data+files/tsunamisall.txt actualall.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./data+files/outputall.txt actualall.txt

clean:
	rm $(OBJS) $(EXEC)
