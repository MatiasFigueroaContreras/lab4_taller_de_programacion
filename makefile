FLAGS = -g -Wall

all: clean test_FordFulkersonGraph test_FordFulkersonSolver test_MBPSolver run

test_MBPSolver: MBPSolver.o FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_MBPSolver.cpp
	g++ $(FLAGS) -o test_MBPSolver MBPSolver.o FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_MBPSolver.cpp

test_FordFulkersonSolver: FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonSolver.cpp
	g++ $(FLAGS) -o test_FordFulkersonSolver FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonSolver.cpp

test_FordFulkersonGraph: FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonGraph.cpp
	g++ $(FLAGS) -o test_FordFulkersonGraph FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonGraph.cpp

MBPSolver.o: MBPSolver.cpp MBPSolver.h
	g++ $(FLAGS) -c MBPSolver.cpp

FordFulkersonSolver.o: FordFulkersonSolver.cpp FordFulkersonSolver.h
	g++ $(FLAGS) -c FordFulkersonSolver.cpp

FordFulkersonGraph.o: FordFulkersonGraph.cpp FordFulkersonGraph.h
	g++ $(FLAGS) -c FordFulkersonGraph.cpp

FordFulkersonData.o: FordFulkersonData.cpp FordFulkersonData.h
	g++ $(FLAGS) -c FordFulkersonData.cpp

clean:
	rm -f test_FordFulkersonGraph test_FordFulkersonSolver test_MBPSolver *.o

run:
	./test_FordFulkersonGraph
	./test_FordFulkersonSolver
	./test_MBPSolver