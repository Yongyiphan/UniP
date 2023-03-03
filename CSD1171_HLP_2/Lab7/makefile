# name of C++ compiler
CXX       = g++
# options to C++ compiler
CXX_FLAGS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror
# flag to linker to make it link with math library
LDLIBS    = -lm
# list of object files
OBJS      = ft-driver.o
# name of executable program
EXEC      = ft.out
#			1	 2	   3      4     5   6   7   8     9        10  11   12		
TestFile  = Copy Count Equal Fill Find Max Min Remove Replace Sum Swap SwapRanges

# by convention the default target (the target that is built when writing
# only make on the command line) should be called all and it should
# be the first target in a makefile
all : $(EXEC)

# however, the problem that arises with the previous rule is that make
# will think all is the name of the target file that should be created
# so, we tell make that all is not a file name
.PHONY : all

# this rule says that target $(EXEC) will be built if prerequisite
# files $(OBJS) have changed more recently than $(EXEC)
# text $(EXEC) will be replaced with value sllist.out
# text $(OBJS) will be substituted with list of prerequisites in line 10
# line 31 says to build $(EXEC) using command $(CXX) with
# options $(CXX_FLAGS) specified on line 6
$(EXEC) : $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(EXEC) $(LDLIBS)

# target sllist-driver.o depends on both sllist-driver.cpp and sllist.hpp
# and is created with command $(CXX) given the options $(CXX_FLAGS)
ft-driver.o : ft-driver.cpp ft.hpp student.hpp
	$(CXX) $(CXX_FLAGS) -c ft-driver.cpp -o ft-driver.o

# says that clean is not the name of a target file but simply the name for
# a recipe to be executed when an explicit request is made
.PHONY : clean
# clean is a target with no prerequisites;
# typing the command in the shell: make clean
# will only execute the command which is to delete the object files
clean :
	rm -f $(OBJS) $(EXEC)

# says that rebuild is not the name of a target file but simply the name
# for a recipe to be executed when an explicit request is made
.PHONY : rebuild
# rebuild is for starting over by removing cleaning up previous builds
# and starting a new one
rebuild :
	$(MAKE) clean
	$(MAKE)

.PHONY : test
test : $(EXEC)
	./$(EXEC) > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt ft-output.txt
test1: $(EXEC)
	./$(EXEC) 1 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 1, $(TestFile)).txt
test2: $(EXEC)
	./$(EXEC) 2 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 2, $(TestFile)).txt
test3: $(EXEC)
	./$(EXEC) 3 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 3, $(TestFile)).txt
test4: $(EXEC)
	./$(EXEC) 4 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 4, $(TestFile)).txt
test5: $(EXEC)
	./$(EXEC) 5 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 5, $(TestFile)).txt
test6: $(EXEC)
	./$(EXEC) 6 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 6, $(TestFile)).txt
test7: $(EXEC)
	./$(EXEC) 7 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 7, $(TestFile)).txt
test8: $(EXEC)
	./$(EXEC) 8 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 8, $(TestFile)).txt
test9: $(EXEC)
	./$(EXEC) 9 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 9, $(TestFile)).txt
test10: $(EXEC)
	./$(EXEC) 10 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 10, $(TestFile)).txt
test11: $(EXEC)
	./$(EXEC) 11 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 11, $(TestFile)).txt
test12: $(EXEC)
	./$(EXEC) 12 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt Test$(word 12, $(TestFile)).txt

testall: $(EXEC)
	./$(EXEC) 11 > your-output.txt
	./$(EXEC) 12 >> your-output.txt
	./$(EXEC) 8  >> your-output.txt
	./$(EXEC) 2  >> your-output.txt
	./$(EXEC) 5  >> your-output.txt
	./$(EXEC) 1  >> your-output.txt
	./$(EXEC) 4  >> your-output.txt
	./$(EXEC) 9  >> your-output.txt
	./$(EXEC) 7  >> your-output.txt
	./$(EXEC) 6  >> your-output.txt
	./$(EXEC) 3  >> your-output.txt
	./$(EXEC) 10 >> your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-output.txt ft-output.txt