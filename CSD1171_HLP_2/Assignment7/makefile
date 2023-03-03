# name of C++ compiler
CXX       = g++
# options to C++ compiler
CXX_FLAGS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror
# flag to linker to make it link with math library
LDLIBS    = -lm
# list of object files
OBJS      = vector-driver.o vector.o
# name of executable program
EXEC      = vector.out

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
# text $(EXEC) will be replaced with value vector.out
# text $(OBJS) will be substituted with list of prerequisites in line 10
# line 31 says to build $(EXEC) using command $(CXX) with
# options $(CXX_FLAGS) specified on line 6
$(EXEC) : $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(EXEC) $(LDLIBS)

# target vector-driver.o depends on both vector-driver.cpp and vector.hpp
# and is created with command $(CXX) given the options $(CXX_FLAGS)
vector-driver.o : vector-driver.cpp vector.hpp
	$(CXX) $(CXX_FLAGS) -c vector-driver.cpp -o vector-driver.o
	
# target vector.o depends on both vector.cpp and vector.hpp
# and is created with command $(CXX) given the options $(CXX_FLAGS)
vector.o : vector.cpp vector.hpp
	$(CXX) $(CXX_FLAGS) -c vector.cpp -o vector.o

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
test1 : $(EXEC)
	./$(EXEC) 1 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./your-output.txt ./test1.txt
test2 : $(EXEC)
	./$(EXEC) 2 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./your-output.txt ./test2.txt
test3 : $(EXEC)
	./$(EXEC) 3 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./your-output.txt ./test3.txt
test4 : $(EXEC)
	./$(EXEC) 4 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./your-output.txt ./test4.txt
test5 : $(EXEC)
	./$(EXEC) 5 > your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./your-output.txt ./test5.txt
testall : $(EXEC)
	./$(EXEC) 1 > your-output.txt
	./$(EXEC) 2 >> your-output.txt
	./$(EXEC) 3 >> your-output.txt
	./$(EXEC) 4 >> your-output.txt
	./$(EXEC) 5 >> your-output.txt
	diff -y --strip-trailing-cr --suppress-common-lines ./your-output.txt ./output.txt
