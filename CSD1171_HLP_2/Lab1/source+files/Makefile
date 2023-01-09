
GCC_OPTIONS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror

OBJS = wc-driver.cpp wc.cpp
Testdir = ../sample+text+files/
File1 = $(Testdir)161-0.txt
File2 = $(Testdir)duck.txt
File3 = $(Testdir)marylamb.txt
File4 = $(Testdir)pg2641.txt
File5 = $(Testdir)pg6761.txt
File6 = $(Testdir)pg69703.txt


wc.out: $(OBJS) 
	g++ $(GCC_OPTIONS) $(OBJS) -o wc.out


161:
	make
	./wc.out $(File1)
	../sample+exec/sample-wc.out $(File1)
duck:
	make
	./wc.out $(File2)
	../sample+exec/sample-wc.out $(File2)
lamb:
	make
	./wc.out $(File3)
	../sample+exec/sample-wc.out $(File3)
	
pg2641:
	make
	./wc.out $(File4)
	../sample+exec/sample-wc.out $(File4)

pg6761:
	make
	./wc.out $(File5)
	../sample+exec/sample-wc.out $(File5)

pg69703:
	make
	./wc.out $(File6)
	../sample+exec/sample-wc.out $(File6)