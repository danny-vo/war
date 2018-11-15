# Which compiler
CXX = g++

# Flags for compiler
WFLAGS   = -Wall -Wextra# Prompts warnings for easily fixable sus code
SYMFLAGS = -g# Debug symbols for gdb 
THRFLAGS = -pthread# Enable multithread support
PERFLAGS = -fpermissive# Downgrades some compiler specific errors into warnings to allow compilation (you should really fix them however)
VERFLAGS = -std=c++11# Target language version

# Brevity's sake
CXXFLAGS = $(WFLAGS) $(SYMFLAGS) $(THRFLAGS) $(PERFLAGS) $(VERFLAGS)

# Name of your program executable
PROGRAM = war

# Source code, i.e. all the c++ files in the directory
CCSRC  = $(wildcard *.cc)
CPPSRC = $(wildcard *.cpp)

# Object files to be created from their respective c++ files
CCOBJS  = $(CCSRC:.cc=.o)
CPPOBJS = $(CPPSRC:.cpp=.o)
OBJS    = $(CCOBJS) $(CPPOBJS)

# Default make target, i.e. create the executable for your program
all: $(PROGRAM)

# Program executable dependent on object files from each c src, compiles them
$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

# The following are targets for convenience, e.g. you can type "make valgrind" to
# compile (if needed) then run valgrind on your created executable and so forth

# Runs the executable
test: $(PROGRAM)
	./$(PROGRAM)

# Runs gdb on the executable
gdb: $(PROGRAM)
	gdb ./$(PROGRAM)

# Runs valgrind on the executable
valgrind: $(PROGRAM)
	valgrind --leak-check=yes ./$(PROGRAM)

# Removes all object files and executable from the directory
clean:
	-rm -f $(OBJS) $(PROGRAM)