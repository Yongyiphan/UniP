
GCC_OPTIONS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror

OBJS = wc-driver.cpp wc.cpp
Testdir = ../sample+text+files/
File1 = $(Testdir)161-0.txt
File2 = $(Testdir)duck.txt
File3 = $(Testdir)marylamb.txt
File4 = $(Testdir)pg2641.txt

testRun = 2

wc.out: $(OBJS) 
	g++ $(GCC_OPTIONS) $(OBJS) -o wc.out

161:
	./wc.out $(File1)
	../sample+exec/sample-wc.out $(File1)
duck:
	./wc.out $(File2)
	../sample+exec/sample-wc.out $(File2)
lamb:
	./wc.out $(File3)
	../sample+exec/sample-wc.out $(File3)