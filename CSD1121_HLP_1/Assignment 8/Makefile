GCC_OPTIONS = -std=c11 -pedantic-errors -Wstrict-prototypes -Wall -Wextra  -Werror -Werror=vla
OBJS = qdriver.o q.o
EXEC = q.out

$(EXEC) : $(OBJS)
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm
	
qdriver.o : qdriver.c q.h
	gcc $(GCC_OPTIONS) -c qdriver.c -o qdriver.o
	
q.o : q.c q.h
	gcc $(GCC_OPTIONS) -c q.c -o q.o

test:
	./q.out 1 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output1.txt
	./q.out 2 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output2.txt
	./q.out 3 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output3.txt
	./q.out 4 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output4.txt
	./q.out 5 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output5.txt
	./q.out 6 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output6.txt
	./q.out 7 myoutput1.txt
	diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./output/output7.txt


clean:
	rm $(OBJS) $(EXEC)
