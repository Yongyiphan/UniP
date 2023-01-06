GCC_OPTIONS = -std=c11 -pedantic-errors -Wstrict-prototypes -Wall -Wextra -Wno-format-security -Werror -Werror=vla
OBJS = qdriver.o q.o
EXEC = q.out

$(EXEC) : $(OBJS)
	gcc $(GCC_OPTIONS) $(OBJS) -o q.out -lm
	
qdriver.o : qdriver.c q.h
	gcc $(GCC_OPTIONS) -c qdriver.c -o qdriver.o
	
q.o : q.c q.h
	gcc $(GCC_OPTIONS) -c q.c -o q.o

test:
	 ./q.out ./data+files/grades1.txt  myoutput1.txt
	 diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./data+files/output1.txt
	 ./q.out ./data+files/grades2.txt  myoutput1.txt
	 diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./data+files/output2.txt
	 ./q.out ./data+files/grades3.txt  myoutput1.txt
	 diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./data+files/output3.txt
	 ./q.out ./data+files/grades4.txt  myoutput1.txt
	 diff -y --strip-trailing-cr --suppress-common-lines myoutput1.txt ./data+files/output4.txt

out:
	 ./q.out ./data+files/grades1.txt myoutput1.txt



clean:
	rm $(OBJS) $(EXEC)
