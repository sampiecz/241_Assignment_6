#
# PROGRAM: Assign 6   
# PROGRAMMER: Samuel Piecz 
# LOGON ID: Z1732715 
# DATE DUE: 11/09/17 
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o    Queue.o
	g++ $(CCFLAGS) -o assign6 assign6.o Queue.o

# Rule to compile source code file to object code
assign6.o: assign6.cpp    Queue.h
	g++ $(CCFLAGS) -c assign6.cpp
Queue.o : Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
