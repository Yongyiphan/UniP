
GCC_OPTIONS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror

OBJS = q-driver.cpp q.cpp
Testdir = ./data+files/
File1 = $(Testdir)tsunamis1.txt
File2 = $(Testdir)tsunamis2.txt
File3 = $(Testdir)tsunamis3.txt

File4 = $(Testdir)output1.txt
File5 = $(Testdir)output2.txt
File6 = $(Testdir)output3.txt


q.out: $(OBJS) 
	g++ $(GCC_OPTIONS) $(OBJS) -o q.out

file1:
	make
	./q.out $(File1) $(Testdir)kek.txt
	diff -y --strip-trailing-cr --suppress-common-lines $(Testdir)kek.txt $(File4)

file2:
	make
	./q.out $(File2) $(Testdir)kek.txt
	diff -y --strip-trailing-cr --suppress-common-lines $(Testdir)kek.txt $(File5)

file3:
	make
	./q.out $(File3) $(Testdir)kek.txt
	diff -y --strip-trailing-cr --suppress-common-lines $(Testdir)kek.txt $(File6)