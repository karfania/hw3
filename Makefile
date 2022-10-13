CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) -o $@ llrec.o llrec-test.o

llrec-test.o: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

valgrind: llrec-test
	$(VALGRIND) ./llrec-test llrec-test1.in

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 