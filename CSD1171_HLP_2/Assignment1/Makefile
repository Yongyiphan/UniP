
GCC_OPTIONS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror

OBJS = q-driver.cpp q.cpp
Testdir = ./data/
File1 = $(Testdir)file1-stats.txt
File2 = $(Testdir)file1.txt
File3 = $(Testdir)file2-stats.txt
File4 = $(Testdir)file2.txt
File5 = $(Testdir)file3-stats.txt
File6 = $(Testdir)file3.txt


q.out: $(OBJS) 
	g++ $(GCC_OPTIONS) $(OBJS) -o q.out

file1:
	make
	./q.out $(File2) $(Testdir)kek.txt
	diff -y --strip-trailing-cr --suppress-common-lines $(Testdir)kek.txt $(File1)

file2:
	make
	./q.out $(File4) $(Testdir)kek.txt
	diff -y --strip-trailing-cr --suppress-common-lines $(Testdir)kek.txt $(File3)

file3:
	make
	./q.out $(File6) $(Testdir)kek.txt
	diff -y --strip-trailing-cr --suppress-common-lines $(Testdir)kek.txt $(File5)